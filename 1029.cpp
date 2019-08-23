//1029 Median
//本题非常之恶心，题目说数字小于long int，实则为int数据类型就可以，但是不能把两个数组全部存放进去，否则最后一个测试用例会内存超限
//不知道考这个内存超限有什么意义，估计是为了考察学生动态处理数据的能力
//因此最多将第一行的所有元素存储起来，第二行每次用一个临时变量来存储队列的头，每次读取完，都进行处理，不占用额外的内存

#include<iostream>
#include<queue>

#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

queue<int> v1;

int main()
{
	int N1,N2,temp;
	//首先将第一行的所有数据存储在一个队列中
	scanf("%d",&N1);
	for(int i=0;i<N1;i++)
	{
		scanf("%d",&temp);
		v1.push(temp);
	}
	//在队列最后加一个无限大整形，之后来比较时更方便（这里是参考网上大神们的写法）
	v1.push(0x7fffffff);
	scanf("%d",&N2);
	int del=(N1+N2-1)/2;//先根据两个队列的大小，记录全部需要删除的元素个数,将前del个数全部删除，之后就可以找到中位数了
	int cnt=0;
	for(int i=0;i<N2;i++)//读取所有v2的元素
	{
		scanf("%d",&temp);
		if(cnt==del)//如果删除个数达到要求，输出当前两个队列头较小的数字为中位数
		{
			cout<<MIN(v1.front(),temp)<<endl;
			return 0;
		}
		//如果第二行数据的头temp，比第一行的前面部分数据大，将第一行前面的数据删除
		while(temp>v1.front())
		{
			v1.pop();//删除v1中的元素
			cnt++;//每删除一次，记录一下
			if(cnt==del)//当删除个数达到要求，输出当前两个队列头较小的数字为中位数
			{
				cout<<MIN(v1.front(),temp)<<endl;
				return 0;
			}
		}
		//如果没有到达要求，删除第二行数据头（即进入下一次读取数据，更新temp）
		cnt++;//删除v2中的元素,继续往后读一位
	}
	//若第二行所有的数字都读取完，但是还没有找到中位数，则在第一行中继续进行寻找
	while(cnt!=del)
	{
		v1.pop();
		cnt++;
		if(cnt==del)
		{
			cout<<v1.front()<<endl;
			return 0;
		}
	}
	return 0;
}

/*
附上写的所有的测试用例

4 11 12 13 14
5 9 10 15 16 17
13

1 1
3 2 3 4
2

3 2 3 4
1 1
2

3 1 3 4
3 2 4 6
3

3 2 4 6
3 1 3 5
3

3 1 4 5
3 2 3 6
3

4 2 3 4 5
1 1
3
*/
