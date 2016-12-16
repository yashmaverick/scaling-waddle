#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b)
{
	return strcmp(a,b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		getchar();
		char s[n][11];
		for (i = 0; i < n; i++)
		{
			scanf("%s",s[i]);
			//printf("%s\n",s[i]);
		}
		qsort(s,n,11,compare);
		int i1=0,i2=1,flag=0;
		while(i2<n)
		{
			if(strncmp(s[i1],s[i2],1)!=0)
			{
				i1++;
				i2++;
			}
			else
			{
				char *r;
				r = strstr(s[i2],s[i1]);
				if(r==NULL)
				{
					i1++;
					i2++;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}