//1025 PAT Ranking
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

struct Stu
{
	char reg_num[14];
	int score,local_num,local_rank,final_rank;
};

vector<vector<Stu>> All_info;
vector<Stu> Res;
bool compare(Stu a,Stu b);

void input();
void process();

int main()
{
	input();
	process();
	return 0;
}

void input()
{
	int N;
	scanf("%d",&N);
	All_info.resize(N);
	for(int i=0;i<N;i++)
	{
		int K;
		scanf("%d",&K);
		for(int j=0;j<K;j++)
		{
			Stu temp;
			temp.local_num=i+1;
			scanf("%s %d",&temp.reg_num,&temp.score);
			All_info[i].push_back(temp);
		}
		sort(All_info[i].begin(),All_info[i].end(),compare);
		for(int rank=1,p=0;K>0;K--)
		{
			if(p!=0)
				rank=(All_info[i][p].score==All_info[i][p-1].score)?rank:p+1;
			All_info[i][p++].local_rank=rank;
		}
	}
	return;
}

bool compare(Stu a,Stu b)
{
	return a.score==b.score?(strcmp(a.reg_num,b.reg_num)<0):a.score>b.score;
	//注意使用strcmp函数的时候，当两个字符串不相等的时候，C标准没有规定返回值会是1 或 -1，只规定了正数和负数，见百度百科https://baike.baidu.com/item/strcmp/5495571?fr=aladdin
	//一开始使用这个函数的时候写成了与-1进行比较，导致两个测试点没有通过
}

void process()
{
	for(int i=0;i<All_info.size();i++)
	{
		for(int j=0;j<All_info[i].size();j++)
			Res.push_back(All_info[i][j]);
	}
	sort(Res.begin(),Res.end(),compare);
	for(int rank=1,p=0;p<Res.size();p++)
	{
		if(p!=0)
			rank=(Res[p].score==Res[p-1].score)?rank:p+1;
		Res[p].final_rank=rank;
	}
	printf("%d\n",Res.size());
	for(int i=0;i<Res.size();i++)
	{
		printf("%s %d %d %d\n",Res[i].reg_num,Res[i].final_rank,Res[i].local_num,Res[i].local_rank);
	}
	return;
}
