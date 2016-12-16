#include<stdio.h>
#include<string.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return;
}
void quick_sort(int b[],int low,int high)
{
	int i,j,pivot;
	if(low>=high)
		return;
	pivot=low;
	i=low;
	j=high;
	while(i<j)
	{
		while(b[i]<=b[pivot] && i<=high)
			i++;
		while(b[j]>b[pivot])
			j--;
		if(i<j)
			swap(&b[i],&b[j]);
	}
	swap(&b[pivot],&b[j]);
	quick_sort(b,j+1,high);
	quick_sort(b,low,j-1);
}
int main()
{
	int test,i,j,max=100000;
	scanf("%d",&test);
	while(test--)
	{
		int n,b[100005];
		char a[100005];
		scanf("%s",a);
		n=strlen(a);
		for(i=0;i<n;i++)
		{
			if(a[i]=='J')
				b[i]=max-1;
			if(a[i]=='M')
				b[i]=1;
			if(a[i]=='R')
				b[i]=-max;
		}
		int c=0;
		for(i=1;i<n;i++)
		{
			b[i] = (b[i-1]+b[i]);
			if(b[i]==0)
				c++;
		}/*
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(b[i]>b[j])
					swap(&b[i],&b[j]);*/
		quick_sort(b,0,n-1);
		/*for(i=0;i<n;i++)
			printf("%d ",b[i]);*/
		int d=0,g=0;
		int p;
		for(i=0;i<n;i++)
		{
			p=1;
			while(b[i]==b[i+1])
			{
				p++;
				i++;
			}
			g+=(p*(p-1))/2;
		}
		int ans;
		ans=g+c;
		printf("%d\n",ans);
	}
	return 0;
}




