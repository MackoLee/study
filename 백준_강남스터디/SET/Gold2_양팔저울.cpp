//https://www.acmicpc.net/problem/2629
//채점 번호     	아이디 	문제 번호	  결과	  메모리	시간	언어	    코드 길이
//21445954	sangok1993	2629	맞았습니다!!	1308	0	C++14 / 수정	621

#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int T, chu;
    set<int> measure;
    scanf("%d",&T);
    while(T--!=0){
        scanf("%d", &chu);
        set<int> temp;
        for(int m: measure){
            temp.insert(m+chu);
            temp.insert(abs(m-chu));
        }
        for(int t:temp)
            measure.insert(t);
        measure.insert(chu);
    }
    
    scanf("%d",&T);
    while(T--!=0){
        scanf("%d", &chu);
        if (measure.find(chu) != measure.end())
            printf("Y ");
        else
            printf("N ");
    }

    return 0;
}
