//1013 Battle Over Cities
#include<iostream>

using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 1001

int N, M, K;
int dis[MAXN][MAXN];
bool visit[MAXN];

void input();
void process();
void DFS(int);//从一点开始进行DFS

int main()
{
	input();
	process();
	return 0;
}

void input()
{
	//cin >> N >> M >> K;
	scanf("%d %d %d", &N, &M, &K);
	int x, y;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dis[i][j] = dis[j][i] = INF;
	for (int i = 0; i < M; i++)
	{
		//cin >> x >> y;
		scanf("%d %d", &x, &y);
		dis[x][y] = dis[y][x]= 1;
	}
	return;
}

void DFS(int p)
{
	visit[p] = true;
	for (int i = 1; i <= N; i++)
	{
		if (dis[p][i] == 1 && !visit[i])
			DFS(i);
	}
	return;
}

void process()
{
	int city, count;
	for (int i = 0; i < K; i++)
	{
		//cin >> city;
		scanf("%d", &city);
		count = 0;
		for (int j = 1; j <= N; j++)
			visit[j] = false;
		visit[city] = true;
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				count++;
				DFS(i);
			}
		}
		//cout << count - 1 << endl;
		printf("%d\n", count - 1);
	}
	return;
}
