import re
import sys
import collections

if __name__ == "__main__":
    s = sys.stdin.readline().rstrip()
    loop = int(sys.stdin.readline().rstrip())
    lst = collections.deque([])
    for i in range(loop):
        source = sys.stdin.readline().rstrip()
        lst.append(source)

    regx = collections.deque([])
    for i in s:
        if i.isalpha():
            regx.append(i+'+')
        elif i == '.':
            regx.append('\.')
        else:  #'*'
            #regx.append('[a-z.]*')
            regx.append('.*')
    regx = "".join(regx)
    print(len(regx))
    sys.stdout.write(regx+'\n')
    sys.stdout.write('========================================\n')
    while True:
        try:
            val = lst.popleft()
            result = re.match(regx, val)
            #result = re.search(regx, val)
            if result:
            #if result and val == result.group():
                sys.stdout.write(val + '\n')
        except IndexError:
            break

    # for i in lst:
    #     result = re.search(regx,i)
    #     if result and i == result.group() :
    #         sys.stdout.write(i + '\n')