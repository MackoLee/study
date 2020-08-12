# https://programmers.co.kr/learn/courses/30/lessons/42862?language=python3
# 정확성  테스트
# 테스트 1 〉	통과 (0.05ms, 10.9MB)
# 테스트 2 〉	통과 (0.05ms, 10.8MB)
# 테스트 3 〉	통과 (0.05ms, 10.8MB)
# 테스트 4 〉	통과 (0.05ms, 10.8MB)
# 테스트 5 〉	통과 (0.09ms, 10.8MB)
# 테스트 6 〉	통과 (0.05ms, 10.8MB)
# 테스트 7 〉	통과 (0.08ms, 10.8MB)
# 테스트 8 〉	통과 (0.04ms, 10.7MB)
# 테스트 9 〉	통과 (0.05ms, 10.8MB)
# 테스트 10 〉	통과 (0.06ms, 10.8MB)
# 테스트 11 〉	통과 (0.05ms, 10.8MB)
# 테스트 12 〉	통과 (0.04ms, 10.9MB)
# 채점 결과
# 정확성: 100.0
# 합계: 100.0 / 100.0
def solution(n, l, r):
    answer = 0
    l.sort()
    r.sort()
    
    for i in range(1,n+1):
        re =1
        if l[:1] == [i] :
            if (r[:1] == [i+1] or r[:1] == [i]) and not(r[:1] == l[1:2] ):
                r = r[1:]
            else:
                re = 0
            l = l[1:]
        elif r[:1] == [i]:
            if l[:1] == [i+1] and not(l[:1] == r[1:2] ):
                l = l[1:]
            r = r[1:]
        # 1, 2, 4   2, 3, 5
        answer += re
    
    return answer
