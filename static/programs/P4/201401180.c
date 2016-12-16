#include <stdio.h>
#include <string.h>
long long int cmpfunc (const void * a, const void * b)
{
	   return ( *(long long int*)a - *(long long int*)b );
}
int main()
{
	int t1;
	scanf("%d",&t1);
	while(t1--)
	{
		char s[100000];
		scanf(" %s",s);
		int i;
		long long int jmr[100000];
		long long int x,y,z;
		x = 10000;
		y = 1;
		z = -10001;
		int len = strlen(s);
		len++;
		/*if (s[0] == 'J')
			jmr[0] = 1;
		else if (s[0] == 'M')
			jmr[0] = 2;
		else
			jmr[0] = -3;*/
		jmr[0] = 0;
		for (i = 1; i < len; i++)
		{
			if (s[i-1] == 'J')
				jmr[i] = jmr[i-1]+x;
			else if (s[i-1] == 'M')
				jmr[i] = jmr[i-1]+y;
			else if (s[i-1] == 'R')
				jmr[i] = jmr[i-1]+z;
		}
		long long int t=1;long long int ans=0;
		/*for (i = 0; i < len; i++)
			printf("%lld ",jmr[i]);
		printf("\n");*/
		qsort(jmr,len,sizeof(long long int),cmpfunc);
		/*for (i = 0; i < len; i++)
			printf("%lld ",jmr[i]);
		printf("\n");*/
		for (i = 1; i < len; i++)
		{
			if (jmr[i] == jmr[i-1])
				t++;
			else
			{
				ans = ans + t*(t-1)/2;
				t = 1;
			}
		}
	//	printf("t = %lld\n",t);
	//	printf("%lld\n",(t*(t-1))/2);
		printf("%lld\n",ans +(t*(t-1)/2));
	}
	return 0;
}	

