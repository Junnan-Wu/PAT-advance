//1094 The Largest Generation
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct person
{
	int ID;//记录这个人的ID
	vector<person*> child;//存储这个人的孩子的指针
};

vector<person*> family;
int N,M;

person* creat(int i);
void initialization();
void print_res();

int main()
{
	initialization();
	print_res();
	return 0;
}

person* creat(int i)
{
	person *a=new person;
	a->ID=i;
	return a;
}

void initialization()
{
	scanf("%d %d",&N,&M);
	family.resize(N+1);
	for(int i=1;i<=N;i++)//建立一个空树
	{
		person *temp=creat(i);
		family[i]=temp;
	}
	for(int i=0;i<M;i++)
	{
		//对有孩子的人，记录其孩子的位置
		int id,k;
		scanf("%d %d",&id,&k);
		family[id]->child.resize(k);
		for(int j=0;j<k;j++)
		{
			int child;
			scanf("%d",&child);
			family[id]->child[j]=family[child];
		}
	}
	return;
}

void print_res()
{
	queue<person*>q;
	q.push(family[1]);//放入根节点
	int level=1,this_generation=1;//记录每一层的人数
	int next_generation=0;
	int max_generation=this_generation,position=level;//保存最大层的人数与层数
	while(!q.empty())
	{
		if(q.front()->child.size()>0)
		{
			for(int i=0;i<q.front()->child.size();i++)
			{
				q.push(q.front()->child[i]);
				next_generation++;
				//每一次向队列中push新的成员，下一代的人数加1
			}
		}
		q.pop();
		this_generation--;
		//如果这一代的人数pop完
		if(this_generation==0)
		{
			//层数加1，更新本层的人数，同时比较是否是最大人数的generation
			level++;
			this_generation=next_generation;
			next_generation=0;
			if(this_generation>max_generation)
			{
				max_generation=this_generation;
				position=level;
			}
		}
	}
	printf("%d %d\n",max_generation,position);
	return;
}
