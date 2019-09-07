//1041 Be Unique
#include<iostream>
#include<vector>
#include<queue>

#define MAXN 10001

using namespace std;

vector<int> V(MAXN,0);//储存每一个数字出现的个数
queue<int> Q;
int N;
void process();

int main()
{
	process();
	return 0;
}

void input()
{
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++)
	{
		//记录每一个数字出现的次数
		scanf("%d", &temp);
		V[temp]++;
		Q.push(temp);
	}
	return;
}

void process()
{
	input();
	while (!Q.empty())
	{
		int temp;
		temp = Q.front();
		//找到第一个出现次数为1次的数字
		if (V[temp] == 1)
		{
			printf("%d\n", temp);
			return;
		}
		Q.pop();
	}
	printf("None\n");
	return;
}
