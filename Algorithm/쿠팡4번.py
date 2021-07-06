INF = 987654321
#dp[100][100];
#int edge[100][100];
dp = []
edge = []

def solution(depar,hub,dest, roads) :
    #인덱싱화
    dic = {} 
    dic[roads[0][0]] = 0
    dic[roads[0][1]] = 1
    idx = 2
    for i in range(1,len(roads)):
        if (roads[i][0] in dic.keys()) == False :
            dic[roads[i][0]] = idx
            idx += 1
        if (roads[i][1] in dic.keys()) == False :
            dic[roads[i][1]] = idx
            idx += 1
    for road in roads:
        edge
        road[1]


if __name__ == "__main__":
    r = [["ULSAN","BUSAN"],["DAEJEON","ULSAN"],["DAEJEON","GWANGJU"],["SEOUL","DAEJEON"],["SEOUL","ULSAN"],["DAEJEON","DAEGU"],["GWANGJU","BUSAN"],["DAEGU","GWANGJU"],["DAEGU","BUSAN"],["ULSAN","DAEGU"],["GWANGJU","YEOSU"],["BUSAN","YEOSU"]]
    solution("SEOUL","DAEGU","YEOSU",r)
    #9
    #r = [["SEOUL","DAEJEON"],["ULSAN","BUSAN"],["DAEJEON","ULSAN"],["DAEJEON","GWANGJU"],["SEOUL","ULSAN"],["DAEJEON","BUSAN"],["GWANGJU","BUSAN"]]
    #solution("ULSAN", "SEOUL","BUSAN",r)
    #0

# int main(void)
# {
# 	cin >> N;
# 	// �׷��� ��� �ʱ�ȭ
# 	for (int i = 1; i <= N; i++)
# 	{
# 		int num1 = 0, num2 = 0, dist = 0;
# 		cin >> num1 >> num2 >> dist;
# 		edge[num1][num2] = dist;
# 		edge[num2][num1] = dist;
# 	}
# 	// �׷��� ��� �ʱ�ȭ (N + 1�� ������ �������� ������ 1�� �� ���� ����)
# 	for (int i = 1; i <= N + 1; i++)
# 	{
# 		for (int t = 1; t <= N + 1; t++)
# 		{
# 			if (i == t) { dp[i][t] = 0; }
# 			else if (edge[i][t] > 0) { dp[i][t] = edge[i][t]; }
# 			else { dp[i][t] = INF; }
# 		}
# 	}

# 	// ������ 1 ~ N + 1���� ��ȸ (N + 1�� ������ �������� ������ 1�� �� ���� ����)
# 	for (int k = 1; k <= N + 1; ++k)
# 	{
# 		for (int i = 1; i <= N + 1; ++i)
# 		{
# 			for (int j = 1; j <= N + 1; ++j)
# 			{
# 				if (dp[i][k] != INF && dp[k][j] != INF)
# 				{
# 					dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
# 				}
# 			}
# 		}
# 	}

# 	for (int i = 1; i <= N + 1; ++i)
# 	{
# 		cout << "dp[" << i << "] : ";
# 		for (int j = 1; j <= N + 1; ++j)
# 		{
# 			cout << dp[i][j] << " ";
# 		}
# 		cout << "\n";
# 	}
# }