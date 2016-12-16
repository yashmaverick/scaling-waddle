#include<stdio.h>
void merge(int left[],int right[],int a[],int n)
{
	int mid=(n/2);
	int nl=(mid);
	int nr=(n-mid);
	int i=0,j=0,k=0;
	while(i<nl && j<nr)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=left[i];
		i++;
		k++;
	}

	while(j<nr)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}
void part(int a[],int n)
{
	if(n<2)
		return;
	int mid=n/2;
	int left[mid];
	int right[n-mid];
	int i;
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}
	part(left,mid);
	part(right,(n-mid));
	merge(left,right,a,n);
}
int main()
{       
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,k,a[10000],l,flag=0;
		char s[1000];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&a[i]);
		}
		part(a,n);
		int sum=0;
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			l=n-1;
			while(j<l)
			{
				sum=a[i]+a[j]+a[l];
				if(sum<k)
					j++;
				else if(sum>k)
					l--;
				else
				{
					printf("YES\n");
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

