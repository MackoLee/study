#include <algorithm>
#include <string>
#include <vector>

#define INF 987654321
using namespace std;

int solution(vector<string> strs, string t)
{
    vector<int> dp(t.size()+1,INF);
    sort(strs.begin(),strs.end());
    dp[0]=0;
    for(int i=1;i<=t.size();i++)
        for(int len=1;len<6;len++)
            if(i-len>-1 and 
              *lower_bound(strs.begin(),strs.end(),t.substr(i-len,len))==t.substr(i-len,len))
                dp[i]=min(dp[i],dp[i-len]+1);
    return dp[t.size()]==INF?-1:dp[t.size()];
}
