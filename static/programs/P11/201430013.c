#include<stdio.h>
#include<stdlib.h>
long long int top;
long long int ind;
void push(long long int *a,long long int *b,long long int *c,long long int i)
{
	ind++;
	top=i;
	c[ind]=i;
}
void pop(long long int *a,long long int *b,long long int *c,long long int i)
{
	if(ind!=0)
	{
		b[top]=(i-c[ind-1]-1)*a[top];
		top=c[ind-1];
		ind--;
	}
	else
	{
//		printf("case2\n");
//		printf("%lld\n",i);
		b[top]=(i)*a[top];
		top=-1;
		ind--;
	}

}
int main()
{
	while(1)
	{
		long long int i,test;
		scanf("%lld",&test);
		long long int *a,*b,*c;
		long long int max=0;
		a=(long long int*)malloc(sizeof(long long int)*test);
		b=(long long int*)malloc(sizeof(long long int)*test);
		c=(long long int*)malloc(sizeof(long long int)*test);
		if(test==0)
			return 0;
		ind=-1;
		top=-1;
		for(i=0;i<test;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<test;i++)
		{
			if(a[i]>=a[top])
				push(a,b,c,i);
			if(a[i]<a[top])
			{
				while(top!=-1&&a[top]>a[i])
					pop(a,b,c,i);
				push(a,b,c,i);
			}
//			printf("index=%lld\n",ind);
		}
		while(ind!=-1)
			pop(a,b,c,test);
		for(i=0;i<test;i++)
		{
			if(b[i]>max)
				max=b[i];
		}
		printf("%lld\n",max);
		free(a);
		free(b);
		free(c);
	}
}
