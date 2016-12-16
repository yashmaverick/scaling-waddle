#include<stdio.h> 
long long int max;

long long int hist(long long int a[],long long int n) {
	long long int j=1,top,temp,area,s;
	top=0;
	long long int b[n];
	b[0]=0;
	max=0;
	while(j<n)
	{
		if(top==-1 || a[j]>=a[b[top]]) 
		{
			top++;
			b[top]=j;
			j++;
		}
		else
		{
			s=top;
			top--;
			if(top==-1)
				area=a[b[s]]*j;
			else
				area=a[b[s]]*(j-b[top]-1); 
			if(max<area)
				max=area;
		}
	}
	while(top!=-1) 
	{
		s=top;
		top--;
		if(top==-1)
			area=a[b[s]]*j; 
		else area=a[b[s]]*(j-b[top]-1);
		if(max<area)
			max=area;
	}
	return max;
}
long long int main()
{

	long long int n,i;
	scanf("%lld",&n);
	while(n!=0) 
	{ 
		long long int a[n];
		if(n!=0)
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			hist(a,n);
			printf("%lld\n",max);
		}
		scanf("%lld",&n);
	}
	return 0;
}

