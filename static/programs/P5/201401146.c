#include<stdio.h>
void qsort(int *a,int low,int high)
{
	if(low>=high)
		return;
	int w,i,t;
	w=low;
	for(i=low;i<=high;i++)
	{
		if(a[i]<=a[high])
		{
			t=a[i];
			a[i]=a[w];
			a[w]=t;
			w++;
		}
	}
	qsort(a,low,w-2);
	qsort(a,w,high);
}
int main()
{
	int t,n,k,i,nig[1000],j,h,flag,E;
	char s[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d ",&n,&h);
		for(i=0;i<n;i++)
			scanf("%s %d",s,&nig[i]);
		qsort(nig,0,n-1);
		flag=0;
		for(i=0;i<n-2;i++)
		{
			E=h-nig[i];
			j=i+1;
			k=n-1;
			while(j<k)
			{
				if(nig[j]+nig[k]==E)
				{
					flag=1;
					break;
				}
				else if(nig[j]+nig[k]<E)
					j++;
				else
					k--;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
