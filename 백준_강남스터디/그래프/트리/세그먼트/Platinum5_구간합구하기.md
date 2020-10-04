https://www.acmicpc.net/problem/2042   
채점 번호	아이디	문제 번호	결과	메모리	시간	언어	코드 길이	   
22982223	sangok1993	2042	맞았습니다!!	18368	148	C++14 / 수정	904
```c++
#include <iostream>

#define tree_size (1<<20)
using namespace std;
int a,b,N,M,K;
long seg[tree_size*2]={0},c;
void make_seg(){
    for(int i=0;i<N;i++) cin>>seg[tree_size+i];
    for(int i=tree_size-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
}
void update_seg(int idx, long value){
    idx+=tree_size;
    seg[idx]=value;
    for(idx/=2;idx;idx/=2) seg[idx]=seg[idx*2]+seg[idx*2+1];
}
long get_seg(int a, int b){
    long answer=0;
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1) answer+=seg[a++];
        if(~b&1) answer+=seg[b--];
    }
    return answer;
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M>>K;
    make_seg();
    for(;M or K;){
        cin>>a>>b>>c;
        if(a==1){
            M--;
            update_seg(b-1, c);
        }
        else{
            K--;
            cout<<get_seg(b-1,c-1)<<'\n';
        }
    }
    return 0;
}
```
