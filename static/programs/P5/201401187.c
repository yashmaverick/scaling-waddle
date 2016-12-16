#include<stdio.h>
void sort();
int partition();
void triplet();
int main()
{
	int n,k,t,i;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int a[n];
		for(i=0;i<n;i++)
		{
			while(1)
			{
				scanf("%c",&c);
				if(c==' ')
					break;
			}
			scanf("%d",&a[i]);
		}
		triplet(a,n,k);
	}
	return 0;
}
void triplet(int a[],int n,int k)
{
	int i,h,l;
	sort(a,0,n-1);
	for(i=0;i<n-2;i++)
	{
		l=i+1;
		h=n-1;
		while(l<h)
		{
			if(a[i]+a[l]+a[h]==k)
			{
				printf("YES\n");
				return;
			}
			else if(a[i]+a[l]+a[h]>k)
				h--;
			else
				l++;
		}
	}
	printf("NO\n");
	return;
}
void sort(int a[],int l,int h)
{
	if(l<h)
	{
		int p= partition(a,l,h);
		sort(a,l,p-1);
		sort(a,p+1,h);
	}
}
int partition(int a[],int l,int h)
{
	int temp;
	int x=a[h];
	int i=(l-1),j;
	for(j=l;j<h;j++)
	{
		if(a[j]<=x)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[h];
	a[h]=temp;
	return (i+1);
}



