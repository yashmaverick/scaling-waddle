#include<stdio.h>

long long int top=-1;
long long int stack[100004];
long long int b[100004],max=0;

void lt(long long int *a,long long int n)
{
	long long int i,x,c;
	max=0;
	for(i=0;i<n;i++)
	{
			while(a[stack[top]]>a[i]&&top!=-1)
			{
//				printf("blah");
				if(stack[top]==i-1)
					x=stack[top];
				c=x-stack[top]+1;
				b[stack[top]]=c*a[stack[top]];
				//printf("%lld ",b[stack[top]]);
				top--;
			}
			top++;
			stack[top]=i;
		//	printf("%d ",stack[top]);
	}
	
	if(top!=-1)
	{
		x=stack[top];
		while(top!=-1)
		{
			c=x-stack[top]+1;
		        b[stack[top]]=c*a[stack[top]];
            	        //printf("%lld ",b[stack[top]]);
			top--;
		}
//		printf("%d ",top);
	}
/*	printf("\n");
	for(i=0;i<n;i++)
		printf("%lld ",b[i]);*/
}
	
void rt(long long int *a,long long int n)
{
        int i,x,c;
	max=0;
	for(i=0;i<n;i++)
	{
			while(a[n-stack[top]-1]>a[n-i-1]&&top!=-1)
			{
				if(stack[top]==i-1)
					x=stack[top];
				c=x-stack[top];
				b[n-stack[top]-1]+=c*a[n-stack[top]-1];
				top--;
			}
		        top++;
			stack[top]=i;
//			printf("%d ",n-stack[top]-1);
	}
        
	if(top!=-1)
        {
		x=stack[top];
		while(top!=-1)
		{
			c=x-stack[top];
			//printf("%d\t",n-stack[top]-1);
			b[n-stack[top]-1]+=c*a[n-stack[top]-1];
			//printf("%lld ",b[n-stack[top]-1]);
			top--;
		}
//		printf("%d ",top);
	}
        
}

void maxarea(long long int *a,long long int n)
{
	long long int i;
	lt(a,n);
	rt(a,n);
	for(i=0;i<n;i++)
	{
		if(max<b[i])
			max=b[i];
	}

	printf("%lld\n",max);

}

int main()
{
	long long int i,n,a[100005];
	long long int max;
	//scanf("%d",&t);
	scanf("%lld",&n);
	while(n!=0)
	{
		//scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		maxarea(a,n);
		scanf("%lld",&n);
	}
	return 0;
}
