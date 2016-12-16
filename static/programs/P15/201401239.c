#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d",&y);
	for(x=0;x<y;x++)
	{
		int n,i,j,k,min;
		scanf("%d %d",&n,&k);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<=n-k;i++)
		{
			min=a[i];
			for(j=i;j<i+k-1;j++)
			{
				if(a[j+1]<min)
					min=a[j+1];
			}
			if(i!=n-k)
				printf("%d ",min);
			else
				printf("%d\n",min);
			while(min!=a[i] && i<n-k)
			{
				if(min>=a[i+k])
					min=a[i+k];

					if(i!=n-k-1)
						printf("%d ",min);
					else
						printf("%d\n",min);
				
				i++;
			}
		}
	}
	return 0;
}
