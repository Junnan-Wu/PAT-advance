//1020 Tree Traversals
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

#define MAXN 30

using namespace std;

typedef struct Node* ptrNode;
struct Node
{
	int ID;
	ptrNode left,right;
};

int N;
vector<int> postorder,inorder;

void input();
Node* creatNode(int root);
Node* creattree(int post,int in,int len);
void output(Node* a);

int main()
{
	input();
	Node *root=creattree(0,0,N);
	output(root);
	return 0;
}

void input()
{
	scanf("%d",&N);
	postorder.resize(N);inorder.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&postorder[i]);
	for(int i=0;i<N;i++)
		scanf("%d",&inorder[i]);
	return;
}

Node* creatNode(int root)
{
	Node *a=new Node;
	a->ID=root;
	a->left=NULL;
	a->right=NULL;
	return a;
}

Node* creattree(int post,int in,int len)
{
	if(len==0)
		return NULL;
	int root=postorder[post+len-1];//根节点是后续遍历的最后一个值
	Node* now=creatNode(root);//创建根节点
	int proot=find(inorder.begin(),inorder.end(),root)-inorder.begin();//在中序遍历中找到根节点，根节点左边是左子树，右边是右子树
	int lenleft=proot-in,lenright=len-1-lenleft;//计算左右子树的长度
	int leftpost,leftin,rightpost,rightin;//左子树后序，中序，右子树后序中序
	leftpost=post;
	leftin=in;
	rightpost=post+lenleft;
	rightin=in+lenleft+1;
	now->left=creattree(leftpost,leftin,lenleft);
	now->right=creattree(rightpost,rightin,lenright);
	return now;
}

void output(Node *root)
{
	queue<Node*> q;
	vector<int> out;
	q.push(root);
	while(!q.empty())
	{
		out.push_back(q.front()->ID);
		if(q.front()->left!=NULL)
			q.push(q.front()->left);
		if(q.front()->right!=NULL)
			q.push(q.front()->right);
		q.pop();
	}
	for(int i=0;i<out.size();i++)
	{
		if(i==0)
			printf("%d",out[i]);
		else
			printf(" %d",out[i]);
	}
	return;
}
