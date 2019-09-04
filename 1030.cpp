//1030 Travel Plan
#include<iostream>
#include<vector>

using namespace std;

#define INF 0x7fffffff

struct edge
{
	int dis, cost;
};

//临时储存路径，以及最终储存路径
vector<int> path,res;
//储存拜访信息
vector<bool> visit;
//储存边的信息
vector<edge> E;
//储存地图信息
vector<vector<edge>> G;
int N, M, S, D;
int MINDIS=INF, MINCOST=INF;

void input();
void DFS(int p, int dis, int cost);

int main()
{
	input();
	DFS(S, 0, 0);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
	cout << MINDIS << ' ' << MINCOST << endl;
	return 0;
}

void input()
{
	scanf("%d %d %d %d", &N, &M, &S, &D);
	G.resize(N); E.resize(M); visit.resize(N);
	//初始化地图
	for (int i = 0; i < N; i++)
		G[i].resize(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j].cost = G[i][j].dis = INF;
	//初始化拜访数组
	for (int i = 0; i < N; i++)
		visit[i] = false;
	for (int i = 0; i < M; i++)
	{
		int city1, city2;
		scanf("%d %d %d %d", &city1, &city2, &E[i].dis, &E[i].cost);
		G[city1][city2] = G[city2][city1]=E[i];
	}
	return;
}

void DFS(int p, int dis, int cost)
{
	visit[p] = true;
	path.push_back(p);
	if (dis > MINDIS)//剪枝，如果当前路径已经超出最短路，直接退出
	{
		visit[p] = false;
		path.pop_back();
		return;
	}
	if (p == D)//如果到达终点
	{
		if ((dis < MINDIS)||(dis==MINDIS&&cost<MINCOST))//如果距离更小，或者距离相等但是花费最小
		{
			MINDIS = dis;
			MINCOST = cost;
			res = path;
			visit[p] = false;
			path.pop_back();
			return;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!visit[i] && G[p][i].dis != INF)
			DFS(i, dis + G[p][i].dis, cost + G[p][i].cost);
	}
	visit[p] = false;
	path.pop_back();
	return;
}
