//1140 Look-and-say Sequence
#include<iostream>
#include<string>

using namespace std;

string int_to_string(int n);
string next_string(string s);

int main()
{
	string s; int N;
	cin >> s >> N;
	for (int i = 0; i < N-1; i++)
		s = next_string(s);
	cout << s << endl;
	return 0;
}

string int_to_string(int n)
{
	string s;
	while (n != 0)
	{
		s = (char)(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

string next_string(string s)
{
	string temp;
	char c=s[0];
	temp = c;
	int count = 1;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != c)
		{
			temp += int_to_string(count)+s[i];
			//在这里使用+=来对字符串进行追加，一开始使用temp=temp+str的形式，最后测试用例会超时
			count = 1;
			c=s[i];
		}
		else
			count++;
	}
	temp += int_to_string(count);
	return temp;
}
