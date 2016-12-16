#include<stdio.h>
#include<stdlib.h>
#define Max 100000
int main()
{
	int ans,min,max,q,a,b,n,i,in[Max],pre[Max],indin[Max],preind[Max];
	scanf("%d",&n);	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pre[i]);
		preind[pre[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&in[i]);
		indin[in[i]]=i;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		ans=Max+1;
		if(indin[a]>indin[b])
		{
			min=indin[b];
			max=indin[a];
		}
		else
		{
			min=indin[a];
			max=indin[b];
		}
		for(i=min;i<=max;i++)
			if(preind[in[i]]<ans)
				ans=preind[in[i]];
		printf("%d\n",pre[ans]);
	}
	return 0;
}
