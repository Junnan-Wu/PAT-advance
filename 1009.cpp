//1009 Product of Polynomials
//first we need an array p[0],p[1] to store the exponents of two Polynomials
//then we need three arraies ploy[0],poly[1],poly[2] to store the coeffients.
//and at end,we need an array K to store the numbers of non-zero terms of each Polynomials

#include<stdio.h>

#define MAXK 2001

int main()
{
    double poly[3][MAXK]={0};//pay attention to initialize the array
    int K[2];int *p[2];
    for(int i=0;i<2;i++)
    {
        scanf("%d",&K[i]);
        p[i]=new int[K[i]];
        for(int j=0;j<K[i];j++)
        {
            scanf("%d",&p[i][j]);
            scanf("%lf",&poly[i][p[i][j]]);
        }
    }
    for(int i=0;i<K[0];i++)
    {
        for(int j=0;j<K[1];j++)
        {
            poly[2][p[0][i]+p[1][j]]+=poly[0][p[0][i]]*poly[1][p[1][j]];
        }
    }
    int count=0;
    for(int i=0;i<MAXK;i++)
    {
        if(poly[2][i]!=0)
            count++;
    }
    printf("%d",count);
    for(int i=MAXK-1;i>=0;i--)
    {
        if(poly[2][i]!=0)
            printf(" %d %.1f",i,poly[2][i]);
    }
    printf("\n");
    return 0;
}
