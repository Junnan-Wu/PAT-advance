//1058 A+B in Hogwarts
#include<iostream>

using namespace std;

int main()
{
	int G1, S1, K1, G2, S2, K2;
	scanf("%d.%d.%d %d.%d.%d", &G1, &S1, &K1, &G2, &S2, &K2);
	G1 += G2; S1 += S2; K1 += K2;
	if (K1>=29)
	{
		S1++;
		K1 -= 29;
	}
	if(S1>=17)
	{
		G1++;
		S1 -= 17;
	}
	printf("%d.%d.%d\n", G1, S1, K1);
	return 0;
}
