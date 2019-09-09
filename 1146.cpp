//1146 Topological Order
//拓扑排序，如果后一个点的入度不为0，是不可以输出的
#include<iostream>
#include<vector>

using namespace std;

#define MAXN 1001

int Graph[MAXN][MAXN];
int indegree[MAXN];//计算每一个点的入度
int N,M;
void input();
int judge();

int main()
{
    input();
    int test;
    scanf("%d",&test);
    vector<int> result;
    for(int i=0;i<test;i++)
    {
        int res=judge();
        if(res==-1)
            result.push_back(i);
    }
    for(int i=0;i<result.size();i++)
    {
        if(i!=0)printf(" ");
        printf("%d",result[i]);
    }
    return 0;
}


void input()
{
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[a][b]=1;//a点到b点的距离为1
        indegree[b]++;//b点入度加1
    }
}

int judge()
{
    int store[MAXN];
    for(int i=0;i<=N;i++)
        store[i]=indegree[i];
    vector<int> V;
    V.resize(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&V[i]);
    }
    for(int i=0;i<N;i++)
    {
        if(store[V[i]]!=0)//判断V[i]点的入度，如果不为零，证明不是拓扑排序
            return -1;
        else//如果是0，将V[i]的所有后节点的入度-1
        {
            for(int j=1;j<=N;j++)
            {
                if(Graph[V[i]][j]==1)
                    store[j]--;
            }
        }
    }
    return 0;
}
