// https://www.acmicpc.net/problem/3006
//채점 번호      아이디	  문제 번호	  결과	   메모리	시간	언어	     코드 길이
//21771072	sangok1993	3006	맞았습니다!!	1892	32	C++14 / 수정	933

#include <stdio.h>
#include <string.h>
using namespace std;

int Tree[100001], idx[100001], N;
void update(int index, int value){
    while(index <= N){
        Tree[index]+=value;
        index+=(index&-index);
    }
}
int sum(int index){
    int answer=0;
    index--;
    while(index>0){
        answer+=Tree[index];
        index-=(index&-index);
    }
    return answer;
}
int sum(int a, int b){
    return sum(b)-sum(a);
}
int main(){
    scanf("%d",&N);
    memset(Tree, 0, N+1);
    memset(idx, 0, N+1);
    for(int i=1; i<=N; i++){
        scanf("%d",idx);
        idx[idx[0]] = i;
        update(i, 1);
    }
    int index;
    for(int i=0; i<N; i++){
        if(i%2){
            index = idx[N-i/2];
            printf("%d\n", sum(index+1,N+1)); //sum[index+1~N+1)
        }
        else{
            index = idx[1+i/2];
            printf("%d\n", sum(1,index)); //sum[1~ index)
        }
        update(index, -1);
    }
}
