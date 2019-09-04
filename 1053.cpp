//1053 Path of Equal Weight
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, S;

struct node
{
	int value;
	vector<node*> children;
};

vector<node*>V;
vector<int> path;
bool compare(node* a, node* b)
{
	return a->value > b->value;
};
void input();
void dfs(node* root);

int main()
{
	input();
	dfs(V[0]);
	return 0;
}

void input()
{
	scanf("%d %d %d", &N, &M, &S);
	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		node* temp = new node;
		scanf("%d", &temp->value);
		V[i] = temp;
	}
	for (int i = 0; i < M; i++)
	{
		int root, n;
		scanf("%d %d", &root, &n);
		V[root]->children.resize(n);
		for (int j = 0; j < n; j++)
		{
			int child;
			scanf("%d", &child);
			V[root]->children[j] = V[child];
		}
		//开始储存孩子节点的时候，就按照从大到小的顺序存储，这样在dfs的时候，输出顺序也是一样的
    //一开始使用string来存储最后路径，通过string比大小，但是有一个测试点没有过
		sort(V[root]->children.begin(), V[root]->children.end(), compare);
	}
	return;
}

void dfs(node* root)
{
	path.push_back(root->value);
	if (root->children.size() != 0)
	{
		for (int i = 0; i < root->children.size(); i++)
			dfs(root->children[i]);
	}
	else//如果是叶子节点，计算路径和
	{
		int sum = 0;
		for (int i = 0; i < path.size(); i++)
			sum += path[i];
		if (sum == S)
		{
			for (int i = 0; i < path.size(); i++)
			{
				if (i != 0)cout << ' ';
				cout<<path[i];
			}
			cout << endl;
		}
	}
	path.pop_back();
	return;
}
