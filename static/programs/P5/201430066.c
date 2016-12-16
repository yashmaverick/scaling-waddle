#include<stdio.h>
int main()
{
	int test_cases,i;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int n,k,j;
		scanf("%d%d",&n,&k);
		int a[n];
		for(j=0;j<n;j++)
		{
			int b[1000];
			scanf("%s",b);
			scanf("%d",&a[j]);
		}
		int x,y,temp;
		for(x=0;x<n;x++)
		{
			for(y=0;y<n-1;y++)
			{
				if(a[y]>a[y+1])
				{
					temp=a[y+1];
					a[y+1]=a[y];
					a[y]=temp;
				}
			}
		}
		int z,flag=0;
		for(x=0;x<n;x++)
		{
			y=x+1;
			z=n-1;
			while(y<z)
			{
				if((a[x]+a[y]+a[z])==k)
				{
					flag=1;
					break;
				}
				else if((a[x]+a[y]+a[z])>k)
					z--;
				else if((a[x]+a[y]+a[z])<k)
					y++;
			}
			if(flag==1)
				break;

		}
		if(flag==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
