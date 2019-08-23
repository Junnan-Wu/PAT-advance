//1064 Complete Binary Search Tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

template<typename T>inline T pow(T a,T n)
{
	if(n==0)
		return 1;
	T res=1;
	while(n--)
	{
		res*=a;
	}
	return res;
}

struct Node
{
	int ID;
	Node *left,*right;
};

bool compare(int a,int b)
{
	return a<b;
}

vector<int> store,res;
void input();
int find_root(int st,int N);//从st开始的N个数
Node* build_tree(int st,int N);
void BFS(Node *root);

int main()
{
	input();
	Node *root=build_tree(0,store.size());
	BFS(root);
	for(int i=0;i<res.size();i++)
	{
		if(i!=0)
			printf(" ");
		printf("%d",store[res[i]]);
	}
	return 0;
}

Node* creat(int n)
{
	if(n==-1)
		return NULL;
	Node *a=new Node;
	a->ID=n;
	a->left=NULL;
	a->right=NULL;
	return a;
}

void input()
{
	int N;
	scanf("%d",&N);
	store.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&store[i]);
	sort(store.begin(),store.end(),compare);
	return;
}

int find_root(int st,int N)
{
	if(N==0)
		return -1;
	int level=0;
	int leaf=1;
	while(N>=leaf)
	{
		N-=leaf;
		level++;
		leaf*=2;
	}
	int left_tree=(N<=leaf/2)?N+pow(2,level-1)-1:pow(2,level)-1;
	return st+left_tree;
}

Node* build_tree(int st,int N)
{
	Node* root=creat(find_root(st,N));//建立根节点；
	if(root==NULL)
		return root;
	int st_left=st;//左树的起点
	int st_right=root->ID+1;//右树的起点
	int nleft=root->ID-st;//左树个数
	int nright=N-nleft-1;//右树个数
	root->left=build_tree(st_left,nleft);
	root->right=build_tree(st_right,nright);
	return root;
}

void BFS(Node *root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		if(q.front()->left!=NULL)
			q.push(q.front()->left);
		if(q.front()->right!=NULL)
			q.push(q.front()->right);
		res.push_back(q.front()->ID);
		q.pop();
	}
	return;
}
