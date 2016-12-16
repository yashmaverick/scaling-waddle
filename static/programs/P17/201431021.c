#include<stdio.h>
int main()
{
	int i, j, k, a[100000], b[100000];
	scanf("%d", &j);
	for (i = 0; i < j; i++)
	{
		scanf("%d", &b[i]);
	}
	for ( i = 0; i < j; i++)
	{
		scanf("%d", &a[i]);
	}
	int t, p, q, val1, val2;
	scanf("%d", &t);
	for ( i = 0; i < t; i++)
	{
		int test,test2,test3;
		scanf("%d %d", &p, &q);
		for ( test= 0;test < j; test++)
		{
			if (a[test] == p)
			{
				val1 = test;
				break;
			}
		}
		for ( test = 0; test < j; test++)
		{
			if (a[test]==q)
			{
				val2 = test;
				break;
			}
		}
		if (val1<val2)
		{
			for (test2 = 0; test2 < j; test2++)
			{
				int flag = 0;
				for ( test3 = val1; test3 <= val2; test3++)
				{
					if (b[test2] == a[test3])
					{
						printf("%d\n", a[test3]);
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					break;

			}
		}
		else
		{
				for (test2 = 0; test2 < j; test2++)
			{
				int flag1 = 0;
				for ( test3 = val2; test3 <= val1; test3++)
				{
					if (b[test2] == a[test3])
					{
						flag1 = 1;
						printf("%d\n", a[test3]);
						break;
					}
				}
				if (flag1 == 1)
					break;
			}
		}

	}
	return 0;
}
