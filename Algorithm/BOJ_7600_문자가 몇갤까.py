if __name__ == "__main__":
    while True:
        dic = {}
        s = input()
        if s == '#':
            break
        ans = 0
        for i in s:
            if i.isalpha():
                if (i.lower() in dic.keys()) == False:
                    dic[i.lower()] = True
                    ans += 1
        print(ans)
