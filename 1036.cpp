//1036 Boys vs Girls
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Stu
{
	string name,ID;
	char gender;
	int grade;
};

vector<Stu> boy, girl;
bool compare(Stu a, Stu b);
void input();
void output();

int main()
{
	input();
	output();
	return 0;
}

bool compare(Stu a, Stu b)//定义排序准则，男性从小到大排，女性从大到小排
{
	if (a.gender == 'M')
		return a.grade < b.grade;
	else
		return a.grade > b.grade;
}

void input()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		Stu temp;
		cin >> temp.name >> temp.gender >> temp.ID >> temp.grade;
		if (temp.gender == 'M')
			boy.push_back(temp);
		else
			girl.push_back(temp);
	}
	sort(boy.begin(), boy.end(), compare);
	sort(girl.begin(), girl.end(), compare);
	return;
}

void output()
{
	//用judge来判断是否男性或女性有缺席
	bool judge = true;
	if (girl.size() != 0)
		cout << girl[0].name << ' ' << girl[0].ID << endl;
	else
	{
		judge = false;
		cout << "Absent" << endl;
	}
	if (boy.size() != 0)
		cout << boy[0].name << ' ' << boy[0].ID << endl;
	else
	{
		judge = false;
		cout << "Absent" << endl;
	}
	if (!judge)
		cout << "NA" << endl;
	else
		cout << girl[0].grade - boy[0].grade << endl;
	return;
}
