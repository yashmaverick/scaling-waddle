#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int main()
{
	int n,i;
	scanf("%d",&n);
	int pre[n],in[n],h2[1000000]={0};
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		h2[in[i]]=i;
	}
/*	for(i=0;i<n;i++)
		printf("%d ",h2[i+1]);
	printf("\n");*/
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,root=0,lo=-1,a;
		scanf("%d %d",&x,&y);
		while(1)
		{
		//	printf("%d\n",root);
			if(h2[pre[root]]<=max(h2[x],h2[y]) && h2[pre[root]]>=min(h2[x],h2[y]))
			{
				printf("%d\n",pre[root]);
				break;
			}
			else if(h2[pre[root]]>max(h2[x],h2[y]))
				root=root+1;
			else if(h2[pre[root]]<min(h2[x],h2[y]))
			{
				a=root;
				root+=h2[pre[root]]-lo;
				lo=h2[pre[a]];
			}
		}
	}
	return 0;
}
