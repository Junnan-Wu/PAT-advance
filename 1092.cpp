//1092 To Buy or Not to Buy
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	string sell,want;
	getline(cin,sell);
	getline(cin,want);
	map<char,int> m;
	//用map存储每个珠子最后剩余的个数
	for(int i=0;i<sell.size();i++)
		m[sell[i]]++;
	for(int i=0;i<want.size();i++)
		m[want[i]]--;
	int extra=0,need=0;
	//计算剩余的珠子数与需要的珠子数
	for(auto i=m.begin();i!=m.end();i++)
	{
		if(i->second>0)
			extra+=i->second;
		else if(i->second<0)
			need-=i->second;
	}
	if(need==0)
		printf("Yes %d\n",extra);
	else
		printf("No %d\n",need);
	return 0;
}
