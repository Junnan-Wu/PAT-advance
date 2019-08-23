//1083 List Grades
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct stu
{
	string name,ID;
	int grade;
};

int N;
vector<stu> store;
vector<stu> res;

bool compare(stu a,stu b);
void input();
void out();

int main()
{
	input();
	out();
	return 0;
}

bool compare(stu a,stu b)
{
	return a.grade==b.grade?a.name<b.name:a.grade>b.grade;
}

void input()
{
	scanf("%d",&N);
	store.resize(N);
	for(int i=0;i<N;i++)
	{
		cin>>store[i].name>>store[i].ID>>store[i].grade;
	}
	return;
}

void out()
{
	int grade1,grade2;
	cin>>grade1>>grade2;
	for(int i=0;i<N;i++)
	{
		if(store[i].grade>=grade1&&store[i].grade<=grade2)
			res.push_back(store[i]);
	}
	if(res.size()==0)
		cout<<"NONE\n";
	else
	{
		sort(res.begin(),res.end(),compare);
		for(int i=0;i<res.size();i++)
			cout<<res[i].name<<' '<<res[i].ID<<endl;
	}
	return;
}
