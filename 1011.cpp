//1011 World Cup Betting

#include<stdio.h>

int main()
{
    double bet[3][3];
    double mul=1;
    for(int i=0;i<3;i++)
    {
        int p=-1;
        double tepmax=-1;
        for(int j=0;j<3;j++)
        {
            scanf("%lf",&bet[i][j]);
            if(tepmax<bet[i][j])
            {
                p=j;
                tepmax=bet[i][j];
            }
        }
        switch(p)
        {
            case 0:
                printf("W ");
                break;
            case 1:
                printf("T ");
                break;
            case 2:
                printf("L ");
                break;
        }
        mul*=tepmax;
    }
    mul=(mul*0.65-1)*2;
    printf("%.2f\n",mul);
    return 0;
}
