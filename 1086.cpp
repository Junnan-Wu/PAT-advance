//1086 Tree Traversals Again
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct node
{
	int ID;
	node* left, * right;
};

vector<node*> V;
vector<int> preorder, inorder,postorder;
int N;
void input();
void build_tree(vector<int> pre, vector<int> in);
void find_postorder(node* root);

int main()
{
	input();
	build_tree(preorder, inorder);
	find_postorder(V[preorder[0]]);
	for (int i = 0; i < postorder.size(); i++)
	{
		if (i != 0)cout << ' ';
		cout << postorder[i];
	}
	cout << endl;
	return 0;
}

void input()
{
	scanf("%d", &N);
	V.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		node* temp = new node;
		temp->ID = i;
		temp->left = temp->right= NULL;
		V[i] = temp;
	}
	//模拟题目中栈队列的push pop
	stack<int> s;
	for (int i = 0; i < 2 * N; i++)
	{
		string temp;
		cin >> temp;
		if (temp == "Push")
		{
			int now;
			cin >> now;
			//每push一次，先序遍历数组push
			s.push(now);
			preorder.push_back(now);
		}
		else
		{
			//每pop一次，中序遍历push
			inorder.push_back(s.top());
			s.pop();
		}
	}
	return;
}

void build_tree(vector<int> pre, vector<int> in)//根据先序跟中序建立树
{
	int root = pre[0];//根节点的ID
	int p = find(in.begin(), in.end(), root) - in.begin();//找到中序根节点的位置
	//计算左右树的大小
	int lenl, lenr;
	lenl = p; lenr = in.size() - p - 1;
	if (lenl != 0)
	{
		//左树的根节点是先序的第二个
		V[root]->left = V[pre[1]];
		vector<int> nexpre, nexin;
		nexpre.assign(pre.begin() + 1, pre.begin() + p+1);
		nexin.assign(in.begin(), in.begin() + p);
		build_tree(nexpre, nexin);
	}
	if (lenr != 0)
	{
		//右树的根节点是先序的p+2个
		V[root]->right = V[pre[p + 1]];
		vector<int> nexpre, nexin;
		nexpre.assign(pre.begin() + 1 + p, pre.end());
		nexin.assign(in.begin() + 1 + p, in.end());
		build_tree(nexpre, nexin);
	}
	return;
}

//将后序遍历结果存放在postorder数组中
void find_postorder(node* root)
{
	if (root->left)
		find_postorder(root->left);
	if (root->right)
		find_postorder(root->right);
	postorder.push_back(root->ID);
	return;
}
