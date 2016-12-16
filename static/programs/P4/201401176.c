#include<stdio.h>
#include<string.h>
int temp[100005];
void merge_sort(int a[],int m,int l,int r);
void merge(int a[],int l,int r);
void merge(int a[],int l,int r)
{
	int m;
	m=(l+r)/2;
	if(l>=r)
		return ;
	merge(a,l,m);
	merge(a,m+1,r);
	merge_sort(a,m,l,r);
}
void merge_sort(int a[],int m,int l,int r)
{
	int i,j,k;
	k=l;
	i=l;
	j=m+1;
	while(k<=m&&j<=r)
	{
		if(a[k]<a[j])
		{
			temp[i]=a[k];
			k++;
		}
		else 
		{
			temp[i]=a[j];
			j++;
		}
		i++;
	}
	while(j<=r)
	{
		temp[i]=a[j];
		i++;j++;
	}
	while(k<=m)
	{
		temp[i]=a[k];
		i++;k++;
	}
	for(i=l;i<=r;i++)
		a[i]=temp[i];
}
int main()
{
	int i,p,a[100005],len,t,ans,c,g;
	char b[100005];
	scanf("%d",&t);
	c=getchar();
	while(t--)
	{
		ans=0;
		len=0;
		//i=1;
		scanf("%s",b);
		//while((c=getchar())!='\n')
		len=strlen(b);
			if(b[0]=='J')
				a[0]=-1;
			if(b[0]=='M')
				a[0]=-10004;
			if(b[0]=='R')
				a[0]=10005;
		for(i=1;i<len;i++)
		{
			if(b[i]=='J')
				a[i]=-1;
			if(b[i]=='M')
				a[i]=-10004;
			if(b[i]=='R')
				a[i]=10005;
			a[i]=a[i]+a[i-1];
		}
		//for(i=1;i<len;i++)
		//	a[i]=a[i]+a[i-1];
		//for(i=0;i<len+1;i++)
		//printf("%d ",a[i]);
		merge(a,0,len-1);
		p=0;
		g=0;
		for(i=0;i<len-1;i++)
		{
			p++;
			if(a[i]==0)
				g++;
			if(a[i]!=a[i+1])
			{
				ans+=(p*(p-1))/2;
				p=0;
			}
		}
		if(a[len-1]==0)
			g++;
		ans=ans+g+(p*(p+1))/2;
		printf("%d\n",ans);
	}
	return 0;
}
