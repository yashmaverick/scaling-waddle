#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,max,n,k,min,a[100000];
		k=-99999;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		scanf("%d",&a[j]);
		min=a[0];
		
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
			min=a[i];
			else if(a[i]>min)
			{max=a[i]-min;
			if(max>k)
			k=max;}
		}
		if(k>0)
		printf("%d\n",k);
		else
			printf("0\n");
	}
		return 0;
}
                

