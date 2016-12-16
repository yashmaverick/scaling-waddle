#include<stdio.h>
int n;
int pre[100000],in[100000];
int val[1000000]={0};
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		val[in[i]]=i;
	}
	int t,a,b,root,ans,flag=0,left=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		root=pre[0];
		left=0;flag=0;
		while(flag!=1)
		{
			if((val[a]<=val[root]&&val[b]>=val[root])||(val[a]>=val[root]&&val[b]<=val[root]))
			{
				ans=root;
				flag=1;
			}
			else
			{
				left++;
				root=pre[left];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}




