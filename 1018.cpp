//1018 Public Bike Management
#include<stdio.h>
#include<vector>

#define MAXN 501
#define INF 0x3f3f3f3f

using namespace std;

int map[MAXN][MAXN];//存储地图信息
int C,N,M,D;
int bike[MAXN];//存储自行车信息
bool visit[MAXN];//储存是否拜访过
vector<int> pathtep,path;//临时存储路径,与最后储存路径
int mindis=INF;//储存最短路径长度
int need=0,back=0;

void input();
void find_path(int p,int des,int dis,int cur,int cnt);
//递归解决查找最短路，p是当前的位置，des是终点，dis是当前路径长度
//cur是当前携带的自行车数量,cnt是当前需要携带的自行车个数

int main()
{
	input();
	find_path(0,D,0,0,0);
	printf("%d ",need);
	for(int i=0;i<path.size();i++)
	{
		if(i!=0)
		{
			printf("->%d",path[i]);
		}
		else
		{
			printf("%d",path[i]);
		}
	}
	printf(" %d\n",back);
	return 0;
}

void input()
{
	scanf("%d %d %d %d",&C,&N,&D,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&bike[i]);
		bike[i]=bike[i]-C/2;
	}
	for(int i=0;i<=N;i++)
		visit[i]=false;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			map[i][j]=INF;
	for(int i=0;i<M;i++)
	{
		int p1,p2,dis;
		scanf("%d %d %d",&p1,&p2,&dis);
		map[p1][p2]=map[p2][p1]=dis;
	}
	return;
}

void find_path(int p,int des,int dis,int cur,int cnt)
{
	visit[p]=true;
	pathtep.push_back(p);//将该点存入路径
	if(dis>mindis)//如果路径长度超出最大值
	{
		visit[p]=false;
		pathtep.pop_back();
		return;
	}
	if(p==des)//如果到达终点
	{
		if(dis<mindis)//如果距离更短，一定更新
		{
			mindis=dis;
			path=pathtep;
			need=cnt;
			back=cur+need;
		}
		else if(dis==mindis)
		{
			if(cnt<need)//如果距离一样，需要发出的车更少，更新
			{
				mindis=dis;
				path=pathtep;
				need=cnt;
				back=cur+need;
			}
			else if(cnt==need)
			{
				if(cur+need<back)//距离一样，发出的车一样，回收的车更少，也更新
				{
					mindis=dis;
					path=pathtep;
					need=cnt;
					back=cur+need;
				}
			}
		}
		//回溯
		visit[p]=false;
		pathtep.pop_back();
		return;
	}
	for(int i=0;i<=N;i++)
	{
		if(map[p][i]!=INF&&!visit[i])
		{
			int nextdis=dis+map[p][i];
			//注意如何计算下一个节点的后需要的自行车
			int nextcur=cur+bike[i];//首先记录增加下一个节点后拥有的自行车个数
			int nextcnt=cnt;//记录增加了下一个节点需要的自行车，假设不变
			if(nextcur<-1*cnt)//如果下一节点拥有的自行车个数比需要的总共需要的自行车个个数还小，更新需要的自行车
				nextcnt=-1*nextcur;
			find_path(i,des,nextdis,nextcur,nextcnt);
		}
	}
	visit[p]=false;
	pathtep.pop_back();
	return;
}
