https://www.acmicpc.net/problem/1275   
채점 번호	아이디	문제 번호	결과	메모리	시간	언어	코드 길이    
23003655	sangok1993	1275	맞았습니다!!	4032	96	C++14 / 수정	845
```c++
#include <iostream>
#include <algorithm>

#define tree_size (1<<17)
using namespace std;
int a,b,c,d,N,Q;
long seg[tree_size*2]={0};
void make_seg(){
    for(int i=0;i<N;i++) cin>>seg[tree_size+i];
    for(int i=tree_size-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
}
void update_seg(int idx, int value){
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
    cin>>N>>Q;
    make_seg();
    for(;Q--;){
        cin>>a>>b>>c>>d;
        cout<<get_seg(min(a-1,b-1),max(a-1,b-1))<<'\n';
        update_seg(c-1, d);
    }
    return 0;
}
```
