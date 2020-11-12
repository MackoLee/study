https://www.acmicpc.net/problem/16357

```c++
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int tree_size=1<<18;
int seg[tree_size*2]={0},lazy[tree_size*2]={0},N,ux,vx;

void update_seg(int i, int s, int size, int a, int b, int v){
    if(s==a and s+size-1==b){
        lazy[i]+=v;
        return;
    }
    if(lazy[i]){
        lazy[i*2]+=lazy[i];
        lazy[i*2+1]+=lazy[i];
        lazy[i]=0;
    }
    size/=2;
    int m=s+size;
    if(a<m) update_seg(i*2,s,size,a,min(b,m-1),v);
    if(b>=m) update_seg(i*2+1,m,size,max(a,m),b,v);
    seg[i]=max(seg[i*2]+lazy[i*2],seg[i*2+1]+lazy[i*2+1]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    vector<pair<int,int>> y(N);
    vector<int> y_down;
    for(int i=0;i<N;i++){
        cin>>ux>>y[i].second>>vx>>y[i].first;
        y_down.push_back(y[i].first);
        y_down.push_back(y[i].second);
    }
    sort(y_down.begin(), y_down.end());
    y_down.erase(unique(y_down.begin(), y_down.end()),y_down.end());
    for(int i=0;i<N;i++){
        y[i].first=lower_bound(y_down.begin(),y_down.end(),y[i].first)-y_down.begin();
        y[i].second=lower_bound(y_down.begin(),y_down.end(),y[i].second)-y_down.begin();
    }

    sort(y.begin(), y.end());
    set<pair<int,int>> y_in_line;
    vector<int> choose(y_down.size());
    int idx=0;
    for(int line=0; line<y_down.size();line++){
        while(line==y[idx].first){
            y_in_line.insert({y[idx].second, idx});
            idx++;
        }
        auto it=y_in_line.begin();
        while(y_in_line.size() and it->first<line){
            y_in_line.erase(it);
            it=y_in_line.begin();
        }
        choose[line]=y_in_line.size();
    }

    for(auto [a,b]: y) update_seg(1,0,tree_size,a,b,1);
    y_in_line.clear();
    idx=0;
    int answer=0;
    for(int line=0; line<y_down.size();line++){
        while(line==y[idx].first){
            y_in_line.insert({y[idx].second, idx});
            update_seg(1,0,tree_size,y[idx].first,y[idx].second,-1);
            idx++;
        }
        auto it=y_in_line.begin();
        while(y_in_line.size() and it->first<line){
            int i=it->second;
            update_seg(1,0,tree_size,y[i].first,y[i].second,1);
            y_in_line.erase(it);
            it=y_in_line.begin();
        }
        answer=max(answer, choose[line]+seg[1]);
    }
    cout<<answer;
    return 0;
}

```
