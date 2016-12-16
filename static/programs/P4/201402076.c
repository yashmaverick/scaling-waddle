#include<stdio.h>
#include<string.h>
long long int a[100005],b[100005];
void qusort(int sp,int ep)
{
	if(sp>=ep)
		return;
	int mid=(sp+ep)/2;
	qusort(sp,mid);
	qusort(mid+1,ep);
	int i=sp,j=mid+1,k=sp;
	
	while(i<=mid&&j<=ep)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=ep)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=sp;i<=ep;i++)
	{
		a[i]=b[i];
	}
	return;
}

int main()
{
	int n,k,i,j,t;
	char c[100005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c);
		n=strlen(c);
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				if(c[i]=='J')
					a[i]=-1000001;
				else if(c[i]=='M')
					a[i]=999999;
				else 
					a[i]=2;
			}
			else
			{
				
				if(c[i]=='J')
					a[i]=a[i-1]-1000001;
				else if(c[i]=='M')
					a[i]=a[i-1]+999999;
				else 
					a[i]=a[i-1]+2;
			}
		}
		a[n]=0;
		qusort(0,n);
		long long ans=0;
		int rep=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
				rep++;
			else
			{
				long long temp;
				temp=rep*1LL*(rep-1);
				temp=temp/2;
				ans+=temp;
				rep=1;
			}
		}
//		for(i=0;i<=n;i++)
//			printf("%lld ",a[i]);

		long long temp;
		temp=rep*1LL*(rep-1);
		temp=temp/2;
		ans+=temp;
		printf("%lld\n",ans);
	}
	return 0;
}

