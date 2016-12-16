#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void *a , const void *b)
{
	return *(int *)a - *(int *)b ;
}

#define gi(x) scanf("%d",&x)
#define pi(x) printf("%d",x)
#define gc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define glli(x) scanf("%lld",&x)
#define plli(x) printf("%lld",x)
#define gllu(x) scanf("%llu",&x)
#define pllu(x) printf("%llu",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define mod 1000000007

void parr(int array[],int start,int end)
{
	int i;
	for (i=start; i<=end; i++)
	{
		pi(array[i]);
		endl;
	}
	endl;
	return ;
}

long long int maxelem,minelem;
long long int maxheap[200000],minheap[200000];

//set the array as 0
void set_arr(long long int array[])
{
	long long int i;
	for(i=0;i<200000;i++)
		array[i] = 0;
	return ;
}

//insert an element in the minheap
void insert_min(long long int num)
{
	long long int temp;
	if(num > 1)
	{
		if(minheap[num] < minheap[num/2])
		{
			temp = minheap[num];
			minheap[num] = minheap[num/2];
			minheap[num/2] = temp;
			insert_min(num/2);
		}
	}
	return ;
}

//insert an element in the max heap
void insert_max(long long int num)
{
	long long int temp;
	if(num > 1)
	{
		if(maxheap[num] > maxheap[num/2])
		{
			temp = maxheap[num];
			maxheap[num] = maxheap[num/2];
			maxheap[num/2] = temp;
			insert_max(num/2);
		}
	}
	return ;
}

//delete an element from the minheap
void delete_min()
{
	minheap[1] = minheap[minelem];
	minelem--;
	long long int j=1,child,temp;
	while((2*j) <= minelem)
	{
		if(((2*j)+1) > minelem)
			child = 2*j;
		else
		{
			if(minheap[2*j] < minheap[(2*j)+1])
				child = 2*j;
			else
				child = 2*j + 1;
		}
		if(minheap[child] < minheap[j])
		{
			temp = minheap[child];
			minheap[child] = minheap[j];
			minheap[j] = temp;
		}
		j = child;
	}
	return ;
}

//delete an element from the maxheap
void delete_max()
{
	maxheap[1] = maxheap[maxelem];
	maxelem--;
	long long int j=1,child,temp;
	while((2*j) <=maxelem)
	{
		if(((2*j)+1) > maxelem)
			child = 2*j;
		else
		{
			if(maxheap[2*j] > maxheap[(2*j)+1])
				child = 2*j;
			else
				child = 2*j + 1;
		}
		if(maxheap[child] > maxheap[j])
		{
			temp = maxheap[j];
			maxheap[j] = maxheap[child];
			maxheap[child] = temp;
		}
		j = child;
	}
	return ;
}

//main function to return the sum 
long long int median(long long int a,long long int b,long long int c,long long int n)
{
	long long int temp,temp2;
	long long int i;
	long long int ans = 1;
	long long int current;
	minelem = 0;
	maxelem = 0;
	set_arr(maxheap);
	set_arr(minheap);
	maxheap[++maxelem] = 1;
	insert_max(maxelem);
	current = maxheap[1];
	for(i=2;i<=n;i++)
	{
		temp = c%mod;
		temp2 = ((current%mod)*(a%mod))%mod;
		temp2 = temp2 + ((i%mod)*(b%mod));
		temp2 = temp2%mod;
		temp = (temp + temp2)%mod;
		ans = ans + temp;
		if(temp > current)
		{
			minheap[++minelem] = temp;
			insert_min(minelem);
			if(minelem - maxelem >= 2)
			{
				maxheap[++maxelem] = minheap[1];
				insert_max(maxelem);
				delete_min();
			}
		}
		else
		{
			maxheap[++maxelem] = temp;
			insert_max(maxelem);
			if(maxelem - minelem >=2)
			{
				minheap[++minelem] = maxheap[1];
				insert_min(minelem);
				delete_max();
			}
		}
		if(minelem > maxelem)
			current = minheap[1];
		else
			current = maxheap[1];
	}
	return ans;
}

int main()
{
	long long int t;
	glli(t);
	while(t--)
	{
		long long int a,b,c,n;
		glli(a);glli(b);glli(c);glli(n);
		plli(median(a,b,c,n));
		endl;
	}
	return 0;
}
