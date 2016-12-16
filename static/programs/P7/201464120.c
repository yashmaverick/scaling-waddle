#include<stdio.h>
#include<string.h>
int temp[1000010];
void mergesort(int A[],int s,long long int e)
{
	if(s==e)
		return;
	mergesort(A,s,(s+e)/2);
	mergesort(A,(s+e)/2+1,e);
	int t1,t2,p=0;
	int mid= (s+e)/2;
	t1=s;
	t2=mid+1;

	while(t1<=mid || t2<=e)
	{
		if(t1>mid)
		{
			temp[p++]= A[t2++];
		}
		else if(t2>e)
		{
			temp[p++]=A[t1++];
		}

		else
		{
			if(A[t1]<A[t2])
				temp[p++]=A[t1++];
			else
				temp[p++]=A[t2++];
		}
	}
	int i;
	for(i=0;i<p;i++)
	{
		A[s+i]=temp[i];
	}
}

int main()
{
	int z;
	scanf("%d",&z);
	while(z!=0)
	{
	long long int n,i,t=0;
	long long int c=0;
	int x[1000010];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);	
	mergesort(x,0,n-1);
	for(i=1;i<=n;i++)
	{
		if(x[i]!=x[i-1])
		{
			c=c+((i-t)*(i-t-1))/2;
			t=i;
		}
	}	
		printf("%lld\n",c);
		z--;
	}
	return 0;
}
