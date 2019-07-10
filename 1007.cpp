#include<stdio.h>

#define MAXK 10001

int num[MAXK];

int main()
{
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++)
        scanf("%d",&num[i]);
    int st=0,ed=0,i=0,tep=0;//record the start and end of subsequence,i is current point，tep is the temporary start
    int max=-1,cur=0;//define three point
    while(i<K)
    {
        cur+=num[i];
        if(cur>max)
        {
            max=cur;
            ed=i;
            st=tep;
        }
        else if(cur<0)
        {
            tep=i+1;
            cur=0;
        }
        i++;
    }
    if(max==-1)
    {
        max=0;st=0;ed=K-1;
    }
    printf("%d %d %d\n",max,num[st],num[ed]);
    return 0;
}
