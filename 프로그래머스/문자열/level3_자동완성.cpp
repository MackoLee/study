#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define words_ad words.begin(),words.end()
using namespace std;

int answer=0;
void print(vector<string> a){
    for(string i:a)
        cout<<i<<'\n';
}
string get_next_word(string word){
    char c=word[word.size()-1];
    c++;
    return word.substr(0,word.size()-1)+c;
}
void DFS(vector<string>::iterator b,vector<string>::iterator e, int idx){
    int cnt=0;
    idx++;
    auto it=b;
    for(;it!=e;it++,cnt++){
        if(it->size()==idx){
            b++;
            answer+=idx;
        }
    }
    if(cnt==1 and b!=e) answer+=idx;
    else if(cnt>1){
        while(b!=e){
            auto lower=lower_bound(b,e,b->substr(0,idx+1)),
                 upper=lower_bound(b,e,get_next_word(b->substr(0,idx+1)));
            DFS(lower,upper,idx);
            b=upper;
        }
    }
}
int solution(vector<string> words) {
    sort(words_ad);
    vector<string>::iterator it=words.begin();
    while(it!=words.end()){
        auto lower=lower_bound(words_ad,it->substr(0,1)), 
             upper=lower_bound(words_ad,get_next_word(it->substr(0,1)));
    
        DFS(lower,upper,0);
        it=upper;
    }
    return answer;
}
