#include<stdio.h>
int a[10000],b[10000];
int merge(int start,int end)
{

	int r=0,i,j,k;
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
{
	int t;
	char str[10000];
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%d",&a[i]);
		}
		merge(0,n-1);
		int state=0;
		for(i=0;i<n-2;i++)
		{
			int ptr1=i+1,ptr2=n-1;
			while(ptr1<ptr2)
			{
				if(a[i]+a[ptr1]+a[ptr2]==k)
				{
					printf("YES\n");
					state=1;
					break;
				}
				if(a[i]+a[ptr1]+a[ptr2]>k)
					ptr2--;
				if(a[i]+a[ptr1]+a[ptr2]<k)
					ptr1++;
			}
			if(state==1)
				break;
		}
		if(state==1)
			continue;
		printf("NO\n");
	}
	return 0;
}
