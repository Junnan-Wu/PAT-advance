//1021 Deepest Root
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;

#define MAXN 10001

bool visit[MAXN];
map<int,set<int>> graph;//使用这种map<int,set<int>>数据结构存储图的结构，节约开销，如果使用临街矩阵，则会超出内存限制
set<int> deepest_roots;//记录最深根节点的索引
int N;
int max_deep;//临时储存最大深度

void input();
void find_deepest_roots();
void DFS(int i,int deep);

int main()
{
	input();
	find_deepest_roots();
	return 0;
}

void input()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	max_deep=0;
	return;
}

void DFS(int i,int deep)
{
	visit[i]=true;
	if(deep>max_deep)//最大深度更新的时候，清空deepest_roots数组
	{
		max_deep=deep;
		deepest_roots.clear();
		deepest_roots.insert(i);
	}
	else if(deep==max_deep)//最大深度相同的时候，添加节点
	{
		deepest_roots.insert(i);
	}
	for(auto j=graph[i].begin();j!=graph[i].end();j++)
	{
		if(!visit[*j])
			DFS(*j,deep+1);
	}
	return;
}

void find_deepest_roots()
{
	fill(visit,visit+N+1,false);
	int roots;
	int components=0;
	for(int i=1;i<=N;i++)
	{
		if(!visit[i])
		{
			components++;
			DFS(i,0);//通过一次DFS找到一个叶子节点
		}
	}
	if(components>1)//由于题目保证N个节点只有N-1个边，所以要么是一棵树，要么是森林，不会出现只有一个连通图，且有回路的情况
	//因此上面的DFS次数就是连通图的个数
	{
		printf("Error: %d components\n",components);
		return;
	}
	fill(visit,visit+N+1,false);
	DFS(*deepest_roots.begin(),0);//根据叶子节点找到最深的根节点
	fill(visit,visit+N+1,false);
	DFS(*deepest_roots.begin(),0);//找到所有最深的根节点
	for(auto i=deepest_roots.begin();i!=deepest_roots.end();i++)
	{
		printf("%d\n",*i);
	}
	return;
}
