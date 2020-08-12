# https://programmers.co.kr/learn/courses/30/lessons/12926?language=python3
# 확성  테스트
# 테스트 1 〉	통과 (0.07ms, 10.7MB)
# 테스트 2 〉	통과 (0.05ms, 10.7MB)
# 테스트 3 〉	통과 (0.06ms, 10.7MB)
# 테스트 4 〉	통과 (0.04ms, 10.7MB)
# 테스트 5 〉	통과 (0.07ms, 10.7MB)
# 테스트 6 〉	통과 (0.08ms, 10.8MB)
# 테스트 7 〉	통과 (0.06ms, 10.7MB)
# 테스트 8 〉	통과 (0.05ms, 10.8MB)
# 테스트 9 〉	통과 (0.07ms, 10.8MB)
# 테스트 10 〉	통과 (0.05ms, 10.7MB)
# 테스트 11 〉	통과 (0.11ms, 10.6MB)
# 테스트 12 〉	통과 (0.08ms, 10.7MB)
# 테스트 13 〉	통과 (6.45ms, 10.8MB)
# 채점 결과
# 정확성: 100.0
# 합계: 100.0 / 100.0
    
lower = [chr(ord('a')+i) for i in range(26) ]
upper = [chr(ord('A')+i) for i in range(26) ]
def solution(s, n):
    return ''.join(list(map( lambda x: secret(x,n) , s)))

def secret(x, n):
    if x in lower:
        return lower[((lower.index(x)+n)%26)]
    if x in upper:
        return upper[((upper.index(x)+n)%26)]
    return x
