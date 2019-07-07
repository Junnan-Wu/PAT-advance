//A+B for Polynomials
//because N1 and N2 is between 0-1000, so be careful of the MAXK is 1001
//we use two lines of array to store the Polynomials

#include<stdio.h>

#define MAXK 1001

double coefficients[2][MAXK];//store two lines of exponents and coefficients,index is exponent and value is coefficient
int K;
void init();
void process();


int main()
{
    init();
    process();
    return 0;
}

void init()
{
    //initialize coefficients array
    for(int i=0;i<2;i++)
        for(int j=0;j<MAXK;j++)
            coefficients[i][j]=0;
    int temp;
    for(int i=0;i<2;i++)//put the number to two int[]
    {
        scanf("%d",&K);
        for(int j=0;j<K;j++)
        {
            scanf("%d",&temp);
            scanf("%lf",&coefficients[i][temp]);
        }
    }
    return;
}

void process()
{
    int count=0;
    for (int i=0; i<MAXK; i++)
    {
        coefficients[0][i]+=coefficients[1][i];
        if(coefficients[0][i]!=0)//recording the count of the nonezero terms
            count++;
    }
    printf("%d",count);
    for(int i=MAXK-1;i>=0;i--)
    {
        if(coefficients[0][i]!=0)
            printf(" %d %.1lf",i,coefficients[0][i]);
    }
    printf("\n");
    return;
}
