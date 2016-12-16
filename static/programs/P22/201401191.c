#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007
int maxheap[1000010],minheap[1000010],median;
void insert_min(int);
void insert_max(int);
void min_heapify();
void max_heapify();
void put_median(int);
int check();
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		long long int fin;
		int a,b,c,n,i,j,k;
		scanf("%d%d%d%d",&a,&b,&c,&n);
		median=1;
		fin=1;
		maxheap[0]=1;
		maxheap[1]=1;
		minheap[0]=0;
		k=1;
		for(i=2;i<=n;i++)
		{
			median=maxheap[1];
			k=(int)((((long long)a*(long long)(maxheap[1]))%mod+((long long)b*(long long)i)%mod+c)%mod);
			fin=fin+(long long int)k;
			put_median(k);
		}
		printf("%Ld\n",fin);
	}
	return 0;
}
void put_median(int num)
{
	int bal=check();
	if(bal>=1)
	{
		if(num>=median)
		{
			insert_min(num);
		}
		else
		{
			insert_min(maxheap[1]);
			maxheap[1]=maxheap[maxheap[0]];
			maxheap[0]--;
			max_heapify(1);
			insert_max(num);
		}
	}
	else
	{
		if(num>median)
		{
			insert_min(num);
			insert_max(minheap[1]);
			minheap[1]=minheap[minheap[0]];
			minheap[0]--;
			min_heapify(1); 
/*			insert_max(minheap[1]);
			minheap[1]=minheap[minheap[0]];
			minheap[0]--;
			min_heapify(1);
			insert_min(num); */
		}
		else
		{
			insert_max(num);
		}
	}
	return;
}
int check()
{
	return maxheap[0]-minheap[0];
}
void insert_min(int nu)
{
	int i,tmp;
	minheap[0]++;
	i=minheap[0];
	minheap[i]=nu;
	while(i>1)
	{
		if(minheap[i/2]>minheap[i])
		{
			tmp=minheap[i/2];
			minheap[i/2]=minheap[i];
			minheap[i]=tmp;
			i=i/2;
		}
		else
		{
			break;
		}
	}
}
void insert_max(int nu)
{
	int i,tmp;
	maxheap[0]++;
	i=maxheap[0];
	maxheap[i]=nu;
	while(i>1)
	{
		if(maxheap[i/2]<maxheap[i])
		{
			tmp=maxheap[i/2];
			maxheap[i/2]=maxheap[i];
			maxheap[i]=tmp;
			i=i/2;
		}
		else
		{
			break;
		}
	}
}
void min_heapify(int ind)
{
	int l=ind;
	if(2*ind<=minheap[0]&&minheap[l]>minheap[2*ind])
	{    
		l=2*ind;
	}
	if(2*ind+1<=minheap[0]&&minheap[l]>minheap[2*ind+1])
	{
		l=2*ind+1;
	}
	int tmp;
	if(l!=ind)
	{
		tmp=minheap[l];
		minheap[l]=minheap[ind];
		minheap[ind]=tmp;
		min_heapify(l);
	}
	return;
}
void max_heapify(int ind)
{
	int l=ind;
	if(2*ind<=maxheap[0]&&maxheap[l]<maxheap[2*ind])
	{    
		l=2*ind;
	}
	if(2*ind+1<=maxheap[0]&&maxheap[l]<maxheap[2*ind+1])
	{
		l=2*ind+1;
	}
	int tmp;
	if(l!=ind)
	{
		tmp=maxheap[l];
		maxheap[l]=maxheap[ind];
		maxheap[ind]=tmp;
		max_heapify(l);
	}
	return;
}
