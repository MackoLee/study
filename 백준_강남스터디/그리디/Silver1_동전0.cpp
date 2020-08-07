//https://www.acmicpc.net/problem/11047
//채점 번호      	아이디	   문제 번호	결과	 메모리	시간	언어	     코드 길이
//20869779	sangok1993	11047	맞았습니다!!	1984	0	C++14 / 수정	365

#include <iostream>

using namespace std;

int answer=0, money;

void dfs(int n){
    int A;
    cin>>A;
    if(n>1) dfs(n-1);

    if(money>=A){
        answer += money/A;
        money %= A;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n>>money;
    dfs(n);
    cout<<answer<<endl;
    return 0;
}


