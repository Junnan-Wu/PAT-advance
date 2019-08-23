//1026 Table Tennis
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

#define START 8*3600
#define END 21*3600

struct player
{
	int arrive,serve,wating,play;//到达时间，开始服务时间，等待时间，打球时间
	int VIP;//是否VIP
};

vector<player> store;//记录所有数据
vector<queue<player>> table;//模拟等待窗口
vector<player> nowqueue;//记录当前正在等待的队伍
vector<int> served;//记录不同桌子服务的人数
int K;//桌子数
int M;//VIP桌子数量
int N;//人数
int head;//记录store数据当前的头
set<int> VIPtable;//记录vip桌子的编号

void input();
bool compare(player a,player b)
{
	return a.arrive<b.arrive;
}
void print_res(player a);
void simulation();
void process_vip(int t);
void process_ordinary(int t);

int main()
{
	input();
	simulation();
	for(int i=0;i<K;i++)
	{
		if(i==K-1)
			printf("%d\n",served[i]);
		else
			printf("%d ",served[i]);
	}
	return 0;
}

void input()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int h,m,s,t,v;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&t,&v);
		if(h*3600+m*60+s>END)
			continue;
		player temp;
		temp.arrive=h*3600+m*60+s;
		temp.play=t<=120?t:120;//一个坑点，虽然题目说每对玩的时间小于2小时，但是还是有大于两小时的输入
		temp.VIP=v;
		store.push_back(temp);
	}
	sort(store.begin(),store.end(),compare);
	scanf("%d %d",&K,&M);
	for(int i=0,temp;i<M;i++)
	{
		scanf("%d",&temp);
		VIPtable.insert(temp);
	}
	head=0;
	served.resize(K);
	return;
}

void simulation()
{
	table.resize(K);
	int nvip=0;//记录nowqueue中vip用户的个数
	for(int t=START;t<END;t++)//注意9点进入的不能计算！否则1，3两个测试点不能过
	{
		while(head<store.size()&&store[head].arrive<=t)//先将该时刻所有人放入队里
		{
			if(store[head].VIP==1)
				nvip++;
			nowqueue.push_back(store[head++]);
		}
		int empty_table=0,nviptable=0;//记录当前空的球桌个数与空的vip球桌个数
		for(int i=0;i<K;i++)//先将结束的桌子清空
		{
			bool judge=find(VIPtable.begin(),VIPtable.end(),i+1)!=VIPtable.end();//判断该桌子是不是vip桌子
			if(!table[i].empty())//如果球桌不空，判断该球桌的人是否训练完毕
			{
				if(table[i].front().serve+table[i].front().play*60==t)
				{
                    //训练完毕后将其弹出，增加空球桌的个数
					table[i].pop();
					empty_table++;
					if(judge)//如果还是vip球桌，增加其个数
						nviptable++;
				}
			}
			else//如果球桌为空，增加空球桌与vip球桌个数
			{
				if(judge)
					nviptable++;
				empty_table++;
			}

		}
		//因为要先处理队列中vip用户，因此在前面要记录vip用户的个数与vip桌子的个数
		while(nvip>0&&nviptable>0)//注意先处理vip用户的时候，如果没有vip桌子，vip用户按照普通用户处理
		{
			process_vip(t);
			nvip--;nviptable--;empty_table--;
		}
		if(empty_table>0)
		{
			process_ordinary(t);
		}
	}
}

//该函数要求处理的vip用户一定进入vip桌子，因此进入该函数的时候就要判断是否有vip用户与vip桌子
void process_vip(int t)
{
	vector<player>::iterator vip;
	//找到第一个是vip的用户
	vip=nowqueue.end();
	for(int i=0;i<nowqueue.size();i++)
	{
		if(nowqueue[i].VIP==1)
		{
			vip=nowqueue.begin()+i;
			break;
		}
	}
	//找到第一台空的vip桌子
	int have_viptable=-1;
	for(auto i=VIPtable.begin();i!=VIPtable.end();i++)//查询当前是否有vip桌子
	{
		if(table[(*i)-1].empty())
		{
			 have_viptable=(*i)-1;
			 break;
		}
	}
	if(vip!=nowqueue.end()&&have_viptable>=0)//如果有vip且有vip桌子
	{
		vip->serve=t;
		vip->wating=t-vip->arrive;
		table[have_viptable].push(*vip);
        //向vip球桌push一个vip用户，同时在served数组记录,输出信息
		served[have_viptable]++;
		print_res(*vip);
		nowqueue.erase(vip);
	}
}

void process_ordinary(int t)
{
    //处理一般用户，如果当前时刻，有空球桌，且等待队列不空，将其弹入球桌
	for(int i=0;i<K;i++)
	{
		if(table[i].empty()&&!nowqueue.empty())
		{
			table[i].push(*nowqueue.begin());
			table[i].front().serve=t;
			table[i].front().wating=t-table[i].front().arrive;
			served[i]++;//每次向球桌push的时候，在served数组中进行记录
			print_res(table[i].front());//同时输出其信息，因为按照serve的时间顺序弹入，与输出顺序一致
			nowqueue.erase(nowqueue.begin());//将等待队列的该元素删除
		}
	}
	return;
}

void print_res(player a)
{
	int h,m,s;
	h=a.arrive/3600;
	m=(a.arrive-h*3600)/60;
	s=a.arrive-h*3600-m*60;
	printf("%02d:%02d:%02d ",h,m,s);
	h=a.serve/3600;
	m=(a.serve-h*3600)/60;
	s=a.serve-h*3600-m*60;
	printf("%02d:%02d:%02d %d\n",h,m,s,(int)(a.wating/60.0+0.5));
	return;
}
