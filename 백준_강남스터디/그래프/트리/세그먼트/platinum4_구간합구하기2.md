https://www.acmicpc.net/problem/10999   
채점 번호	아이디	문제 번호	결과	메모리	시간	언어	코드 길이	   
23001109	sangok1993	10999	맞았습니다!!	34752	148	C++14 / 수정	1556
```c++
#include <iostream>
#include <algorithm>

#define tree_size (1<<20)

struct Node{
    int S=0, area=1,M;
    Node(int i){
        for(;i<tree_size;i*=2)area*=2;
        S=i-tree_size;
        M=S+area/2;
    }
};
using namespace std;
int a,b,c,N,M,K;
long seg[tree_size*2]={0},d,lazy[tree_size*2]={0};

void lazy_update_pnt(int i, long c){
    lazy[i]+=c;
    Node node(i);
    for(i/=2;i;i/=2) seg[i]+=c*node.area;
}
void lazy_update(int a,int b,long c){
    a+=tree_size;
    b+=tree_size;
    for(;a<=b;a/=2,b/=2){
        if(a&1) lazy_update_pnt(a++,c);
        if(~b&1) lazy_update_pnt(b--,c);
    }
}
long lazy_get_seg(int a, int b, int i){
    Node node(i);
    if(a==node.S and b==node.S+node.area-1) return seg[i]+lazy[i]*node.area;
    if(lazy[i]){
        lazy[i*2]+=lazy[i];
        lazy[i*2+1]+=lazy[i];
        seg[i]+=lazy[i]*node.area;
        lazy[i]=0;
    }
    if(b<node.M) return lazy_get_seg(a,b,i*2);
    else if(node.M<=a) return lazy_get_seg(a,b,i*2+1);
    else return lazy_get_seg(a,node.M-1,i*2)+lazy_get_seg(node.M,b,i*2+1);
}
void make_seg(){
    for(int i=0;i<N;i++) cin>>seg[tree_size+i];
    for(int i=tree_size-1;i>0;i--) seg[i]=seg[i*2]+seg[i*2+1];
}
int main(){
    cin.tie(NULL);ios::sync_with_stdio(false);
    cin>>N>>M>>K;
    make_seg();
    for(;M or K;){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            M--;
            lazy_update(b-1,c-1,d);
        }
        else{
            cin>>b>>c;
            K--;
            cout<<lazy_get_seg(b-1,c-1,1)<<'\n';
        }
    }
    return 0;
}

```
