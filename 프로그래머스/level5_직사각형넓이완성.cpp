#include <vector>
#include <set>
#include <algorithm>

#define tree_size (1<<18)
#define XXYY pair<pair<int,int>,pair<int,int>>

using namespace std;

int seg_major[tree_size*2]={0};
int seg_major_num[tree_size*2]={0};
int seg_minor[tree_size*2]={0};

vector<int> x_loc,y_loc;
set<XXYY> candi;

long long answer =0;

int get_idx(int y){
    return (int) (lower_bound(y_loc.begin(),y_loc.end(),y)-y_loc.begin());
}
void update_seg(int i, int value){
    for(;i>0;i/=2){
        seg_minor[i]+=value;
        if(seg_major_num[i]>0) break; //이미 크기를 차지하고 있으면 더이상 업데이트를 할 필요가 없다.
    }//이렇게 하면 최상위에는 반드시 업데이트된 크기만 남아있게 된다.
}
void insert_seg(int a, int b){
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            if(seg_major_num[a]++==0) update_seg(a/2,seg_major[a]-seg_minor[a]);
            a++;
        }
        if(~b&1){
            if(seg_major_num[b]++==0) update_seg(b/2,seg_major[b]-seg_minor[b]);
            b--;
        }
    }
}
void erase_seg(int a,int b){
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            if(--seg_major_num[a]==0) update_seg(a/2,seg_minor[a]-seg_major[a]);
            a++;
        }
        if(~b&1){
            if(--seg_major_num[b]==0) update_seg(b/2,seg_minor[b]-seg_major[b]);
            b--;
        }
    }
}
long long solution(vector<vector<int>> rect)
{
    sort(rect.begin(),rect.end());
    
    //get x, y locations
    for(auto r:rect){
        x_loc.push_back(r[0]);
        x_loc.push_back(r[2]);
        y_loc.push_back(r[1]);
        y_loc.push_back(r[3]);
    }
    //O(nlogn)
    sort(x_loc.begin(),x_loc.end());
    sort(y_loc.begin(),y_loc.end());
    x_loc.erase(unique(x_loc.begin(),x_loc.end()),x_loc.end());
    y_loc.erase(unique(y_loc.begin(),y_loc.end()),y_loc.end());

    //make seg  O(n)
    for(int i=0;i<y_loc.size()-1;i++) seg_major[i+tree_size]=y_loc[i+1]-y_loc[i];
    for(int i=tree_size-1;i>0;i--) seg_major[i]=seg_major[i*2]+seg_major[i*2+1];

    //y to idx
    for(int i=0;i<rect.size();i++){ //O(nlogn)
        rect[i][1]=get_idx(rect[i][1]);
        rect[i][3]=get_idx(rect[i][3])-1;
    }

    //get_area
    auto it = rect.begin();
    int sickbulja=0;
    for(int i=1;i<x_loc.size();i++){ //O(nlognlogn)
        int pre_x=x_loc[i-1];
        while(it!=rect.end() and it->at(0)==pre_x){//시작지점에 포함되는 것을 추가.
            candi.insert({{it->at(2),sickbulja++},{it->at(1),it->at(3)}});
            insert_seg(it->at(1),it->at(3)); //O(lognlogn)
            it++;
        }
        while(candi.size() and candi.begin()->first.first==pre_x){//시작지점이 지난부분을 삭제.
            erase_seg(candi.begin()->second.first,candi.begin()->second.second); 
            //O(lognlogn)
            candi.erase(candi.begin()); //O(logn)
        }
        answer+=(long long)((long long)seg_minor[1]*(long long)(x_loc[i]-pre_x));
    }
    return answer;
}
