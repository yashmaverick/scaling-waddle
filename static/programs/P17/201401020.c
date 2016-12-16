#include<stdio.h>
int main()
{
	int n,l,j,i;
	int pre[100005],in[100005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,k;
		scanf("%d%d",&l,&k);
		int pone,ptwo;
		for(i=0;i<n;i++)
		{
			if(pre[i]==l || pre[i]==k)
			{
				pone=i;
				break;
			}
		}
		for(i=pone+1;i<n;i++)
		{
			if(pre[i]==l || pre[i]==k)
			{
				ptwo=i;
				break;
			}	
		}
		int var;
		int flag=0;
		for(i=0;i<n;i++)
		{
			for(j=pone;j<=ptwo;j++)
			{
				if(in[i]==pre[j])
				{
					printf("%d\n",in[i]);
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	return 0;
}
