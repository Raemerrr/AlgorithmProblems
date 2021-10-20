if __name__ == "__main__":
    cnt = 0
    dic = {}
    while True:
        try:
            k = input()
            if k in dic.keys():
                dic[k] += 1
            else:
                dic[k] = 1
            cnt += 1
        except EOFError:
            break
    for key, val in sorted(dic.items()):
        print(key, '%.4f' % (val / cnt * 100))
