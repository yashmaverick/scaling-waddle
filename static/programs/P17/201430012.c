#include <stdio.h>
#include <limits.h>
#define MAX 1000000
int n;
int pre[MAX], in[MAX];
#define min(x,y)	(x<y)?x:y
#define max(x,y)	(x>y)?x:y
int find(int u)
{
	int i;
	for (i = 0; i < n; i++)
		if (in[i] == u)
			return i;
}
int main()
{
	int i, j, q, u, v, l, r, temp1, temp2, ans, flag;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d", &u, &v);
		temp1 = find(u); temp2 = find(v);
		l = min(temp1, temp2); r = max(temp1, temp2);
		flag = 1;
		for (j = 0; j < n; j++)
		{
			for (i = l; i <= r; i++)
			{
				if (pre[j] == in[i])
				{
					flag = 0;
					break;
				}
			}
			if (!flag)
			{
				printf("%d\n", pre[j]);
				break;
			}
		}
	}
	return 0;
}