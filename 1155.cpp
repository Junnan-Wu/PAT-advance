//1155 Heap Paths
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int value;
	node* left, * right;
};

vector<node*> V;//存储堆
vector<int> path;//存储路径
bool judgemax=true,judgemin = true;//判断该堆是大堆还是小堆

node* creat_node();//创建一个节点
void input();//输入并建立树
void dfs(node* root);//深度遍历堆

int main()
{
	input();
	dfs(V[0]);
	if (judgemax)
		cout << "Max Heap" << endl;
	else if (judgemin)
		cout << "Min Heap" << endl;
	else
		cout << "Not Heap" << endl;
	return 0;
}

node* creat_node()
{
	node* temp = new node;
	temp->left = temp->right= NULL;
	return temp;
}

void input()
{
	int N;
	scanf("%d", &N);
	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		V[i] = creat_node();
		scanf("%d", &V[i]->value);
	}
  //由于树是完全二叉树，所以i节点的左节点是i*2+1,右节点是(i+1)*2
	for (int i = 0; i < N; i++)
	{
		if (i * 2 + 1 < N)
			V[i]->left = V[i * 2 + 1];
		if ((i + 1) * 2 < N)
			V[i]->right = V[(i + 1) * 2];
	}
	return;
}

void dfs(node* root)
{
	path.push_back(root->value);
	bool flag=false;
  //如果存在左右子树，继续搜索
	if (root->right)
	{
		dfs(root->right);
		flag = true;
	}
	if (root->left)
	{
		dfs(root->left);
		flag = true;
	}
  //如果不存储左右子树，证明是根节点，输出路径，同时判断是大堆还是小堆
	if (!flag)
	{
		cout << path[0];
		for (int i = 1; i < path.size(); i++)
		{
			cout << ' '<<path[i];
			if (path[i] > path[i - 1])
				judgemax = false;
			if (path[i] < path[i - 1])
				judgemin = false;
		}
		cout << endl;
	}
  //遍历结束，弹出该节点
	path.pop_back();
	return;
}
