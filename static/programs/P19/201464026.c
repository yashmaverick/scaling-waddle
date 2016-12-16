#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpfunc(const void *a, const void *b)
{
	const char **i = (const char **)a;
	const char **j = (const char **)b;
	return strcmp(*i,*j);
}
int check(char *a,char *b)
{
	int i,j;
	if(strlen(a)<strlen(b))
		return 0;
	else
	{
		j = strlen(b);
		for(i=0;i<j;i++)
			if(a[i]!=b[i])
				break;
		if(i==j)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		char **s = (char **)malloc(sizeof(char *)*n);
        for(i=0;i<n;i++)
            s[i] = (char *)malloc(sizeof(char)*11);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		qsort(s,n,sizeof(char *),cmpfunc);
		for(i=1;i<n;i++)
		{
			if(check(s[i],s[i-1]))
				break;
		}
		if(i==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
