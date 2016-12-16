#include<stdio.h>
void merge(long long int a[1001],long long int initial,long long int middle,long long int end)
{
	//printf("d\n");
long long int new[1001];
long long int m,n,c,l,p,q,x;
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

int  sort(long long int a[1001],long long int leftind,long long int rightind)
{
long long int mid;
	if(leftind<rightind)
{
		mid=(leftind+rightind)/2;
sort(a,leftind,mid);
sort(a,mid+1,rightind);
merge(a,leftind,mid,rightind);

	}
return ;
}
int main()
{
long long int n,mod,j=0,weight[2][1001],d,c,v,x=0;
long long int a[1000001],sum,l,i,p,new[1001],total,flag[1001];
scanf("%lld%lld",&n,&mod);
for(i=0;i<n;i++)
{
sum=0;
scanf("%lld",&a[j]);
weight[1][i]=j;
d=a[j];
for(l=0;l<d;l++)
{
//printf("for1\n");
j++;
scanf("%lld",&a[j]);
sum=(sum+(a[j]%mod))%mod;
}
weight[0][i]=sum;
new[i]=weight[0][i];
j++;
total=j;
flag[i]=1;
}
sort(new,0,(n-1));
for(i=0;i<n;i++)
{
printf("%lld\n",new[i]);
for(j=0;j<n;j++)
{
if(flag[j]==1 && new[i]==weight[0][j])
{
x=j;
flag[j]=0;
break;
}
}
v=weight[1][x];
c=a[weight[1][x]];
while(c--)
{
printf("%lld\n",a[v+1]);
v++;
}
printf("\n");
}
return 0;
}
