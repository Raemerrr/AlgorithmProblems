import sys

INF = 10000000
n = 0
m = 0
arr = []
dp = []

def proc():
    #dp 테이블 초기화
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i != j:
                if arr[i][j] > 0:
                    dp[i][j] = arr[i][j]
                else:
                    dp[i][j] = INF
    #계산식
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if dp[i][k] != INF and dp[k][j] != INF:
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j])

    idx = 0
    result = INF
    for i in range(1, len(dp)):
        if result > sum(dp[i]):
            idx = i
            result = sum(dp[i])
    #정답 출력
    print(idx)


if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().rstrip().split())
    arr = [[0 for x in range(n + 1)] for y in range(n + 1)]
    # 값 얕은 복사
    dp = arr[:]
    for i in range(m):
        num1, num2 = map(int, sys.stdin.readline().rstrip().split())
        arr[num1][num2] = 1
        arr[num2][num1] = 1
    proc()
