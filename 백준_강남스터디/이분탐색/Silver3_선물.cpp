//https://www.acmicpc.net/problem/1166
//채점 번호	      아이디	  문제 번호	결과	    메모리	시간	언어	    코드 길이
//21176155	sangok1993	1166	맞았습니다!!	1112	0	C++14 / 수정	544

#include <stdio.h>

using namespace std;

int N, L, W, H;
long long box_num(int a, double b){
    return (long long)(((double) a)/b);
}
int min(int a, int b, int c){
    return a<b?(a<c?a:c):(b<c?b:c);
}
double binary(){
    double l=0, h,m;
    h=(double) min(L,W,H);
    for(int i=0; i<60; i++){
        m = (l+h)/2.0;
        if(N>box_num(L,m)*box_num(W,m)*box_num(H,m))
            h=m;
        else
            l=m;
    }
    return l;
}
int main(){
    scanf("%d %d %d %d",&N, &L, &W, &H);
    printf("%.9lf\n",binary());
    return 0;
}
