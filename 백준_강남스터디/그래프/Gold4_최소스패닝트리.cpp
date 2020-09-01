// https://www.acmicpc.net/problem/1197
//채점 번호     	아이디	    문제 번호	결과	  메모리	시간	  언어	      코드 길이
//22204793	sangok1993	1197	맞았습니다!!	2400	48	C++14 / 수정	750

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pnt;
vector<pair<int, pair<int,int>>> lines;

int get_pnt(int a){
    return pnt[a]==-1?a:pnt[a]=get_pnt(pnt[a]);
}
bool up_pnt(int a, int b){
    int p_a=get_pnt(a), p_b=get_pnt(b);
    if(p_a!=p_b){
        pnt[p_a]=p_b;
        return 1;
    }
    return 0;
}

int main(){
    int V,E,A,B,C,sum=0;

    scanf("%d%d",&V,&E);
    pnt.resize(V+1,-1);
    lines.resize(E);
    for(int i=0; i<E; i++){
        scanf("%d%d%d",&A,&B,&C);
        lines[i]={C,{A,B}};
    }
    sort(lines.begin(), lines.end());

    for(auto line:lines)
        if(up_pnt(line.second.first,line.second.second))
            sum+=line.first;

    printf("%d",sum);
    return 0;
}
