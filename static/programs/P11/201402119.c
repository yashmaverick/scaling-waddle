#include<stdio.h>

long long int h;

void  push(long long int b[] , long long int element)
{
	h++;
	b[h]=element;
}

void pop(long long int b[])
{
	if(h != -1)
		h--;
}

long long int top(long long int b[])
{
	if(h != -1)
		return b[h];
}

int main()
{
	long long int i,j,n=342312,a[100001],b[100001],x=0,y=0,k,f,area=0,max=0;
	
	while(1)
	{
		max =0,h=-1;
		scanf("%lld",&n);
		if(n == 0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(h != -1)	
				x=top(b);
			if(h == -1 || a[x] <= a[i])
			{
				push(b,i);
			}
			else
			{
				while(1)
				{
					y=top(b);
					k=a[y];
					if(k > a[i] && h!=-1)
					{
						pop(b);
						if(h == -1)
						{
							area = i*k;
						}
						else
						{
							f=top(b);
							area = (i-f-1)*k;
						}
						if(area > max)
						{
							max = area;
						}
					}
					else
					{
						push(b,i);
						break;
					}
				}
			}
		}
		while(h != -1)
		{
			x=top(b);
			pop(b);
			if(h == -1)
				area=a[x]*n;
			else
			{
				y=top(b);
				area=a[x]*(n-y-1);
			}
			if(area > max)
			{
				max = area;
			}
		}	
			printf("%lld\n",max);
	}
	return 0;
}




