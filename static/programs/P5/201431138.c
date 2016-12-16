#include<stdio.h>
#include<string.h>
int  sum(int [],int,int);
void quicksort(int [],int,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,p;
		scanf("%d%d",&n,&k);
		int i,x[n],g=0;
		char c[100000];
		for(i=0;i<n;i++)
			scanf("%s%d",c,&x[i]);

		quicksort(x,0,n-1);
		p=sum(x,n,k);
		if(p)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

void quicksort(int x[],int first,int last)
{
	int pivot,j,temp,i;
	if(first>=last)
		return;

	pivot=first;
	i=first;
	j=last;

	while(i<j)
	{
		while(x[i]<=x[pivot]&&i<last)
			i++;
		while(x[j]>x[pivot])
			j--;
		if(i<j)
		{
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
		}
	}
	temp=x[pivot];
	x[pivot]=x[j];
	x[j]=temp;
	quicksort(x,first,j-1);
	quicksort(x,j+1,last);

}
int  sum(int x[],int n,int k)
{
	int l,r,i;
	for(i=0;i<n-2;i++)
	{
		l=i+1;
		r=n-1;
		while(l<r)
		{
			if(x[i]+x[l]+x[r]==k)
				return 1;
			else if(x[i]+x[l]+x[r]<k)
				l++;
			else if(x[i]+x[l]+x[r]>k)
				r--;
		}
	}
	return 0;
}

