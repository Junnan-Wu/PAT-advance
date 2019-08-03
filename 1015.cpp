//1015 Reversible Primes
#include<stdio.h>

#define MAX 15

char number_D[MAX];//存放转化为D进制的数字,注意这里必须使用字符串来存储转化为D进制的数字
//因为10000的2进制数已经超过了15位，使用int已经无法存储了

bool Is_Prime(int n);
int Reverse_Number_Base_Radix_D(int n,int radix);
bool Judge_Is_Reverse_Prime(int N,int D);

int main()
{
	int N,D;
	while(1)
	{
		scanf("%d",&N);
		if(N<0)return 0;
		scanf("%d",&D);
		if(Judge_Is_Reverse_Prime(N,D))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

bool Is_Prime(int n)
{
	if(n<=1)
		return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int Reverse_Number_Base_Radix_D(int n,int radix)//计算数字n的radix进制数的逆序数
{
	int index=0;
	while(n!=0)
	{
		number_D[index++]=(n%radix)+'0';
		n/=radix;
	}//先将n转为radix进制，每一位存在字符串数组中
	//再逆序取出，计算逆序数字
	int sum=0,mul=1;
	for(index--;index>=0;index--)
	{
		sum+=(number_D[index]-'0')*mul;
		mul*=radix;
	}
	return sum;
}

bool Judge_Is_Reverse_Prime(int N,int D)
{
	if(!Is_Prime(N))//如果本身不是质数，直接返回false
		return false;
	int number=Reverse_Number_Base_Radix_D(N,D);//计算数字N的D进制数的逆序数字
	if(Is_Prime(number))
		return true;
	else
		return false;
}
