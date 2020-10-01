import sys

if __name__ == "__main__":
    n = int(input())
    while n:
        strs = sys.stdin.readline().rstrip().split()
        for data in strs:
            print(data[::-1], end=' ')
        print()
        n -= 1
