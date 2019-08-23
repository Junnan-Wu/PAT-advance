//1099 Build A Binary Search Tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Node
{
	int index,store;
	Node *left,*right;
};

vector<int> v;
vector<int> in_order,level_order;//记录中序遍历的结果,层序遍历结果
vector<Node *> T;
int N;

Node* creat_node(int index);
void initialization();
void find_in_order(Node *root);
void put_number();
void print_level_order();

int main()
{
	initialization();//初始化，并建树
	put_number();//根据中序遍历填入数字
	print_level_order();//根据层序遍历输出结果
	return 0;
}

Node* creat_node(int index)
{
	Node *a=new Node;
	a->index=index;
	a->left=a->right=NULL;
	return a;
}

void initialization()//初始化，根据节点信息建立树
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		Node *temp=creat_node(i);
		T.push_back(temp);
	}
	for(int i=0;i<N;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if(l!=-1)
			T[i]->left=T[l];
		if(r!=-1)
			T[i]->right=T[r];
	}
	//将节点储存的信息记录在数组v中，同时按照从小到大的顺序进行排列
	v.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	return;
}

void find_in_order(Node *root)//由于将数字填入二叉搜索树的顺序即为中序遍历的顺序，因此记录中序遍历的index的顺序
{
	if(root->left)
		find_in_order(root->left);
	in_order.push_back(root->index);
	if(root->right)
		find_in_order(root->right);
	return;
}

void put_number()//根据中序遍历结果把数字填入二叉搜索树
{
	find_in_order(T[0]);
	for(int i=0;i<N;i++)
		T[in_order[i]]->store=v[i];
	return;
}

void print_level_order()//最后根据层序遍历的结果，输出
{
	queue<Node*> q;
	q.push(T[0]);
	while(!q.empty())
	{
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		level_order.push_back(q.front()->store);
		q.pop();
	}
	for(int i=0;i<N;i++)
	{
		if(i!=0)printf(" ");
		printf("%d",level_order[i]);
	}
	return;
}
