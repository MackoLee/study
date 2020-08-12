//https://www.acmicpc.net/problem/2225
//채점 번호    	아이디	    문제 번호	결과	    메모리	시간	  언어      	코드 길이
//21623198	sangok1993	2225	맞았습니다!!	1152	12	C++14 / 수정	398

#include <stdio.h>

using namespace std;

int main(){
    int N, K, dp[201][201] = {0,};
    scanf("%d%d",&N,&K);
    for(int i=0; i<=N; i++)
        dp[0][i] = 1;
    for(int i=1; i<K; i++)
        for(int j=0; j<=N; j++)
            for(int k=0; k<=N; k++)
                if(j+k<=N)
                    dp[i][j+k]=(dp[i][j+k]+dp[i-1][j])%1000000000;
    printf("%d",dp[K-1][N]);
    return 0;
}
