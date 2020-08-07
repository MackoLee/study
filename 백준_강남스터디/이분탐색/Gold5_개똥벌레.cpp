//https://www.acmicpc.net/problem/3020
//채점 번호      	아이디  	문제 번호  	결과   	메모리	시간	언어	      코드 길이
//21011283	sangok1993	3020	맞았습니다!!	2644	56	C++14 / 수정	770

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_NUM 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N,H, result, min_result=MAX_NUM, cnt=0;
    
    cin>>N>>H;
    N/=2;
    
    int top[100000], bottom[100000];
    for(int i=0;i<N;i++)
        cin>>bottom[i]>>top[i];
    
    sort(top,top+N);
    sort(bottom,bottom+N);

    for(int i=0;i<H;i++){
        result = N-(int)(lower_bound(top, top+N,H-i)-top) +
                    N-(int)(lower_bound(bottom,bottom+N,1+i)-bottom);
        if(result==min_result) cnt++;
        else if(result<min_result){
            min_result=result;
            cnt=1;
        }
    }
    cout<<min_result<<" "<<cnt<<endl;
    return 0;
}
