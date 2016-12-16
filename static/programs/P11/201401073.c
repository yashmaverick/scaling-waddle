//a program to find the maximum area of the fence that can be painted in a single roll of the roller
//coded by dipankar jain
#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<stdlib.h>

#define gi(x) scanf("%lld",&x)
#define pi(x) printf("%lld",x)
#define endl printf("\n")
#define tab printf("\t")
#define space printf(" ")
#define maxn 100010


int main()
{
	while(1)
	{
		long long int n,top=-1;
		long long int array[maxn],stack[maxn],lefts[maxn],rights[maxn];
		gi(n);
		if(n == 0)
			break;
/*		array = (int *)malloc(sizeof(int));
		stack = (int *)malloc(sizeof(int));
		lefts = (int *)malloc(sizeof(int));
		rights = (int *)malloc(sizeof(int));*/
		long long int i;
		for(i=0;i<n;i++)
			gi(array[i]);
		for( i=0 ; i<n ; i++)
		{
			if(top == -1)
			{
				lefts[i] = -1;
				stack[++top] = i;
			}				
			else if(array[i] > array[stack[top]])
			{
				lefts[i] = stack[top];
				stack[++top] = i;
			}
			else
			{
				while(array[i] <= array[stack[top]] && top!=-1)
					top--;
				if(top == -1)
				{
					lefts[i] = -1;
					stack[++top] = i;
				}
				else
				{
					lefts[i] = stack[top];
					stack[++top] = i;
				}
			}
		}
		
		top = -1;
		for( i=n-1 ; i>=0 ; i--)
		{
			if(top == -1)
			{
				rights[i] = n;
				stack[++top] = i;
			}				
			else if(array[i] > array[stack[top]])
			{
				rights[i] = stack[top];
				stack[++top] = i;
			}
			else
			{
				while(array[i] <= array[stack[top]] && top!=-1)
					top--;
				if(top == -1)
				{
					rights[i] = n;
					stack[++top] = i;
				}
				else
				{
					rights[i] = stack[top];
					stack[++top] = i;
				}
			}
		}
		long long int maxarea=0,area;
		for( i=0 ; i<n ; i++)
		{
			area = (array[i]*(rights[i] - lefts[i] -1));
			if(area > maxarea)
				maxarea = area;
		}
		pi(maxarea);
		endl;
	}
	return 0;
}

