#include<stdio.h>
void qsort(long long int a[1001],long long int start,long long int end)
{
	long long int i,j,pivot,temp;
	if(start<end)
	{
		pivot=start;
		i=start;
		j=end;
		while(i<j)
		{
			while(a[i]<=a[pivot])
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		qsort(a,start,j-1);
		qsort(a,j+1,end);
	}
}
int main()
{
	long long int t,n,k,i,j,l,r,a[1001],c,y;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		int w=0;
		scanf("%lld%lld",&n,&k);
		for(j=0;j<n;j++)
		{
			while((c=getchar())!=' ');
			scanf("%lld",&a[j]);
		}
		qsort(a,0,n-1);
		for(j=0;j<n-2&&w==0;j++)
		{
			l=j+1;
			r=n-1;
			while(l<r&&w==0)
			{
				if((a[j]+a[l]+a[r])==k)
				{	
					printf("YES\n");
					w=1;
				}
				if((a[j]+a[l]+a[r])<k)
					l++;
				if((a[j]+a[l]+a[r])>k)
					r--;
			}
		}
		if(w==0)
			printf("NO\n");
	}
	return 0;
}

