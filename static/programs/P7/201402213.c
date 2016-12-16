#include<stdio.h>
int a[1000010],b[1000010];
int i,j,k;
int merge(int start,int end)
{

	int r=0;
	if(start!=(start+end)/2)
		merge(start,(start+end)/2);
	if(((start+end)/2)+1!=end)
		merge(((start+end)/2)+1,end);
	for(i=start,j=((start+end)/2)+1;i<=(start+end)/2&&j<=end;)
	{
		if(a[i]<a[j])
			b[r++]=a[i++];
		else
			b[r++]=a[j++];
	}
	if(i>(start+end)/2)
		for(k=j;k<=end;)
			b[r++]=a[k++];
	else if(j>end)
		for(k=i;k<=(start+end)/2;)
			b[r++]=a[k++];
	for(i=start,j=0;i<=end;i++)
		a[i]=b[j++];


	return 0;
}
int main()
{int t,n,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(p=0;p<n;p++)
			scanf("%d",&a[p]);
		merge(0,n-1);
		a[n]=10000010;
		long long int count=1;
		long long ans=0;
		for(p=1;p<=n;p++)
		{
			if(a[p]==a[p-1])
				count++;
			else
			{
				ans+=(count*(count-1)/2);
				count=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
