#include <stdio.h>
#include <stdlib.h>
#define MAX 1000007
#define s(n) scanf("%d",&n)
#define f0(n) int i;for(i=0;i<n;i++)
int A[MAX];

int main()
{
	int t,i,n,k,a,b,j;
	s(n);
	int *pre=(int*)malloc(sizeof(int)*n);
	int *ino=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		s(pre[i]);
	for(i=0;i<n;i++)
		s(ino[i]);
	s(t);
	for(i=0;i<t;i++)
	{
		s(a);s(b);
		int f=0,i1,i2;
		for(j=0;j<n;j++)
		{
			if(f==2)
				break;
			if(ino[j]==a)
			{	i1=j;f++;}
			if(ino[j]==b)
			{	i2=j;f++;}
		}
		if(i1>i2)
		{
			int t=i1;
			i1=i2;
			i2=t;
		} 
		for(j=i1;j<=i2;j++)
			A[ino[j]]=1;
		int p;
		for(j=0;j<n;j++)
			if(A[pre[j]]==1)
			{
				p=pre[j];
				break;
			}
		printf("%d\n",p);
		memset(A,0,sizeof(A)/sizeof(int));
	}

	return 0;
}