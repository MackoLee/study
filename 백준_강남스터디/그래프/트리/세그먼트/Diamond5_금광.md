https://www.acmicpc.net/problem/10167
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

const int INF=1<<30,tree_size= 1<<12;
using namespace std;

vector<pair<pair<int,int>,int>> coor;
vector<int> y_loc;
int N,x,y,w;

void update_seg(int i,int s,int size,int a, int b,int v,long long* lazy_seg, long long* seg){
    if(s==a and s+size-1==b){
        lazy_seg[i]+=v;
        return;
    }
    if(lazy_seg[i]){
        lazy_seg[i*2]+=lazy_seg[i];
        lazy_seg[i*2+1]+=lazy_seg[i];
        lazy_seg[i]=0;
    }
    size/=2;
    int m=s+size;
    if(a<m) update_seg(i*2, s, size, a, min(m-1,b), v, lazy_seg, seg);
    if(m<=b) update_seg(i*2+1, m, size, max(m,a), b, v, lazy_seg, seg);
    seg[i]=max(seg[i*2]+lazy_seg[i*2],seg[i*2+1]+lazy_seg[i*2+1]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x>>y>>w;
        coor.push_back({{x,y},w});
        y_loc.push_back(y);
    }

    sort(coor.begin(), coor.end());
    sort(y_loc.begin(),y_loc.end());
    y_loc.erase(unique(y_loc.begin(),y_loc.end()),y_loc.end());
    for(int i=0;i<N;i++) coor[i].first.second=(int) (lower_bound(y_loc.begin(),y_loc.end(),coor[i].first.second)-y_loc.begin());
    long long answer=0;
    for(int i=0;i<N;i++){
        long long l_seg[tree_size*2]={0},l_lazy_seg[tree_size*2]={0},r_seg[tree_size*2]={0},r_lazy_seg[tree_size*2]={0},cen=0;
        for(x=0;x<i;x++)
            if(coor[x].first.first==coor[i].first.first)
                update_seg(1,0,tree_size,0,coor[x].first.second,coor[x].second,l_lazy_seg,l_seg);

        for(int j=i;j<N;j++){
            for(;x<N and coor[j].first.first>=coor[x].first.first;x++){
                if(coor[i].first.second < coor[x].first.second)
                    update_seg(1,0,tree_size,coor[x].first.second,tree_size-1,coor[x].second,r_lazy_seg,r_seg);
                else if(coor[i].first.second > coor[x].first.second)
                    update_seg(1,0,tree_size,0,coor[x].first.second,coor[x].second,l_lazy_seg,l_seg);
                else {
                    r_lazy_seg[1]+=coor[x].second;
                    l_lazy_seg[1]+=coor[x].second;
                    cen+=coor[x].second;
                }
            }
            
            answer=max(answer,max(l_seg[1]+l_lazy_seg[1],r_seg[1]+r_lazy_seg[1]));
            answer=max(answer,l_seg[1]+l_lazy_seg[1]+r_seg[1]+r_lazy_seg[1]-cen);
        }
    }
    cout<<answer;
    return 0;
}
```
