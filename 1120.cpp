//1120 Friend Numbers
#include<iostream>
#include<set>

using namespace std;

int cal_FriendID(int n)
{
	int res=0;
	while(n)
	{
		res+=n%10;
		n/=10;
	}
	return res;
}

int main()
{
	int N;
	set<int> ID;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int temp;
		scanf("%d",&temp);
		ID.insert(cal_FriendID(temp));
	}
	printf("%d\n",ID.size());
	for(auto i=ID.begin();i!=ID.end();i++)
	{
		if(i!=ID.begin())
			printf(" ");
		printf("%d",*i);
	}
	return 0;
}
