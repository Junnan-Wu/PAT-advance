//1016 Phone Bills
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

inline int S2D(string a)//将两位的字符串转化为数字
{
	return (a[0] - '0') * 10 + (a[1] - '0');
}

int Rate[24];//记录不同时段的费用比率

struct Call_Info//记录一个通话状态
{
	string time;//通话时间
	string flag;//通话状态
};

map<string, vector<Call_Info>> Store;//储存所有人的信息
double res[2];//临时储存一次计算的结果
void input();//输入所有人的信息
bool compare(Call_Info a, Call_Info b);
void sort_Call_Info(vector<Call_Info>& a);
void cal_time(string time1, string time2);//通过两个时间来计算一个人该时间的通话时长与花费
void process();

int main()
{
	input();
	process();
	return 0;
}

void input()
{
	for (int i = 0; i < 24; i++)
		scanf("%d", &Rate[i]);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string name;
		Call_Info temp;
		cin >> name >> temp.time >> temp.flag;
		//scanf("%s %s %s",name,temp.time,temp.flag);
		Store[name].push_back(temp);
	}
	for (auto i = Store.begin(); i != Store.end(); i++)//输入后按照时间进行排序
		sort_Call_Info(i->second);
	return;
}

bool compare(Call_Info a, Call_Info b)
{
	return a.time < b.time;
}

void sort_Call_Info(vector<Call_Info>& a)
{
	sort(a.begin(), a.end(), compare);
	return;
}

void cal_time(string time1, string time2)//根据两个时间来计算通话时间与通话费用
{
	res[0] = 0; res[1] = 0;//储存结果的数组，0存历经时间，1存花费
	int ts[3], te[3];//记录开始的时间与结束的时间
	for (int i = 0, s = 3; i < 3; i++, s += 3)//将time1，time2的时间记录在两个数组中
	{
		ts[i] = S2D(time1.substr(s, 2));
		te[i] = S2D(time2.substr(s, 2));
	}
	res[0] = (te[0] - ts[0]) * 24 * 60 + (te[1] - ts[1]) * 60 + (te[2] - ts[2]);
	int d = ts[0], h = ts[1], m = ts[2];
	bool flag = true;
	for (; d <= te[0]; d++)
	{
		for (; h <= 23; h++)
		{
			for (; m <= 59; m++)
			{
				if (d == te[0] && h == te[1] && m == te[2])
				{
					flag = false;
					break;
				}
				res[1] += Rate[h];
			}
			m = 0;
			if (!flag)break;
		}
		h = 0;
		if (!flag)break;
	}
	res[1] /= 100;
	return;
}

void process()
{
	for (auto i = Store.begin(); i != Store.end(); i++)//i是不同的客户
	{
		bool flag = false;//保证有客户才输出名字，且仅输出一次，设置标记
		double sum = 0;
		for (int j = 0; j < i->second.size(); j++)
		{
			if (i->second[j].flag == "on-line" && j + 1 < i->second.size())
			{
				if (i->second[j + 1].flag == "off-line")
				{
					if(!flag)//第一次才输出客户名字
						cout << i->first << " " << i->second[0].time.substr(0, 2) << endl;
					cout << i->second[j].time.substr(3, 8) << " " << i->second[j + 1].time.substr(3, 8) << " ";
					cal_time(i->second[j].time, i->second[j + 1].time);
					printf("%d $%.2f\n", int(res[0]), res[1]);
					sum += res[1];
					flag = true;
				}
			}
		}
		if(flag)
			printf("Total amount: $%.2f\n", sum);
	}
}
