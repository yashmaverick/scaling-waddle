#include<stdio.h>
int main()
{
	int t,tt;
	scanf("%d",&t);
	for(tt=0;tt<t;tt++)
	{
		int i,n,k,a[100000],b[100000],s[100000],p;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=-1;
		s[0]=0;
		p=1;
		for(i=1;i<n;i++)
		{
			int state=0;
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
		for(i=0;i<n-k+1;i++)
		{
			p=n-1-i;
a:
			if(b[p]<=n-1-i-k)
				s[i]=a[p];
			else
			{
				p=b[p];
				goto a;
			}
		}
		for(i=n-k;i>=0;i--)
			if(i==0)
				printf("%d",s[i]);
			else
			printf("%d ",s[i]);
		printf("\n");
	}
	return 0;
}
