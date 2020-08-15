// https://www.acmicpc.net/problem/2169
// 채점 번호	 아이디	     문제 번호	   결과  	메모리	시간	언어	       코드 길이
//21780202	sangok1993	2169	맞았습니다!!	17748	168	C++14 / 수정	770

#include <stdio.h>
#include <algorithm>

#define INF -987654321
using namespace std;

int N, M, map[1000][1000], dp[1000][1000][3];
bool visited[1000][1000];

int DFS(int n, int m, int d){
    if(!(0<=n && n<N && 0<=m && m<M)) return INF;
    if(n==N-1 and m==M-1) return map[n][m];
    if(visited[n][m]) return INF;
    int& def = dp[n][m][d];
    if(def!=INF) return def;
    visited[n][m]=true;
    def=map[n][m] + max(max(DFS(n, m-1,0),DFS(n, m+1,1)),DFS(n+1,m,2));
    visited[n][m]=false;
    return def;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            scanf("%d",map[i]+j);
            for(int k=0;k<3;k++)
                dp[i][j][k]=INF;
        }
    printf("%d", DFS(0,0,0));
    
    return 0;
}
