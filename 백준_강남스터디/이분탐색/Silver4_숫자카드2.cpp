//https://www.acmicpc.net/problem/10816
//채점 번호	   아이디	   문제 번호	 결     과	메모리	시간	언어     	코드 길이
//20521512	sangok1993	10816	맞았습니다!!	3940	328	C++14 / 수정	560

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    int a;
    cin>>N;
    vector<int> card(N,0);
    for(int i =0; i<N; i++){
        cin>>a;
        card[i] = a;
    }
    sort(card.begin(),card.end());
    cin>>M;
    for(int i =0; i<M; i++){
        cin>>a;
        cout<<upper_bound(card.begin(),card.end(),a)-
                lower_bound(card.begin(),card.end(),a)<<' ';
    }
    cout<<endl;
    return 0;
        
}
