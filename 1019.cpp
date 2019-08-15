//1019 General Palindromic Number 
#include<stdio.h>
#include<vector>

using namespace std;

typedef vector<int> Numbers;

Numbers number_Base_B(int n,int b);
bool judeg_if_Palindromic_Number(Numbers a);

int main()
{
	int N,b;
	scanf("%d %d",&N,&b);
	Numbers a=number_Base_B(N,b);
	bool judge=judeg_if_Palindromic_Number(a);
	if(judge)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i=a.size()-1;i>=0;i--)
	{
		if(i==0)
			printf("%d\n",a[i]);
		else
			printf("%d ",a[i]);
	}
	return 0;
}

Numbers number_Base_B(int n,int b)
{
	Numbers a;
	while(n!=0)
	{
		a.push_back(n%b);
		n/=b;
	}
	return a;
}

bool judeg_if_Palindromic_Number(Numbers a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=a[a.size()-1-i])
			return false;
	}
	return true;
}
