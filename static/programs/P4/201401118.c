#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,count,c;
		char s[100000];
		int a[100000];
		scanf("%s",s);
		count=0;
		n=strlen(s);
		for(i=0;i<n;i++)
		{
			if(s[i]==74)
				a[i]=100001;
			if(s[i]==82)
				a[i]=1;
			if(s[i]==77)
				a[i]=-100002;
		}
		for(i=1;i<n;i++)
			a[i]=a[i-1]+a[i];
		for(i=0;i<n;i++)
		{
			if(a[i]==0)
				count++;
		}
		qsort(a, n, sizeof(int), cmpfunc);
	

		c=1;
		for(i=0;i<n;i++)
		{
			if(a[i]==a[i+1])
				c++;
			if(a[i]!=a[i+1])
			{
			
				count+=(c*(c-1))/2;
				c=1;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
