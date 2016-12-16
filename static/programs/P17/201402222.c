#include<stdio.h>
int main()
{
	int n,I[1000001],P[1000001],js,t,w,J,W,r,i,j,head,tail,flag1,flag2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&P[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&I[i]);
	}
	scanf("%d",&t);
	int flag,flag3;
	while(t--)
	{
		flag1=0;flag2=0;
		scanf("%d %d",&W,&J);
		for(i=0;i<n;i++)
		{
			if(I[i]==W)
			{
				w=i;
				flag1=1;
			}
			if(I[i]==J)
			{
				js=i;
				flag2=1;
			}
			if(flag1==1 && flag2==1)
			{
				break;
			}
		}
		flag=1;
		if(js>w)
		{
			flag=0;
		}
		flag3=1;
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(P[i]==I[j])
					{
						if((flag==0 && (j>=w && j<=js)) || (flag==1 && (j<=w && j>=js)))
						{
							printf("%d\n",I[j]);
							flag3=0;
							break;
						}
					}
				}
				if(flag3==0)
				{
					break;
				}
			}


	}
	return 0;
}
