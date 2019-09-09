//1124 Raffle for Weibo Followers
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int M, N, S;
vector<string> forward_list;
map<string, int> m;//记录一个人是否中过奖

int main()
{
	cin >> M >> N >> S;
	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		forward_list.push_back(temp);
	}
	if (forward_list.size() < S)
	{
		cout << "Keep going...\n";
		return 0;
	}
	else
	{
		for (int i = S - 1; i < forward_list.size();)
		{
			if (m[forward_list[i]]++!= 0)
			{
				i++;
				continue;
			}
			cout << forward_list[i] << endl;
			i += N;
		}
	}
	return 0;
}
