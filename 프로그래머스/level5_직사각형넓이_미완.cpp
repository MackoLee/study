#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define XXYY pair<pair<int,int>,pair<int,int>>
using namespace std;

set<int> x_loc;
set<XXYY> candi;
set<XXYY> y_candi;
bool cmp(vector<int> a, vector<int> b){
    return a[0]==b[0]?a[2]<b[2]:a[0]<b[0];
}
long long get_area(int x){
    long long y_area=0;
    int max_y2=0;
    for(auto xy:y_candi){ //O(N)
        auto pair_y=xy.first;
        int y1=pair_y.first, y2=pair_y.second;
        if(y2>max_y2){
            y_area+= (y2- max(y1,max_y2));
            max_y2=y2;
        }
    }
    return y_area*x;
}
long long solution(vector<vector<int>> rect)
{
    long long answer=0;
    sort(rect.begin(),rect.end(),cmp);
    for(auto r:rect){
        x_loc.insert(r[0]);
        x_loc.insert(r[2]);
    }

    auto it = rect.begin();
    auto x_it = x_loc.begin();

    for(;x_it!=x_loc.end();){
        while(it!=rect.end() and it->at(0)==*x_it){
            candi.insert({{it->at(2),it->at(0)},{it->at(1),it->at(3)}});
            y_candi.insert({{it->at(1),it->at(3)},{it->at(2),it->at(0)}});
            it++;
        }
        int pre_x=*x_it++;
        while((candi.begin()->first).first==pre_x){
            y_candi.erase({candi.begin()->second,candi.begin()->first});
            candi.erase(candi.begin());
        }
        if(candi.size()) answer+=get_area(*x_it-pre_x);
    }
    return answer;
}
