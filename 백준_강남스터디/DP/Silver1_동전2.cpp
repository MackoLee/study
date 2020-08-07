//https://www.acmicpc.net/problem/2294
//채점 번호	     아이디	  문제 번호	  결과	  메모리	시간	언어      	코드 길이
//20738188	sangok1993	2294	맞았습니다!!	1984	0	C++14 / 수정	717

#include <iostream>
#include <vector>
#include <algorithm>
#define min(a,b) a<b?a:b
#define MAX_VALUE 100001

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k,dp[10001],min_value;

    cin>>n>>k;
    vector<int> coin(n,MAX_VALUE);
    
    for(int i=0;i<n;i++)
        cin>>coin[i];
    sort(coin.begin(), coin.end());
    unique(coin.begin(), coin.end());

    dp[0]=0;
    for(int i=1;i<=k;i++){
        min_value=MAX_VALUE;
        for(int j:coin){
            if(i<j) break;
            min_value=min(min_value, dp[i-j]);
        }
        dp[i] = min_value+1;
    }

    if(dp[k]>=MAX_VALUE) cout<<-1<<endl;
    else cout<<dp[k]<<endl;
    return 0;
}
