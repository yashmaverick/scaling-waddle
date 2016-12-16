#include<stdio.h>
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int partition(int a[],int strt,int end)
{
	int pivot=a[end],pindx=strt,i;
	for(i=strt;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[pindx]);
			pindx++;

		}
	}
	swap(&a[pindx],&a[end]);
	return pindx;
}
void quicks(int a[],int strt,int end)
{
	if(strt>=end)
		return;
	int pindx;
	pindx=partition(a,strt,end);
	quicks(a,strt,pindx-1);
	quicks(a,pindx+1,end);
}
int main()
{
	int n,i,j,a[1001],K,k,p,t,sum;
	char night[10001];
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&n,&K);
		for(i=0;i<n;i++)
		{
			scanf("%s",night);
			scanf("%d",&a[i]);
		}
		quicks(a,0,n-1);
		p=0;k=n-1;j=1;
		for(i=0;i<n;i++)
		{
			k=n-1;
			j=i+1;
			while(j<k)
			{
				sum=a[i]+a[j]+a[k];
				if(sum==K)
				{
					p=1;
					break;
				}
				else if(sum<K)
					j++;
				else if(sum>K)
					k--;
			}
			if(p==1)
				break;
		}
		if(p==1)
			printf("YES\n");
		else
			printf("NO\n");
		t--;
	}
	return 0;
}
