# https://programmers.co.kr/learn/courses/30/lessons/42840?language=python3

# 정확성  테스트
# 테스트 1 〉	통과 (0.05ms, 10.6MB)
# 테스트 2 〉	통과 (0.04ms, 10.7MB)
# 테스트 3 〉	통과 (0.04ms, 10.9MB)
# 테스트 4 〉	통과 (0.04ms, 10.8MB)
# 테스트 5 〉	통과 (0.05ms, 10.8MB)
# 테스트 6 〉	통과 (0.06ms, 10.9MB)
# 테스트 7 〉	통과 (1.57ms, 11.1MB)
# 테스트 8 〉	통과 (0.51ms, 11MB)
# 테스트 9 〉	통과 (2.87ms, 13.6MB)
# 테스트 10 〉	통과 (1.33ms, 11.1MB)
# 테스트 11 〉	통과 (2.98ms, 14.1MB)
# 테스트 12 〉	통과 (2.49ms, 13.3MB)
# 테스트 13 〉	통과 (0.19ms, 10.7MB)
# 테스트 14 〉	통과 (2.85ms, 14.5MB)
# 채점 결과
# 정확성: 100.0
# 합계: 100.0 / 100.0

def solution(answers):
    answer = []
    supo ={
        1 : [1,2,3,4,5],
        2 : [2,1,2,3,2,4,2,5],
        3 : [3,3,1,1,2,2,4,4,5,5]
    }
    ans=[0,0,0]
    for i in range(len(answers)):
        if answers[i] == supo[1][i%5]:
            ans[0]+=1
        if answers[i] == supo[2][i%8]:
            ans[1]+=1
        if answers[i] == supo[3][i%10]:
            ans[2]+=1
        
    if max(ans) == ans[0]:
        answer.append(1)
    if max(ans) == ans[1]:
        answer.append(2)
    if max(ans) == ans[2]:
        answer.append(3)
    return answer
