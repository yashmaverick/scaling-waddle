#include<stdio.h>
int main()
{
	long long int n,i,j,area,max,top,pop,push;
	long long int stack[100007];
	while(1)
	{
		area=max=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		top=-1;
		for(i=0;i<n;i++)
		{
			if(top==-1||a[stack[top]]<=a[i])
			{
				stack[++top]=i;
			}
			else
			{
				//		while(a[stack[top-1]]>a[i]&&top!=0)
				j=stack[top];
				top--;
				//	stack[top]=i;
				//	if(top==0)
				//		max=a[i]*(stack[top])
				//	else
				if(top==-1)
					max=a[j]*i;
				else
					max=a[j]*(i-stack[top]-1);
				if(max>area)
					area=max;
				i--;
			}
		}
		while(top!=-1)
		{
			j=stack[top];
			top--;
			if(top==-1)            //stack empty
				max=a[j]*i;
			else
				max=a[j]*(i-stack[top]-1);
			if(max>area)
				area=max;
		}
		printf("%lld\n",area);
	}
	return 0;
}
