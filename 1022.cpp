//1022 Digital Library
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

typedef int ID;
typedef string Title;
typedef string author;
typedef string key;
typedef string publisher;
typedef string year;

map<Title,set<ID>> T;
map<author,set<ID>> A;
map<key,set<ID>> K;
map<publisher,set<ID>> P;
map<year,set<ID>> Y;

void input();
void process(int id,string temp);
void show_result();
void show_map(map<string,set<int>> &a,string temp);

int main()
{
	input();
	show_result();
	return 0;
}

void input()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int id;
		scanf("%d\n",&id);
		string temp;
		getline(cin,temp);//读取titile
		T[temp].insert(id);
		getline(cin,temp);//读取author
		A[temp].insert(id);
		getline(cin,temp);//读取key word;
		process(id,temp);
		getline(cin,temp);//读取publisher
		P[temp].insert(id);
		getline(cin,temp);//读取year
		Y[temp].insert(id);
	}
	return;
}

void process(int id,string temp)//根据字符串将key words添加索引
{
	for(int i=0;i<temp.length();)
	{
		int j=i+1;
		for(;j<temp.length();j++)
		{
			if(temp[j]==' ')
				break;
		}
		K[temp.substr(i,j-i)].insert(id);
		i=j+1;
	}
	return;
}

void show_result()
{
	int m,flag;
	string temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d: ",&flag);
		getline(cin,temp);
		cout<<flag<<": "<<temp<<endl;
		switch(flag)
		{
		case 1:
			show_map(T,temp);
			break;
		case 2:
			show_map(A,temp);
			break;
		case 3:
			show_map(K,temp);
			break;
		case 4:
			show_map(P,temp);
			break;
		case 5:
			show_map(Y,temp);
			break;
		}
	}
	return;
}

void show_map(map<string,set<int>> &a,string temp)
{
	if(a[temp].empty())
		printf("Not Found\n");
	else
		for(auto j=a[temp].begin();j!=a[temp].end();j++)
			printf("%07d\n",*j);//一定要补全7位数字，不然后面两个测试用例无法通过
	return;
}
