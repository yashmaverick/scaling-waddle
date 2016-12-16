#include<stdio.h>
#include<stdlib.h>
int stack[500001];
int top=-1;
void push(int val)
{
	top++;
	stack[top]=val;
	return ;
}
void pop()
{
	if(top==-1)
		return ;
	top--;
}
int main()
{
	int n,i,j,value,temp;
	long long int a[500001];
	long long int count;
	while(1)
	{count=0;
		top=-1;
		scanf("%d",&n);
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			i=0;
			while(i<n)
			{
			//	scanf("%d",&value);
				if(a[i]<=stack[top]||top==-1)
				{
					push(a[i]);
					temp=top;
					while(stack[temp]==stack[top]&&top!=-1)
						temp--;
					if(temp>0)
						count=count+temp;
					i++;
				}
				else
				{
					count=count+n-1-i;
	//				printf("%d %d\n",i,count);
					top--;
				}
	//			printf("hi%d\n",count);
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
