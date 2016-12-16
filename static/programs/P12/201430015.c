#include<stdio.h>

long long int a[500003],top=-1;

void push(long long int x)
{
	if(top==(500000))
	{
		return;
	}
	else
	{
		top++;
		a[top]=x;
	}
}

long long int pop()
{
	long long int x;
	if(top==-1)
	{
		return -1;
	}
	else
	{
		x=a[top];
		top--;
		return x;
	}
}

long long top1()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return a[top];
	}
}

int main()
{
	long long int c[500003];
	long long int i,j,n,temp;
	long long int sum;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
		{
			break;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
		}
		sum=0;
		top=-1;
		push(0);
		for(i=1;i<n;i++)
		{
		//	if(top==-1)
		//	{
		//		push(i);
		//		continue;
		//	}
			if(c[i]>c[top1()])
			{
				while((top!=-1)&&(c[i]>c[top1()]))
				{
					sum+=n-i-1;
					pop();
				}

				j=top;
				while((c[a[j]]==c[i]))
				{

					j--;
					if(j==-1)
					{
						break;
					}

				}
				if(j>0)
				{
					sum+=j;
				}
				push(i);

			}
			else
			{
				j=top;
				while((j!=-1)&&(c[a[j]]==c[i]))
				{

					j--;
					if(j==-1)
					{
						break;
					}

				}
				if(j>0)
				{
					sum+=j;
				}
				push(i);

			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}

