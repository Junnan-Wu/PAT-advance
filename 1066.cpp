#include<iostream>
#include<vector>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

struct node
{
	int value;
	node* left, * right;
};

node* insert(node* root,int n);

int main()
{
	int N;
	node* root=NULL;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		root = insert(root, temp);
	}
	cout << root->value;
	return 0;
}

node* creat(int n)
{
	node* temp = new node;
	temp->value = n;
	temp->left = temp->right = NULL;
	return temp;
}

int height(node* root)
{
	if (root == NULL)
		return 0;
	return MAX(height(root->left), height(root->right)) + 1;
}

node* Rrotation(node* root)
{
	node* now_root = root->left;
	root->left = now_root->right;
	now_root->right = root;
	return now_root;
}

node* Lrotation(node* root)
{
	node* now_root = root->right;
	root->right = now_root->left;
	now_root->left = root;
	return now_root;
}

node* LRrotation(node* root)
{
	//先左旋再右旋
	root->left = Lrotation(root->left);
	return Rrotation(root);
}

node* RLrotation(node* root)
{
	//先右旋再左旋
	root->right = Rrotation(root->right);
	return Lrotation(root);
}

//node* LRrotation(node* root)
//{
//	node* now_root = root->left->right;
//	root->left->right = now_root->left;
//	now_root->left = root->left;
//	root->left = now_root->right;
//	now_root->right = root;
//	return now_root;
//}
//
//node* RLrotation(node* root)
//{
//	node* now_root = root->right->left;
//	root->right->left = now_root->right;
//	now_root->right = root->right;
//	root->right = now_root->left;
//	now_root->left = root;
//	return now_root;
//}

node* insert(node*root,int n)
{
	if (root == NULL)
		root = creat(n);
	else if (n <= root->value)
	{
		root->left=insert(root->left, n);
		if (height(root->left) - height(root->right) == 2)//如果插入后左边的树高度达到2
		{
			if (n < root->left->value)//R旋转
				root = Rrotation(root);
			else//LR旋转
				root = LRrotation(root);
		}
	}
	else
	{
		root->right = insert(root->right, n);
		if (height(root->right) - height(root->left) == 2)//如果插入后右边的树高度达到2
		{
			if (n < root->right->value)//RL旋转
				root = RLrotation(root);
			else//L旋转
				root = Lrotation(root);
		}
	}
	return root;
}
