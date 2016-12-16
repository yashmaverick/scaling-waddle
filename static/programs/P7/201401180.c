#include <stdio.h>
void merge(int a[], int t[], int lpos, int rpos, int re)
{
	int i;
	int le;
	int n;
	int tpos=lpos;
	le = rpos-1;
	n = re-lpos+1;
	while(lpos<=le && rpos<=re)
	{
		if (a[lpos] <= a[rpos])
			t[tpos++] = a[lpos++];
		else
			t[tpos++] = a[rpos++];
	}
	while(lpos<=le)
		t[tpos++]=a[lpos++];
	while(rpos<=re)
		t[tpos++]=a[rpos++];
	for (i = 0; i < n; i++,re--)
		a[re] = t[re];
}
void sort(int a[], int t[], int l, int r)
{
	int c;
	if (l < r)
	{
		c = (l+r)/2;
		sort(a,t,l,c);
		sort(a,t,c+1,r);
		merge(a,t,l,c+1,r);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int a[1000000];
		int t[1000000];
		int i;
		int f = 0;
		long long int ans = 0;
		long long int count = 1;
		scanf("%d",&n);
		for (i = 0; i < n; i++)
			scanf("%d",&a[i]);
		sort(a,t,0,n-1);
		for (i = 0; i < n-1; i++)
		{
			if (a[i] == a[i+1])
			{
				f = 1;
				count++;
			}
			if (a[i] != a[i+1])
			{
				ans += ((count*(count-1))/2);
				count = 1;
				f = 0;
			}
		}
		ans += count*(count-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}
