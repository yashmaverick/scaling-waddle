#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s[100005];
#define min(x,y) (x<y)?x:y
int compare(const void *a, const void *b)
{
	const char **ia = (const char **)a;
	const char **ib = (const char **)b;
	return strcmp(*ia, *ib);
}
int main()
{
	int t, n, i, j, k, flag, len1, len2, len;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			s[i] = malloc(15);
			scanf("%s", s[i]);
		}
		flag = 0;
		qsort(s, n, sizeof(char *), compare);
		for (i = 1; i < n; i++)
		{
			j = k = 0;
			len1 = strlen(s[i]); len2 = strlen(s[i - 1]);
			len = min(len1, len2);
			flag = 0;
			while (j != len)
			{
				if (s[i][j] != s[i - 1][j])
					break;
				j++;
			}
			if (j == len)
			{
				flag = 1;
				break;
			}
			free(s[i - 1]);
		}
		puts((!flag) ? ("YES") : ("NO"));
	}
	return 0;
}