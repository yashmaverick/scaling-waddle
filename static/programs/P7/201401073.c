#include<stdio.h>
#include<stdlib.h>

#define MAXS 1000010
 
int cmpfunc( void const *a, void const *b)
{
	return (*(int*)a - *(int *)b);
}

unsigned long long int add (unsigned long long int val)
{
	return ( (val*(val - 1))/2);
}

int main()
{
	int testc;
	scanf("%d",&testc);
	while(testc--)
	{
		int n,ar[MAXS],cur,i;
		unsigned long long int sum,count;
		scanf("%d",&n);
		
		for(i = 0; i < n; i++)
		{
			scanf("%d",&ar[i]);
		}
		qsort(ar,n,sizeof(int),cmpfunc);
		cur = ar[0];
		count = 1;
		sum = 0;
		for( i = 1; i < n;i++)
		{
			if(ar[i] == cur)
				count ++;
			else 
			{
				sum = sum + add(count);
				count = 1;
				cur = ar[i];
			}
		
		}
		sum = sum + add(count);
		printf("%llu\n",sum);
	}
	return 0;
}
				
		

