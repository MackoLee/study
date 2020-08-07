//https://www.acmicpc.net/problem/2156
//채점 번호	     아이디	  문제 번호 	결과	 메모리	시간	언어	     코드 길이
//20762709	sangok1993	2156	맞았습니다!!	1984	0	C++14 / 수정	448

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,dp[10001]={0,},w[10001]={0,};
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>w[i];

    dp[1]=w[1];
    dp[2]=w[1]+w[2];
    dp[3]=max(w[1], w[2])+w[3];
    
    for(int i=4;i<=n;i++)
        dp[i] = w[i]+max(w[i-1]+max(dp[i-3], dp[i-4]), dp[i-2]);

    cout<<max(dp[n-1],dp[n])<<endl;
    
    return 0;
}
