#include<stdio.h>
long long int comp(long long int q[],long long int w[],long long int s,long long int d)
{
	while(s<1)
	{
		if(q[s]>w[d])
			s++;
		else
			d++;
	}
	return s;
}
int main()
{
	int t,g;
	scanf("%d",&t);
	for(g=0;g<t;g++)
	{
		long long int a,b,c,i;
		scanf("%lld",&a);
		long long int aa[a];
		for(i=0;i<a;i++)
			scanf("%lld",&aa[i]);
		scanf("%lld",&b);
		long long int bb[b];
		for(i=0;i<b;i++)
			scanf("%lld",&bb[i]);
		scanf("%lld",&c);
		long long int cc[c];
		for(i=0;i<c;i++)
			scanf("%lld",&cc[i]);
		long long int ans[b];
		long long int j,k=0;
		i=0;
		long long int get =comp(aa,bb,i,0);
		for(i=0;i<b;i++)
		{
			if(k<i)
				k=i;
			if(k>=c)
				ans[i]=0;
			else
			{
			   while(k<c)
			  {
				if (bb[i]>cc[k])
					k++;
				else
					break;
			  }
			  ans[i]=c-k;
		    }
		}
		long long int u;
		long long int yyy=0;
		for(u=0;u<b;u++)
		{
			yyy=yyy+bb[u];
		}
		if(yyy>a)
			yyy=0;
		long long int temp=0;
		for(j=b-1;j>=0;j--)
		{
			temp+=ans[j];
			ans[j]=temp;
		}
		long long int an=0;
		j=0;
		i=0;
		for(i=0;i<a;i++)
		{
			if(j<i) j=i;
			while(j<b)
			{
				if(aa[i]>bb[j])
					j++;
				else
					break;
			}
			if(j<b)
				an+=ans[j];
			else
				break;
		}
		printf("%lld\n",an);
	}
	return 0;
}
