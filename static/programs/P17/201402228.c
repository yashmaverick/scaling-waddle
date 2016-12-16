#include<stdio.h>
int pre[100];
int in[100];
int stat;
int main()
{
	int n,i,j,l,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	int t,m,k,le,x,y;
	int ri;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		stat=0;
		le=0;
		ri=n;
		scanf("%d%d",&x,&y);
	//	printf("%d %d\n",x,y);
		for(j=0;j<n;j++)
		{
			if(in[j]==x)
			{
				m=j;
				break;
			}
		}
		for(p=0;p<n;p++)
		{
			if(in[p]==y)
			{
				l=p;
				break;
			}
		}
	//	printf("%d\n",n);
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				
				if(le<=k && ri>=k || le>=k && ri<=k)
				{
					if(in[k]==pre[j])
					{
					//	printf("%d\n",k);
						if(m<k && l>k || m>k && l<k || m==k || l==k)
						{
					//		printf("hi");
				                        printf("%d\n",in[k]);
							stat=1;
							break;
							
						}
						else
						{
							if(m>k && l>k)
							{
								le=k+1;
								ri=n-1;
						//flag1=1;
							}
							else if(m<k && l<k)
							{
								le=0;
								ri=k-1;
							//	flag1=1;
							}

						}
					}
				}
			//rintf("bye\n");
			}
			if(stat==1)
				break;
		}
	}
	return 0;
}












