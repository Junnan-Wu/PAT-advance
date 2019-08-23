//1054 The Dominant Color
#include<iostream>
#include<vector>
//这里使用unordered_map与map对结果的运行速度差异好像不是很大
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

unordered_map<int,int> Picture;
//map<int,int> Picture;

vector<pair<int,int>> V;

bool compare(pair<int,int> a,pair<int,int>b)
{
	return a.second>b.second;
}

int main()
{
	int M,N;
	cin>>M>>N;
	for(int i=0;i<N;i++)
	{
		int color;
		for(int j=0;j<M;j++)
		{
			scanf("%d",&color);//注意，这里使用scanf才能保证不超时
			Picture[color]++;
		}
	}
	for(auto i=Picture.begin();i!=Picture.end();i++)
	{
		V.push_back(*i);
	}
	sort(V.begin(),V.end(),compare);
	printf("%d\n",V.begin()->first);
	return 0;
}
