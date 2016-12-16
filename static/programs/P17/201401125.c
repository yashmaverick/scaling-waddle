#include <stdio.h>
int main()
{
	int n,i,pren[100005],node[100005];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pren[i]);
	for(i=0;i<n;i++)
		scanf("%d",&node[i]);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,ai,bi,ri,j;
		scanf("%d%d",&a,&b);
		for(i=0;i<n;i++)
		{
			if(node[i]==a)
				ai=i;
			if(node[i]==b)
				bi=i;
		}
		int root;
		for(i=0;i<n;i++)
		{
			root=pren[i];
			for(j=0;j<n;j++)
				if(root==node[j])
					ri=j;
			if((ai<=ri && bi>=ri) || (ai>=ri && bi<=ri))
			{
				printf("%d\n",root);
				break;
			}
		}

	}
	return 0;
}