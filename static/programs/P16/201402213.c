#include<stdio.h>
int a[33];
int main()
{
	int n,i;
	scanf("%d",&n);
	a[0]=1;
	for(i=1;i<33;i++)
		a[i]=a[i-1]*2;
	while(n--)
	{
		int q;
		scanf("%d",&q);
		if(q==1)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<33;i++)
			if(a[i]>q)
				break;
		if(q<=a[i-1]+a[i-2]-1)
			printf("%d\n",2*(i-1)-1);
		else
			printf("%d\n",2*(i-1));
	}
	return 0;
}
