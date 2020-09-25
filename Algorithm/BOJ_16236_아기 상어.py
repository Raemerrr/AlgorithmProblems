import sys
from collections import deque


class Shark:
    def __init__(self, y, x):
        self.y = y
        self.x = x
    def __str__(self):
        return '(y : {}, x : {}, size : {})'.format(self.y, self.x, self.size)

fishDic = {}
#fishSizeList = []
n = 0
board = []
s = Shark(0,0)
fishs = {}
isRun = True
#BFS돌며 방문 가능(크기 작은 물고기) 지점을 모두 골라
#(,) 튜플 형식으로 저장해 소팅 후 해당 위치부터 다시 시작하는 것으로
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def CheckRange(y, x) :
    if y > -1 and y < n and x > -1 and x < n :
        return True
    else :
        return False

def BFS():
    ans = 0
    tempAns = 0
    dq = deque([s])
    flagSize = 2
    flagKill = 0
    visited = [[False for x in range(n)] for y in range(n)]
    while len(dq):
        possiblePosList = []
        loopCnt = len(dq)
        for loop in range(loopCnt):
            curShark = dq.popleft()
            for i in range(len(dy)):
                tempY = curShark.y + dy[i]
                tempX = curShark.x + dx[i]
                curSize = flagSize
                if CheckRange(tempY,tempX) and visited[tempY][tempX] == False and board[tempY][tempX] <= curSize and board[tempY][tempX] != 9:
                    visited[tempY][tempX] = True
                    #이번 턴에 가능한 물고기가 있는가?
                    if board[tempY][tempX] == 0 or  board[tempY][tempX] == curSize:
                        dq.append(Shark(tempY,tempX))
                    else :
                        dq.append(Shark(tempY,tempX))
                        possiblePosList.append((tempY,tempX))
        tempAns += 1
        #잡아 먹을 것 들이 있다면 선택 해야함.
        if len(possiblePosList) > 0 :
            possiblePosList.sort()
            t_Shark = dq.popleft()
            dq.clear()
            t_Shark.y = possiblePosList[0][0]
            t_Shark.x = possiblePosList[0][1]
            flagKill += 1
            ans += tempAns
            tempAns = 0
            #물고기 리스트에서 지우기
            fishDic[board[t_Shark.y][t_Shark.x]] -= 1
            if fishDic[board[t_Shark.y][t_Shark.x]] == 0 :
                del(fishDic[board[t_Shark.y][t_Shark.x]])
            if (flagKill == flagSize):
                flagKill = 0
                flagSize += 1
            dq.append(t_Shark)
            for lst in board :
                if 9 in lst :
                    lst[lst.index(9)] = 0
                    break
            board[possiblePosList[0][0]][possiblePosList[0][1]] = 9
            possiblePosList.clear()
            visited = [[False for x in range(n)] for y in range(n)]
        liveFishs = list(fishDic.keys())
        liveFishs.sort()
        
        if len(fishDic) == 0 or flagSize <= liveFishs[0] :
            break
    return ans

if __name__ == "__main__":
    n = int(input())
    board = [[0 for x in range(n)] for y in range(n)]
    for i in range(n):
        board[i] = list(map(int, sys.stdin.readline().rstrip().split()))
        for j in range(len(board[i])):
            if board[i][j] == 9:
                s = Shark(i, j)
            elif board[i][j] > 0:
                if board[i][j] in fishDic :
                    fishDic[board[i][j]] += 1
                else :
                    fishDic[board[i][j]] = 1
    if (len(fishDic) == 0):
        print(0)
    else:
        print(BFS())