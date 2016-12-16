#include<stdio.h>
int y;
struct stack
{
	long long int top;
	long long int b[100010];
}c;
void push(long long int x)
{
	c.top++;
	c.b[c.top]=x;
        return;
}
long long int  pop()
{
	if(c.top==-1)
		return;
	else
	{
		y=c.b[c.top];
		c.top--;
		
		return y;
	}
}
int main()
{
	long long int n,max_area=0,count,sum=0,j,i,t,a[100010];
	long long int left[100010],right[100010];
	while(1)
{
        scanf("%lld",&n);
	max_area=0;
	if(n==0)
	{
	break;
	}	
	else
	{
		for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	c.top=-1;
	push(0);
	left[0]=0;
	long long int sum=0;
	for(j=1;j<n;j++)
	{
		if(a[j-1]>=a[j])
		{
			count=0;
			while(c.top!=-1 && (a[c.b[c.top]]>=a[j]))
			{
				t=pop();
				count++;
			        count=count+left[t];
						
			}
			push(j);
			//printf("%d  xxy  \n",count);
			left[j]=count;
		}
		else
		{
			left[j]=0;
			push(j);
		}
	}
	sum=0;
	c.top=-1;
	push(n-1);
	right[n-1]=0;
	for(j=n-2;j>=0;j--)
	{
		if(a[j+1]>=a[j])
		{
			count=0;
			while(c.top!=-1 && (a[c.b[c.top]]>=a[j]))
			{
				t=pop();
				count++;
			       count+=right[t];
			}
		        
			push(j);
			//printf("%d  yyx\n",count);
			right[j]=count;
		}
		else
		{
			right[j]=0;
			push(j);
		}
	}
	for(j=0;j<n;j++)
	{
		if(((left[j]+right[j]+1)*a[j])>max_area)
			max_area=(left[j]+right[j]+1)*a[j];
	}
	printf("%lld\n",max_area);
	}
}
	return 0;
}







