if __name__ == "__main__":
    s = input()
    for i in s:
        if i.isalpha():
            n = ord(i) + 13
            if i.islower():
                if n > ord('z'):
                    n = n % ord('z') + ord('a') - 1
            else:
                if n > ord('Z'):
                    n = n % ord('Z') + ord('A') - 1
            print(chr(n), end='')
        else:
            print(i, end='')
