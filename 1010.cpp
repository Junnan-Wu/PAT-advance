//1010 Radix
//this problem has some difficult point
//fisrt there is case which two number is bigger than MAX_INT, so we need to use long long to store two numbers
//second if we use for loop，it will run time out
//third if the base is not unique,we need to find the min_base which is satisfied the request

#include<stdio.h>
#include<string.h>

#define MAXN 11

long long number_to_ten(char*,long long);
long long find_radix(char*,long long);

int main()
{
    char a[MAXN],b[MAXN];
    long long tag,radix;
    scanf("%s %s %lld %lld",&a,&b,&tag,&radix);
    long long res;
    if(tag==1)
    {
        res=find_radix(b, number_to_ten(a,radix));
    }
    else
    {
        res=find_radix(a, number_to_ten(b, radix));
    }
    if(res==-1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%lld\n",res);
    }
    return 0;
}


long long number_to_ten(char *a,long long radix)//calculate the number of char with radix
{
    long long sum=0,len=strlen(a),mul=1;
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            if(a[i]-'0'>=radix)return 0;
            sum+=(a[i]-'0')*mul;
        }
        else
        {
            if(a[i]-'a'+10>=radix)return 0;
            sum+=(a[i]-'a'+10)*mul;
        }
        mul*=radix;
    }
    return sum;
}

long long find_radix(char* a,long long equal)
{
    long long min_radix=2,max_radix;
    long long radix;
    for(int i=0;i<strlen(a);i++)//find the min base
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            min_radix=min_radix>(a[i]-'0')?min_radix:(a[i]-'0'+1);
        }
        else
        {
            min_radix=min_radix>(a[i]-'a'+10)?min_radix:(a[i]-'a'+10+1);
        }
    }
    max_radix=(equal+1)>min_radix?(equal+1):min_radix+1;//find the max base
    while(min_radix<=max_radix)
    {
        radix=(min_radix+max_radix)/2;
        long long sum=number_to_ten(a,radix);
        if(sum<0)
        {
            max_radix=radix-1;
            continue;
        }
        if(sum>equal)
        {
            max_radix=radix-1;
        }
        else if(sum<equal)
        {
            min_radix=radix+1;
        }
        else
        {
            max_radix=radix;
            if(number_to_ten(a, min_radix)==equal)
            {
                return min_radix;
            }
        }
    }
    return -1;
}
