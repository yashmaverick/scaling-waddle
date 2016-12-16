#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n)
	{
		long long int a[n],b[n],c[n],d,e,p=-1,count=0,i;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		d=a[0];
		e=a[n-1];
		for(i=0;i<n;i++)
		{
			if(i)
			{
				if(a[i]>=d)
					d=a[i];
				else
					count++;
				if(a[n-i-1]>=e)
					e=a[n-1-i];
				else
					count++;
				if(a[i]<b[p])
				{
					b[p+1]=a[i];
					p++;
					c[p]=1;
				}
				else if(a[i]==b[p])
				{
					count+=c[p];
					c[p]++;
				}
				else
					while(a[i]>b[p])
					{
						p--;
						if(p==-1)
						{
							b[0]=a[i];
							p++;
							c[0]=1;
							break;
						}
						else if(a[i]==b[p])
						{
							count+=c[p];
							c[p]++;
							break;
						}
						else if(a[i]<b[p])
						{
							p++;
							b[p]=a[i];
							c[p]=1;
							break;
						}
					}
			}
			else
			{
				p=0;
				b[p]=a[0];
				c[p]=1;
			}
		}
		printf("%lld\n",n*(n-1)/2-count);
		scanf("%lld",&n);
	}
	return 0;
}
