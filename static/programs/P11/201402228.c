#include<stdio.h>
long long int stack[100003];
long long int top;
long long int ret;
long long int re;
int stat;
void push(long long int i,long long int n)
{
	top++;
	stack[top]=i;
}
int pop()
{
	re=stack[top];
	top--;
	return re;
}
int main()
{
	long long int area[100003];
	while(1)
	{
		top=-1;
		long long int n,i,a[100003],area[100003],re;
		scanf("%lld",&n);
		if(n==0)
			break;
		else
		{
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
				area[i]=0;
			}
			for(i=0;i<n;i++)
			{
				if(top==-1)
				{
					push(i,n);
				}
				else
				{
					if(a[i]>=a[stack[top]])
					{
						push(i,n);
					}
					else
					{
						stat=0;
						while(a[stack[top]]>a[i])
						{
							if(stat==0)
							{
								ret=pop();
								area[ret]=(1*a[ret]);
								stat=1;
							}
							else
							{
								re=pop();
								area[re]=((ret-re+1)*a[re]);
							}
							if(top==-1)
								break;

						}
						push(i,n);
						

					}
				}
			}
			for(i=top;i>=0;i--)
			{
				area[stack[i]]=((stack[top]-stack[i]+1)*a[stack[i]]);
			}
			top=-1;
			for(i=n-1;i>=0;i--)
			{
				if(top==-1)
				{
					push((n-i-1),n);
				}
				else
				{
					if(a[i]>=a[n-stack[top]-1])
					{
						push((n-i-1),n);
					}
					else
					{
						int f=0;
						stat=0;
						while(a[n-stack[top]-1]>a[i])
						{
							if(stat==0)
							{
								ret=pop();
								area[n-ret-1]=area[n-ret-1]+0;
								stat=1;
							}
							else
							{
								re=pop();
								area[n-re-1]=area[n-re-1]+((ret-re)*a[n-re-1]);
							}
							if(top==-1)
							{
								push((n-i-1),n);
								f=1;
							}
						}
						if(f==0)
						{
							push((n-i-1),n);
						}

					}
				}

			}
			for(i=top;i>=0;i--)
			{
				area[n-stack[i]-1]=area[n-stack[i]-1]+((stack[top]-stack[i])*a[n-stack[i]-1]);
			}
			long long int max=area[0];
			for(i=1;i<n;i++)
			{
				if(area[i]>=max)
					max=area[i];
			}
			printf("%lld\n",max);

		}
	}
	return 0;
}





