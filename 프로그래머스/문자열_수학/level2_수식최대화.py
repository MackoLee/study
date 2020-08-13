# 다음에 할때는 eval() 이라는 함수를 사용해 보자.
# eval('2*2') = 4


# https://programmers.co.kr/learn/courses/30/lessons/67257
# 정확성  테스트
# 테스트 1 〉	통과 (0.12ms, 11MB)
# 테스트 2 〉	통과 (0.12ms, 10.9MB)
# 테스트 3 〉	통과 (0.14ms, 10.9MB)
# 테스트 4 〉	통과 (0.15ms, 10.9MB)
# 테스트 5 〉	통과 (0.19ms, 10.9MB)
# 테스트 6 〉	통과 (0.18ms, 10.9MB)
# 테스트 7 〉	통과 (0.18ms, 10.9MB)
# 테스트 8 〉	통과 (0.21ms, 10.9MB)
# 테스트 9 〉	통과 (0.22ms, 10.9MB)
# 테스트 10 〉	통과 (0.24ms, 10.9MB)
# 테스트 11 〉	통과 (0.24ms, 10.9MB)
# 테스트 12 〉	통과 (0.29ms, 10.9MB)
# 테스트 13 〉	통과 (0.29ms, 10.9MB)
# 테스트 14 〉	통과 (0.31ms, 11MB)
# 테스트 15 〉	통과 (0.34ms, 10.9MB)
# 테스트 16 〉	통과 (0.13ms, 11MB)
# 테스트 17 〉	통과 (0.12ms, 10.9MB)
# 테스트 18 〉	통과 (0.13ms, 11MB)
# 테스트 19 〉	통과 (0.13ms, 10.9MB)
# 테스트 20 〉	통과 (0.14ms, 10.9MB)
# 테스트 21 〉	통과 (0.35ms, 10.9MB)
# 테스트 22 〉	통과 (0.31ms, 11MB)
# 테스트 23 〉	통과 (0.11ms, 10.9MB)
# 테스트 24 〉	통과 (0.35ms, 10.9MB)
# 테스트 25 〉	통과 (0.32ms, 10.9MB)
# 테스트 26 〉	통과 (0.12ms, 11MB)
# 테스트 27 〉	통과 (0.34ms, 10.9MB)
# 테스트 28 〉	통과 (0.33ms, 11MB)
# 테스트 29 〉	통과 (0.33ms, 10.9MB)
# 테스트 30 〉	통과 (0.34ms, 10.9MB)
# 채점 결과
# 정확성: 100.0
# 합계: 100.0 / 100.0

def cal3(ex):
    arr = []
    s=0
    for i,e in enumerate(ex):
        if e==op3:
            arr.append(ex[s:i])
            s=i+1
    arr.append(ex[s:])
    return cal(list(map(int, arr)), op3)
def cal2(ex):
    arr = []
    s=0
    for i,e in enumerate(ex):
        if e==op2:
            arr.append(ex[s:i])
            s=i+1
    arr.append(ex[s:])
    return cal(list(map(cal3, arr)), op2)
def cal1(ex):
    arr = []
    s=0
    for i,e in enumerate(ex):
        if e==op1:
            arr.append(ex[s:i])
            s=i+1
    arr.append(ex[s:])
    return cal(list(map(cal2, arr)), op1)
def cal(arr,op):
    if op=='*':
        re = 1
        for i in arr:
            re*=i
        return re
    if op=='+':
        return sum(arr)
    if op=='-':
        return arr[0] - sum(arr[1:])
def solution(expression):
    global op1, op2, op3
    max_num=0
    op1, op2, op3 = '*','+','-'
    max_num= max(max_num,abs(cal1(expression)))
    op1, op2, op3 = '*','-','+'
    max_num= max(max_num,abs(cal1(expression)))
    op1, op2, op3 = '+','*','-'
    max_num= max(max_num,abs(cal1(expression)))
    op1, op2, op3 = '+','-','*'
    max_num= max(max_num,abs(cal1(expression)))
    op1, op2, op3 = '-','+','*'
    max_num= max(max_num,abs(cal1(expression)))
    op1, op2, op3 = '-','*','+'
    max_num= max(max_num,abs(cal1(expression)))
    return max_num
