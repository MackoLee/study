#include <iostream>
#include <vector>
#include <set>

#define get_inner(i) ((i)*(i-1)*3+1)

using namespace std;
int honeycomb[10001]={0};
set<pair<int,int>> sorce_set;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=1;i<6;i++) sorce_set.insert({1+(i/2==1),i});
    for(int i=0;i<7;i++) honeycomb[i]=i+1-i/5*4;
    
    for(int i=2,j=0;get_inner(i)+j<10000;){
        auto it=sorce_set.begin();
        while((j>0 and (honeycomb[get_inner(i-1) + j-j/i-1]==it->second or honeycomb[get_inner(i-1) + j-(j+1)/i]==it->second)) or
              (j==0 and honeycomb[get_inner(i-1)]==it->second) or
              (j==i*6-1 and honeycomb[get_inner(i)]==it->second) or
              honeycomb[get_inner(i) + j-1]==it->second
              )
            it++;
        honeycomb[get_inner(i)+j]=it->second;
        sorce_set.erase(it);
        sorce_set.insert({it->first+1,it->second});
        
        if(i*6==++j){
            i++;
            j=0;
        }
    }

    int N,m;
    for(cin>>N;N--;){
        cin>>m;
        cout<<honeycomb[m-1]<<'\n';
    }

    return 0;
}
