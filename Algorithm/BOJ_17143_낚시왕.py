import sys


class Fish:
    def __init__(self, id, y, x, s, d, z):
        self.id = id
        self.y = y
        self.x = x
        self.s = s
        self.d = d
        self.z = z

    def move(self):
        #loop 구간을 최적화 하였으며
        #물고기 이동을 한번에 가능한 거리로 이동 시켰습니다.
        #상하 이동
        if self.d == 1 or self.d == 2:
            loop = self.s % (2 * r - 2)
            while loop:
                addPos = getDir(self.d)
                remainingDist = 0
                if self.d == 1:
                    remainingDist = self.y - 1
                else:
                    remainingDist = r - self.y
                dist = min(loop, remainingDist)
                self.y += (addPos[0] * dist)
                self.x += (addPos[1] * dist)
                loop -= dist
                #loop가 남았다면 벽에 부딪힌 것
                #방향 전환
                if loop > 0:
                    self.d = 2 if self.d == 1 else 1
        #좌우 이동
        else:
            loop = self.s % (2 * c - 2)
            while loop:
                addPos = getDir(self.d)
                remainingDist = 0
                if self.d == 3:
                    remainingDist = c - self.x
                else:
                    remainingDist = self.x - 1
                dist = min(loop, remainingDist)
                self.y += (addPos[0] * dist)
                self.x += (addPos[1] * dist)
                loop -= dist
                #loop가 남았다면 벽에 부딪힌 것
                #방향 전환
                if loop > 0:
                    self.d = 4 if self.d == 3 else 3


#물고기 방향에 따른 증/감 값 반환
def getDir(d):
    if d == 1:
        return [-1, 0]
    elif d == 2:
        return [1, 0]
    elif d == 3:
        return [0, 1]
    else:
        return [0, -1]


r = c = fishCnt = ans = 0
board = []
fishDic = {}


def proc():
    #이 게임은 낚시꾼이 맨 우측으로 갈때 까지 진행
    for x in range(1, c + 1):
        #낚시꾼 사냥
        for y in range(1, r + 1):
            #물고기가 있다는 것
            if board[y][x] > 0:
                global ans
                ans += fishDic[board[y][x]].z
                del (fishDic[board[y][x]])
                board[y][x] = 0
                break
        #상어 이동
        tDic = {}
        checkPointList = []
        for f in list(fishDic.values()):
            #기존 board에서 제거
            board[f.y][f.x] = 0
            #상하, 좌우 이동
            f.move()
            board[f.y][f.x] = f.id
            #이동 한 물고기 위치 관리 tDic에 추가
            if tDic.get((f.y, f.x)):
                tDic[(f.y, f.x)].append((f.id, f.z))
            else:
                tDic[(f.y, f.x)] = [(f.id, f.z)]
                checkPointList.append((f.y, f.x))

        #이동 한 물고기 위치 tDic에서 물고기가 겹치는 위치가 있다면
        for key in checkPointList:
            tDic[key].sort(key=lambda x: x[1])
            for z in range(len(tDic[key]) - 1):
                del (fishDic[tDic[key][z][0]])
            board[key[0]][key[1]] = tDic[key][-1][0]


if __name__ == "__main__":
    r, c, fishCnt = map(int, sys.stdin.readline().rstrip().split())
    board = [[0 for x in range(c + 1)] for y in range(r + 1)]
    for i in range(1, fishCnt + 1):
        n1, n2, n3, n4, n5 = map(int, sys.stdin.readline().rstrip().split())
        f = Fish(i, n1, n2, n3, n4, n5)
        board[n1][n2] = f.id
        fishDic[f.id] = f
    if fishCnt > 0:
        proc()
    print(ans)