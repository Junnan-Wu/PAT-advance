//1050 String Subtraction
#include<iostream>
#include<string>
#include<map>

using namespace std;

map<char, int> M;

int main()
{
	string S1, S2;
	getline(cin, S1);
	getline(cin, S2);
	for (int i = 0; i < S2.length(); i++)
	{
		M[S2[i]] = 1;
	}
	for (int i = 0; i < S1.length(); i++)
	{
		if (M[S1[i]] == 1)continue;
		cout << S1[i];
	}
	return 0;
}
