#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int ls[100000],rs[100000],a[100000],n,i,top,marea,area;
	while(1)
	{

		marea=0;
		long int width[100000] = { [0 ... 99999] = 1 };
		scanf("%ld",&n);
		if(n==0)
			break;
		top=-1;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
		{
			while(top!=-1 && a[ls[top]]>=a[i])
				top=top-1;
			if(top==-1)
				width[i] += i;
			else
				width[i] += i - ls[top] -1;
			ls[++top]=i;
		}
		/*for(i=0;i<n;i++)
		  printf("%d ",width[i]);
		  printf("\n");*/
		top=-1;
		for(i=n-1;i>=0;i--){
			while(top!=-1 && a[rs[top]]>=a[i] )
				top=top-1;
			if(top==-1)
				width[i] += n-1-i;
			else
				width[i] += rs[top] - i -1;
			rs[++top]=i;
		}
		/*for(i=0;i<n;i++)
		  printf("%d ",width[i]);
		  printf("\n");*/
		for(i=0;i<n;i++)
		{
			area=width[i]*a[i];
			if(area>marea)
				marea=area;
		}
		printf("%ld\n",marea);
	}
	return 0;
}
