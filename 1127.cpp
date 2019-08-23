//1127 ZigZagging on a Tree
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

struct node
{
	int val;
	node *left,*right;
};

vector<int> inorder,postorder,zigorder;
vector<int> level_count;//记录层序遍历的每一层个数
int N;
void initialization();//初始化函数
node* creat(int in_st,int post_st,int n);//根据前序中序位置建立根节点
node* build_tree(int in_st,int post_st,int n);//建立树
void BFS(node* root);//根据根节点层序遍历，将结果暂时放在zigorder数组中，同时记录每一层的个数放在level_count数组中
void revese_zig();//从0层开始，偶数层的遍历结果要逆转

int main()
{
	initialization();
	node *root=build_tree(0,0,N);
	BFS(root);
	revese_zig();
	for(int i=0;i<zigorder.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",zigorder[i]);
	}
	return 0;
}

node* creat(int in_st,int post_st,int n)//给定一个前序中序建立一个节点
{
	node *temp=new node;
	temp->val=postorder[post_st+n-1];
	temp->left=temp->right=NULL;
	return temp;
}

void initialization()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int temp;
		scanf("%d",&temp);
		inorder.push_back(temp);
	}
	for(int i=0;i<N;i++)
	{
		int temp;
		scanf("%d",&temp);
		postorder.push_back(temp);
	}
	return;
}

node* build_tree(int in_st,int post_st,int n)//给定中序的起点，前序的起点，与树节点个数，递归找根节点
{
	int root_val=postorder[post_st+n-1];
	node *root=creat(in_st,post_st,n);
	//计算左树个数
	int nleft=find(inorder.begin()+in_st,inorder.begin()+in_st+n,root_val)-(inorder.begin()+in_st);
	//右树个数
	int nright=n-nleft-1;
	//左树的前序与后序的起点
	int left_in_st=in_st,left_post_st=post_st;
	//右树的前序与后序的起点
	int right_in_st=in_st+nleft+1,right_post_st=post_st+nleft;
	if(nleft!=0)
		root->left=build_tree(left_in_st,left_post_st,nleft);
	if(nright!=0)
		root->right=build_tree(right_in_st,right_post_st,nright);
	return root;
}

void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	int count_this_level=1,count_next_level=0;
	level_count.push_back(1);
	while(!q.empty())
	{
		if(q.front()->left)
		{
			q.push(q.front()->left);
			count_next_level++;
		}
		if(q.front()->right)
		{
			q.push(q.front()->right);
			count_next_level++;
		}
		zigorder.push_back(q.front()->val);
		q.pop();
		count_this_level--;
		if(count_this_level==0)//本层遍历完毕，记录下一层的个数在level_count数组中，同时更新本层
		{
			level_count.push_back(count_next_level);
			count_this_level=count_next_level;
			count_next_level=0;
		}
	}
	return;
}

void revese_zig()
{
	int p=0;
	stack<int> tep;
	for(int i=0;i<level_count.size();i++)
	{
		if(i%2==0)//对于偶数层，需要逆转层序遍历的结果，使用一个栈即可
		{
			for(int k=p;k<p+level_count[i];k++)
			{
				tep.push(zigorder[k]);
			}
			for(int k=p;k<p+level_count[i];k++)
			{
				zigorder[k]=tep.top();
				tep.pop();
			}
		}
		p+=level_count[i];
	}
	return;
}
