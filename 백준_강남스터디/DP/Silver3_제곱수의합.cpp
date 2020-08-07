//https://www.acmicpc.net/problem/1699
//채점 번호	      아이디	  문제 번호	  결과	   메모리	시간	언어	     코드 길이
//20869223	sangok1993	1699	맞았습니다!!	2256	32	C++14 / 수정	299

#include <iostream>

#define MAX_NUM 100001
using namespace std;

int main(){
    int n, dp[100001]={0,};

    cin>>n;

    dp[0]=-MAX_NUM;
    for(int i=1; i<=n; i++)
        for(int j=1; j*j<=i; j++)
            dp[i] = min(dp[i], dp[i-(j*j)]+1);

    cout<<dp[n]+MAX_NUM<<endl;
    return 0;
}


