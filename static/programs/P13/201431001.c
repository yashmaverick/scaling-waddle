#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define si(a)               scanf("%d",&a)
#define sii(a,b)            scanf("%d %d",&a,&b)
#define sl(a)               scanf("%lld",&a)
#define slu(a)              scanf("%llu",&a)
#define sf(a)               scanf("%f",&a)
#define sd(a)               scanf("%lf",&a)
#define ss(a)               scanf("%s",a)
#define pi(a)               printf("%d",a)
#define pii(a,b)            printf("%d %d",a,b)
#define pl(a)               printf("%lld",a)
#define pnl					printf("\n")

#define LL                  long long 
#define UI                  unsigned int
#define ULL                 unsigned long long
#define MOD                 1000000007
#define MAX                 1000000007000
#define forall(i,a,b)       for(i=a; i<b; i++)

#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))

/*
int b_search(int a[],int key,int min,int max)
{
        if(max == min)
            return max;
        else if(key > a[max])
        	return max;
        else if(key < a[max])
        	return max;
        else{
                int mid = min + (max - min)/2;
                if(key < a[mid])
                        return b_search(a, key, min, mid - 1);
                else if(key > a[mid])
                        return b_search(a, key, mid + 1, max);
                else
                        return mid;
        }
}
*/

int b_search(int a[],int key, int min, int max)
{
	int mid,ans;
	if(min > max)
		return 0;
	else if(min == max)
		return max;
	
	if(a[min] > key)
		return min;
	else if(key > a[max])
		return max + 1;

	
		mid = min + (max - min)/2;
		if(key > a[mid])
		{
			if(key < a[mid + 1])
				return mid + 1;
			else
				ans = b_search(a, key, mid + 1, max);
		}
		else
		{
			if(key > a[mid - 1])
				return mid;
			else
				ans = b_search(a, key, min, mid);
		}
	
	return ans;
}
typedef struct deepest  
{
	int value;
	int depth;
}deepest;

deepest* deepestnode(int post[], int start, int end)
{
	deepest *deepest_element;
	deepest_element = (deepest*)malloc(sizeof(deepest));
	int root = post[end];
	
	if(end <= start)
	{
		deepest_element -> value = root;
		deepest_element -> depth = 0;
		return deepest_element;
	}
	if(end - start == 1)
	{
		deepest_element -> value = post[start];
		deepest_element -> depth = 1;
		return deepest_element;
	}
	
	int j = b_search(post, root, start, end-1) - 1;
	//if(start==0){
	//	printf("left\n");
	//	printf("i=%d\n",i);
	//	printf("j=%d\n",j);
	//}
	//else{
	//	printf("right\n");
	//	printf("i=%d\n",i);
	//	printf("j=%d\n",j);
	//}
	//2 1 3 4 6 7 5

	deepest *left = deepestnode(post, start, j);
	deepest *right = deepestnode(post, j + 1, end - 1);
	
	left->depth++;
	right->depth++;

	if(left -> depth < right -> depth)
		return right;
	else if(left ->depth > right->depth)
		return left;
	else 
		if (left -> value < right -> value)
			return left;
		else
			return right;
	}

	int main()
	{
		int t;
		si(t);
		while(t--)
		{
			int arr[1000001];
			int N,i;
			si(N);
			for(i = 0; i < N; i++)
				si(arr[i]);

			deepest *element = deepestnode(arr, 0, N - 1);
			pii(element -> value, element -> depth);
			pnl;
		}
		return 0;
	}