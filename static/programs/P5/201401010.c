#include<stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return (*(int*)a-*(int*)b);
}

int main()
{
	int t,i,n,j,k,a[1000000],x,y,z,flag;
	char night[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		flag=0;
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%s %d",night,&a[j]);
		qsort(a,n,sizeof(int),compare);
		for(j=0;j<n-2;j++)
		{
			x=j;
			y=j+1;
			z=n-1;
			while(y<z)
			{
				if(a[x]+a[y]+a[z]==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				else if(a[x]+a[y]+a[z]>k)
				z--;
				else
				y++;
			}
			if(flag==1)
			break;
		}
		if(flag==0)
		printf("NO\n");
	}
	return 0;
}
