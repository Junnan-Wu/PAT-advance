//1125 Chain the Ropes
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	vector<int>rope(N);
	for(int i=0;i<N;i++)
		scanf("%d",&rope[i]);
	sort(rope.begin(),rope.end());
	double max=0;
	for(int i=0;i<N;i++)
	{
		max+=rope[i]/2.0;
		if(i!=N-1&&i!=0)//注意第一次与最后一次不用再对折
			max/=2.0;
	}
	printf("%d\n",(int)(max));
	return 0;
}
