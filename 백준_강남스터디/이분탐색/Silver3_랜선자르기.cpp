//https://www.acmicpc.net/problem/1654
//채점 번호	      아이디	   문제 번호	결과	  메모리	시간	언어	     코드길이
//21331401	sangok1993	1654	맞았습니다!!	1152	4	C++14 / 수정	460

#include <stdio.h>

using namespace std;

int N, K, line[10000];

bool check(int m){
    int num=0;
    for(int i=0; i<K; i++)
        num+=line[i]/m;
    return num<N;
}
int main(){
    scanf("%d %d", &K, &N);
    unsigned int l=1,m,h=1<<31;
    
    for(int i=0; i<K; i++)
        scanf("%d",line+i);

    while(l+1!=h){
        m=(h+l)/2;
        if(check(m))
            h=m;
        else
            l=m;
    }
    printf("%d\n", l);
    
    return 0;
}
