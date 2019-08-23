//1113 Integer Set Partition
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a,int b)
{
	return a<b;
}

int main()
{
	int N,temp;
	vector<int> V;//注意题目虽然说的是两个set,但是还是不能用set进行存储，我们看到第一个测试用例中有两个相同的元素
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&temp);
		V.push_back(temp);
	}
	int S1=0,S2=0;
    //因为首先要保证个数的差值最小，因此两个集合的个数确定了，一个是N/2,另一个是N-N/2;
	int n1=N/2;
	int n2=N-n1;
    //在差值最小的情况下，保证两个集合数的和差最多，因此要将n1个小的数放在一个集合，n2个大的数放在一个集合
    sort(V.begin(),V.end(),compare);
	for(int i=0;i<n1;i++)
		S1+=V[i];
	for(int i=n1;i<N;i++)
		S2+=V[i];
	cout<<n2-n1<<' '<<S2-S1<<endl;
	return 0;
}
