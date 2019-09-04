//1056 Mice and Rice
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct mouse
{
	int weight;
	int rank;
};

int Np, Ng;
vector<mouse>V;
queue<int> order;
queue<int> win;//存放上一轮比赛的获胜的老鼠的编号

void input();//输入数据
void play();//进行比赛

int main()
{
	input();
	play();
	for (int i = 0; i < Np; i++)
	{
		if (i != 0)cout << ' ';
		cout << V[i].rank;
	}
	return 0;
}

void input()
{
	scanf("%d %d", &Np, &Ng);
	V.resize(Np);
	for (int i = 0; i < Np; i++)//使用V数组来存储老鼠的信息
	{
		mouse temp;
		scanf("%d", &temp.weight);
		temp.rank = -1;
		V[i] = temp;
	}
	for (int i = 0; i < Np; i++)//将比赛顺序放在order数组中
	{
		int temp;
		scanf("%d", &temp);
		order.push(temp);
	}
	return;
}

void play()
{
	while (1)
	{
    //记录本轮比赛的淘汰者的排名
		int this_rank = order.size() % Ng == 0 ? order.size() / Ng + 1 : order.size() / Ng + 2;
		while (!order.empty())//上一轮比赛没有结束
		{
			vector<int> temp;//临时存储本轮的老鼠编号
			for (int i = 0; i < Ng && !order.empty(); i++)//将Ng个老鼠放在一个临时数组中
			{
				int t;
				t = order.front();
				temp.push_back(t);
				order.pop();
			}
			int max = -1, id = -1;
			for (int i = 0; i < temp.size(); i++)//找到本轮比赛的最大老鼠的体重与ID
			{
				if (V[temp[i]].weight > max)
				{
					max = V[temp[i]].weight;
					id = temp[i];
				}
			}
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i] != id)
				{
					V[temp[i]].rank = this_rank;
				}
				else
				{
					win.push(temp[i]);//胜利者放在win数组中
				}
			}
		}
		order = win;//将上一次比赛的获胜者全部放入下一次的比赛顺序
		while (!win.empty())//清空
			win.pop();
		if (order.size() == 1)//最后一个获胜者直接设置为冠军
		{
			int temp = order.front();
			V[temp].rank = 1;
			break;
		}
	}
	return;
}
