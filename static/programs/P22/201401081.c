#include<stdio.h>
#include<stdlib.h>
#define lli long long int
#define MOD 1000000007

lli a,b,c,n;

lli min_H[200005];
lli min_size;
lli max_H[200005];
lli max_size;

void min_shuffle_up(lli pos)
{
	if(pos<=1)
		return;
	if(min_H[pos]<min_H[pos/2])
	{
		lli temp;
		temp=min_H[pos/2];
		min_H[pos/2]=min_H[pos];
		min_H[pos]=temp;
		min_shuffle_up(pos/2);
	}
}

void min_shuffle_down(lli pos)
{
	if(2*pos>min_size)
		return;
	lli l=0,r=0;
	if(2*pos<=min_size)
		l=2*pos;
	if(2*pos+1<=min_size)
		r=2*pos+1;
	lli  num=pos;
	if(l!=0&&min_H[num]>min_H[l])
		num=l;
	if(r!=0&&min_H[num]>min_H[r])
		num=r;
	if(num!=pos)
    {
		lli temp;
		temp=min_H[num];
		min_H[num]=min_H[pos];
		min_H[pos]=temp;
		min_shuffle_down(num);
    }
}

void min_insert_heap(lli node)
{
	min_H[++min_size]=node;
	min_shuffle_up(min_size);
}

lli pop_min()
{
	lli temp=min_H[1];
	min_H[1]=min_H[min_size];
	min_H[min_size--]=0;
	min_shuffle_down(1);
	return temp;
}

void max_shuffle_up(lli pos)
{
	if(pos<=1)
		return;
	if(max_H[pos]>max_H[pos/2])
	{
		lli temp;
		temp=max_H[pos/2];
		max_H[pos/2]=max_H[pos];
		max_H[pos]=temp;
		max_shuffle_up(pos/2);
	}
}

void max_shuffle_down(lli pos)
{
	if(2*pos>max_size)
		return;
	lli l=0,r=0;
	if(2*pos<=max_size)
		l=2*pos;
	if(2*pos+1<=max_size)
		r=2*pos+1;
	lli  num=pos;
	if(l!=0&&max_H[num]<max_H[l])
		num=l;
	if(r!=0&&max_H[num]<max_H[r])
		num=r;
	if(num!=pos)
    {
		lli temp;
		temp=max_H[num];
		max_H[num]=max_H[pos];
		max_H[pos]=temp;
		max_shuffle_down(num);
    }
}

void max_insert_heap(lli node)
{
	max_H[++max_size]=node;
	max_shuffle_up(max_size);
}

lli pop_max()
{
	lli temp=max_H[1];
	max_H[1]=max_H[max_size];
	max_H[max_size--]=0;
	max_shuffle_down(1);
	return temp;
}

void balance()
{
	lli temp;
	temp=min_size-max_size;
	if(temp<-1)
		min_insert_heap(pop_max());
	else if(temp>0)
		max_insert_heap(pop_min());
	else return;
	balance();
}

int main()
{
	int t;
	lli sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		min_size=0;
		max_size=0;
		scanf("%lld",&a);
		scanf("%lld",&b);
		scanf("%lld",&c);
		scanf("%lld",&n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		lli i,temp;
		max_insert_heap(1);
		sum+=1;
		temp=(a+(b*2)%MOD+c)%MOD;
		sum+=temp;
		min_insert_heap(temp);
		for(i=3;i<=n;i++)
		{
			temp=((a*max_H[1])%MOD+(b*i)%MOD+c)%MOD;
			if(temp<=max_H[1])
				max_insert_heap(temp);
			else
				min_insert_heap(temp);
			balance();
			sum+=temp;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
