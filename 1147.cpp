#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int key;
	node* left, * right;
};

vector<node*> Tree;
vector<int> level,postorder;
void process();

int main()
{
	process();
	return 0;
}

node* creat(int n)
{
	node* temp=new node;
	temp->key = n;
	temp->left = temp->right = NULL;
	return temp;
}

void build_tree()
{
	Tree.clear();
	Tree.resize(level.size());
	for (int i = 0; i < level.size(); i++)
		Tree[i] = creat(level[i]);
	for (int i = 0; i < Tree.size(); i++)
	{
		if (i * 2 + 1 < Tree.size())
			Tree[i]->left = Tree[i * 2 + 1];
		if ((i + 1) * 2 < Tree.size())
			Tree[i]->right = Tree[(i + 1) * 2];
	}
	return;
}

bool judge_max(node* root)
{
	if (root->left)
		if (root->key >= root->left->key)
			return judge_max(root->left);
		else
			return false;
	if(root->right)
		if (root->key >= root->right->key)
			return judge_max(root->right);
		else
			return false;
	return true;
}

bool judge_min(node* root)
{
	if (root->left)
		if (root->key <= root->left->key)
			return judge_min(root->left);
		else
			return false;
	if (root->right)
		if (root->key <= root->right->key)
			return judge_min(root->right);
		else
			return false;
	return true;
}

void find_postorder(node* root)
{
	if (!root)
		return;
	find_postorder(root->left);
	find_postorder(root->right);
	postorder.push_back(root->key);
	return;
}

void process()
{
	int M, N;
	cin >> M >> N;
	level.resize(N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &level[j]);
		}
		build_tree();
		postorder.clear();
		find_postorder(Tree[0]);//计算该树的后序遍历结果
		if (judge_max(Tree[0]))
			printf("Max Heap\n");
		else if (judge_min(Tree[0]))
			printf("Min Heap\n");
		else
			printf("Not Heap\n");
		for (int k = 0; k < postorder.size(); k++)
		{
			if (k != 0)printf(" ");
			printf("%d", postorder[k]);
		}
		printf("\n");
	}
	return;
}
