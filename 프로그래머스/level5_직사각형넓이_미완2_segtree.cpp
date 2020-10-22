#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define tree_size (1<<18)
#define XXYY pair<pair<int,int>,pair<int,int>>
using namespace std;

struct SEGTREE{
    int major=0;
    int major_num=0;
    int minor=0;
};

SEGTREE seg[tree_size*2];

vector<int> x_loc,y_loc;
set<XXYY> candi;

int get_idx(int y){
    return (int) distance(y_loc.begin(),find(y_loc.begin(),y_loc.end(),y));
}
void update_seg(int i, int value){
    for(;i>0;i/=2){
        seg[i].minor+=value;
        if(seg[i].major_num>0) break;
    }
}
void insert_seg(int a, int b){
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            if(seg[a].major_num++==0) update_seg(a/2,seg[a].major-seg[a].minor);
            a++;
        }
        if(~b&1){
            if(seg[b].major_num++==0) update_seg(b/2,seg[b].major-seg[b].minor);
            b--;
        }
    }
}
void erase_seg(int a,int b){
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            //cout<<seg[a].major<<' '<<seg[a].major_num<<' '<<seg[a].minor<<'\n';
            if(--seg[a].major_num==0) update_seg(a/2,seg[a].minor-seg[a].major);
            a++;
        }
        if(~b&1){
            //cout<<seg[b].major<<' '<<seg[b].major_num<<' '<<seg[b].minor<<'\n';
            if(--seg[b].major_num==0) update_seg(b/2,seg[b].minor-seg[b].major);
            b--;
        }
    }
}
bool cmp(vector<int> a, vector<int> b){
    return a[0]==b[0]?a[2]<b[2]:a[0]<b[0];
}
long long solution(vector<vector<int>> rect)
{
    long long answer=0;
    sort(rect.begin(),rect.end(),cmp);
    
    //get x, y locations
    for(auto r:rect){
        x_loc.push_back(r[0]);
        x_loc.push_back(r[2]);
        y_loc.push_back(r[1]);
        y_loc.push_back(r[3]);
    }
    sort(x_loc.begin(),x_loc.end());
    sort(y_loc.begin(),y_loc.end());
    x_loc.erase(unique(x_loc.begin(),x_loc.end()),x_loc.end());
    y_loc.erase(unique(y_loc.begin(),y_loc.end()),y_loc.end());
    
    //make seg
    for(int i=0;i<y_loc.size()-1;i++) seg[i+tree_size].major=y_loc[i+1]-y_loc[i];
    for(int i=tree_size-1;i>0;i--) seg[i].major=seg[i*2].major+seg[i*2+1].major;
    
    //get_area
    auto it = rect.begin();
    auto x_it = x_loc.begin();

    for(;x_it!=x_loc.end();){
        while(it!=rect.end() and it->at(0)==*x_it){
            candi.insert({{it->at(2),it->at(0)},{it->at(1),it->at(3)}});
            insert_seg(get_idx(it->at(1)), get_idx(it->at(3))-1);
            it++;
        }
        int pre_x=*x_it++;
        while((candi.begin()->first).first==pre_x){
            erase_seg(get_idx(candi.begin()->second.first), get_idx(candi.begin()->second.second)-1);
            candi.erase(candi.begin());
        }
        if(candi.size()) answer+=seg[1].minor*(*x_it-pre_x);
    }
    return answer;
}
