#include<stdio.h>
int main()
{
        long long int a[100000],b[100000],c[100000];
	int p,q,r,w,x,count,t,i,j=0;
	scanf("%d",&t);
	while(j<t)
	{
	count=0;
		scanf("%d",&p);
	for(i=0;i<p;i++)
		scanf("%lld",&a[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
		scanf("%lld",&b[i]);
	scanf("%d",&r);
	for(i=0;i<r;i++)
		scanf("%lld",&c[i]);
	for(i=0,w=0,x=0;i<p;)
	{
     
		if(a[i]>b[q-1]||b[w]>c[r-1]||a[i]>c[r-1])
			break;
		if(a[i]<=b[w])
		{
			if(b[w]<=c[x])
			{//printf("%d %d %d\n",i,w,x);
				count++;}
		}
		//printf("%d %d %d\n",i,w,x);
		if(x==r-1)
		{
			if(w!=q-1)
			{
				w++;
				x=w;
			}
			else
			{
				i++;
				w=i;
				x=i;
			}
			continue;
		}
		x++;
	}
        printf("%d\n",count);
	j++;
	}
	return 0;
}
