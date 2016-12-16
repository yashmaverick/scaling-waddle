#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
inline long long int nC2(long long int n)
{
	return n*(n-1)/2;
}
int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	while(test--)
	{
		int c;
		int *a;
		int i,j;
		char s[100000];
		scanf("%s",s);
		a=(int*)malloc(strlen(s)*sizeof(int));
		long long int sum=0;
		long long int count=0;
		i=0;
		while(i<strlen(s))
		{
			c=s[i];
			if(c=='J')
				sum+=100000;
			else if(c=='M')
				sum+=-100001;
			else
				sum+=1;
			a[i++]=sum;
			if(a[i-1]==0)
				count++;
		}
		int counta=0;
		qsort(a, i, sizeof(int), cmpfunc);
		long long int b;
		b=a[0];
		for(j=1;j<i;j++)
		{
			if(a[j]==b)
				counta++;
			else
			{
				count+=nC2(counta+1);
				counta=0;
				b=a[j];
			}
		}
		if(a[i-1]==a[i-2])
			count+=nC2(counta+1);
		printf("%lld\n",count);
	}
	return 0;
}


