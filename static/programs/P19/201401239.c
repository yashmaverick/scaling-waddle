#include<stdio.h>
long long int d[1000001],a[1000001],s[100001];
void msort(long long int c[],long long int l,long long int r)
{
	long long int mid=l+(r-l)/2;
	if(r-l==1)
		return ;
	msort(c,l,mid);
	msort(c,mid,r);
	long long int i,j=0,k;
	for(i=l;i<mid;i++)
		d[j++]=c[i];
	i=0;j=mid;k=l;
	while(i<(mid-l) && j<r)
		c[k++]=(d[i]>c[j])?c[j++]:d[i++];
	while(i<(mid-l))
		c[k++]=d[i++];
}
int main()
{
	long long int t,y;
	scanf("%lld",&t);
	for(y=0;y<t;y++)
	{
		long long int w;
		long long int j=0,i;
		long long int n;
		scanf("%lld",&n);
		i=0;
		while(i<n)
		{
			scanf("%lld",&s[i]);
			w=s[i];
			w=w/10;
			while(w!=0)
			{
				a[j]=w;
				w=w/10;
				j++;
			}
			i++;
		}
		//msort(a,0,j);
		msort(s,0,n);
		
		long long int first,last,mid,k=0,search;
		if(j>0)
		{
			msort(a,0,j);
		for(i=0;i<n;i++)
		{

			search=s[i];
			first=0;
			last=j-1;
			mid=(first+last)/2;
			while(first<=last)
                        {
				if(a[mid]<search)
				{
					first=mid+1;
					mid=(first+last)/2;
		
				}
				else if(a[mid]==search)
				{
					k=1;
					break;
				}
				else
				{
					
					last=mid-1;
					mid=(first+last)/2;
				}
			}
	 
			if(k==1)
			{
				break;
			}
		}
		}
		long long int p=1;
		for(i=0;i<n-1;i++)
		{
			if(s[i]==s[i+1])
			{	p=2;
				break;
			}
		}

		if(k==1 || p==2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}










