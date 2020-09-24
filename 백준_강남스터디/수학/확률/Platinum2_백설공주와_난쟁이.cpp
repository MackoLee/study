//https://www.acmicpc.net/problem/2912
//22758557	sangok1993	2912	맞았습니다!!	4632	132	C++14 / 수정	

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
