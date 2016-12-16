#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	while (n!=0)
	{
	long long int a[n],s[n],j=-1,num=0,k=0,i,p=-1,x,y;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	i=0;
	while(i<n)
	{
		if(j==-1 || p>=a[i])
		{
			j++;
			s[j]=a[i];
			p=s[j];
			i++;
			if(j>1)
			{
				x=s[j];
				y=j;
				while(x==s[y-1] && y>=1)
					y--;
				if(y>0)
				num=num+y-1;
			}
		}
		else
		{
			j--;
			p=s[j];
			num=num+n-i-1;
		}

	}
	printf("%lld\n",num);
	scanf("%lld",&n);
	}
	return 0;
}

