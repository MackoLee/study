https://www.acmicpc.net/problem/13925
```c++
#include <iostream>
#include <algorithm>

const int tree_size=1<<17,MOD=1e9+7;
using namespace std;

long long seg[tree_size*2]={0}, lazy1[tree_size*2]={0}, lazy2[tree_size*2], lazy3[tree_size*2];
int N,M;
long long get_sum(int i,int size){
    long long answer;
    if(lazy3[i]!=MOD) (answer=lazy3[i]*size)%=MOD;
    else answer=seg[i];
    (answer*=lazy2[i])%=MOD;
    (answer+=lazy1[i]*size)%=MOD;
    return answer;
}
void give_lazy(int i){
    if(lazy3[i]!=MOD){
        lazy1[i*2]=0;
        lazy1[i*2+1]=0;
        lazy2[i*2]=1;
        lazy2[i*2+1]=1;
        lazy3[i*2]=lazy3[i];
        lazy3[i*2+1]=lazy3[i];
        lazy3[i]=MOD;
    }
    if(lazy2[i]!=1){
        (lazy1[i*2]*=lazy2[i])%=MOD;
        (lazy1[i*2+1]*=lazy2[i])%=MOD;
        (lazy2[i*2]*=lazy2[i])%=MOD;
        (lazy2[i*2+1]*=lazy2[i])%=MOD;
        lazy2[i]=1;
    }
    if(lazy1[i]!=0){
        (lazy1[i*2]+=lazy1[i])%=MOD;
        (lazy1[i*2+1]+=lazy1[i])%=MOD;
        lazy1[i]=0;
    }
}
void query123(int i, int s, int size,int q, int x, int y,int v){
    if(s==x and s+size-1==y){
        if(q==1) (lazy1[i]+=v)%=MOD;
        else if(q==2){
            (lazy1[i]*=v)%=MOD;
            (lazy2[i]*=v)%=MOD;
        }
        else{
            lazy1[i]=0;
            lazy2[i]=1;
            lazy3[i]=v;
        }
        return;
    }
    give_lazy(i);
    size/=2;
    int m=s+size;
    if(x<m)query123(i*2,s,size,q,x,min(m-1,y),v);
    if(m<=y)query123(i*2+1,m,size,q,max(m,x),y,v);
    (seg[i]=get_sum(i*2,size)+get_sum(i*2+1,size))%=MOD;
}
long long query4(int i, int s, int size, int x, int y){
    if(s==x and s+size-1==y) return get_sum(i,size);
    give_lazy(i);
    long long answer=0;
    size/=2;
    int m=s+size;
    if(x<m) (answer+=query4(i*2,s,size,x,min(m-1,y)))%=MOD;
    if(m<=y) (answer+=query4(i*2+1,m,size,max(m,x),y))%=MOD;
    (seg[i]=get_sum(i*2,size)+get_sum(i*2+1,size))%=MOD;
    return answer;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int q,x,y,v;
    cin>>N;
    for(int i=0;i<N;i++) cin>>seg[tree_size+i];
    for(int i=0;i<tree_size;i++){
        lazy2[tree_size+i]=1;
        lazy3[tree_size+i]=MOD;
    }
    for(int i=tree_size-1;i>0;i--){
        (seg[i]=seg[i*2]+seg[i*2+1])%=MOD;
        lazy2[i]=1;
        lazy3[i]=MOD;
    }
    for(cin>>M;M--;){
        cin>>q>>x>>y;
        if(q==4) cout<<query4(1,0,tree_size,x-1,y-1)<<'\n';
        else{
            cin>>v;
            query123(1,0,tree_size,q,x-1,y-1,v);
        }
    }
    return 0;
}
```
