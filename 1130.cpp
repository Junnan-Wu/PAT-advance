//1130 Infix Expression
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node
{
	string s;
	node* left, * right;
};

vector<node*> V;

node* creat_node()
{
	node* temp = new node;
	temp->left = temp->right = NULL;
	return temp;
}

int input();//输入数据并建立树，返回根节点的序号
string express(node* root);//根据根节点

int main()
{
	int root=input();
	string res = express(V[root]);
	cout << res << endl;
	return 0;
}

int input()
{
	int N;
	scanf("%d", &N);
	V.resize(N+1);
	for (int i = 1; i <= N; i++)//建立树
	{
		V[i] = creat_node();
	}
	vector<int> n;//临时的数组来记录哪个节点是根节点
	n.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int l, r;
		cin >> V[i]->s >> l >> r;
		if (l != -1)
		{
			V[i]->left = V[l];
			n[l] = 1;//其左节点不是根节点
		}
		if (r != -1)
		{
			V[i]->right = V[r];
			n[r] = 1;//其右节点不是根节点
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (n[i] != 1)
			return i;
	}
}

string express(node* root)
{
	string l="", r="";//左右表达式
	if (root->left)//如果有左树，计算左树的表达式
	{
		l = express(root->left);
		if(l!=root->left->s)//如果表达式就是左树本身，不用加括号，反之要加括号
			l = '(' + l + ')';
	}
	if (root->right)
	{
		r = express(root->right);
		if (r != root->right->s)
			r = '(' + r + ')';
	}
	return l + root->s + r;
}
