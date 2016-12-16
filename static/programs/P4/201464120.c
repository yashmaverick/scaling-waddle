#include<stdio.h>
#include<string.h>
int temp[100010];

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
	int d=0,n,i;
	int t=0;
	long long int c=0;
	char a[100010];
	scanf("%s",a);
	n=strlen(a);
	int x[100010];
	a[n]='\0';
	for(i=0;i<n;i++)
	{
		if(a[i]=='J')
			x[i]=100001;
		if(a[i]=='M')
			x[i]=1;
		if(a[i]=='R')
			x[i]=-100002;
	}
	for(i=1;i<n;i++)
		x[i]=x[i-1]+x[i];	
	mergesort(x,0,n-1);
	for(i=0;i<n;i++)
	{
		if(x[i]==0)
			d++;
	}
	
	for(i=1;i<=n;i++)
	{
		if(x[i]!=x[i-1])
		{
			c=c+((i-t)*(i-t-1))/2;
			t=i;
		}
	}	
	c=c+d;
		printf("%lld\n",c);
		test--;
	}
	return 0;
}

