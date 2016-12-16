#include<stdio.h>
//#include<math.h>

long power(int base, int exp)
{
	if (exp)
	{
		return (base * power(base, exp-1));
	}
	return 1;
}
int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int Q;
		int diameter;
		int level=0;
		scanf("%d", &Q);
		if(Q==1)
			diameter=0;
		else
		{
			int i;
			i=Q;
			do
			{
				i=i/2;
				level ++;
			}while(i != 1);
//			printf("%d\n", level);



			int a, b;
			a=power(2, level);
			b=power(2, level-1);
//			printf("%d\n", a);
//			printf("%d\n", b);

			if( Q>=a+b)
				diameter=(2*level);
			else
				diameter=(2*level)-1;

		}
				printf("%d\n", diameter);
	}
	return 0;
}
