//1024 Palindromic Number
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(string n);
void process();

int main()
{
	process();
	return 0;
}

string add(string a,string b)
{
	char p='0';
	for(int i=a.length()-1;i>=0;i--)
	{
		int n=((a[i]-'0')+(b[i]-'0')+(p-'0'))%10;//计算本位的和
		p=((a[i]-'0')+(b[i]-'0')+(p-'0'))/10+'0';//计算下一次的进位
		a[i]='0'+n;
	}
	if(p!='0')//如果最后有进位，在字符串首位添加
		a.insert(a.begin(),p);
	return a;
}

void process()
{
	string N;
	int K,step=0;
	cin>>N>>K;
	while(K--)
	{
		string temp=N;
		reverse(N.begin(),N.end());
		if(N==temp)
			break;
		N=add(temp,N);
		step++;
	}
	cout<<N<<endl;
	cout<<step<<endl;
	return;
}
