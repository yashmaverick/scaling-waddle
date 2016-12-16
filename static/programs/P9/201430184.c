#include<stdio.h>
int main()
{
	int test,count;
	//	scanf("%d",&test);
	//	for(count=0;count<test;count++)
	{
		int n,mod,i,j;
		scanf("%d %d",&n,&mod);
		int a[1000000],t,b[n],c[n],k,l,m,p,h,y;
		for(i=0;i<1000000;i++)
		{
			a[i]=0;
		}
		l=0;
		p=0;
		for(i=0;i<1000000;i++)
		{
			scanf("%d",&t);
			a[i]=t;
			b[l]=i;
			i++;
			p=0;
			for(j=i;j<t+i;j++)
			{
				scanf("%d",&k);
				a[j]=k;
				p=((p%mod)+(a[j]%mod))%mod;
			}
			c[l]=p%mod;
			l++;
			i=j-1;
			m=n;
			if(l==m)
			{
				break;
			}
		}
		for (i = 0 ; i < ( n - 1 ); i++)
		{
			for (j = 0 ; j < n - i - 1; j++)
			{
				if (c[j] > c[j+1]) 
				{
					h   = b[j];
					b[j]   = b[j+1];
					b[j+1] = h;
					y=c[j];
					c[j]=c[j+1];
					c[j+1]=y;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",c[i]);
		   for(j=b[i]+1;j<a[b[i]]+b[i]+1;j++)
		   {
			   printf("%d\n",a[j]);
		   }
		   printf("\n");
		}
	}

return 0;
}

