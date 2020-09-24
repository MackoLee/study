https://www.acmicpc.net/problem/2912   
22758557	sangok1993	2912	맞았습니다!!	4632	132	C++14 / 수정	

# 절반 이상 존재한다면 A-B까지 아무 원소나 뽑았을때 그 원소가 절반이상 존재할 확률은 1/2 보다 크다.   
# 그렇게에 아무 원소나 뽑아서 20번 정도만 반복해도 20번 연속으로 정답이 아닌 경우를 고를확률은 1/2^20=1/1000000 보다도 낮다.,
# 즉, 99.9999999 확률로 정답이다.   

``` c++
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

pair<int,int> nanjang[300000];
int C,N,M,A,B,c,arr[300001],r=0;

int main(){
    scanf("%d%d",&N,&C);
    
    for(int i=0;i<N;i++){
        scanf("%d",arr+i+1);
        nanjang[i]={arr[i+1],i+1};
    }
    sort(nanjang,nanjang+N);
    for(scanf("%d",&M);M--;){ //O(M*C*logN)
        scanf("%d%d",&A,&B);
        pair<int,int> lower,upper;
        int i=21;
        for(;--i;){
            r=rand()%(B-A+1);
            c=arr[A+r];
            lower={c,A};upper={c,B};
            if((B-A+1)/2 < (int)((upper_bound(nanjang,nanjang+N,upper)-lower_bound(nanjang,nanjang+N,lower)))) break;
        }
        if(i) printf("yes %d\n",c);
        else puts("no");
    }
    
    return 0;
}
```
