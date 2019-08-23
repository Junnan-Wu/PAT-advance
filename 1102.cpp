//1102 Invert a Binary Tree
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int index;
	node *left,*right;
};

vector<node*> v;
vector<int> level_order,in_order;
int N;
int Root;

node* creat(int i);//建立节点
void initialization();//建立树
void find_level_order();//计算层序遍历输出结果
void find_in_order(node *root);//计算中序遍历输出结果

int main()
{
	initialization();
	find_level_order();
	find_in_order(v[Root]);
	for(int i=0;i<level_order.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",level_order[i]);
	}
	printf("\n");
	for(int i=0;i<in_order.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",in_order[i]);
	}
	return 0;
}

node* creat(int i)
{
	node *temp=new node;
	temp->index=i;
	temp->left=temp->right=NULL;
	return temp;
}

void initialization()
{
	cin>>N;
	char l,r;
	v.resize(N);
	for(int i=0;i<N;i++)
	{
		node* temp=creat(i);
		v[i]=temp;
	}
	Root=(N-1)*N/2;
	for(int i=0;i<N;i++)
	{
		cin>>l>>r;
		if(l!='-')
		{
			v[i]->left=v[l-'0'];
			Root-=l-'0';
		}
		if(r!='-')
		{
			v[i]->right=v[r-'0'];
			Root-=r-'0';
		}
	}
	return;
}

//注意本题的层序遍历与中序遍历都是从右子树开始进行
void find_level_order()
{
	queue<node*> q;
	q.push(v[Root]);
	while(!q.empty())
	{
		if(q.front()->right)q.push(q.front()->right);
		if(q.front()->left)q.push(q.front()->left);
		level_order.push_back(q.front()->index);
		q.pop();
	}
	return;
}

void find_in_order(node *root)
{
	if(root->right)find_in_order(root->right);
	in_order.push_back(root->index);
	if(root->left)find_in_order(root->left);
	return;
}
