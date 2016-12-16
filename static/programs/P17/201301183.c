#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int po[n];
	int io[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&po[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&io[i]);
	}
	int tn,ti;
	scanf("%d",&tn);
	for(ti=0;ti<tn;ti++)
	{
		int s,e;
		int min = n+1;
		int flag = 0;
		int j;
		scanf("%d %d",&s,&e);
		if(s==e)
		{
			printf("%d\n",s);
		}
		else
		{
		for(i=0;i<n;i++)
		{
			if(io[i] == s || io[i] == e)
			{
				for(j=0;j<n;j++)
				{
					if(po[j] == io[i])
					{
						if(min > j)
							min = j;
					}
				}
				flag = flag + 1;

			}
			if(flag == 1 )
			{
				if(io[i]!=s && io[i]!=e)
				{
				for(j=0;j<n;j++)
				{
					if(po[j] == io[i])
					{
						if(min > j)
							min = j;
					}
				}
			}
			}
			
		}
		printf("%d\n",po[min]);
	}
	}
	return 0;
}
