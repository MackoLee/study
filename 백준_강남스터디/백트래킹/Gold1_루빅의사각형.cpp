// https://www.acmicpc.net/problem/2549
//채점 번호     	아이디	문제 번호	결과        	메모리	시간	언어	            코드 길이
// 21864138	sangok1993	2549	맞았습니다!!	1112	268	C++14 / 수정	1891

#include <stdio.h>
#include <string>

using namespace std;

int puzzle[4][4], answer[4][4];

void set(){
    for(int i=0; i<16; i++)
        answer[i/4][i%4]=i+1;
}
int check(){
    int cnt=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(puzzle[i][j]==answer[i][j]) cnt++;
    return cnt;
}
void move(int rc, int i, int k){
    int temp;
    if(rc==2){
        while(k--){
            temp=answer[0][i-1];
            for(int j=0; j<3; j++)
                answer[j][i-1]=answer[j+1][i-1];
            answer[3][i-1]=temp;
        }
    }
    else{
        while(k--){
            temp=answer[i-1][0];
            for(int j=0; j<3; j++)
                answer[i-1][j]=answer[i-1][j+1];
            answer[i-1][3]=temp;
        }
    }
}
bool DFS(int N, int rc, int lines,int N_cnt){
    if(N==N_cnt) return false;
    if(N-N_cnt<4 and check()<4) return false;
    if(N-N_cnt<3 and check()<8) return false;
    if(N-N_cnt<2 and check()<12) return false;
    if(check()==16){
        printf("%d\n", N_cnt);
        return true;
    }
    for(int a=0;a<4;a++){
        if((lines>>a)%2){
            for(int m=1; m<4; m++){
                move(rc%2+1, a+1, m);
                if(DFS(N, rc, lines-(1<<a),N_cnt+1)){
                    printf("%d %d %d\n",rc%2+1, a+1, m);
                    return true;
                }
                move(rc%2+1, a+1, (4-m));
            }
        }
        for(int m=1; m<4; m++){
            move(rc, a+1, m);
            if(DFS(N, rc%2+1, 15, N_cnt+1)){
                printf("%d %d %d\n",rc, a+1, m);
                return true;
            }
            move(rc, a+1, 4-m);
        }
    }
    return false;
}
int main(){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d",puzzle[i]+j);
    for(int i=2; i<9; i++){
        set();
        if(DFS(i, 1, 15, 0)) return 0;
    }
    return 0;
}
