//1017 Queueing at Bank
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//计算两个时间之间的秒数
#define A_to_B_Time(a,b) (((b)/10000-(a)/10000)*60*60+((b)%10000/100-(a)%10000/100)*60+((b)%100-(a)%100))
//计算从A时间经过B分钟到达的时间
inline int A_time_plus_B(int a,int b)
{
	int plus=a%10000/100+b;
	int time=(a/10000+plus/60)*10000+plus%60*100+a%100;
	return time;
}

struct people
{
	int be,st,ed;//进入银行时间与开始处理时间,结束时间
	int pt;
};

vector<people> store;
vector<queue<people>> windows;
int N,K;
int All;//存储所有能处理的人的个数

void input();
bool compare(people a,people b);
void simulation();
double cal_average();

int main()
{
	input();
	simulation();
	printf("%.1f\n", cal_average());
	return 0;
}

void input()
{
	scanf("%d %d",&N,&K);
	int h,m,s,p;
	All=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		people temp;
		temp.be=h*10000+m*100+s;
		if(temp.be<=170000)All++;//计算总共有多少人要进行处理
		temp.st=0;
		temp.ed=0;
		temp.pt=p;
		store.push_back(temp);
	}
	windows.resize(K);
	sort(store.begin(),store.end(),compare);
}

bool compare(people a,people b)
{
	return a.be<b.be;
}

void simulation()
{
	int head=0;
	for(int i=0;i<K;i++)//开始时刻将早于八点到的顾客放入队列
	{
		if(head<N)
		{
			if(store[head].be<=80000)
			{
				store[head].st=80000;//最初进入队列的人的开始时间是八点
				store[head].ed=A_time_plus_B(store[head].st,store[head].pt);
				windows[i].push(store[head++]);
			}
		}
	}
	for(int time=80000;head<All;time++)//注意循环结束条件不是终止时间小于17点，而是所有能处理的人处理完
	{
		if(time%100==60)
			time+=40;
		if(time%10000==6000)
			time+=4000;
		for(int i=0;i<K;i++)
		{
			if(!windows[i].empty())//如果队列不空
			{
				//队列头的人结束了
				if(windows[i].front().ed==time)
				{
					windows[i].pop();
				}
			}
			if(windows[i].empty())//如果队列空了，看能不能加人
			{
				if(head<N)//还有待处理的人
				{
					if(store[head].be<=time)
					{
						store[head].st=time;
						store[head].ed=A_time_plus_B(store[head].st,store[head].pt);
						windows[i].push(store[head++]);
					}
				}
			}
		}
	}
	return;
}

double cal_average()
{
	int number=0;double sum=0;
	for(int i=0;i<N;i++)
	{
		if(store[i].st!=0)
		{
			number++;
			sum+=A_to_B_Time(store[i].be,store[i].st);
		}
	}
	if(number==0)
		return 0;
	return sum/60.0/number;
}
