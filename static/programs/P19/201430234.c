#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dot=0;
int lev=0;
int fo=0;
int compare(const void *a, const void *b)
{
	return strcmp(a,b);lev++;
}
int main()
{lev++;
	int t;lev++;
	scanf("%d",&t);lev++;
	while(t--)
	{lev++;
		int n,i;lev++;
		scanf("%d",&n);lev++;
		getchar();lev++;
		char s[n][11];lev++;
		for (i = 0; i < n; i++)
		{lev++;
			scanf("%s",s[i]);lev++;
			//printf("%s\n",s[i]);lev++;
		}lev++;
		qsort(s,n,11,compare);lev++;
		int i1=0,i2=1,flag=0;lev++;
		while(i2<n)
		{lev++;
			if(strncmp(s[i1],s[i2],1)!=0)
			{lev++;
				i1++;lev++;
				i2++;lev++;
			}
			else
			{lev++;
				char *r;lev++;
				r = strstr(s[i2],s[i1]);lev++;
				if(r==NULL)
				{lev++;
					i1++;lev++;
					i2++;lev++;
				}
				else
				{lev++;
					flag = 1;lev++;
					break;lev++;
				}
			}lev++;
		}
		if(flag==0)
		{lev++;
			printf("YES\n");lev++;
		}
		else
		{
			lev++;
			printf("NO\n");lev++;
		}lev++;
	}
	return 0;
}