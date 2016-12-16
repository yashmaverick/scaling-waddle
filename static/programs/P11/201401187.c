#include<stdio.h>
#define ll long long int
ll i,a[100001]={0},max=100001;
void push();
void pop();
void print();
int main()
{
	ll n,v,s[100001],j,max,area,k,x;
	i=-1;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		for(j=0;j<n;j++)
			scanf("%lld",&s[j]);
		max=0;
		j=0;
		while(j<n)
		{
			if(i==-1||s[a[i]]<=s[j])
				push(j++);
			else
			{
				x=a[i];
				pop();
				if(i==-1)
					k=j;
				else
					k=j-a[i]-1;
				area=s[x]*k;
				if(max<area)
					max=area;
//				printf("%d\n",max);
			}
		}
		while(i!=-1)
		{
			x=a[i];
			pop();
			if(i==-1)
				k=j;
			else
				k=j-a[i]-1;
			area=s[x]*k;
			if(max<area)
				max=area;
//			printf("%d\n",max);
		}
		printf("%lld\n",max);
	}
	return 0;
}
void push(ll v)
{
	if(i==max-1)
		return;
	i=i+1;
	a[i]=v;
	return;
}
void pop()
{
	if(i==-1)
		return;
	i=i-1;
	return;
}
/*void print()
{
	ll j;
	if(i==-1)
	{
		printf("-1");
		return;
	}
	for(j=i;j>=0;j--)
		printf("%d ",a[j]);
	printf("\n");
	return;
}*/

	



