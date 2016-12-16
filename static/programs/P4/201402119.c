#include<stdio.h>
#include<string.h>

long long int*  merge(long long int a[], long long int b[] ,long long int d[] ,long long int m ,long long int n)
{
	long long int i,j,k;
	i=0;j=0;k=0;
	while(i<m && j<n)
	{
		if(a[i]>=b[j])
		{
			d[k]=b[j];
			k++;j++;
		}
		else
		{
			d[k]=a[i];
			k++;i++;
		}
	}
	while(i<m)
	{
		d[k]=a[i];
		k++;i++;
	}
	while(j<n)
	{
		d[k]=b[j];
		k++;j++;
	}
	return d;
}
long long int merge_sort(long long int c[], long long int n)
{
	long long int i;
	long long int left[n],right[n];
	if(n<=1){
		return;
	}
	for(i=0;i<n/2;i++){
		left[i]=c[i];}
	for(i=n/2;i<n;i++){
		right[i-n/2]=c[i];}
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,c,n/2,n-n/2);
	return;
}

int main()
{
	long long int n,t,tmp,i,j,cnt=0;
	long long int  a[100000];
	long long int max,min,var;
	long long int cnt1;
	scanf("%lld",&t);
	getchar();
	while(t--)
	{
		cnt1=0,cnt=0;
		char c[100000];
		min=10000000;
		max=-10000000;
		i=0;cnt=0;
		scanf("%s",c);
		n=strlen(c);
	//	printf("%d\n",n);
		for(i=0;i<n;i++)
		{	
			if(c[i] == 'M'&& c[i] != '\n')
			{
				if(i==0)
					a[i]=1000+1;
				if(i>0)
					a[i]=a[i-1] + 1000 + 1;
			}
			else if(c[i] =='J'&& c[i] != '\n')
			{
				if(i==0)
					a[i]=1;
				if(i>0)
					a[i]=a[i-1] + 1;

			}
			else if(c[i] == 'R'&& c[i] != '\n')
			{
				if(i==0)
					a[i]=-1000-2;
				if(i>0)
					a[i]=a[i-1] - 1000 - 2;
			}
			if(a[i] <= min)
				min=a[i];
			if(a[i] >= max)
				max=a[i];
		}

		merge_sort(a,n);
		min=a[0];max=a[n-1];
		var=max-min+1;
		long long int b[var];
		for(i=0;i<var;i++)
		{
			b[i]=0;
		}
		for(i=0;i<n;i++)
		{
			tmp=a[i]-min;
			if(tmp == -min)
				cnt1++;
			b[tmp]++;
		}
		for(i=0;i<var;i++)
		{
			cnt=cnt+(b[i])*(b[i]-1)/2;
		}	
		printf("%lld\n",cnt+cnt1);
	}
	return 0;
}
