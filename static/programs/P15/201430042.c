#include<stdio.h>
int bottom,top,count,k;
int b[10001],flag,n;
int a[10001];
void push(int index)
{
	int i;
	if(top==-1)
	{
		top++;
		bottom++;
		b[bottom]=index;
	}
	else
	{
		if(a[b[top]]<=a[index])
		{
			top++;
			b[top]=index;
		}
		else
		{
			for(i=bottom;i<=top;i++)
			{
				if(a[b[i]]>a[index])
				{
					top=i;
					b[top]=index;
					break;
				}
			} 
		}
	}
	count++;
	if(count>=k)  
	{

		printf("%d",a[b[bottom]]);
		flag++;
		if(flag==n-k+1)
			printf("\n");
		else
			printf(" ");
		if(count-k==b[bottom])
		{
			if(top>bottom)  
				bottom=bottom+1;
			else if(top==bottom)
			{
				top=-1;
				bottom=-1;
			}
			//printf("b=%d\n",bottom);
		}
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int i;
		top=-1;
		bottom=-1;
		count=0;
		flag=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			push(i);

		}
	}
	return 0;
}

