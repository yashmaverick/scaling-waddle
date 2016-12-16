#include<stdio.h>

int new[1000000];
void merge(long long int a[],long long int initial,long long int middle,long long int end)
{
	//printf("d\n");
	int m,n,c,l,p,q,x;
	m=initial;
	n=middle+1;
	c=initial;
	while(m<=middle && n<=end)
	{
		if(a[m]>=a[n])
		{	new[c]=a[n];
			n++;
		}
		else
		{
			new[c]=a[m];
			m++;
		}
		c++;
	}
	if(m>middle)
		for(l=n;l<=end;l++)
		{
			new[c]=a[l];
			c++;
		}
	else
		for(l=m;l<=middle;l++)
		{
			new[c]=a[l];
			c++;
		}
	for(x=initial;x<=end;x++)
	{
		a[x]=new[x];
	}
}

int  sort(long long int a[],long long int leftind,long long int rightind)
{
	int mid;
	if(leftind<rightind)
    {
 		mid=(leftind+rightind)/2;
		sort(a,leftind,mid);	
		sort(a,mid+1,rightind);
		merge(a,leftind,mid,rightind);
	}
}
long long int a[1000000], count[1000000];
int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		long long int n,k;	
		long long int i,o=0,l,cp=0;
		long long sum = 0;
		scanf("%lld",&n);
		for(l=0;l<1000000;l++)
		{
			count[l]=1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}	
		sort(a,0,(n-1));
		for(i=0;i<(n-1);i++)
		{
			if(a[i]==a[i+1])
			{
				count[o]++;
			}
			else
			{
				o++;
				cp=o;
			}
		}
		for(k=0;k<=cp;k++)
		{
			sum=sum+((count[k])*(count[k]-1))/2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
