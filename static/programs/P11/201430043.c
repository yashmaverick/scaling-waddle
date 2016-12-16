#include<stdio.h>
//#include<stddef.h>
long long int max=0,first=-1;
long long int x[100007],y[100007];

void Traverse(long long int *a,long long int n)
{
	long long int i,b,c;
	max=0;
	for(i=0;i<n;i++)
	{
		while(a[y[first]]>a[i]&&first!=-1)
		{
			if(y[first]==i-1)
				b=y[first];
			c=b-y[first]+1;
			x[y[first]]=c*a[y[first]];
			first--;
		}
		first++;
		y[first]=i;
	}
	if(first!=-1)
	{
		b=y[first];
		while(first!=-1)
		{
			c=b-y[first]+1;
			x[y[first]]=c*a[y[first]];
			first--;
		}
	}
	max=0;
	for(i=0;i<n;i++)
	{
		while(a[n-y[first]-1]>a[n-i-1]&&first!=-1)
		{
			if(y[first]==i-1)
				b=y[first];
			c=b-y[first];
			x[n-y[first]-1]+=c*a[n-y[first]-1];
			first--;
		}
		first++;
		y[first]=i;
	}
	if(first!=-1)
	{
		b=y[first];
		while(first!=-1)
		{
			c=b-y[first];
			x[n-y[first]-1]+=c*a[n-y[first]-1];
			first--;
		}
	}

}

int main()
{
	long long int j,N,max;
	long long int z[100007];
	while(1)
	{
		max=0;
		scanf("%lld",&N);
		if(N==0)
			break;
		else
		{
			for(j=0;j<N;j++)
				scanf("%lld",&z[j]);
			Traverse(z,N);
			for(j=0;j<N;j++)
			{
				if(max<x[j])
					max=x[j];
			}
			printf("%lld\n",max);
		}
	}
	return 0;
}
