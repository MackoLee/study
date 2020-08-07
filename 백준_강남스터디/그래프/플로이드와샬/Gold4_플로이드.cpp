//https://www.acmicpc.net/problem/11404
//채점 번호   	아이디	     문제 번호	 결과	   메모리	시간	언어	     코드 길이
//20675438	sangok1993	11404	맞았습니다!!	2116	28	C++14 / 수정	819

#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool update=true;
#define NO_ROOT 10000000
#define min(a,b) a<b?a:b

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int i,j,r;
    cin>>N>>M;
    
    vector<vector<int>> bus_root(N,vector<int>(N,NO_ROOT));
    
    for(int x =0; x<M; x++){
        cin>>i>>j>>r;
        bus_root[i-1][j-1]=min(bus_root[i-1][j-1],r);
    }
    for(int i=0;i<N;i++) bus_root[i][i]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                bus_root[j][k]=min(bus_root[j][k],bus_root[j][i]+bus_root[i][k]);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<< bus_root[i][j]%NO_ROOT<<' ';
        cout<<endl;
    }
    
    return 0;
}
