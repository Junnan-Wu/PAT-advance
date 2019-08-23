//1028 List Sorting
#include<iostream>
#include<string.h>
#include<algorithm>

#define MAXN 100000

using namespace std;

struct stu
{
	int ID;
	char name[9];
	int grade;
}STU[MAXN];

int flag,N;
void input();
void process();
bool compare_ID(stu a,stu b);
bool compare_name(stu a,stu b);
bool compare_grade(stu a,stu b);

int main()
{
	input();
	process();
	return 0;
}

void input()
{
	scanf("%d %d",&N,&flag);
	for(int i=0;i<N;i++)
	{
		scanf("%d %s %d",&STU[i].ID,&STU[i].name,&STU[i].grade);
	}
	return;
}

void process()
{
	bool (*pointf)(stu,stu);//使用指向函数的指针来定义sort的compare函数
	switch(flag)
	{
	case 1:
		pointf=compare_ID;
		break;
	case 2:
		pointf=compare_name;
		break;
	case 3:
		pointf=compare_grade;
		break;
	}
	sort(STU,STU+N,pointf);
	for(int i=0;i<N;i++)
		printf("%06d %s %d\n",STU[i].ID,STU[i].name,STU[i].grade);
	return;
}

bool compare_ID(stu a,stu b)
{
	return a.ID<b.ID;
}

bool compare_name(stu a,stu b)
{
	return strcmp(a.name,b.name)==0?a.ID<b.ID:strcmp(a.name,b.name)<0;//注意第二个测试用例中，名字一样也是默认按照ID的升序排列
}

bool compare_grade(stu a,stu b)
{
	return a.grade==b.grade?a.ID<b.ID:a.grade<b.grade;
}
