import sys

n = k = 0


def getPI(pattern):
    pi = [0 for x in range(len(pattern))]
    j = 0
    for i in range(1, len(pattern)):
        while j > 0 and pattern[i] != pattern[j]:
            j = pi[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j
    return pi


def KMP(s, pattern):
    pi = getPI(pattern)
    j = 0
    for i in range(len(s)):
        while j > 0 and s[i] != pattern[j]:
            j = pi[j - 1]
        if s[i] == pattern[j]:
            if j == len(pattern) - 1:
                return True
            else:
                j += 1
    return False


if __name__ == "__main__":
    n, k = map(int, sys.stdin.readline().rstrip().split())
    lsts = []
    for t in range(n):
        #입력은 받지만 사용하지 않음.
        cnt = int(input())
        lst = list(sys.stdin.readline().rstrip().split())
        lsts.append(lst)
    #가장 짧은 프로그램 코드를 기준으로 바이러스 코드 조합을 만든다.
    lsts.sort(key=lambda x: len(x))
    combi = []
    for i in range(len(lsts[0]) - k + 1):
        combi.append(lsts[0][i:i + k])
    #정답을 표출할 flag
    flag = False
    for c in combi:
        #역방향으로 바이러스 코드를 확인해 볼 프로그램 코드 목록
        reversedCheckList = []
        #정방향 탐색
        for l in lsts:
            if KMP("".join(l), "".join(c)) == False:
                #정방향 탐색 중 실패한 목록 저장
                reversedCheckList.append(l)

        #정방향 탐색으로 실패한 목록이 없다면 최종 답 도출
        if len(reversedCheckList) == 0:
            flag = True
            break

        reversedFlag = True
        #역방향 탐색
        c = c[::-1]
        for l in reversedCheckList:
            if KMP("".join(l), "".join(c)) == False:
                #역방향으로도 존재하지 않다면 바로 종료
                reversedFlag = False
                break
        if reversedFlag:
            flag = True
            break
    #최종 답 표현
    if flag:
        print('YES')
    else:
        print('NO')