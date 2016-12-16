#include<stdio.h>
void push(long long int val,long long int stack[],long long int *last)
{
	stack[*last]=val;
	(*last)++;
}
long long int pop(long long int stack[],long long int *last)
{
	if(*last==0)
		return -1;
	else
	{
		(*last)--;
		return stack[*last];
	}
}
long long int top(long long int stack[],long long int *last)
{
	if(*last==0)
		return -1;
	else
		return stack[*last-1];
}
long long int func(long long int pop,long long int p,long long int a[],long long int stack[]);
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int i,a[n],stack[n],last=0,count=0,le,p;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(i==0)
				push(i,stack,&last);
			else if(a[top(stack,&last)]>=a[i])
				push(i,stack,&last);
			else if(a[top(stack,&last)]<a[i])
			{
				while(top(stack,&last)!=-1&&a[top(stack,&last)]<a[i])
				{
					count=count+n-i-1;
					p=pop(stack,&last);
					le=func(p,last,a,stack);
					if(le>0)
						count=count+le-1;
				}
				push(i,stack,&last);
			}
		}
	
		if(top(stack,&last)!=-1)
		{
			while(top(stack,&last)!=-1)
			{
				p=pop(stack,&last);
				le=func(p,last,a,stack);
				if(le>0)
					count=count+le-1;
			}
		}
		printf("%lld\n",count);
		scanf("%lld",&n);
	}
	return 0;
}
long long int func(long long int pop,long long int p,long long int a[],long long int stack[])
{
        long long int i=p-1;
        while(i>=0)
        {
        if(a[stack[i]]==a[pop])
        {
        i--;
        continue;
        }
        else
        break;
        }
        if(i>=0)
        return i+1;
        else
        return 0;
}

/*long long int func(long long int p,long long int a[],long long int stack[])
{
	long long int x=p-1,i=0;
	long long int r=0;
	while(i<=x)
	{
		if(a[stack[p]]<a[stack[i]])
		r++,i++;
	//	if(a[stack[p]]>=a[stack[x]])
	//	x--;
		else 
		break;
	}
	return r;
}*/
