//https://www.acmicpc.net/problem/1475
//채점 번호	      아이디	   문제 번호	결과  	메모리	시간	언어	     코드 길이
//20621620	sangok1993	1475	맞았습니다!!	1984	0	C++14 / 수정	447

#include <iostream>
using namespace std;

#define max(a,b) a>b ? a:b

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string room;
    int number[10] ={0,};
    
    cin>>room;

    for(char i:room)
        number[i-'0']++;

    number[6] = (number[6]+number[9]+1)/2; //69를 하나로 침.
    number[9]=0;

    for(int i:number)
        number[0]=max(number[0], i);

    cout<<number[0]<<endl;
    return 0;
}
