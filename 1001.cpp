//1001 A+B Format
//because A and B is between a and b where −10^6-10^6
//so A+B is between -2*10^6 and 2*10^6, that is -2,000,000
//so three numbers are enough to represent the sum of A and B
#include "stdio.h"

int main()
{
  int a,b;
  scanf("%d %d",&a,&b);
  int c=a+b;
  //int c=103213;
  bool flag=(c>=0);//because remainder operation may have erro for the negative numbers
  //so we need to flag wheather the sum is negative and change the negative to positive
  if(!flag)
    c=-c;
  int n1,n2,n3;//three number to represent the sum
  n3=c%1000;n2=c/1000%1000;n1=c/1000000%1000;
  if(!flag)
    printf("-");
  if(n1!=0)
  {
    printf("%d,%03d,%03d\n",n1,n2,n3);
  }
  else if(n2!=0)
  {
    printf("%d,%03d\n",n2,n3);
  }
  else
  {
    printf("%d\n",n3);
  }
  return 0;
}
