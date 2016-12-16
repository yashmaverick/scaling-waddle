#include<stdio.h>
long long int i,m,r1,r2,r[1000000],a[1000000],b[1000000];
void lca(long long int start,long long int end,long long int parent)
{
	for(i=start;i<=end;i++)
	{
		if(b[i]==a[parent])
			break;
	}
	if(i<r1&&i<r2)
		lca(i+1,end,i+1);
	else if(i>r1&&i>r2)
		lca(start,i-1,parent+1);
	else
		printf("%lld\n",b[i]);
}
int main()
{
	scanf("%lld",&m);
	int i;
	for(i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&b[i]); 
		r[b[i]]=i;
	}
	long long int q;
	scanf("%lld",&q);
	while(q--)
	{
		long long int p1,p2;
		scanf("%lld %lld",&p1,&p2);
		r1=r[p1];
		r2=r[p2];
		lca(0,m-1,0);
	}
	return 0;
}
