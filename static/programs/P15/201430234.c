#include<stdio.h>
int main()
{
	int w;
	scanf("%d",&w);
	while(w--)
	{
		int n,k,i,j,x;
		scanf("%d %d",&n,&k);
		int a[n+1],b[n+1];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=a[0];
		int s=0;
		for(j=0;j<n;j++)
		{
			b[j]=a[j];
		}
		for(j=1;j<n;j++)	
		{
			if(j>=k)
			{
				s++;


			}
			x=j;
			while(x>s)
			{
				if(b[x]<=b[x-1])
					b[x-1]=b[x];
				else 
					break;
				x--;
			}
		}
		int h;
		for(h=0;h<n-k;h++)
			printf("%d ",b[h]);
		printf("%d\n",b[n-k]);


	}
	return 0;
}
