// https://www.acmicpc.net/problem/1197
// 채점 번호	아이디	문제 번호	결과	메모리	시간	언어	코드 길이	제출한 시간
// 22000401	sangok1993	1197	맞았습니다!!	5668	64	C++14 / 수정	950

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> n2n;
int V, E, a, b, c, e;

int spening(){
    int sum=0;
    vector<bool> visited(V+1,false);
    vector<pair<int,int>> heap;
    heap.push_back({0,1});
    while(!heap.empty()){
        int cost=-heap.front().first, p= heap.front().second;
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        if(visited[p]) continue;
        visited[p]=true;
        sum+=cost;
        for(auto next : n2n[p]){
            if(visited[next.second]) continue;
            heap.push_back({-next.first, next.second});
            push_heap(heap.begin(), heap.end());
        }
    }
    return sum;
}
int main(){
    scanf("%d%d",&V, &E);
    n2n.resize(V+1);
    while(E--){
        scanf("%d%d%d",&a,&b,&c);
        n2n[a].push_back({c,b});
        n2n[b].push_back({c,a});
    }
    printf("%d", spening());
    
    return 0;
}

