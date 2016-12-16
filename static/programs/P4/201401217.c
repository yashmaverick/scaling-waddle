#include<stdio.h>
#include<string.h>
void merge(int left[],int right[],int c[],int m,int u)
{
	int i=0,j=0,k=0;
	while(i<m && j<u)
	{
		if(left[i]<right[j])
		{
			c[k++]=left[i++];
		}
		else if(left[i]>right[j])
		{
			c[k++]=right[j++];
		}
		else
		{
			c[k++]=left[i++];
			c[k++]=right[j++];
		}
	}
	while(i<m)
	{
		c[k++]=left[i++];
	}
	while(j<u)
	{
		c[k++]=right[j++];
	}
}
void merge_sort(int a[],int n)
{

	int i;
	int left[n],right[n];
	if(n<=1)
	{
		return;
	}
	for(i=0;i<n/2;i++)
	{
		left[i]=a[i];
	}
	for(i=n/2;i<n;i++)
	{
		right[i-n/2]=a[i];
	}
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,a,n/2,n-n/2);
}
int main()
{
	int t,x,n,y;
	char c,s[100001];
	scanf("%d",&t);	
	for(x=0;x<t;x++)
	{
		getchar();
		scanf("%s",s);
		n=strlen(s);
		int a[n];
		a[0]=0;
		for(y=1;y<(n+1);y++)
		{
			if(s[y-1]=='J')
				a[y]=(a[y-1]+100000);
			else if(s[y-1]=='M')
				a[y]=(a[y-1]+5);
			else
				a[y]=a[y-1]-100005;
		}
		//printf("y is %d\n",y);
		//printf("SRIKANTH\n");
//		for(y=0;y<(n+1);y++)
//			printf("%d ",a[y]);
		merge_sort(a,n+1);
		int ans=0;int count=1;
		for(y=0;y<(n+1);y++)
		{
			if(a[y+1]==a[y])
			{
				count++;
				continue;
			}
			ans=ans+((count*(count-1))/2);
			count=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
