#include<stdio.h>
long long int stack[1000000];
int pointer=-1;
void push(int value)
{
pointer++;
stack[pointer]=value;
return;
}
void pop()
{
if(pointer==-1)
return ;
pointer--;
}

int main()
{
	int n, i ;
	scanf("%d",&n);
	while(n!=0)
	{
	int a[n],b[n],c[n];
	long long int max,maxtemp;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0;
		pointer=-1;
	while(i<n)
	{
		if(pointer==-1 || a[i]>=a[stack[pointer]])
		{
//			printf("iii\n");
			push(i);
			
			i++;
//			printf("inside\n");
		}

		else
		{
			b[stack[pointer]]=i;
//			printf("b:%d\ninside",b[stack[pointer]]);
//			printf("min index:%d\n",b[head->index]);
			pop();
		}
	}

	while(pointer!=-1)
	{
		b[stack[pointer]]=n;
		pop();
	}
	i=n-1;
	while(i>=0)
	{
		if(pointer==-1 || a[stack[pointer]]<=a[i])
		{
			push(i);
			i--;
		}

		else
		{
			c[stack[pointer]]=i;
			pop();
		}
	}

	while(pointer!=-1)
	{
		c[stack[pointer]]=-1;
		pop();
	}
/*	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");*/
	max=0;
	for(i=0;i<n;i++)
	{
		maxtemp=((long long)(b[i]-c[i]-1)*(long long)a[i]);
		if(max<maxtemp)
		max=maxtemp;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d  ",b[i]);
	}
	printf("\n");*/
	printf("%lld\n",max);
	scanf("%d",&n);
}
	return 0;
}
