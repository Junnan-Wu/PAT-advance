//1115 Counting Nodes in a BST
//递归建立二叉搜索树，然后层序遍历树，记录每一层的节点的个数
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

struct node
{
	int value;
	node* left, * right;
};

node* Tree;

vector<int> V;
void input();
node* creat(int n);
void build_tree(node* root, int n);
void BFS();

int main()
{
	input();
	Tree = creat(V[0]);
	for (int i = 1; i < N; i++)
		build_tree(Tree, V[i]);
	BFS();
	return 0;
}

void input()
{
	scanf("%d", &N);
	V.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &V[i]);
	return;
}

node* creat(int n)
{
	node* temp = new node;
	temp->value = n;
	temp->left = temp->right = NULL;
	return temp;
}

void build_tree(node* root, int n)
{
	if (root->value >= n)
	{
		if (root->left == NULL)
		{
			root->left = creat(n);
			return;
		}
		else
			build_tree(root->left, n);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = creat(n);
			return;
		}
		else
			build_tree(root->right, n);
	}
	return;
}

void BFS()
{
	queue<node*> q;
	int thislevel = 1, nextlevel = 0;
	//记录本层的个数与下层的个数
	vector<int> levelcount;
	//有一个测试点只有两层，注意要把第一层的1个放入
	levelcount.push_back(1);
	q.push(Tree);
	while (!q.empty())
	{
		node* f = q.front();
		q.pop(); thislevel--;
		if (f->left)
		{
			q.push(f->left);
			nextlevel++;
		}
		if (f->right)
		{
			q.push(f->right);
			nextlevel++;
		}
		//当层的个数pop完毕，进入下一层，更新层的节点个数
		if (thislevel == 0)
		{
			thislevel = nextlevel;
			levelcount.push_back(nextlevel);
			nextlevel = 0;
		}
	}
	levelcount.pop_back();//由于最后一层的后还记录了一个0，需要额外弹出
	cout << levelcount[levelcount.size() - 1] << " + " << levelcount[levelcount.size() - 2] << " = ";
	cout << levelcount[levelcount.size() - 1]+ levelcount[levelcount.size() - 2] << endl;
	return;
}
