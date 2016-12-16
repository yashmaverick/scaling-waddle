#include<stdio.h>
int main()
{
	int t,d;
	scanf("%d",&t);
	for(d=0;d<t;d++)
	{
		int n1,n2,n3,count=0;
		scanf("%d",&n1);
		int a[n1],i;
		for(i=0;i<n1;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n2);
		int b[n2];
		for(i=0;i<n2;i++)
			scanf("%d",&b[i]);
		scanf("%d",&n3);
		int c[n3];
		for(i=0;i<n3;i++)
			scanf("%d",&c[i]);
		int x,y,z;
		for(x=0;x<n1;x++)
		{
			for(y=x;y<n2;y++)
			{
				if(b[y]<a[x])
					break;
				else
				{				
					for(z=y;z<n3;z++)
					{
						if(c[z]<b[y])
							break;					
						else
						{					
							if(a[x]<=b[y]&&b[y]<=c[z])
							{
								count=count+n3-z;
								break;
							}
						}

					}
				}
			}

		}
		printf("%d\n",count);

	}
	return 0;
}


