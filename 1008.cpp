//1008 Elevator
//this problem is easy,pay attentino to reading the problem
#include<stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int *list=new int[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&list[i]);
    }
    int cur=0,time=0;
    for(int i=0;i<N;i++)
    {
        if(list[i]>cur)
        {
            time+=(list[i]-cur)*6;
        }
        else
        {
            time+=(cur-list[i])*4;
        }
        cur=list[i];
    }
    time+=5*N;
    printf("%d\n",time);
    return 0;
}
