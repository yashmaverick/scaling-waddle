#include <stdio.h>
int first(int a[], int low, int high, int x, int n)
{
	if (high >= low)
	{
		int mid = (low+high)/2;
		if ((mid == low || a[mid-1] < x) && a[mid] >= x)
		{
			return mid;
		}
		else if (x > a[mid])
			return first(a,mid+1,high,x,n);
		else
			return first(a,low,mid-1,x,n);
	}
	return -1;	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p1,q1,r1;
		int t3;
		int i;
		long long int ans=0,temp;
		int p[100001],q[100001],r[100001];
		scanf("%d",&p1);
		for(i = 0; i < p1; i++)
			scanf("%d",&p[i]);
		int t1[100001];
		scanf("%d",&q1);
		for(i = 0; i < q1; i++)
			scanf("%d",&q[i]);
		long long int t2[100001];
		
		t2[q1] = 0;
		scanf("%d",&r1);
		for(i = 0; i < r1; i++)
			scanf("%d",&r[i]);
		for (i = q1-1; i >= 0; i--)
		{
			temp = first(r,i,r1-1,q[i],r1);
			if (temp != -1) t2[i] = r1-temp+t2[i+1];
			else t2[i] = t2[i+1];
		}
//		for(i = 0; i < q1; i++)
//			printf("%d ",t2[i]);
//		printf ("\n");
		for (i = 0; i < p1; i++)
		{
			temp = first(q,i,q1-1,p[i],q1);
			if (temp != -1) ans += t2[temp];
		}			
		printf("%lld\n",ans);
	}
	return 0;
}
