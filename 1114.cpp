//1114 Family Property
//DFS查找集合个数
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct people
{
	int father=-1, mother=-1;
	vector<int> children;
	int M=0, area=0;
};

struct result
{
	int id, np;
	double avgs, avga;
};

vector<int> store;//记录所有出现的人的id
vector<people> V(10000);//储存所有信息
vector<bool> visit(10000, false);//储存是否拜访过的信息
vector<result> res;//储存结果

void process();

int main()
{
	process();
	return 0;
}

//对于最后结果的输出排序准则
bool compare(result a, result b)
{
	return a.avga == b.avga ? a.id<b.id : a.avga>b.avga;
}

void input()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int id,k;
		scanf("%d", &id);
		store.push_back(id);
		scanf("%d %d %d", &V[id].father, &V[id].mother, &k);
		//记录id人的父母的编号,如果父母存在，向store中push，同时将父母的儿子节点增加id
		if (V[id].father != -1)
		{
			store.push_back(V[id].father);
			V[V[id].father].children.push_back(id);
		}
		if (V[id].mother != -1)
		{
			store.push_back(V[id].mother);
			V[V[id].mother].children.push_back(id);
		}
		//记录id的孩子的信息
		if (k != 0)
		{
			V[id].children.resize(k);
			for (int i = 0; i < k; i++)
			{
				scanf("%d", &V[id].children[i]);
				//向store中加入id的孩子
				store.push_back(V[id].children[i]);
				//同时该孩子的父亲或者母亲之一为id
				if (V[V[id].children[i]].father == -1)
				{
					V[V[id].children[i]].father = id;
					continue;
				}
				V[V[id].children[i]].mother = id;
			}
		}
		scanf("%d %d", &V[id].M,&V[id].area);
	}
	return;
}

//DFS第一个参数是当前人，np是该family目前已经遍历到的人个数，m是房子个数，area是房子面积，minid是遍历过程中找到的最小id
void DFS(int n,int &np,int &m,int &area,int &minid)
{
	//如果拜访过，直接返回
	if (visit[n])
		return;
	visit[n] = true;
	np++;
	m += V[n].M;
	area += V[n].area;
	//如果当前id更小，更新minid
	if (minid > n)
		minid = n;
	//依次对其父亲，母亲，所有孩子进行搜索
	if (V[n].father != -1)
		DFS(V[n].father, np,m,area, minid);
	if (V[n].mother != -1)
		DFS(V[n].mother, np,m,area, minid);
	if (V[n].children.size() != 0)
	{
		for (int i = 0; i < V[n].children.size(); i++)
		{
			DFS(V[n].children[i],np,m,area, minid);
		}
	}
	return;
}

void process()
{
	input();
	for (int i = 0; i < store.size(); i++)
	{
		//对于所有出现过的人，进行DFS
		if (!visit[store[i]])
		{
			result temp;
			//初始时刻入参都设置为0
			int np=0, area=0,minid=store[i],m=0;
			DFS(store[i], np, m, area, minid);
			//每DFS一次证明有一个family，记录该family的信息
			temp.id = minid;
			temp.np = np;
			temp.avgs = m / (np + 0.0);
			temp.avga = area / (np + 0.0);
			res.push_back(temp);
		}
	}
	sort(res.begin(), res.end(), compare);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
	{
		printf("%04d %d %.3lf %.3lf\n", res[i].id, res[i].np, res[i].avgs, res[i].avga);
	}
	return;
}
