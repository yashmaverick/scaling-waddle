#include<stdio.h>
int main()
{
	long long int n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;

	long long int i,a[n],s[n],w=-1,topofstack,m,k,l,max=0,area,p=0;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[p]<=a[i] || w==-1)
		{
			w=w+1;
			s[w]=i;
			p=s[w];
		}
		else
		{        
			while(w>-1 && a[s[w]]>a[i])
			{
			topofstack=s[w];
			w--;
			k=(w==-1)?i:i-s[w]-1;         /*i.e if stack is empty k=i*/
			area=a[topofstack]*k;
			if(area>max)
				max=area;
			}
			w=w+1;
			s[w]=i;
			p=s[w];
		}
	}
	while(w!=-1)
	{
		topofstack=s[w];
		w=w-1;
		l=(w==-1)?n:n-s[w]-1;      
		area=a[topofstack]*l;
		if(max<area)
			max=area;
	}
	printf("%lld\n",max);
	}
	return 0;
}
