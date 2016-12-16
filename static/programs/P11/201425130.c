#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
long long int MaxRectangle(long long int A[],long long int n);

struct StackItem
{
	long long int index;
	long long int height;
};
int main()
{	
	long long int A[200000],n,p,r;
	scanf("%lld",&n);
	while(n!=0)
	{
		for(p=0;p<n;p++)
		{
			scanf("%lld",&A[p]);		
		}
		r=MaxRectangle(A,n);
		printf("%lld\n",r);
		scanf("%lld",&n);
	}
	return 0;
}

long long int MaxRectangle(long long int A[],long long int n)
{
	long long int i,maxarea=-1,top=-1,left,currentarea;
	struct StackItem *s = (struct StackItem*)malloc(sizeof(struct StackItem)*n);

	for(i=0;i<=n;i++)	
	{
		while(top>=0 && (i==n || s[top].height>A[i]))
		{	
			if(top>0)
				left = s[top-1].index;
			else		
				left = -1;
			currentarea = (i-left-1)*s[top].height;			
			--top;	

			if(currentarea > maxarea)
				maxarea=currentarea;
		}	
		if(i<n)
		{	
			++top;
			s[top].height = A[i];
			s[top].index = i;

		}
	}
	return  maxarea;
}

