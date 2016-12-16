#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,*l,m,i,j,n,k,t;m=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		a=(int *)malloc(sizeof(int)*n);
		l=(int *)malloc(sizeof(int)*(n-k+1));
	     //int a[n],l[n-k+1];
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		m=a[0];
		l[0]=0;
		for(j=0;j<k;j++)
		{
			if(a[j]<m)
			{
				m=a[j];
				l[0]=j;
			}
		}
		for(j=1;j<n-k+1;j++)
		{
			if(l[j-1]<j)
			{
				m=a[j];l[j]=j;
				for(i=j;i<j+k;i++)
				{
					if(a[i]<m)
					{
						m=a[i];
						l[j]=i;
					}
				}
			}
			else
			{
				if(a[l[j-1]]<a[j+k-1])
					l[j]=l[j-1];
				else
					l[j]=j+k-1;
			}
		}
		for(i=0;i<n-k+1;i++)
		{
			printf("%d",a[l[i]]);
			if(i!=n-k)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
