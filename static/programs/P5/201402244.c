#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,v,i,sana,j,k,l=0;
		scanf("%d%d",&n,&v);
		int a[1000];
		char b[10];
		for(i=0;i<n;i++)
		{
			scanf("%s",b);
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
			
			if(a[i]>v)
				break;
					for(k=j+1;k<n;k++)
					{               
					        if(a[i]+a[j]>v)
							break;

						if(a[i]+a[j]+a[k]==v)
						{
									l=1;
									break;
								
						}
					}
				
			}
			if(l==1)
				break;
		}
		if(l==1)   
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
