#include<stdio.h>
int l;
long long  int ptr1=1,ptr2=1;
void swap(long long int m,long long int n,long long int a[])
{
	if(m>=ptr1&&n>=ptr1)
		return ;
	int temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
long long int min(long long int m,long long int n,long long int a[])
{
	if(m>=ptr1)
		return n;
	else if(n>=ptr1)
		return m;
	else
	{
		if(a[m]<a[n])
			return m;
		return n;
	}
}
void refresh1(long long int p,long long int a[])
{
	if(p==0)
		return;
	if(a[p]<a[p/2])
	{
		swap(p,p/2,a);
		refresh1(p/2,a);
	}
}
void refresh2(long long int p,long long int a[])
{
	if(p==0)
		return;
	if(2*p<ptr1)
	{
		long long int r=min(2*p,2*p+1,a);
		if(a[r]<a[p])
		{
			swap(r,p,a);
			refresh2(r,a);
		}
	}
}
void delete(long long int a[])
{
	a[1]=a[ptr1-1];
	a[ptr1-1]=-1;
	ptr1--;
	refresh2(1,a);
}
void insert(long long int a[],long long int s)
{
	a[ptr1]=s;
	ptr1++;
	refresh1(ptr1-1,a);
}
void swap1(long long int m,long long int n,long long int a[])
{
	if(m>=ptr2&&n>=ptr2)
		return ;
	long long int temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
long long int max(long long int m,long long int n,long long int a[])
{
	if(m>=ptr2)
		return n;
	else if(n>=ptr2)
		return m;
	else
	{
		if(a[m]<a[n])
			return n;
		return m;
	}
}
void refresh1m(long long int p,long long int a[])
{
	if(p==0)
		return;
	if(a[p]>a[p/2])
	{
		swap1(p,p/2,a);
		refresh1m(p/2,a);
	}
}
void refresh2m(long long int p,long long int a[])
{
	if(p==0)
		return;
	if(2*p<ptr2)
	{
		int r=max(2*p,2*p+1,a);
		if(a[r]>a[p])
		{
			swap1(r,p,a);
			refresh2m(r,a);
		}
	}
}
void deletem(long long int a[])
{
	a[1]=a[ptr2-1];
	ptr2--;
	refresh2m(1,a);
}
void insertm(long long int a[],long long int s)
{
	a[ptr2]=s;
	ptr2++;
	refresh1m(ptr2-1,a);
}
int main()
{
	int test;
	scanf("%d",&test);
	long long int a[300000];
	long long int b[300000];
	long long int arr[300000];
	while(test--)
	{
		ptr1=ptr2=1;;
		long long int k,p1,p2,p3;
		scanf("%lld %lld %lld %lld",&p1,&p2,&p3,&k);
		a[0]=-100;
		b[0]=10000000000;
		long long int count=1;
		int i;
		for(i=0;i<k-1;i++)
		{
			if(i==0)
			{
				a[1]=1;
				arr[i]=1;
				ptr1++;
			}
			else
			{
				if(ptr2!=1&&arr[i]>b[1]||arr[i]>a[1])
				{
					insert(a,arr[i]);
					if(ptr1-ptr2>1)
					{
						insertm(b,a[1]);
						delete(a);
					}
					else if(ptr2-ptr1>1)
					{
						insert(a,b[1]);
						deletem(b);
					}
				}
				else
				{
					insertm(b,arr[i]);
					if(ptr1-ptr2>1)
					{
						insertm(b,a[1]);
						delete(a);
					}
					else if(ptr2-ptr1>1)
					{
						insert(a,b[1]);
						deletem(b);
					}
				}
			}
			long long int med,l;
			if(ptr1>ptr2)
				med=a[1];
			else
				med=b[1];
			arr[i+1]=((p1*med)%1000000007+(p2*(i+2))%1000000007+p3%1000000007)%1000000007;
			count+=arr[i+1];
		}
		printf("%lld\n",count);
	}
	return 0;
}
