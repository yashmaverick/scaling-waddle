#include<stdio.h>
struct node {
	long long int val;
	struct node* next;
};
typedef struct node node;
int main()
{
	long long int n;
	scanf("%lld",&n);
	while(n>0)
	{
		long long int a[100000],s[100000],b[100000],i,p,c[100000],d[100000];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		b[0]=-1;
		s[0]=0;
		p=1;
		for(i=1;i<n;i++)
		{
			long long int state=0;
			while(a[s[p-1]]>=a[i])
			{
				p--;
				state=1;
				if(p==0)
				{
					b[i]=-1;
					s[p]=i;
					p++;
					break;
				}
				else if(a[s[p-1]]<a[i])
				{
					b[i]=s[p-1];
					s[p]=i;
					p++;
					break;
				}
			}
			if(state==0)
			{
				b[i]=s[p-1];
				s[p]=i;
				p++;
			}
		}
		for(i=0;i<n;i++)
			c[i]=a[n-1-i];
		d[0]=-1;
		s[0]=0;
		p=1;
		for(i=1;i<n;i++)
		{
			long long int state=0;
			while(c[s[p-1]]>=c[i])
			{
				p--;
				state=1;
				if(p==0)
				{
					d[i]=-1;
					s[p]=i;
					p++;
					break;
				}
				else if(c[s[p-1]]<c[i])
				{
					d[i]=s[p-1];
					s[p]=i;
					p++;
					break;
				}
			}
			if(state==0)
			{
				d[i]=s[p-1];
				s[p]=i;
				p++;
			}
		}
		long long int max=0,r;
		for(i=0;i<n;i++)
		{
			r=a[i]*(n-d[n-1-i]-1-b[i]-1);
			if(r>max)
				max=r;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
