#include<stdio.h>
long long int a[500000],n,b[500000];
long long int top,c,flag=1;
long long int count(long long int x)
{
	long long int i,k;
	if(x>=2)
	{
		k=a[b[x]];
		//if(flag==2)
		//	printf("%d ",x);	
	for(i=x-1;i>=0;i--)
	{
		if(k<a[b[i]]){
		// if(flag==2)
//		  printf("%d ",i);

		return i;}
	}
	return 0;
	}
	else
		return 0;
}
void push(long long int index)
{
	long long int i;
	if(top==-1)
	{
		top++;
		b[top]=index;
		return;
	}
	if(a[b[top]]>=a[index])
	{
		top++;
		b[top]=index;
		//c=c+count(top);
		return;
	}
	for(i=top;i>=0;i--)
	{
		if(a[index]>a[b[i]])
		{
			c=c+count(i)+n-index-1;
			//printf("zero=%d\n",count(i));
		}
		else
		{
			//printf("hii");
			//c=c+count(i);
			top=i+1;
			b[top]=index;
			return;
		}
	}
	top=-1;
	push(index);
	return;
}
int main()
{
	long long int i;
	while(1)
	{
		//begin=-1;
		top=-1;
		c=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
			push(i);
//		for(i=0;i<=top;i++)
		
//			printf("%d",a[b[i]]);
//		printf("%d",c);
		if(top!=-1)
			for(i=top;i>=0;i--)
			{
				flag=2;
				c=c+count(i);
			}
		printf("%lld\n",c);
	}
	return 0;
}

