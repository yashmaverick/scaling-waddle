#include <stdio.h>

#define MOD 1000000007
#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))

long long int min_heap[200010], end_min_heap = 1;
long long int max_heap[200010], end_max_heap = 1;

void insert_min_heap(long long int a)
{
	min_heap[end_min_heap] = a;
	long long int i = end_min_heap;
	while(i != 1 && min_heap[i/2] > min_heap[i])
	{
		long long int temp = min_heap[i/2];
		min_heap[i/2] = min_heap[i];
		min_heap[i] = temp;
		i = i/2;
	}
	end_min_heap++;
}

void insert_max_heap(long long int a)
{
	max_heap[end_max_heap] = a;
	long long int i = end_max_heap;
	while(i != 1 && max_heap[i/2] < max_heap[i])
	{
		long long int temp = max_heap[i];
		max_heap[i] = max_heap[i/2];
		max_heap[i/2] = temp;
		i = i/2;
	}
	end_max_heap++;
}

long long int delete_min_heap()
{
	long long int min_element = min_heap[1];
	min_heap[1] = min_heap[end_min_heap - 1];
	long long int index = 1;

	while(min_heap[index] > min(min_heap[2*index],min_heap[(2*index)+1]))
	{
		long long int min;
		if(min_heap[2 * index] < min_heap[2 * index + 1])
			min = (2 * index);
		else min = (2 * index + 1);
        
        if (end_min_heap <= min)
            break;
        long long int temp = min_heap[min];
        min_heap[min] = min_heap[min/2];
        min_heap[min/2] = temp;
        index = min;
	}
	end_min_heap--;
	return min_element;
}

long long int delete_max_heap()
{
	long long int max_element = max_heap[1];
	max_heap[1] = max_heap[end_max_heap - 1];
	long long int index = 1;

	while(max_heap[index] < max(max_heap[2 * index],max_heap[2 * index + 1]))
	{
		long long int max;
		if(max_heap[2 * index] > max_heap[2 * index + 1])
			max = (2 * index);
		else max = (2 * index + 1);
        
        if (end_max_heap <= max)
            break;

        long long int temp = max_heap[max];
        max_heap[max] = max_heap[max/2];
        max_heap[max/2] = temp;
        index = max;
	}
	end_max_heap--;
	return max_element;
}

void print()
{
	int i;
	printf("Max Heap ");
	for(i = 1;i <= end_max_heap;i++)
		printf("%lld ", delete_max_heap());
	printf("\n");

	printf("Min Heap ");
	for(i = 1;i <= end_min_heap;i++)
		printf("%lld ", delete_min_heap());
	printf("\n");

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		end_min_heap = end_max_heap = 1;
		
		long long int a,b,c,n;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		
		long long int sum = 1;
		insert_max_heap(1);
		long long int i;
		for(i = 2;i <= n; i++)
		{
			long long int median = max_heap[1];
			long long int temp_sum = ((a*median)%MOD + (b*i)%MOD)%MOD + c;
			temp_sum %= MOD;
			//printf("%lld\n", temp_sum);
			//print();

			if(temp_sum <= median) insert_max_heap(temp_sum);
			else insert_min_heap(temp_sum);

			//printf("%lld %lld %lld %lld %lld\n",temp_sum,median,i,end_min_heap,end_max_heap); 
			
			while(end_max_heap > (end_min_heap + 1))
			{
				//printf("first\n");
				insert_min_heap(delete_max_heap());
			}
			while(end_min_heap > end_max_heap)
			{
				//printf("second\n");
				insert_max_heap(delete_min_heap());
			}
			
			sum += temp_sum;
		}
		printf("%lld\n", sum);
	}
	return 0;
}