//Counting Leaves
//the important thing is how to construct the node struct

#include<stdio.h>

#define MAXN 100

int N,M;//the number of nodes in a tree,the number of non-leaf nodes.
bool falg=true;

struct node
{
    int level;
    int num;//numbers of this node's children
    int *child;//the array store its child
};

node family[MAXN];
int queue[MAXN],pt=1;


void init();
void BFS();
void output();

int main()
{
    init();
    BFS();
    output();
    return 0;
}

void init()
{
    scanf("%d %d",&N,&M);
    if(N==0)
    {
        falg=false;
        return;
    }
    for(int i=1;i<=N;i++)
    {
        family[i].level=0;
        family[i].num=0;
    }
    for(int i=0;i<M;i++)
    {
        int ID,K,temp;scanf("%d %d",&ID,&K);
        family[ID].num=K;
        family[ID].child=new int[K];//new its child array
        for(int i=0;i<K;i++)
        {
            scanf("%d",&temp);
            family[ID].child[i]=temp;
        }
    }
    return;
}

void BFS()
{
    queue[pt++]=1;
    for(int i=1;i<pt;i++)//while queue not empty
    {
        for(int j=0;j<family[queue[i]].num;j++)//for all children of the element of head of queue
        {
            int child=family[queue[i]].child[j];//head node's j th child
            queue[pt++]=child;
            family[child].level=family[i].level+1;
        }
    }
    return;
}

void output()
{
    if(!falg)
        return;
    int max=0;
    for(int i=1;i<=N;i++)//calculate the max level of the tree
    {
        max=max>family[i].level?max:family[i].level;
    }
    int *level=new int[max+1];//level[i] stores leaf node of i level
    for(int i=1;i<=N;i++)
    {
        if(family[i].num==0)
        {
            level[family[i].level]++;
        }
    }

    for(int i=0;i<max+1;i++)
    {
        if(i==0)
            printf("%d",level[i]);
        else
            printf(" %d",level[i]);
    }
    printf("\n");
    return;
}
