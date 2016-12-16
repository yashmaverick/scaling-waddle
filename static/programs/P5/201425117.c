#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *, const void *);
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,K,i=0,flag=0;
		scanf("%d %d",&n,&K);
		int A[n];
		char c[100000];
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&A[i]);
		}
		qsort(A, n, sizeof(int), cmpfunc);
		for(i=0;i<n;i++)
		{
			int j=i+1,k=n-1;
			while(j<k)
			{
				if(A[i]+A[j]+A[k]>K)
					k--;
				else if(A[i]+A[j]+A[k]<K)
					j++;
				else if(A[i]+A[j]+A[k]==K)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");				
	}
	return 0;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
