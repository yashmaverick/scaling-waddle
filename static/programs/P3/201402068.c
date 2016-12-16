#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int size;
		scanf("%d",&size);
		int a[size];
		int i,min,msum=0;
		for(i=0;i<size;i++)
		{ scanf("%d",&a[i]);
			if(i==0)
				min=a[i];
			int x=a[i]-min;
			if(min>a[i])
				min=a[i];

			if(msum<x)
			msum=x;
		}
		printf("%d\n",msum);
	}
	return 0;
}
