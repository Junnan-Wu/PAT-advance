//1142 Maximal Clique
//一开始所有的Yes输成了YES……就说怎么一个测试点都通过不了，还是要注意看题目要求
#include<iostream>
#include<vector>

#define MAXN 201

using namespace std;

int Graph[MAXN][MAXN];//记录两点之间的距离
int Nv,Ne,M;

void input();
int judge();

int main()
{
    input();
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        int result=judge();
        switch (result)
        {
            case 1:
                cout<<"Yes"<<endl;
                break;
            case 0:
                cout<<"Not Maximal"<<endl;;
                break;
            default:
                cout<<"Not a Clique"<<endl;
                break;
        }
    }
    return 0;
}

void input()
{
    scanf("%d %d",&Nv,&Ne);
    for(int i=0;i<Ne;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[a][b]=Graph[b][a]=1;
    }
    return;
}

int judge()
{
    int K;
    scanf("%d",&K);
    vector<int> store;
    vector<int> origin(MAXN,0);//储存需要判断的集合
    for(int i=0;i<K;i++)
    {
        int temp;
        scanf("%d",&temp);
        store.push_back(temp);
        origin[temp]=1;//在集合里的设为1
    }
    //先判断给定的点是不是clique
    for(int i=0;i<K-1;i++)
    {
        for(int j=i+1;j<K;j++)
        {
            if(Graph[store[i]][store[j]]==1)
                continue;
            else
                return -1;
        }
    }
    //在判断其他点能不能往里加
    for(int i=1;i<=Nv;i++)
    {
        if(origin[i]==0)//对不是集合内的点进行判断
        {
            bool flag=true;
            for(int j=0;j<K;j++)
            {
                if(Graph[i][store[j]]!=1)//该点跟一个不相连就返回false
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return 0;
        }
    }
    return 1;
}

//可以通AC但是相比上面的算法，有一个测试点运行时间偏高
/*
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

#define MAXN 201

using namespace std;

int Graph[MAXN][MAXN];//记录两点之间的距离
int Nv,Ne,M;
vector<set<int>> V;//储存每一个点的所有邻接点

void input();
int judge();

int main()
{
    input();
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++)
    {
        int result=judge();
        switch (result)
        {
            case 1:
                cout<<"Yes"<<endl;
                break;
            case 0:
                cout<<"Not Maximal"<<endl;;
                break;
            case -1:
                cout<<"Not a Clique"<<endl;
                break;
        }
    }
    return 0;
}

void input()
{
    scanf("%d %d",&Nv,&Ne);
    V.resize(Nv+1);
    for(int i=1;i<=Nv;i++)
        V[i].insert(i);
    for(int i=0;i<Ne;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[a][b]=Graph[b][a]=1;
        V[a].insert(b);
        V[b].insert(a);
    }
    return;
}

int judge()
{
    int K;
    scanf("%d",&K);
    set<int> origin;//储存需要判断的集合
    vector<int> store;
    for(int i=0;i<K;i++)
    {
        int temp;
        scanf("%d",&temp);
        origin.insert(temp);
        store.push_back(temp);
    }
    set<int> res=V[store[0]];
    for(int i=1;i<K;i++)
    {
        set<int> temp;
        //计算上一个集合与下一个集合的交集
        //计算集合的交集，使用set_intersection()函数
        //该函数的前四个参数分别是两个集合的开始与结束，最后一个参数是输出结果，放在一个构造的集合内
        //该集合使用inserter()函数构造，两个参数为集合名，与集合开始
        set_intersection(res.begin(), res.end(), V[store[i]].begin(), V[store[i]].end(), inserter(temp,temp.begin()));
        res=temp;
        //此语句可以加快程序判断
        if(res.size()<origin.size())
        {
            return -1;
        }
    }
    if(res==origin)
        return 1;
    else
    {
        for(auto i=origin.begin();i!=origin.end();i++)
        {
            if(find(res.begin(),res.end(),*i)==res.end())//给定序列的元素没法在res中找到，证明不是clique
                return -1;
        }
        return 0;
    }
}
*/
