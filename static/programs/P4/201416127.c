#include<stdio.h>
#include<string.h>
void partition(int a[],int low,int high);
void mergesort(int a[],int low,int mid,int high);
int per(int n)
{
	return n*(n-1)/2;
}
int func(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}
void partition(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergesort(a,low,mid,high);
	}
}
void mergesort(int a[],int low,int mid,int high)
{
	int i,m,k,l,b[100000];
	l=low;i=low;m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(a[l]<=a[m])
		{
			b[i]=a[l];
			l++;
		}
		else
		{
			b[i]=a[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=b[k];
	}
}
int main()
{
	int l,t,k=0;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		int i,j;int length;
		int c;int a[100000];
		char h[100000];
		a[0]=0;
		i=1;int ans=0;
		//if(k==0)
		//	c=getchar();
		//k=1;
		scanf("%s",h);
		length=strlen(h);
		for(j=0;j<length;j++)
		{
			if(h[j]=='J')
			{
				a[i]=1+a[i-1];
				i++;
			}
			if(h[j]=='M')
			{
				a[i]=-3+a[i-1];
				i++;
			}
			if(h[j]=='R')
			{
				a[i]=2+a[i-1];
				i++;
			}
		}
		/*while((c=getchar())!='\n')
		  {
		  if(c=='J')
		  {
		  a[i]=1+a[i-1];
		  i++;
		  }
		  if(c=='M')
		  {
		  a[i]=-3+a[i-1];
		  i++;
		  }
		  if(c=='R')
		  {
		  a[i]=2+a[i-1];
		  i++;
		  }
		  }*/
		//	qsort(a,i,sizeof(int),func);	
		//		for(j=0;j<i;j++)
		//			printf("%d ",a[j]);
		//		qsort(a,i,sizeof(int),func);
		partition(a,0,i-1);
//		for(j=0;j<i;j++)
//			printf("%d\n",a[j]);
		int count=1;
		j=0;int k=1;
		while(j!=i-1)
		{
			if(a[j]==a[j+1])
			{
				k=1;
				count++;
			}
			else if(a[j]!=a[j+1])
			{
				ans=ans+per(count);
				count=1;
				k=1;
			}
			j++;
			if(j==i-1 && k==0)
				ans=ans+per(count);
		}
		printf("%d\n",ans);
	}
	return 0;
}
