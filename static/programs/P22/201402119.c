#include<stdio.h>

long long int min[200000];

long long int i=1;

void minheap_insert(long long int data)
{
	long long int j;
	min[i]=data;
	j=i;
	while(min[j/2] >= min[j] && j/2>0)
	{
		long long int x;
		x=min[j/2];
		min[j/2]=min[j];
		min[j]=x;
		j=j/2;
	}
	i++;    
}

long long int max[200000];
long long int d=1;

void maxheap_insert(long long int data)
{
	long long int j;
	max[d]=data;
	j=d;
	while(max[j/2] <=  max[j] && j/2>0)
	{
		long long int x;
		x=max[j/2];
		max[j/2]=max[j];
		max[j]=x;
		j=j/2;
	}
	d++;    
}

long long int min_heap()
{
	return min[1];
}

long long int max_heap()
{
	return max[1];
}

long long int mini(long long int a, long long int b)
{
	if(a > b)
		return b;
	else
		return a;
}

long long int maxi(long long int a, long long int b)
{
	if(a >b)
		return a;
	else
		return b;
}

void minheap_delete()
{
	long long int n,x;
	n=i-1;
	long long int tmp=min[n];
	i--;
	min[1]=tmp;
	long long int j=1;
	while(j <= n/2)
	{
		//j++;
		if(2*j <= n)
		{
			if(2*j+1 <= n)
			{
				x=mini(min[2*j],min[2*j+1]);
				if(x <= min[j])
				{
					if(x == min[2*j])
					{
						tmp=min[2*j];
						min[2*j]=min[j];
						min[j]=x;
						j=2*j;
						continue;
					}
					else
					{
						tmp=min[2*j+1];
						min[2*j+1]=min[j];
						min[j]=tmp;
						j=2*j+1;
						continue;
					}
				}
				else
					break;
			}
			else
			{
				if(min[2*j] <= min[j])
				{
					tmp=min[2*j];
					min[2*j]=min[j];
					min[j]=tmp;
					j=2*j;
					continue;
				}
				else
					break;
			}
		}
	}
}


void maxheap_delete()
{
	long long int n,x;
	n=d-1;
	long long int tmp=max[n];
	d--;
	max[1]=tmp;
	long long int j=1;
	while(j <= n/2)
	{
		//j++;
		if(2*j <= n)
		{
			if(2*j+1 <= n)
			{
				x=maxi(max[2*j],max[2*j+1]);
				if(x >= max[j])
				{
					if(x == max[2*j])
					{
						tmp=max[2*j];
						max[2*j]=max[j];
						max[j]=x;
						j=2*j;
						continue;
					}
					else
					{
						tmp=max[2*j+1];
						max[2*j+1]=max[j];
						max[j]=tmp;
						j=2*j+1;
						continue;
					}
				}
				else
					break;
			}
			else
			{
				if(max[2*j] >= max[j])
				{
					tmp=max[2*j];
					max[2*j]=max[j];
					max[j]=tmp;
					j=2*j;
					continue;
				}
				else
					break;
			}
		}
	}
}
long long int a,b,c;
int func( long long int median, long long int i)
{
	long long int l,j,k;
	j=(a*median%1000000007);
	k=(b*i+c)%1000000007;
	l=(j+k)%1000000007;
	return l;	
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		i=1;d=1;
		long long int j,k,p,q,n,median,sum=0;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		median=1;
		sum=1;
		for(j=2;j<=n;j++)
		{
			p=func(median,j);
			if(p > median)
			{
				minheap_insert(p);
			}
			else
			{
				maxheap_insert(p);
			}
			if(i-d == 2)
			{
				maxheap_insert(median);
				median=min_heap();
				minheap_delete();
			}
			else if(d-i >= 1 )
			{
				minheap_insert(median);
				median=max_heap();
				maxheap_delete();
			}
			sum=sum+p;
		}
		printf("%lld\n",sum);
	}
	return 0;
}


/*
   int main()
   {
   int j,n,k;
   scanf("%d",&n);
   for(k=0;k<n;k++)	
   {
   int data;
   scanf("%d",&data);    
   minheap_insert(data);
   }
   int l;
   l=min_heap();
   printf("%d\n",l);
   minheap_delete();
   l=min_heap();
   printf("%d\n",l);
   for(j=1;j<i;j++)
   {
   printf("%d ",min[j]);
   }    
   printf("\n");
   return 0;
   }
 */

