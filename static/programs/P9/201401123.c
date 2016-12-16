#include<stdio.h>
#include<stdlib.h>
typedef long long int L;
#define s(n) scanf("%lld",&n)

typedef struct xyz
{
	L sum;
	L num;
	L *item;
}bags;
bags *point;


int main()
{
	L n, mod,i,j,k,sum;
	s(n);s(mod); // mod lies btw 23 and 10**9+7
	point=(bags *)malloc(n*sizeof(bags));// dynamically create an array of n bags
	for(i=0;i<n;i++)
	{
		s(point[i].num);//dynamically create an array of num items in a bag
		point[i].item=(L *)malloc(point[i].num*sizeof(L));
		for(j=0;j<point[i].num;j++)
		{
			s(point[i].item[j]);
			int x;
			x=point[i].item[j]%mod;
			point[i].sum=((point[i].sum)%mod+point[i].item[j])%mod;
		}
	}
	
	L tempsum;
	L tempnum;
	L *tempitem;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if( point[i].sum > point[j].sum )
			{
				// swap sums
				tempsum=point[i].sum;
				point[i].sum=point[j].sum;
				point[j].sum=tempsum;

				// swap list pointers
				tempitem=point[i].item;
				point[i].item=point[j].item;
				point[j].item=tempitem;

				// swap number of items
				tempnum=point[i].num;
				point[i].num=point[j].num;
				point[j].num=tempnum;
			}
		}
	
	
	for(i=0;i<n;i++)
	{
		int ans;
		ans=point[i].sum;
		printf("%lld\n",ans%mod);
		for(j=0;j<point[i].num;j++)
			printf("%lld\n",point[i].item[j]);//follow a list
		putchar('\n');
	}
	return 0;
}
