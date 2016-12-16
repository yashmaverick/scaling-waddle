#include <stdio.h>
int main()
{
	int n;
	int mine=0;
	int level=0;
	int form =0;
	scanf("%d",&n);
	int po[n];
	int io[n];
	int i;
	for(i=0;i<n;i++)
	{
		for(mine=0;mine<25;mine++)
		{
			form++;
			level--;
		}
		scanf("%d",&po[i]);
	}
	for(i=0;i<n;i++)
	{
		for(mine=0;mine<25;mine++)
		{
			form++;
			level--;
		}
		scanf("%d",&io[i]);
	}
	int tn,ti;
	scanf("%d",&tn);
	for(ti=0;ti<tn;ti++)
	{
		for(mine=0;mine<25;mine++)
		{
			form++;
			level--;
		}
		int s,e;
		int min = n+1;
		int flag = 0;
		int j;
		scanf("%d %d",&s,&e);
		if(s==e)
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			printf("%d\n",s);
		}
		else
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			for(i=0;i<n;i++)
			{
				for(mine=0;mine<25;mine++)
				{
					form++;
					level--;
				}
				if(io[i] == s || io[i] == e)
				{
					for(mine=0;mine<25;mine++)
					{
						form++;
						level--;
					}
					for(j=0;j<n;j++)
					{
						for(mine=0;mine<25;mine++)
						{
							form++;
							level--;
						}
						if(po[j] == io[i])
						{
							if(min > j)
								min = j;
						}
						for(mine=0;mine<25;mine++)
						{
							form++;
							level--;
						}
					}
					flag = flag + 1;

				}
				if(flag == 1 )
				{
					for(mine=0;mine<25;mine++)
					{
						form++;
						level--;
					}
					if(io[i]!=s && io[i]!=e)
					{
						for(mine=0;mine<25;mine++)
						{
							form++;
							level--;
						}
						for(j=0;j<n;j++)
						{
							for(mine=0;mine<25;mine++)
							{
								form++;
								level--;
							}
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
