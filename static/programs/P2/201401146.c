#include<stdio.h>
int L;
void bin_SL(int *a,int low,int high,int k)
{
	if(low>high||k>a[high])
		return;
	if(k<=a[low])
	{
		L=low;
		return;
	}
	int mid=(low+high)/2;
	if(k<=a[mid])
	{
		L=mid;
		bin_SL(a,low,mid-1,k);
	}
	else
		bin_SL(a,mid+1,high,k);
}
int main()
{
	int t,p,q,r,i,j;
	long long int s;
	int A[100000],B[100000],C[100000];
	scanf("%d",&t);
	while(t--)
	{
		long long int sat[100002]={0};
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%d",&A[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%d",&B[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%d",&C[i]);
		s=0;
		for(j=q-1;j>=0;j--)
		{
			L=-1;
			bin_SL(C,j,r-1,B[j]);
			if(L==-1)
				sat[j]=0;
			else
			 	sat[j]=r-L+sat[j+1];
		}
		for(i=0;i<p;i++)
		{
			L=-1;
			bin_SL(B,i,q-1,A[i]);
			if(L==-1)
				break;
			s=s+sat[L];
		}
		printf("%lld\n",s);
	}
	return 0;
}
