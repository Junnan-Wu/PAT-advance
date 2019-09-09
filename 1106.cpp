//1106 Lowest Price in Supply Chain
//注意要读题 输出结果要求输出最小价格供应链的个数
#include<iostream>
#include<vector>

using namespace std;

#define INF 0x7fffffffffffffff

//储存该供应商上一个供货商与本供应商的价格
struct seller
{
	seller* before;
	int ID;
	vector<int> next;
	double price;
};

int N;
double P, r;
double minres = INF;//储存最小的价格
int res=0;//储存最小价格供应链的个数
vector<seller*> V;//储存节点信息
void input();
seller* creat();
void DFS(seller* now);
void process();

int main()
{
	process();
	return 0;
}

seller* creat()
{
	seller* temp = new seller;
	temp->before = NULL;
	return temp;
}

void input()
{
	scanf("%d %lf %lf", &N, &P, &r);
	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		V[i] = creat();
	}
	V[0]->price = P;
	for (int i = 0; i < N; i++)
	{
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++)
		{
			int t;
			scanf("%d", &t);
			V[i]->next.push_back(t);
			V[t]->before = V[i];//t供货商的上线是i;
		}
	}
}

void DFS(seller* now)
{
	if (now->price > minres)
		return;
	if (now->next.size() == 0)
	{
		if (now->price < minres)
		{
			minres = now->price;
			res = 1;
		}
		else if (now->price == minres)
		{
			res++;
		}
		return;
	}
	for (int i = 0; i < now->next.size(); i++)
	{
		V[now->next[i]]->price = now->price * (1 + 0.01 * r);
		DFS(V[now->next[i]]);
	}
	return;
}

void process()
{
	input();
	DFS(V[0]);
	printf("%.4lf %d\n", minres, res);
	return;
}
