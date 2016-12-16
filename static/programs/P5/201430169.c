#include<stdio.h>
void sort(long long int A[], long long int n)
{
	long long int i,j,t;//printf("inside sort fn\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(A[j+1]<A[j])
			{
				t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
	/*for(i=0;i<n;i++)
		printf("%lld ",A[i]);
	printf("\n");*/
	return;
}		
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int A[100000],n,k,i,j,p,q,flag=0;
		char s[500];
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%s %lld",s,&A[i]);
		sort(A,n);
	/*	for(i=0;i<n;i++)
			printf("%lld ",A[i]);
		printf("\n");*/
		for(i=0;i<n-2;i++)
		{
			p=i+1;
			q=n-1;
			while(p<q)
			{
				if(A[i]+A[p]+A[q]==k)
				{
					flag=1;
					//printf(" i=%lld p=%lld q=%lld ",i,p,q);
					break;
				}
				else if(A[i]+A[p]+A[q]>k)
					q-=1;
				else
					p+=1;
			}
			if(flag)
				break;
		}
		//printf("\n");
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");		
	}
	return 0;
}
