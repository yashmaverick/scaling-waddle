#include<stdio.h>
void f(long long int*,long long int*,long long int,long long int,long long int,long long int);
long long int count;
int main()
{
	long long int t,a[100001],b[100001],c[100001],i,mid,l,h,x,j=0,ch,p,q,r;
	scanf("%lld",&t);
	while(j<t)
	{
		count=0;
	scanf("%lld",&p);
	for(i=0;i<p;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&q);
	for(i=0;i<q;i++)
                scanf("%lld",&b[i]);
	scanf("%lld",&r);
	for(i=0;i<r;i++)
		scanf("%lld",&c[i]);
	for(i=0;i<p;i++)
	{
		ch=0;
		l=i;
	        h=q-1;
	//scanf("%d",&x);
	while(l<h)
	{
		mid=(l+h)/2;
		if(b[mid]==a[i])
		{
			while(b[mid-1]==a[i]&&(mid-1)>=i)
				mid--;
			ch++;
			//printf("%d\n",mid);
			f(b,c,q,r,mid,i);
			break;
		}
		else if(b[mid]<a[i])
			l=mid+1;
		else
			h=mid-1;
	}
	if(ch==0&&b[l]<a[i])
	{
		//printf("larger than %d\n",a[l]);
                break;
	}
	else if(ch==0&&b[l]>=a[i])
	{
		//printf("smaller than %d\n",a[l]);
                f(b,c,q,r,l,i);
	}
	}
	printf("%lld\n",count);
	j++;
	}
	return 0;
}
void f(long long int *d,long long int *e,long long int q,long long int r,long long int x,long long int i)
{
	while(x<q)
	{
	int l=x,h=r-1,ch=0,mid;
        while(l<h)
	{
		mid=(l+h)/2;
		if(e[mid]==d[x])
		{
			while(e[mid-1]==d[x]&&(mid-1)>=x)
				mid--;
			ch++;
			//if(mid>=x&&x>=i)
			{
				count+=(r-mid);
				//printf("%d %d %d\n",z[i],d[x],e[mid]);
			break;
		}
		}
		else if(e[mid]<d[x])
                        l=mid+1;
		else
			h=mid-1;

	}
        if(ch==0&&e[l]<d[x])
        {
		//printf("larger than %d\n",a[l]);
		x++;
		break;
	}
	else if(ch==0&&e[l]>=d[x])
	{
		//printf("smaller than %d\n",a[l]);
		//if(l>=x&&x>=i)
		{
			count+=(r-l);
			//printf("%d %d %d\n",z[i],d[x],e[l]);
	        }
	}
	x++;
	//printf("1\n");
	}

}	
