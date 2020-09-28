


if __name__ == "__main__":
    s = input()
    word = input()
    ans = []
    for i in range(len(s)):
        ans.append(s[i])
        if s[i] == word[-1] and len(ans) >= len(word) and "".join(ans[-len(word):]) == word:
            for i in range(len(word)):
                ans.pop()
    ans = ans if len(ans) > 0 else list('FRULA')
    print("".join(ans))
    