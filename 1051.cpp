//1051 Pop Sequence
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int M,N,K;//M是栈最大个数，N是push队列长度，K是测试用例个数

bool judge(queue<int> q);

int main()
{
    scanf("%d %d %d",&M,&N,&K);
    for(int test=0;test<K;test++)
    {
        queue<int> q;
        for(int i=0;i<N;i++)
        {
            int temp;
            scanf("%d",&temp);
            q.push(temp);
        }
        if(judge(q))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
//根据队列来判断是否是一次栈的pop结果
bool judge(queue<int> q)
{
    stack<int> s;
    int num=1;//依次要往stack中push元素，从1开始
    while(1)//循环判断
    {
        //如果栈为空，或者栈顶元素不是队列的头元素，往栈内依次push
        while(s.empty()||s.top()!=q.front())
        {
            //栈满了，但是队列头元素还不等于栈顶元素，返回false
            if(s.size()==M)return false;
            //不满则push到栈顶元素为队列头元素为止
            s.push(num++);
        }
        //如果栈不空且顶元素为队列头元素
        s.pop();
        q.pop();
        //一旦所有元素都比对过，q为空，证明是一次pop方法，返回true
        if(q.empty())
            return true;
    }
}
