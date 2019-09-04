//1134 Vertex Cover
#include<iostream>
#include<vector>

using namespace std;

int N, M;

struct edge
{
	int left, right;//记录一个边的左右点
};

vector<edge> V;//储存边的信息
vector<int> s;//储存判断集合点
void input();
void judge();

int main()
{
	input();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		judge();
	return 0;
}

void input()
{
	scanf("%d %d", &N, &M);
	edge temp;
	s.resize(N);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &temp.left, &temp.right);
		V.push_back(temp);
	}
	return;
}

void judge()
{
	int n,temp;
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
		s[i] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		s[temp] = 1;//集合中有这个点设置为1
	}
	for (int i = 0; i < M; i++)//遍历所有边
	{
		if (s[V[i].left]==1|| s[V[i].right] == 1)//如果该边的左右节点至少一个点在集合内，继续判断
			continue;
		else
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	return;
}
