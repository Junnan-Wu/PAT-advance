//Spell It Right
//becase number is less than 10^100,so the biggest the sum of all the digits less than 1000
//so we can use three number to represent bit,ten bit,hundred bit
#include<stdio.h>
#include<string.h>

char *number[10]={"zero","one","two","three","four",
						"five","six","seven","eight","nine"};

int main()
{
	char s[102];
	scanf("%s",&s);
	int sum=0;
	for(int i=0;i<strlen(s);i++)//include string.h head document to use function strlen
	{
		sum+=s[i]-'0';
	}
	int n1,n2,n3;
	n3=sum%10;sum/=10;
	n2=sum%10;sum/=10;
	n1=sum%10;
	if(n1!=0)
	{
		printf("%s %s %s\n",number[n1],number[n2],number[n3]);
	}
	else if(n2!=0)
	{
		printf("%s %s\n",number[n2],number[n3]);
	}
	else
	{
		printf("%s\n",number[n3]);
	}
	return 0;
}
