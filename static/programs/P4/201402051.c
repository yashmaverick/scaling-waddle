#include<stdio.h>
void merge(long long int a[],long long int low,long long int mid,long long int high);
void partition(long long int a[],long long int low,long long int high);
int main()
{
	long long int t;
	scanf("%lld",&t);
	int g;
	for(g = 0; g <= t -1; g ++ )
	{
		char s[100001];
		long long int n,a[100001],i,j,p,c,sum;
		scanf(" %[^\n]",s);
		n=strlen(s);
			if(s[0]=='J')
			{
				a[0]=10000;
			}
			if(s[0]=='M')
			{
				a[0]=-9999;
			}
			if(s[0]=='R')
			{
				a[0]=-1;
			}
			int k;
		for(i=1;i<n;i++)
		{
			if(s[i]=='J')
			{
				a[i]=a[i-1]+(10000);
			}
			if(s[i]=='M')
			{
				a[i]=a[i-1]+(-9999);
			}
			if(s[i]=='R')
			{

				a[i]=a[i-1]-1;

			}
		}
			partition(a,0,n-1);
	//		for(i=0;i<n;i++)
	//			printf("%d ",a[i]);
			sum=0;
			p=0;
			c=1;
			for(j=0;j<n;j++)
			{ 
				k=j+1;

				if(a[j]==0)
				{
					p++;
				}
				
				if(a[j]==a[k])
				{
					c++;
				
				}
				else if(a[j]!=a[k]&&c>1)
				{
				sum=sum+((c*(c-1))/2);
				c=1;
				}
			}


		printf("%lld\n",(p+sum));
	}		
		return 0;
	
}

	void merge(long long int a[],long long int low,long long int mid,long long int high)
	{
		long long int h,l,m,p,k,s,t[100001];
		h=0;
		l=low;
		m=mid+1;
		while(l<=mid && m<=high)
		{
			if(a[l]==a[m])
			{
				t[h]=a[l];
				h++;
				l++;
				t[h]=a[m];
				m++;
			}
			if(a[l]<a[m])
			{
				t[h]=a[l];
				l++;
			}
			else
			{
				t[h]=a[m];
				m++;
			}
			h++;
		}
		while(m<=high)
		{
			t[h]=a[m];
			h++;
			m++;

		}
		while(l<=mid)
		{
			t[h]=a[l];
			h++;
			l++;

		}
		for(s=low,h=0;s<=high;s++,h++)
		{
			a[s]=t[h];
		}
	}
	void partition(long long int a[],long long int low,long long int high)
	{
		long long int mid;
		if(low>=high)
			return;
		if(low<high)
		{
			mid=(low+high)/2;
			partition(a,low,mid);
			partition(a,mid+1,high);
			merge(a,low,mid,high);
		}
	}



