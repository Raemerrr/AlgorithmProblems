import sys
from collections import deque


class Shark:
    def __init__(self, y, x):
        self.y = y
        self.x = x

    def __str__(self):
        return '(y : {}, x : {}, size : {})'.format(self.y, self.x, self.size)


n = 0
board = []
fishDic = {}
s = Shark(0, 0)
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


#범위 체크
def CheckRange(y, x):
    if y > -1 and y < n and x > -1 and x < n:
        return True
    else:
        return False


#BFS 알고리즘 활용
def BFS():
    ans = 0
    #임시 거리 이동 완료 후 물고기를 먹을 수 없는 경우도 있기 때문
    tempAns = 0
    #deque를 사용해보려고...
    dq = deque([s])
    #현재 상어의 크기
    flagSize = 2
    #현재 상어가 잡아 먹은 물고기 수
    flagKill = 0
    #재방문 방지
    visited = [[False for x in range(n)] for y in range(n)]
    while len(dq):
        #잡아 먹을 물고기의 위치를 저장
        possiblePosList = []
        loopCnt = len(dq)
        for loop in range(loopCnt):
            curShark = dq.popleft()
            for i in range(len(dy)):
                tempY = curShark.y + dy[i]
                tempX = curShark.x + dx[i]
                curSize = flagSize
                if CheckRange(
                        tempY, tempX
                ) and visited[tempY][tempX] == False and board[tempY][
                        tempX] <= curSize and board[tempY][tempX] != 9:
                    visited[tempY][tempX] = True
                    #빈칸 혹은 사이즈가 같은 물고기
                    if board[tempY][tempX] == 0 or board[tempY][
                            tempX] == curSize:
                        dq.append(Shark(tempY, tempX))
                    #잡아 먹을 수 있는 물고기
                    else:
                        dq.append(Shark(tempY, tempX))
                        possiblePosList.append((tempY, tempX))
        #임시 거리
        tempAns += 1
        #잡아 먹을 것 들이 있다면 선택 해야함.
        if len(possiblePosList) > 0:
            possiblePosList.sort()
            dq.clear()
            newSharkY = possiblePosList[0][0]
            newSharkX = possiblePosList[0][1]
            flagKill += 1
            ans += tempAns
            tempAns = 0
            #물고기 리스트 관리
            fishDic[board[newSharkY][newSharkX]] -= 1
            #크기 별 Dic자료구조에 해당 크기의 물고기가 없다면 삭제
            if fishDic[board[newSharkY][newSharkX]] == 0:
                del (fishDic[board[newSharkY][newSharkX]])
            #잡아 먹은 물고기 수와 현재 상어 크기가 같다면 크기 키우기
            if (flagKill == flagSize):
                flagKill = 0
                flagSize += 1
            #deque 자료구조에 추가
            dq.append(Shark(newSharkY, newSharkX))
            #현재 board에 상어 위치를 빈칸으로 변경
            for lst in board:
                if 9 in lst:
                    lst[lst.index(9)] = 0
                    break
            #새로운 상어 위치 입력
            board[possiblePosList[0][0]][possiblePosList[0][1]] = 9
            possiblePosList.clear()
            visited = [[False for x in range(n)] for y in range(n)]
        #물고기 크기를 관리하는 Dic구조에서 현재 물고기 크기를 조회
        liveFishs = list(fishDic.keys())
        liveFishs.sort()
        #현재 물고기가 남은게 없거나 남은 물고기 중 나보다 작은 것이 없다면 종료
        if len(fishDic) == 0 or flagSize <= liveFishs[0]:
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
                if board[i][j] in fishDic:
                    fishDic[board[i][j]] += 1
                else:
                    fishDic[board[i][j]] = 1
    if (len(fishDic) == 0):
        print(0)
    else:
        print(BFS())