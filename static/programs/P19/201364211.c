#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mine=0;
int level=0;
int form=0;
int compare(const void *a, const void *b)
{
	return strcmp(a,b);
}
int main()
{
	for(mine=0;mine<25;mine++)
	{
		form++;
		level--;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(mine=0;mine<25;mine++)
		{
			form++;
			level--;
		}
		int n,i;
		scanf("%d",&n);
		for(mine=0;mine<25;mine++)
		{
			form++;
			level--;
		}
		getchar();
		char s[n][11];
		for (i = 0; i < n; i++)
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			scanf("%s",s[i]);
			//printf("%s\n",s[i]);
		}
		qsort(s,n,11,compare);
		int i1=0,i2=1,flag=0;
		while(i2<n)
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			if(strncmp(s[i1],s[i2],1)!=0)
			{
				for(mine=0;mine<25;mine++)
				{
					form++;
					level--;
				}
				i1++;
				i2++;
			}
			else
			{
				for(mine=0;mine<25;mine++)
				{
					form++;
					level--;
				}
				char *r;
				r = strstr(s[i2],s[i1]);
				if(r==NULL)
				{
					for(mine=0;mine<25;mine++)
					{
						form++;
						level--;
					}
					i1++;
					i2++;
				}
				else
				{
					for(mine=0;mine<25;mine++)
					{
						form++;
						level--;
					}
					flag = 1;
					break;
				}
			}
		}
		if(flag==0)
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			printf("YES\n");
		}
		else
		{
			for(mine=0;mine<25;mine++)
			{
				form++;
				level--;
			}
			printf("NO\n");
		}
	}
	return 0;
}
