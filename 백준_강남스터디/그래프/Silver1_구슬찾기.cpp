//acmicpc.net/problem/2617
//채점 번호	      아이디  	문제 번호	 결과  	  메모리	시간	언어	     코드 길이
//20420858	sangok1993	2617	맞았습니다!!	1988	0	C++14 / 수정	1130

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> hvy_than;
vector<vector<int>> lit_than;
vector<bool> visited;
int cnt;

void hvy_all(int i){
    for(int hvy : hvy_than[i]){
        if(!visited[hvy]){
            visited[hvy] = true;
            cnt++;
            hvy_all(hvy);
        }
    }
}
void lit_all(int i){
    for(int lit : lit_than[i]){
        if(!visited[lit]){
            visited[lit] = true;
            cnt++;
            lit_all(lit);
        }
    }
}

int main(int argc, const char * argv[]){
    int M, N;
    int hvy, lit;
    cin>>M>>N;
    
    hvy_than.resize(M+1);
    lit_than.resize(M+1);

    for(int i=0; i<N; i++){
        cin>>hvy>>lit;
        hvy_than[lit].push_back(hvy);
        lit_than[hvy].push_back(lit);
    }
    
    int answer = 0;
    for(int i = 1; i<M+1; i++){
        visited.assign(M+1,false);
        cnt=0;
        hvy_all(i);
        if(cnt>(M/2)) answer++;
    }
    for(int i = 1; i<M+1; i++){
        visited.assign(M+1,false);
        cnt=0;
        lit_all(i);
        if(cnt>(M/2)) answer++;
    }
    cout<<answer<<endl;
    return 0;
}
