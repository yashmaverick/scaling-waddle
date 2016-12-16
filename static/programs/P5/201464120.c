#include<stdio.h>

int temp[1000];

void mergesort(int A[],int s, int e)
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
	int test;
	scanf("%d",&test);
	while(test!=0)
	{
		int a[1001];
		int i,j,k,n,m,flag=0;
		char z[100];
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s %d",z,&a[i]);
		mergesort(a,0,n-1);
		for(i=0;i<n-2;i++)
		{
		k=n-1;
			j=i+1;
			while(j<k)
			{
//				printf("%d %d %d %d    ",a[i],a[j],a[k],a[i]+a[j]+a[k]);
				if(a[i]+a[j]+a[k]<m)
					j++;
				else if(a[i]+a[j]+a[k]>m)
					k--;
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			printf("NO\n");
		else
			printf("YES\n");
		test--;
	}
	return 0;
}
