https://www.acmicpc.net/problem/9345   

채점 번호	아이디	문제 번호	결과	             메모리   시간     	언어	  코드 길이	   
23450824	sangok1993	9345	맞았습니다!!	3356	160	C++14 / 수정	2090   
```c++
#include <stdio.h>
#include <algorithm>

#define tree_size (1<<17)

using namespace std;

int T,N,K,Q,A,B, seg_max[tree_size*2],seg_min[tree_size*2],c;
char answer[200001];
int read_Int(){
    char c=getc(stdin);
    int answer=0;
    while('0'<=c and c<='9'){
        answer*=10;
        answer+=c-'0';
        c=getc(stdin);
    }
    return answer;
}
void update_seg(int a, int b){
    a+=tree_size, b+=tree_size;
    int temp_a=seg_min[a], temp_b=seg_min[b];

    seg_min[a]=temp_b;
    seg_min[b]=temp_a;
    seg_max[a]=temp_b;
    seg_max[b]=temp_a;
    a/=2;b/=2;
    for(;a>0;a/=2,b/=2){
        seg_min[a] = min(seg_min[a*2],seg_min[a*2+1]);
        seg_max[a] = max(seg_max[a*2],seg_max[a*2+1]);
        seg_min[b] = min(seg_min[b*2],seg_min[b*2+1]);
        seg_max[b] = max(seg_max[b*2],seg_max[b*2+1]);
    }
}
bool get_dvds(int a,int b){
    int min_p=a, max_p=b;
    a+=tree_size,b+=tree_size;
    int min_n=seg_min[a],max_n=seg_max[a];
    for(;a<=b;a/=2,b/=2){
        if(a&1){
            max_n=max(max_n,seg_max[a]);
            min_n=min(min_n,seg_min[a++]);
        }
        if(~b&1){
            max_n=max(max_n,seg_max[b]);
            min_n=min(min_n,seg_min[b--]);
        }
    }
    return min_p==min_n and max_p==max_n;
}
int main(){
    for(T=read_Int();T--;){
        N=read_Int(),K=read_Int();
        c=0;
        for(int i=0;i<N;i++){
            seg_max[tree_size+i]=i;
            seg_min[tree_size+i]=i;
        }
        for(int i=tree_size-1;i>0;i--){
            seg_min[i]=min(seg_min[2*i],seg_min[2*i+1]);
            seg_max[i]=max(seg_max[2*i],seg_max[2*i+1]);
        }

        while(K--){
            Q=read_Int(),A=read_Int(),B=read_Int();
            if(Q){
                if(get_dvds(A,B)){
                    answer[c++]='Y';answer[c++]='E';answer[c++]='S';answer[c++]='\n';
                }
                else{
                    answer[c++]='N';answer[c++]='O';answer[c++]='\n';
                }
            }
            else update_seg(A, B);
        }
        answer[c]='\0';
        printf("%s",answer);
    }
    return 0;
}

```
