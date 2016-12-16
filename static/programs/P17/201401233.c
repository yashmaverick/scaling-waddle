#include<stdio.h>
#include<stdlib.h>
int p[10000],ino[10000];
int main()
{
	int n,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(i=0;i<n;i++)
		scanf("%d",&ino[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n1,n2,n1i,n2i,j,res;
		scanf("%d %d",&n1,&n2);
		for(i=0;i<n;i++)
		{
			if(ino[i]==n1)
				n1i=i;
			if(ino[i]==n2)
				n2i=i;
		}
		int flag=0;
		if(n1i>n2i)
		{
			for(i=0;i<n;i++)
			{
				for(j=n2i;j<=n1i;j++)
				{
					if(p[i]==ino[j])
					{
						res=p[i];
						flag=1;
						break;
					}

				}
if(flag==1)
				break;
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=n1i;j<=n2i;j++)
				{
					if(p[i]==ino[j])
					{
						res=p[i];
						flag=1;
						break;
					}

				}
if(flag==1)
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


