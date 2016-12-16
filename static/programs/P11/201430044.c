#include<stdio.h>
#include<stdlib.h>
long long int top=-1;
void push(long long int *s,long long int i)
{
	top++;
	s[top]=i;
}
void pop(long long int *s)
{
	top--;
}
int main()
{
	long long int n,max,i,area,*a,*s,k,l;
	scanf("%lld",&n);
while(n!=0)
{
	s=(long long int *)malloc(sizeof(long long int)*n);
	a=(long long int *)malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	max=i=0;
	while(i<n)
	{
		if(top==-1||(a[i]>=a[s[top]])){
			push(s,i); i++;}
		else
		{
			/*if(a[i]>=a[s[top]])
			{
				push(s,i);
				i++;
			}*/
			{
				k=s[top];
				pop(s);
				if(top==-1)
				{
					area=a[k]*i;
				}
				else
				{
					area=a[k]*(i-s[top]-1);
				}
				if(area>max)
					max=area;
			}
		}
	}
	while(top!=-1)
	{
		k=s[top];
		pop(s);
		if(top==-1)
		{
			area=a[k]*n;
		}
		else
		{
			area=a[k]*(n-s[top]-1);
		}
		if(area>max)
			max=area;

	}
	printf("%lld\n",max);	
scanf("%lld",&n);
}
	return 0;
}
