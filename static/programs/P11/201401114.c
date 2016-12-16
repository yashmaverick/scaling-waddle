#include<stdio.h>
typedef long long int ll;
typedef struct log
{
	int height;
	int index;
}log;

int top;
log stack[1000001];

void push(int val, int i)
{
		stack[++top].height=val;
		stack[top].index=i;
}

int pop()
{
	return stack[top--].height;
}

void paint(int arr[], int n)
{

	int i=0;
	log right, left;
	int length;
	long long int area, max=0;
	while(i<n)
	{
		
		if(top==-1 || stack[top].height<arr[i] )
		{

			push(arr[i], i);
			i++;
		}
		else
		{
			right.index=i;
			length=pop();
			left.index=stack[top].index;
			if(top!=-1)
				area=(ll)length*(right.index-left.index-1);
			else
				area=(ll)length*(right.index);
			
			if(area>max)
				max=area;
		}
	}
	if(top!=-1)
	{
		while(top!=-1)
		{
			length=pop();
			if(top==-1)
				area=(ll)length*n;
			else
				area=(ll)length*(n-1-stack[top].index);
			if(max<area)
				max=area;
		}
	}
	printf("%lld\n", max);
	
}

int main()
{
	int n, arr[1000001], i,j;
	while(1)
	{
		scanf("%d", &n);
		top=-1;
		if(n==0)
			break;

		for(i=0; i<n; i++)
			scanf("%d", &arr[i]);
		paint(arr,n);
	}
	return 0;
}


