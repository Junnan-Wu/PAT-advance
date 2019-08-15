//1023 Have Fun with Numbers
#include<iostream>

using namespace std;

int main()
{
	char s[22] = { 0 };
	int number[10] = {0}, cal[10] = { 0 };
	char temp;
	int length = 0;
	int i = 0;
	while (cin.peek() != '\n')
	{
		cin >> temp;
		s[i] = temp; i++;
		number[temp - '0']++;
		length++;
	}
	int tep=0;
	for (int i = length - 1; i >= 0; i--)
	{
		int temp = ((s[i] - '0') * 2 + tep) / 10;
		s[i] = ((s[i] - '0') * 2 + tep ) % 10  + '0';
		tep = temp;
	}
	if (tep != 0)
	{
		cout << "No" << endl;
		cout << tep;
		for (int i = 0; i < length; i++)
		{
			cout << s[i];
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			cal[s[i] - '0']++;
		}
		bool judge = true;
		for (int i = 0; i < 10; i++)
		{
			if (cal[i] != number[i])
			{
				judge = false;
				break;
			}
		}
		if (judge)
		{
			cout << "Yes" << endl;
			for (int i = 0; i < length; i++)
			{
				cout << s[i];
			}
		}
		else
		{
			cout << "No" << endl;
			for (int i = 0; i < length; i++)
			{
				cout << s[i];
			}
		}
	}
	return 0;
}
