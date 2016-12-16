#include<stdio.h>
int A[10005];
int B[10005];
int first=0;
int last=0;
void pop()
{
    last--;
}
void push(int n)
{
    B[last]=n;
    last++;
}
void delete()
{
    first++;
}
void printwindow(int n,int k)
{
    int i;
    for(i=0;i<k;i++)
    {
	while((first!=last)&&A[i]<=A[B[last-1]])
	{
	    pop();
	}
	push(i);
    }
    for(i=k;i<n;i++)
    {
	printf("%d ",A[B[first]]);
	while((first!=last)&&B[first]<=(i-k))
	{
	    delete();
	}
	while((first!=last)&&A[i]<=A[B[last-1]])
	{
	    pop();
	}
	push(i);
    }
    printf("%d\n",A[B[first]]);
}
int main()
{
    int n,k,i,t;
    scanf("%d",&t);
    while(t--)
    {
	first=0;
	last=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&A[i]);
	}
	printwindow(n,k);
    }
    return 0;
}
