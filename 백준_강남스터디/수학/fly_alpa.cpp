// https://www.acmicpc.net/problem/1011
// 채점 번호	    아이디	    문제 번호	  결과  메모리	시간	   언어	     코드 길이
// 21962011	sangok1993	1011	맞았습니다!!	1112	4	C++14 / 수정	293

#include <stdio.h>

int main(){
    int T,x,y,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        y-=x;
        long long sum=0;
        for(i=0;;i++){
            sum+=(i/2)+1;
            if(sum>=y) break;
        }
        printf("%d\n",i+1);
    }
    return 0;
}


