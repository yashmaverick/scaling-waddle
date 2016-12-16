#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpfunc( const void *, const void *);
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int l,i,A[100000],sum=0,cnt=0;
		char c[100000];
		scanf("%s",c);
		l=strlen(c);
		for(i=0;i<l;i++)
		{
			if(c[i]=='J')
				A[i]=10002;
			if(c[i]=='M')
				A[i]=1;
			if(c[i]=='R')
				A[i]=-10003;
		}
		for(i=0;i<l-1;i++)
		{
			A[i+1]+=A[i];
			
		}
		qsort(A, l, sizeof(int), cmpfunc);
		for(i=0;i<l;i++)
		{
			if(A[i-1]==A[i])
				cnt++;
			if(A[i-1]!=A[i]||i==l-1)
			{
				sum+=cnt*(cnt-1)/2;
				cnt=1;
			}
		}
		//printf("intermediate sum -->%d\n",sum);
		for(i=0;i<l;i++)
		{
			if(A[i]==0)
				sum++;
		}
		printf("%d\n",sum);	
	}
	return 0;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
