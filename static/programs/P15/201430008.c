#include<stdio.h>
#include<stdlib.h>
int main()
{
        int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,k,j,l;
		scanf("%d",&n);
		scanf("%d",&k);
		int x[10007],y[10007];
		for(j=0;j<n;j++)
		{
			scanf("%d",&x[j]);
			y[j]=x[j];
		}
		int b=0,v,m;
		for(l=1;l<n;l++)	
		{
			v=l;
			m=l;
			  if(m>=k)
				  b++;
				while(v>b)
				{
					if(y[v-1]>y[v])
					y[v-1]=y[m];
					else
						break;
					v--;

				}
		}
	for(i=0;i<n-k;i++)
			printf("%d ",y[i]);
	printf("%d",y[n-k]);
	printf("\n");
	}
	return 0;
}
