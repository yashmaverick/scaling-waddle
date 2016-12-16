#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	int t,A[1001];
	//char S[500];
	scanf("%d",&t);
	while(t--)
	{
		int FLAG=0;
		int n,k,i,l,r;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{	
			//	scanf("%s",S);
			while(getchar()!=' ')
			{}
			scanf("%d",&A[i]);
			//	sum=sum+A[i];
		}
		qsort(A, n, sizeof(int), cmpfunc);
		for(i=0;i<n;i++)
		{
			l=i+1;
			r=n-1;
			while(l<r)
			{
				if(A[i]+A[l]+A[r]==k)
				{       
					FLAG=1;
					break;
				}
				else if(A[i]+A[l]+A[r]<k)
					l++;
				else
					r--;
			}
		}
		if(FLAG==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
