//1014 Waiting in Line
#include<stdio.h>
#include<queue>
#include<vector>

#define MAX 1001

using namespace std;

struct people
{
	int ID;
	int PT;//处理时间
	int ED;//结束时间
};

vector<people> store(MAX);//存储每一个人的初始信息
vector<int> request(MAX);//存储最后要求输出的人的序号
int N,M,K,Q;

void input();//输入函数
void start();//模拟函数
void print_time(int ED);//根据结束时间输出函数
void process();//输出所有要求的人的结果

int main()
{
	input();
	start();
	process();
	return 0;
}

void input()
{
	scanf("%d %d %d %d",&N,&M,&K,&Q);
	for(int i=1;i<=K;i++)//将K个人放入store数组中1-K
	{
		store[i].ID=i;
		scanf("%d",&store[i].PT);
		store[i].ED=0;//将每一个人的结束时间设为0
	}
	for(int i=0;i<Q;i++)
	{
		scanf("%d",&request[i]);
	}
	return;
}

void start()
{
	vector<queue<people>> Bank(N);
	int head=1;
	for(int j=0;j<M;j++)//初始将M*N人放入队列
	{
		for(int i=0;i<N;i++)
		{
			if(head>K)break;
			Bank[i].push(store[head++]);
		}
	}
	for(int i=0;i<N;i++)//初始时候每个队第一个人离开的时间就是他的处理时间
	{
		if(Bank[i].empty())
			continue;
		Bank[i].front().ED=Bank[i].front().PT;
		store[Bank[i].front().ID].ED=Bank[i].front().ED;
	}
	for(int time=0;time<540;time++)//从早上八点到下午五点,如果到了五点就不再服务客户了
	{
		for(int i=0;i<N;i++)
		{
			if(Bank[i].empty())
				continue;
			if(Bank[i].front().ED==time)//如果该时间有人结束，证明可以进入新的人
			{
				Bank[i].pop();//弹出一个人
				if(head<=K)//每弹出一个人，证明可以进入新的人
				{
					//由于每个时间点是从小窗口开始遍历，如果有新的人进入也是从小窗口进入
					Bank[i].push(store[head++]);//进入一个新的人
				}
				if(!Bank[i].empty())//如果进入了新的人，更新队列头的人的结束时间
				{
					Bank[i].front().ED=time+Bank[i].front().PT;
					store[Bank[i].front().ID].ED=Bank[i].front().ED;
				}
			}
		}
	}
	return;
}

void print_time(int ED)
{
	if(ED==0)
	{
		printf("Sorry\n");
		return;
	}
	int h,m;
	h=ED/60;
	m=ED%60;
	h+=8;
	printf("%02d:%02d\n",h,m);
	return;
}

void process()
{
	for(int i=0;i<Q;i++)
	{
		print_time(store[request[i]].ED);
	}
	return;
}
