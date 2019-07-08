//Emergency
//three points should be careful
//1.how to initialize the array(at the beginning all cities should be setted as not visit)
//2.every moment when shortest distance less than now,update update max_team and dis, when the shortest is same but the max_teams could be more, update max_team,numbers of shortest distance
//3.problem requires us to output the numbers of shortest path! not the shortest distance;

#include<stdio.h>

using namespace std;

#define MAXN 501
#define INF 0x3f3f3f3f

int map[MAXN][MAXN];//map[i][j] represent the distance from city i to city j
int dis[MAXN];//stores the distance from city start to each other city
bool visit[MAXN];//stores wheather visit city i
int N,M;//N is the numbers of cities,M is the number of paths
int teams[MAXN];//teams[i] represents the number of the rescue team i
int start,end;//the city we start and end
int max_team[MAXN];//stores the max rescue from start to the each city
int num[MAXN];//be careful that output is number of different shortest path, not the the shortest distance

void init();
void dijkstra();

int main()
{
    init();
    dijkstra();
    printf("%d %d\n",num[end],max_team[end]);
    return 0;
}

void init()
{
    int x,y;//x,y store the different city
    scanf("%d %d %d %d",&N,&M,&start,&end);
    for(int i=0;i<N;i++)
        scanf("%d",&teams[i]);
    for(int i=0;i<N;i++)//initilize the distance of two cities, if two cities don't connect,the distance of them is INF;
    {
        for(int j=0;j<N;j++)
        {
            if(i!=j)
            {
                map[i][j]=INF;
            }
            else
                map[i][j]=0;
        }

    }
    //record the distance
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&x,&y);
        scanf("%d",&map[x][y]);//distance from x to y
        map[y][x]=map[x][y];
    }
    //initilize the shortest distance array, visit array, max_teams array,numbers of different shortest pathes
    //pay attention to that all visit is false!!!
    //and at the beginning, only max_team[start]=team[start],other cities which are not visited the max_team[i] is 0
    for (int i=0;i<N;i++)
    {
        visit[i]=false;
        dis[i]=map[start][i];
        max_team[i]=0;
        num[i]=0;
    }
    max_team[start]=teams[start];
    num[start]=1;
    return;
}

void dijkstra()//this function can find the shortest distance from start to the other city
{
    while(1)
    {
        int min=INF,index=-1;
        for(int i=0;i<N;i++)
        {
            if(!visit[i])//find not visited city that distance is min
            {
                if(min>dis[i])
                {
                    min=dis[i];
                    index=i;
                }
            }
        }
        if(index==-1)
            break;
        visit[index]=true;//set index city is visited
        for(int i=0;i<N;i++)
        {
            if(map[index][i]!=INF&&!visit[i])//index and i is connected, and city i haven't visited
            {
                if(dis[i]>dis[index]+map[index][i])//if dis from start to i longer than the dis from start to index plus index to i
                {
                    dis[i]=dis[index]+map[index][i];
                    max_team[i]=max_team[index]+teams[i];
                    num[i]=num[index];
                }
                else if(dis[i]==dis[index]+map[index][i])
                {
                    num[i]=num[i]+num[index];//if shortest distance is same,numbers of shortest path plus
                    if(max_team[i]<max_team[index]+teams[i])//and if max_team is less
                        max_team[i]=max_team[index]+teams[i];
                }
            }
        }
    }
    return;
}
