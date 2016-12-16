#include<stdio.h>
int main()
{
	int n,l,count,k,r,s;
	int a[500000];
	while(1)
	{
		count=0;
		scanf("%d",&n);
		if(n==0)
			return 0;
		for(l=0;l<n;l++)
		{
			scanf("%d",&a[l]);
		}
		for(k=0;k<n-2;k++)
		{
			for(r=k+2;r<n;r++)
			{
				for(s=k+1;s<r;s++)
				{
					if(a[s]>a[k]||a[s]>a[r]){
						count++;
					         break;}

				}
			}
		}
		printf("%d\n",count);

	}
	return 0;

}
