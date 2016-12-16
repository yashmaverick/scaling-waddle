#include<stdio.h>
int main()
{
	long long int top,i,n,a[100010],b[100010],s[100010],p,max_count,max,t;
	scanf("%lld",&t);
	while(t--)
	{
	top=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	b[n-1]=0;
	s[0]=n-1;
	for(i=n-2;i>=0;i--)
	{
		if(top==-1 || a[s[top]] < a[i])
		{
			b[i]=b[s[top]]+1;
			s[++top]=i;
		}
		else
		{
			while(1)
			{
				if(top!=-1)
					p=a[s[top--]];
				else
				{
					b[i]=b[s[top+1]]+1;
					s[++top]=i;
					break;
				}

				//printf("p=%d\n",p);
				if(p<a[i])
				{
					top++;
					b[i]=b[s[top+1]]+1;
					s[++top]=i;
					break;
				}
			}
		}
	}         
	/*for(i=0;i<n;i++)
		printf("%lld ",b[i]);
	printf("\n");*/
	max_count=b[0];
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(b[i]>max_count)
		{
			max_count=b[i];
			max=a[i];
		}
		if(b[i]==max_count)
		{
			if(a[i]<max)
			{
				max=a[i];
			}
		}
	}
	printf("%lld %lld\n",max,max_count);
	}




	return 0;
}


