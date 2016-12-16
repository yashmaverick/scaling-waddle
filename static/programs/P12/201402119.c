#include<stdio.h>

long long int h=-1,cnt=0;

void push(long long int b[] , long long int data)
{
	h++;
	b[h]=data;
}

void pop(long long int b[])
{
	if(h > -1)
	{
		h--;
	}
}

int top(long long int b[])
{
	if(h > -1)
	{
		return b[h];
	}
}


int main()
{
	long long int i,n,x,k,v,d;v=0;
	while(1)
	{
		scanf("%lld",&n);
		long long int a[n],b[n];
		cnt=0;h=-1;
		if(n == 0)
		{
			break;
		}
		else
		{
			cnt=0;
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
			}
			for(i=0;i<n;i++)	
			{
				if(h != -1)
				{
					x=top(b);
					k = a[x];
				}
				if(h == -1 || k >=a[i])
				{
					push(b,i);
					v=h-1;
					while(v >= 1)
					{
						if(a[b[h]] < a[b[v]])
						{
							cnt =cnt+v;
							break;
						}
						v--;
					}
				}
				else
				{
					while(1)
					{
						if(k >= a[i] || h == -1)
						{
							push(b,i);
							v=h-1;
							while(v >= 1)
							{
								if(a[b[h]] < a[b[v]])
								{
									cnt =cnt+v;
									break;
								}
								v--;
							}
							break;
						}
						else
						{
							pop(b);
							x=top(b);
							k = a[x];
							cnt=cnt+n-i-1;
						}
					}
				}
		}
		printf("%lld\n",cnt);
	}
}
return 0;

}
