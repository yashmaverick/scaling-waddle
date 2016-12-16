#include<stdio.h>
#define MOD 1000000007
#define INF 1000000007

int end_max , end_min; 
long long int heap_min[200000], heap_max[200000];

void push_min(long long int N)
{
//	printf("push %lld into min heap...\n",N);	
	int idx;
	long long int t;	
	heap_min[end_min]=N;
	idx=end_min;

	while(idx)
	{	
		if(N < heap_min[idx/2])
		{
			t = heap_min[idx];
			heap_min[idx] = heap_min[idx/2];
			heap_min[idx/2] = t; 
		}
		else
			break;

		idx = idx/2 ;
	}

	end_min++;
	return ;
}

void push_max(long long int N)
{
//	printf("push %lld into max heap...\n",N);	
	int idx;
	long long int t;	
	heap_max[end_max]=N;
	idx=end_max;

	while(idx)
	{	
		if(N > heap_max[idx/2] )
		{
			t = heap_max[idx];
			heap_max[idx] = heap_max[idx/2];
			heap_max[idx/2] = t; 
		}
		else
			break;

		idx = idx/2 ;
	}

	end_max++;
	return ;
}

long long int pop_min()
{
//	printf("poping %d from heap..\n",heap[top]);
	long long int t,n,r,i;
	r = heap_min[1];
	heap_min[1] = heap_min[end_min-1];
	end_min--;
	
	n=1;
	while( (2*n)+1 <= end_min )
	{
		i = heap_min[2*n] < heap_min[(2*n)+1] ? 2*n : (2*n)+1 ;
		
		if(heap_min[n] > heap_min[i])
		{
			t = heap_min[n];
			heap_min[n] = heap_min[i];
			//in_heap[heap[n]] = n;
			heap_min[i] = t;
			//in_heap[heap[i]] = i;
		}
		else
			break;

		n=i;
	}
	if((2*n) == end_min-1)
	{
		if( heap_min[2*n] < heap_min[n] )
		{	
			t = heap_min[n];
			heap_min[n] = heap_min[2*n];
			//in_heap[heap[n]] = n;
			heap_min[2*n] = t;
			//in_heap[heap[2*n]] = 2*n;
		}
	}
//	printheap();
	return r;	
}

long long int pop_max()
{
//	printf("poping %d from heap..\n",heap[top]);
	long long int t,n,r,i;
	r = heap_max[1];
	heap_max[1] = heap_max[end_max-1];
	end_max--;
	
	n=1;
	while( (2*n)+1 <= end_max )
	{
		i = heap_max[2*n] > heap_max[(2*n)+1] ? 2*n : (2*n)+1 ;
		
		if(heap_max[n] < heap_max[i])
		{
			t = heap_max[n];
			heap_max[n] = heap_max[i];
			//in_heap[heap[n]] = n;
			heap_max[i] = t;
			//in_heap[heap[i]] = i;
		}
		else
			break;

		n=i;
	}
	if((2*n) == end_max-1)
	{
		if( heap_max[2*n] > heap_max[n] )
		{	
			t = heap_max[n];
			heap_max[n] = heap_max[2*n];
			//in_heap[heap[n]] = n;
			heap_max[2*n] = t;
			//in_heap[heap[2*n]] = 2*n;
		}
	}
//	printheap();
	return r;	
}

long long int median()
{
	if( end_min > end_max )
		return heap_min[1];
	else
		return heap_max[1];
}

void insert(long long int n, long long int M)
{
//	printf("inserting %lld....\n",n);
	if( n == M )
	{
		if( end_min > end_max )
			push_max(n);
		else
			push_min(n);
	}
	else if( n < M )
	{
		if(end_max > end_min)
			push_min(pop_max());
		
		push_max(n);
	}
	else
	{
		if(end_min > end_max)
			push_max(pop_min());

		push_min(n);
	}

	return ;	
	
}

int main()
{
	heap_min[0] = -1;
	heap_max[0] = INF;
	heap_min[1] = 1;

	int T, n, i;
	long long int Fi, Mi, a, b, c, sum;

	scanf("%d",&T);
	while(T--)
	{
		end_min = 2, end_max = 1, heap_min[1]=1;	
		sum = 1;

		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		for(i=2;i<=n;i++)
		{
			Mi = median();
//			printf("Median is %lld\n",Mi);
			insert( (Fi = ( (a*Mi)%MOD + (b*i)%MOD + c ) % MOD), Mi ) ;
			sum = (sum + Fi) ;
//			printf("Sum is %lld\n",sum);
		}

		printf("%lld\n",sum);
	}
	return 0;
}
