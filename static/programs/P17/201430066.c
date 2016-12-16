#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],b[n],c[n];
	int i=0;
	while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
	}
	i=0;
	while(i<n)
	{
		scanf("%d",&b[i]);
		i++;
	}
	int t;
	scanf("%d",&t);
	i=0;
	while(i<t)
	{
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		int j=0;
		int p,q;
		while(j<n)
		{
			if(x==b[j])
				p=j;
			if(y==b[j])
				q=j;
			j++;
		}
		int k;
		if(p>q)
		{
			k=p;
			p=q;
			q=k;
		}
		//	printf("%d ",p);
		//	printf("%d\n",q);
		j=p;

		int m=0;
		while(j<q+1)
		{
			c[m]=b[j];
			//	printf("%d ",c[m]);
			j++;
			m++;	
		}
		//	printf("\n");
		i++;
		int r=0,s=0,flag=0;
		while(r<n)
		{
			s=0;
			while(s<m)
			{	
				//	printf("%d<-->%d",c[s],a[r]);
				if(c[s]==a[r])
				{
					printf("%d\n",c[s]);
					flag=1;
					break;
				}
				s++;
			}
			if(flag==1)
				break;
			r++;
		}

	}
	return 0;
}
