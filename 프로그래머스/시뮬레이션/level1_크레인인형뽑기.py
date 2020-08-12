# 테스트 1 〉	통과 (0.05ms, 10.7MB)
# 테스트 2 〉	통과 (0.05ms, 10.8MB)
# 테스트 3 〉	통과 (0.05ms, 10.7MB)
# 테스트 4 〉	통과 (1.68ms, 10.8MB)
# 테스트 5 〉	통과 (0.05ms, 10.7MB)
# 테스트 6 〉	통과 (0.05ms, 10.7MB)
# 테스트 7 〉	통과 (0.12ms, 10.9MB)
# 테스트 8 〉	통과 (0.40ms, 10.8MB)
# 테스트 9 〉	통과 (0.40ms, 10.9MB)
# 테스트 10 〉	통과 (0.45ms, 10.8MB)
# 테스트 11 〉	통과 (1.01ms, 10.8MB)

# 정확성: 100.0
# 합계: 100.0 / 100.0
def solution(board, moves):
    answer = 0
    N = len(board)
    stack = [0]
    for move in moves:
        for i in range(N):
            dol = board[i][move-1]
            board[i][move-1] = 0
            if dol != 0:
                if stack[-1] == dol:
                    answer+=2
                    del stack[-1]
                else:
                    stack.append(dol)
                break
    return answer
