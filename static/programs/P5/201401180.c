#include <stdio.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		int i,j;
		int a[1000];
		char s[1000];
		scanf("%d%d",&n,&k);
		for (i = 0; i < n; i++)
		{
			scanf(" %s",s);
			scanf("%d",&a[i]);	
		}
		qsort(a,n,sizeof(int),cmpfunc);
		int l,r;
		int f = 0;
		for (i = 0; i < n-2; i++)
		{
			l = i+1;
			r = n-1;
			while(l<r)
			{
				if (a[i] + a[l] + a[r] == k)
				{
					printf("YES\n");
					f = 1;
					break;
				}
				else if (a[i] + a[l] + a[r] < k)
					l++;
				else
					r--;
			}
			if (f == 1)
				break;
		}
		if (f == 0)
			printf("NO\n");
	}
	return 0;
}

	
	
