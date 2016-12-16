#include <stdio.h>

int main()
{
	int t,T,n,i,j,pre[100000],in[100000],p1,p2,p1i,p2i;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);

	scanf("%d",&T);

	for(t=0;t<T;t++)
	{
		scanf("%d %d",&p1,&p2);

		for(i=0;i<n;i++)
		{
			if(in[i]==p1)
				p1i=i;

			if(in[i]==p2)
				p2i=i;
		}

		if(p1i>p2i)
		{
			p1i=p1i+p2i;
			p2i=p1i-p2i;
			p1i=p1i-p2i;
		}

		int flag,ans;
		flag=0;

		for(i=0;i<n;i++)
		{
			for(j=p1i;j<=p2i;j++)
			{
				if(pre[i]==in[j])
				{
					flag=1;
					ans=in[j];
				}
			}
			if(flag==1)
				break;
		}

		printf("%d\n",ans);
	}

	return 0;
}
