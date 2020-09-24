# A배열과 B배열을 합친 배열 C에서 문자가 절반이상이 있기 위해서는 반드시 A나 B배열에는 절반이상 존재해야 한다.   
# ex) C=[1,1,2,2,2] 라는 배열이 존재한다고 생각해보자 어떻게 자르든 반드시 2가 절반이상 존재하는 배열이 존재한다.   
# 위 개념을 이용해서 세그먼트 트리를 활용해서 O(m*logn*logn)으로 문제를 해결 할 수 있다.   

``` c++
#include <stdio.h>
#include <algorithm>
#include <vector>

#define size (2<<19)
using namespace std;

pair<int,int> nanjang[300000];
int C,N,M,A,B,c,seg[size*2]={0,},r=0;

int cmp_seg(int A, int area, int c1, int c2){
    if(area/2<(int)((upper_bound(nanjang,nanjang+N,make_pair(c1,A+area))-lower_bound(nanjang,nanjang+N,make_pair(c1,A+1)))))
        return c1;
    if(area/2<(int)((upper_bound(nanjang,nanjang+N,make_pair(c2,A+area))-lower_bound(nanjang,nanjang+N,make_pair(c2,A+1)))))
        return c2;
    return 0;
}
int get_seg(int a, int b){
    int A=a,area=b-a+1;
    a+=size;
    b+=size;
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            int temp=cmp_seg(A,area,seg[a++],0);
            if(temp) return temp;
        }
        if(~b&1){
            int temp=cmp_seg(A,area,seg[b--],0);
            if(temp) return temp;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%d",seg+i+size);
        nanjang[i]={seg[i+size],i+1};
    }
    sort(nanjang,nanjang+N);
    for(int i=size-1;i>0;i--){
        int A=i,area=1;
        for(;A<size;A*=2) area*=2;
        A-=size;
        seg[i]=cmp_seg(A,area,seg[i*2],seg[i*2+1]);
    }
    for(scanf("%d",&M);M--;){
        scanf("%d%d",&A,&B);
        c = get_seg(A-1,B-1);
        if(c) printf("yes %d\n",c);
        else puts("no");
    }
    return 0;
}
```
