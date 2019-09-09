//1084 Broken Keyboard
#include<iostream>
#include<string>
#include<map>

using namespace std;

map<char, int> M;

//将一个字符的大小写的另一个输出
char conversion(char c)
{
	if (c >= 'a' && c <= 'z')
		return 'A' + (c - 'a');
	if (c >= 'A' && c <= 'Z')
		return 'a' + (c - 'A');
	return c;
}

int main()
{
	string S1, S2;
	getline(cin, S1);
	getline(cin, S2);
	for (int i = 0; i < S1.length(); i++)
	{
		//要打出的字符设为1
		M[S1[i]] = M[conversion(S1[i])] = 1;
	}
	for (int i = 0; i < S2.length(); i++)
	{
		//打出的字符设为2
		M[S2[i]] = M[conversion(S2[i])] = 2;
	}
	for (int i = 0; i < S1.length(); i++)
	{
		//如果M[i]为1，表明该字符没有被打出,输出，同时将该字符的大小写属性设为2
		if (M[S1[i]] == 1)
		{
			char c = conversion(S1[i]);
			cout << (c < S1[i] ? c : S1[i]);
			M[c] = M[S1[i]] = 2;
		}
	}
	return 0;
}
