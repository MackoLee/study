# https://programmers.co.kr/learn/courses/30/lessons/42748?language=python3
# 정확성  테스트
# 테스트 1 〉	통과 (0.04ms, 10.7MB)
# 테스트 2 〉	통과 (0.05ms, 10.7MB)
# 테스트 3 〉	통과 (0.04ms, 10.6MB)
# 테스트 4 〉	통과 (0.04ms, 10.7MB)
# 테스트 5 〉	통과 (0.06ms, 10.7MB)
# 테스트 6 〉	통과 (0.04ms, 10.7MB)
# 테스트 7 〉	통과 (0.05ms, 10.7MB)
# 채점 결과
# 정확성: 100.0
# 합계: 100.0 / 100.0
    
def solution(array, commands):
    return [sorted(array[i-1:j])[k-1] for i,j,k in commands]
