#include<stdio.h>
unsigned long long int heap1[250000],heap2[250000],ptr1,ptr2;
void insert1(unsigned long long int val)
{
	heap1[ptr1]=val;
	unsigned long long int x=ptr1;
	ptr1++;
	while(x>1)
	{
		if(heap1[x]<=heap1[x/2])
			break;
		else
		{
			unsigned long long int temp=heap1[x];
			heap1[x]=heap1[x/2];
			heap1[x/2]=temp;
			x=x/2;
		}
	}
}

void insert2(unsigned long long int val)
{
	heap2[ptr2]=val;
	unsigned long long int x=ptr2;
	ptr2++;
	while(x>1)
	{
		if(heap2[x]>=heap2[x/2])
			break;
		else
		{
			unsigned long long int temp=heap2[x];
			heap2[x]=heap2[x/2];
			heap2[x/2]=temp;
			x=x/2;
		}
	}
}

void deletemax1()
{
	heap1[1]=heap1[ptr1-1];
	ptr1--;
	unsigned long long int x=1;
	while(x<ptr1)
	{
		if(2*x+1>=ptr1)
		{
			if(2*x<ptr1)
			{
				if(heap1[2*x]>heap1[x])
				{
					unsigned long long int temp=heap1[x];
					heap1[x]=heap1[2*x];
					heap1[2*x]=temp;
					x=2*x;
				}
				else
					break;
			}
			else
				break;
		}
		else if(heap1[x]>=heap1[2*x] && heap1[x]>=heap1[2*x+1])
			break;
		else
		{
			if(heap1[2*x]>=heap1[2*x+1])
			{
				unsigned long long int temp=heap1[x];
				heap1[x]=heap1[2*x];
				heap1[2*x]=temp;
				x=2*x;
			}
			else
			{
				unsigned long long int temp=heap1[x];
				heap1[x]=heap1[2*x+1];
				heap1[2*x+1]=temp;
				x=2*x+1;
			}
		}
	}
}

void deletemin2()
{
	heap2[1]=heap2[ptr2-1];
	ptr2--;
	unsigned long long int x=1;
	while(x<ptr2)
	{
		if(2*x+1>=ptr2)
		{
			if(2*x<ptr2)
			{
				if(heap2[2*x]<heap2[x])
				{
					unsigned long long int temp=heap2[x];
					heap2[x]=heap2[2*x];
					heap2[2*x]=temp;
					x=2*x;
				}
				else
					break;
			}
			else
				break;
		}
		else if(heap2[x]<=heap2[2*x] && heap2[x]<=heap2[2*x+1])
			break;
		else
		{
			if(heap2[2*x]<=heap2[2*x+1])
			{
				unsigned long long int temp=heap2[x];
				heap2[x]=heap2[2*x];
				heap2[2*x]=temp;
				x=2*x;
			}
			else
			{
				unsigned long long int temp=heap2[x];
				heap2[x]=heap2[2*x+1];
				heap2[2*x+1]=temp;
				x=2*x+1;
			}
		}
	}
}

int main()
{
	unsigned long long int t,a,b,c,n,x,ans,i,j,k,f,m;
	scanf("%llu",&t);
	while(t--)
	{
		ptr1=1;
		ptr2=1;
		scanf("%llu%llu%llu%llu",&a,&b,&c,&n);
		heap1[1]=1;
		ptr1++;
		f=heap1[1];
		ans=f;
		m=heap1[1];
		for(i=2;i<=n;i++)
		{
			f=(a*m%1000000007+b*i%1000000007+c%1000000007)%1000000007;
			ans=ans+f;
			if(i%2==0)
			{
				if(f<heap1[1])
				{
					unsigned long long int x=heap1[1];
					heap1[ptr1]=f;
					ptr1++;
					deletemax1();
					insert2(x);
				}
				else
					insert2(f);
				m=heap1[1];
			}
			else
			{
				if(f>heap2[1])
				{
					unsigned long long int x=heap2[1];
					insert1(x);
					heap2[ptr2]=f;
					ptr2++;
					deletemin2();
				}
				else
					insert1(f);
				m=heap1[1];
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}

					

