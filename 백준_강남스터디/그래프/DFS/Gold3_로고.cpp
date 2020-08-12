//https://www.acmicpc.net/problem/3108
//채점 번호	     아이디  	문제 번호	  결과	  메모리	시간	언어	     코드 길이
//21655050	sangok1993	3108	맞았습니다!!	1128	4	C++14 / 수정	931

#include <stdio.h>

using namespace std;
int N, point[1001][4], answer=-1;
bool visited[1001];

bool check(int a,int b){
    int *r1=point[a], *r2=point[b];
    if((r1[2]<r2[0] or r2[2]<r1[0] or r1[3]<r2[1] or r2[3]<r1[1]) or ((r1[0]>r2[0] and r1[2]<r2[2] and r1[1]>r2[1] and r1[3]<r2[3]) or (r2[0]>r1[0] and r2[2]<r1[2] and r2[1]>r1[1] and r2[3]<r1[3])))
        return false; //직사각형이 안에 있는경우
    return true;
}
void DFS(int p){
    if(visited[p]) return;
    visited[p] = true;
    for(int i=1; i<=N; i++)
        if(check(i, p)) //서로 곂치면
            DFS(i);
}
int main(){
    scanf("%d",&N);
    for(int i=0; i<4; i++)
        point[0][i]=0;
    for(int i=1;i<=N; i++)
        scanf("%d%d%d%d",point[i],point[i]+1,point[i]+2,point[i]+3);
    
    for(int i=0; i<=N; i++){
        if(!visited[i]){
            answer++;
            DFS(i);
        }
    }
    printf("%d",answer);
    return 0;
}
