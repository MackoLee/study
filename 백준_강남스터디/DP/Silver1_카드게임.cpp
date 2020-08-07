//https://www.acmicpc.net/problem/10835
//채점 번호	     아이디	  문제 번호	  결과	   메모리	시간	언어	     코드 길이
//20832851	sangok1993	10835	맞았습니다!!	17640	24	C++14 / 수정	584

#include <iostream>
#define max3(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
using namespace std;
int n, L[2001], R[2001], score[2001][2001]={0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=n; i>0; i--)
        cin>>L[i];
    for(int i=n; i>0; i--)
        cin>>R[i];
    
    for(int l=1; l<=n; l++){
        for(int r=1; r<=n; r++){
            if(L[l]>R[r]) score[l][r] = score[l][r-1]+R[r];
            score[l][r] = max3(score[l][r], score[l-1][r], score[l-1][r-1]);
        }
    }
    cout<<score[n][n]<<endl;
    return 0;
}
