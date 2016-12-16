#include<stdio.h>
#include<stdlib.h>
int start,top,ind;
void push(int i,int a[],int b[])
{
	top++;
	b[top]=i;
}
void pop()
{
	top--;
}
void resize(int b[])
{
	if(start==b[ind])
	{
		ind++;
	}
	start++;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		top=0;
		start=0;
		ind=0;
		int n,k,i;
		int *a,*b;
		scanf("%d %d",&n,&k);
		a=(int *)malloc(n*sizeof(int));
		b=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=0;
		for(i=1;i<k;i++)
		{
			if(a[i]>a[b[top]])
				push(i,a,b);
			else
			{
				while(top>=ind && a[b[top]]>=a[i])
					pop();
				push(i,a,b);
			}
		}
		printf("%d",a[b[ind]]);
		for(i=k;i<n;i++)
		{
			resize(b);
			if(a[i]>a[b[top]])
				push(i,a,b);
			else
			{
				while(top>=ind && a[b[top]]>=a[i])
					pop();
				push(i,a,b);
			}
			printf(" %d",a[b[ind]]);
		}
		printf("\n");
		free(a);
		free(b);
	}
	return 0;
}
