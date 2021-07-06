NTT = "0123456789ABCDEF"


def convert(n, base):
    q, r = divmod(n, base)
    if q == 0:
        return NTT[r]
    else:
        return convert(q, base) + NTT[r]

def sol(N):
    k = ans = 0
    for i in range(2,10):
        result = str(convert(n,i))
        tAns = 1
        for s in result:
            if s != '0':
                tAns *= int(s)
        if ans < tAns :
            ans = tAns
            k = i
        elif ans == tAns and i > k:
            k = i
    print([k, ans])

if __name__ == "__main__":
    n = int(input())
    sol(n)