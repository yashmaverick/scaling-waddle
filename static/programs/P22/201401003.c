#include<stdio.h>
#include<stdlib.h>
#define INF 100000000000
#define MOD 1000000007
long long int max[200009],min[200009],len=0,len1=0,len2=0;
void shuffle_up_min(long long int x)
{
	long long int temp;
	while(min[x]<min[x/2])
	{
		temp=min[x];
		min[x]=min[x/2];
		min[x/2]=temp;
		x=x/2;
	}
	return ;
}
void shuffle_down_min(long long int x)
{
	long long int temp,p;
	while(((2*x)<=len2 && min[2*x]<min[x]) || (((2*x)+1)<=len2 && min[(2*x)+1]<min[x]))
	{
		if(min[2*x]<min[(2*x)+1])
			p=2*x;
		else
			p=(2*x)+1;
		temp=min[p];
		min[p]=min[x];
		min[x]=temp;
		x=p;
	}
	return ;
}
void shuffle_up_max(long long int x)
{
	long long int temp;
	while(max[x]>max[x/2])
	{
		temp=max[x];
		max[x]=max[x/2];
		max[x/2]=temp;
		x=x/2;
	}
	return ;
}
void shuffle_down_max(long long int x)
{
	long long int temp,p;
	while(((2*x)<=len1 && max[2*x]>max[x]) || (((2*x)+1)<=len1 && max[(2*x)+1]>max[x]))
	{
		if(max[2*x]>max[(2*x)+1])
			p=2*x;
		else
			p=(2*x)+1;
		temp=max[p];
		max[p]=max[x];
		max[x]=temp;
		x=p;
	}
	return ;
}
long long int delete_min()
{
	long long int p=min[1];
	min[1]=min[len2--];
	shuffle_down_min(1);
	return p;
}
long long int delete_max()
{
	long long int p=max[1];
	max[1]=max[len1--];
	shuffle_down_max(1);
	return p;
}
void insert_min(long long int x)
{
	min[++len2]=x;
	shuffle_up_min(len2);
	return ;
}
void insert_max(long long int x)
{
	max[++len1]=x;
	shuffle_up_max(len1);
	return ;
}
void insert(long long int x)
{
	long long int y;
	if(len%2==0)
	{
		if(len>0 && x>=min[1])
		{
			insert_min(x);
			y=delete_min();
			insert_max(y);
		}
		else if(len>0)
		{
			insert_max(x);
			y=delete_max();
			insert_min(y);
			y=delete_min();
			insert_max(y);
		}
		else
			insert_max(x);
	}
	else
	{
		if(x>=min[1])
		{
			insert_min(x);
		}
		else
		{
			insert_max(x);
			y=delete_max();
			insert_min(y);
		}
	}
	len++;
	return ;
}
long long int median()
{
	return max[1];
}
int main()
{
	long long int n,x,i,j,t,ans,a,b,c,y;
	scanf("%lld",&t);
	while(t--)
	{
		max[0]=INF;
		min[0]=-INF;
		len=0;
		len1=0;
		len2=0;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		insert(1);
		ans=1;
		for(i=2;i<=n;i++)
		{
			x=max[1];
			y=((a*x)+(b*i)+c)%MOD;
			ans+=y;
			insert(y);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
