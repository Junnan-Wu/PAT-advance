//1027 Colors in Mars 
#include<iostream>

using namespace std;

char digit[14]="0123456789ABC";//使用合并的定义，不用写成一个个的形式

char *ten_base_13(int n)//根据数字返回转为13进制的一个字符串
{
	char *res=new char[3];
	res[0]=digit[n/13];
	res[1]=digit[n%13];
	res[2]='\0';
	return res;
}

int main()
{
	int red,green,blue;
	scanf("%d %d %d",&red,&green,&blue);
	char *Red,*Green,*Blue;
	Red=ten_base_13(red);
	Green=ten_base_13(green);
	Blue=ten_base_13(blue);
	printf("#%s%s%s\n",Red,Green,Blue);
	return 0;
}
