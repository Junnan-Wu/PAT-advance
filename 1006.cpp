//1006 Sign In and Sign Out
//the key to this problem is how to compare two time, we use three variable h,m,s to record hour,minutes,second
//then set t as h*10000+m*100+s, and we only need to compare two ts
//at same time, we update closetime and opentime when input the data,and record the person who locked door and unlocked door

#include<stdio.h>
#include<string.h>

int main()
{
    int M;//the number of the students
    scanf("%d",&M);
    int opentime=999999,closetime=0;//record current min opentime and maxtime
    char unlockedp[16],lockedp[16],temp[16];
    for(int i=0;i<M;i++)
    {
        int h1,m1,s1,h2,m2,s2,t1,t2;
        scanf("%s %d:%d:%d %d:%d:%d",temp,&h1,&m1,&s1,&h2,&m2,&s2);
        t1=h1*10000+m1*100+s1;
        t2=h2*10000+m2*100+s2;
        if(t1<opentime)
        {
            opentime=t1;
            strcpy(unlockedp,temp);
        }
        if(t2>closetime)
        {
            closetime=t2;
            strcpy(lockedp,temp);
        }
    }
    printf("%s %s\n",unlockedp,lockedp);
    return 0;
}
