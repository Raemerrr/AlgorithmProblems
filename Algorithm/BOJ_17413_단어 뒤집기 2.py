if __name__ == "__main__":
    s = input()
    flag = False
    i = 0
    ans = ''
    while i < len(s):
        j = i + 1
        if s[i] == '<':
            while True:
                if s[j] == '>':
                    ans += s[i:j + 1]
                    #해당 단어 포함
                    i = j
                    break
                j += 1
        else:
            temp = ''
            while True:
                if s[j] == ' ':
                    temp = s[i:j]
                    ans += (temp[::-1] + ' ')
                    #해당 단어 포함
                    i = j
                    break
                elif s[j] == '<':
                    temp = s[i:j]
                    ans += temp[::-1]
                    #해당 단어 -1까지 포함 
                    i = j - 1
                    break
                elif j == len(s) - 1:
                    temp = s[i:j + 1]
                    ans += temp[::-1]
                    #해당 단어 포함
                    i = j
                    break
                j += 1
        i += 1
    print(ans)