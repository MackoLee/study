# https://programmers.co.kr/learn/courses/30/lessons/42576?language=python3
# 정확성  테스트
# 테스트 1 〉	통과 (0.09ms, 10.7MB)
# 테스트 2 〉	통과 (0.08ms, 10.7MB)
# 테스트 3 〉	통과 (0.25ms, 10.8MB)
# 테스트 4 〉	통과 (0.43ms, 11.1MB)
# 테스트 5 〉	통과 (0.41ms, 11.1MB)
# 효율성  테스트
# 테스트 1 〉	통과 (25.27ms, 86.6MB)
# 테스트 2 〉	통과 (36.40ms, 127MB)
# 테스트 3 〉	통과 (43.75ms, 155MB)
# 테스트 4 〉	통과 (73.49ms, 168MB)
# 테스트 5 〉	통과 (62.60ms, 167MB)
# 채점 결과
# 정확성: 50.0
# 효율성: 50.0
# 합계: 100.0 / 100.0

import collections


def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]
