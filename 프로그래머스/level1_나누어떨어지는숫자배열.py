# https://programmers.co.kr/learn/courses/30/lessons/12910?language=python3
# 정확성  테스트
# 테스트 1 〉	통과 (0.07ms, 10.9MB)
# 테스트 2 〉	통과 (0.06ms, 10.7MB)
# 테스트 3 〉	통과 (0.09ms, 10.7MB)
# 테스트 4 〉	통과 (0.09ms, 10.8MB)
# 테스트 5 〉	통과 (0.05ms, 10.7MB)
# 테스트 6 〉	통과 (17.54ms, 66.8MB)
# 테스트 7 〉	통과 (0.66ms, 11.2MB)
# 테스트 8 〉	통과 (0.04ms, 10.8MB)
# 테스트 9 〉	통과 (0.45ms, 11.1MB)
# 테스트 10 〉	통과 (0.29ms, 10.9MB)
# 테스트 11 〉	통과 (0.16ms, 10.9MB)
# 테스트 12 〉	통과 (0.17ms, 10.8MB)
# 테스트 13 〉	통과 (0.97ms, 11.4MB)
# 테스트 14 〉	통과 (0.43ms, 11.1MB)
# 테스트 15 〉	통과 (0.37ms, 11.1MB)
# 테스트 16 〉	통과 (0.13ms, 10.7MB)
# 채점 결과
# 정확성: 100.0
합계: 100.0 / 100.0
    
def solution(arr, divisor):
    answer = [i for i in sorted(arr) if not i%divisor]
    return answer if len(answer) else [-1]
