#include<stdio.h>
#include<math.h>
#define f(i,n) for(i=0;i<n;i++)
#define LL long long int 
LL A[1000010],a[1000010];
void read_int(int *address1)
{
	scanf("%d",address1);
}
void read_long(LL *address)
{
	scanf("%lld",address);
}
void hem(LL *pointer)
{
	printf("%lld\n",*pointer);
}
int main()
{
	int t;
	read_int(&t);
	LL max=-10000001,min=10000001,n,ans=0,x,i;
	while(t--)
	{
		max=-10000001;
		min=10000001;
		ans=0;
		read_long(&n);
		f(i,n)
		{
			read_long(&a[i]);
			max=fmax(a[i],max);
			min=fmin(a[i],min);
		}
		f(i,max-min+1) A[i]=0;
		f(i,n) A[a[i]-min]++;
		f(i,max-min+1)
		{
			x=A[i];
			ans+=(x*(x-1))/2;
		}
		hem(&ans);
	}
	return 0;
}
