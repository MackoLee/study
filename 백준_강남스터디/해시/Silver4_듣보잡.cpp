//https://www.acmicpc.net/problem/1764
//채점 번호    	아이디    	문제 번호	 결과	     메모리	시간	언어	     코드 길이
//20511037	sangok1993	1764	맞았습니다!!	7408	384	C++14 / 수정	614

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    set<string> not_listen;
    vector<string> result;
    string temp;
    int N, M;
    cin>>N>>M; //입력
    for(int i = 0; i<N; i++){
        cin>>temp;
        not_listen.insert(temp);
    }
    for(int i = 0; i<M; i++){
        cin>>temp;
        if(not_listen.erase(temp))
            result.push_back(temp);
    }

    cout<<result.size()<<endl;
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
    return 0;
}
