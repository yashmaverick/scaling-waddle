#include<stdio.h>
#include<string.h>
long long int a[100001];
int partition(long long int l,long long int h)
{
	long long int m;
	if(l<h)
	{
		m=(l+h)/2;
		partition(l,m);
		partition(m+1,h);
		merge_sort(l,m,h);
	}   
}
int merge_sort(long long  int l,long long int m,long long int h)
{
	long long int z,i,y,t[h+1],k;
	i=l;
	z=l;
	y=m+1;
	while(z<=m && y<=h)
	{
		if(a[z]<a[y])
		{
			t[i++]=a[z++];
		}   
		else if(a[z]>a[y])
		{
			t[i++]=a[y++];
		}  
		else
		{
			t[i++]=a[z++];
			t[i++]=a[y++];
		}

	}	
	while(z<=m)
		t[i++]=a[z++];
	while(y<=h)
		t[i++]=a[y++];
	/*	if(z>m)
		{
		for(k=y;k<=h;y++)
		{
		t[i++]=a[k];
		}
		}   
		else
		{
		for(k=z;k<=m;k++)
		{
		t[i++]=a[k];
		}   
		}*/
	for(k=l;k<=h;k++)
	{
		a[k]=t[k];
	}


}

int main(){
	 long long int t,i,n,d,p,ans;
	char c[100005];
	scanf("%lld ",&t);
	while(t--)
	{
		i=1;
		ans=0;
		scanf("%s",c);
		int x=strlen(c);
		if(c[0]=='J')
			a[0]=1;
		else if(c[0]=='M')
			a[0]=99999;
		else
			a[0]=-100000;
		d=0;
		for(i=1;i<x;i++)
		{
			if(c[i]=='J')
				a[i]=1+a[i-1];
			else if(c[i]=='M')
				a[i]=99999+a[i-1];
			else
				a[i]=-100000+a[i-1];
			if(a[i]==0)
				d++;
		}
		partition(0,x-1);
		for(i=0;i<x;i++)
		{
			p=1;
			while(a[i]==a[i+1])
			{
				p++;
				i++;
			}
			ans+=(p*(p-1))/2;
		/*	p++;
			if(a[i]!=a[i+1])
			{
				ans+=(p*(p-1))/2;
				p=0;
			}
			*/
		}
		ans+=d;
		printf("%lld\n",ans);
	}
	return 0;
}







