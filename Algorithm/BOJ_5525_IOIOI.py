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
    ans = 0
    pi = getPI(pattern)
    j = 0
    for i in range(len(s)):
        while j > 0 and s[i] != pattern[j]:
            j = pi[j - 1]
        if s[i] == pattern[j]:
            #패턴의 마지막 글자와 같다면 패턴 일치
            if j == len(pattern) - 1:
                ans += 1
                j = pi[j]
            #패턴의 부분 일치 중
            else:
                j += 1
    return ans


if __name__ == "__main__":
    p = ['I']
    n = int(input())
    for i in range(n):
        p.append('OI')
    #입력은 받았지만 사용하지 않는 값 l
    l = int(input())
    s = input()
    print(KMP(s, "".join(p)))