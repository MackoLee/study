//https://www.acmicpc.net/problem/1967
//채점 번호   	아이디   	문제 번호	 결과	    메모리	 시간	 언어	      코드 길이
//21465026	sangok1993	1967	맞았습니다!!	2292	376	C++14 / 수정	804

//현재소스 문제점 : 모든 reef에 대해서 가장긴 길이를 찾는다.
//다음에 착안할 것으로 : root에서 가장 멀리 있는 reef에서의 가장 긴 길이만 찾으면됨.

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_V 300
using namespace std;

vector<vector<pair<int,int>>> n2n;

int go_trip(int pre, int r){
    int answer =0;
    for(auto next : n2n[r])
        if(pre != next.second)
            answer = max(answer, next.first + go_trip(r, next.second));
    return answer;
}
int main(){
    set<int> reef;
    int N, node1, node2, cost,answer=0;
    scanf("%d", &N);
    n2n.resize(N+1);
    for(int i=1; i<=N; i++)
        reef.insert(i);
    while(scanf("%d%d%d", &node1,&node2, &cost)!=EOF){
        n2n[node1].push_back({cost, node2});
        n2n[node2].push_back({cost, node1});
        reef.erase(node1);
    }
    for(int r : reef)
        answer=max(answer, go_trip(0, r));
    
    printf("%d", answer);
    return 0;
}
