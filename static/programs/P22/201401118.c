#include<stdio.h>
#define mod 1000000007
long long int a,b,c,n,med=1,ans,sum=0,max[100010],min[100010],rmax=1,rmin=1;
long long int add(long long int x, long long int y,long long int z)
{
	return (x + y + z)%mod;
}
long long int prod(long long int x,long long int y)
{
	return  (x*y);
}
void maxheap();
void minheap();
void insert(long long int k)
{
	long long int ans;
//	printf("med=%lld\n",med);
	ans=add(prod(a,med),prod(b,k),c);
//	printf("ans=%lld\n",ans);
	sum+=ans;
	if(ans>med)
	{
		rmin++;
		min[rmin]=ans;
		minheap();
	}
	else if(ans<=med)
	{
		rmax++;
		max[rmax]=ans;
		maxheap();
	}
	return;
}
void delmin()
{
	long long int k,j,s,t;
	k=min[1];
	rmax++;
	max[rmax]=k;
	min[1]=min[rmin];
	rmin--;
	j=1;
	while(j<=rmin/2)
	{
		s=2*j;
		if(2*j+1<=rmin)
		{
			if(min[2*j]>min[2*j+1])
				s=2*j+1;
		}
		if(min[s]<min[j])
		{	
			t=min[s];
			min[s]=min[j];
			min[j]=t;
		}
		j=s;
	}
	return;
}
void delmax()
{
	long long int k,j,s,t;
	k=max[1];
	rmin++;
	min[rmin]=k;
	max[1]=max[rmax];
	rmax--;
	j=1;
	while(j<=rmax/2)
	{
		s=2*j;
		if(2*j+1<=rmax)
		{
			if(max[2*j]<max[2*j+1])
				s=2*j+1;
		}
		if(max[s]>max[j])
		{
			t=max[s];
			max[s]=max[j];
			max[j]=t;
		}
		j=s;
	}
	return;
}
void minheap()
{
	long long int j,b;
	j=rmin;
	while(j>1)
	{
		if(min[j]<min[j/2])
		{
			b=min[j];
			min[j]=min[j/2];
			min[j/2]=b;
		}
		j=j/2;
	}
	return;
}
void maxheap()
{
	long long int j,b;
	j=rmax;
	while(j>1)
	{
		if(max[j]>max[j/2])
		{
			b=max[j];
			max[j]=max[j/2];
			max[j/2]=b;
		}
		j=j/2;
	}
	return;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		ans=add(prod(a,med),prod(b,2),c);
		if(ans<med)
		{
			max[1]=ans;
			min[1]=med;
			med=ans;
		}
		else
		{
			max[1]=med;
			min[1]=ans;
		}
		sum+=ans;
		for(i=3;i<=n;i++)
		{
//			printf("min:\n");
//			for(i=1;i<=rmin;i++)
//				printf("%lld\n",min[i]);
//			printf("\nmax:\n");
//			for(i=1;i<=rmax;i++)
//				printf("%lld\n",max[i]);
//			printf("\n");
			insert(i);
			if(rmin>rmax+1)
			{
				delmin();
				maxheap();
			}
			else if(rmax>rmin+1)
			{
				delmax();
				minheap();
			}
			if(rmin>rmax)
				med=min[1];
			else if(rmax>=rmin)
				med=max[1];		
		}
		printf("%lld\n",sum+1);
		rmin=rmax=1;
		sum=0;
		med=1;
	}
	return 0;
}
