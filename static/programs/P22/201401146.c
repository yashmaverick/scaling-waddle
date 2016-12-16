#include<stdio.h>
long long int max_H[200005],min_H[200005];
long long int max,min,mod=1000000007;
void reset()
{
	max=0;
	min=0;
	return;
}
void del_max()
{
	if(max==0)return;
	max_H[1]=max_H[max--];
	long long int i=1,t;
	while(i<=max)
	{
		if(2*i>max)break;
		else if(2*i + 1>max){
			if(max_H[i]<max_H[2*i]){
				t=max_H[2*i];
				max_H[2*i]=max_H[i];
				max_H[i]=t;
				i*=2;
			}
			else break;
		}
		else{
			if(max_H[2*i]<max_H[i]&&max_H[2*i+1]<max_H[i])break;
			else if(max_H[2*i]>max_H[2*i+1])
			{
				t=max_H[2*i];
				max_H[2*i]=max_H[i];
				max_H[i]=t;
				i*=2;
			}
			else
			{
				t=max_H[(2*i)+1];
				max_H[(2*i)+1]=max_H[i];
				max_H[i]=t;
				i=(i*2)+1;
			}
		}
	}
	return;
}
void del_min()
{
	if(min==0)return;
	min_H[1]=min_H[min--];
	long long int i=1,t;
	while(i<=min)
	{
		if(2*i>min)break;
		else if(2*i+1>min){
			if(min_H[2*i]<min_H[i]){
				t=min_H[2*i];
				min_H[2*i]=min_H[i];
				min_H[i]=t;
				i*=2;
			}
			else break;
		}
		else{
			if(min_H[2*i]>min_H[i]&&min_H[2*i+1]>min_H[i])break;
			if(min_H[2*i]<min_H[(2*i)+1])
			{
				t=min_H[2*i];
				min_H[2*i]=min_H[i];
				min_H[i]=t;
				i*=2;
			}
			else
			{
				t=min_H[(2*i)+1];
				min_H[(2*i)+1]=min_H[i];
				min_H[i]=t;
				i=(i*2)+1;
			}
		}
	}
	return;
}
void insert_max(long long int x)
{
	long long int i,t;
	max++;
	i=max;
	max_H[i]=x;
	while(i!=1 && max_H[i/2]<max_H[i])
	{
		t=max_H[i];
		max_H[i]=max_H[i/2];
		max_H[i/2]=t;
		i=i/2;
	}
	return;
}
void insert_min(long long int x)
{
	long long int i,t;
	min++;
	i=min;
	min_H[i]=x;
	while(i!=1 && min_H[i/2]>min_H[i])
	{
		t=min_H[i];
		min_H[i]=min_H[i/2];
		min_H[i/2]=t;
		i=i/2;
	}
	return;
}
long long int comp(long long int x,long long int a,long long int b,long long int c,long long int M)
{
	return (a*M + b*x +c)%mod;
}
void print()
{
	long long int i;
	printf("Max\n");
	for(i=1;i<=max;i++)
		printf("%lld ",max_H[i]);
	printf("\n");
	printf("Min\n");
	for(i=1;i<=min;i++)
		printf("%lld ",min_H[i]);
	printf("\n");
	return;
}
long long int find_med(long long int a,long long int b,long long int c,long long int n)
{
	long long int i,t;
	insert_max(1);
	long long int sum=1,med;
	for(i=2;i<=n;i++)	
	{
		if(max==min || max-min==1)
			med=max_H[1];
		else 
			med=min_H[1];
		t=comp(i,a,b,c,med);
		sum+=t;
		//print();
		//printf("med:%lld\n",med);
		//printf("f(%lld): %lld\n",i,t);
		//printf("_________________\n");
		if(t>=max_H[1])
			insert_min(t);
		else
			insert_max(t);
		if(max-min>1)
		{
			insert_min(max_H[1]);
			del_max();
		}
		else if(min-max>1)
		{
			insert_max(min_H[1]);
			del_min();
		}
		//printf("med=%d\n",med);
		//print();
		//printf("%d %d\n",t,med);
	}
	return sum;
}
int main()
{
	long long int t,a,b,c,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		reset();
		long long int ans=find_med(a,b,c,n);
		printf("%lld\n",ans);
	}
	return 0;
}
