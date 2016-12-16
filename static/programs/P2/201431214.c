#include<stdio.h>
long long int search(long long int *se,long long int q[],long long int r,long long int s)
{
if(*se<q[r]){
return r;

}
long long int mid;
	mid=(r+s)/2;

	if(r>=s)
		return r;
	else
	{
//printf("loop\n");
		if(*se>=q[mid])
		{
//printf("loop1\n");
			search(&se,q,mid+1,s);
		}
		else
		{
//printf("loop2\n");
			search(&se,q,r,mid);
		}
	}
}
int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		long long int a[100001],b[100001],c[100001],new[100002];
		long long int l1,l2,l3,i,sum=0,f,p,m,o;
		scanf("%lld",&l1);
		for(i=0;i<l1;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&l2);
		for(i=0;i<l2;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%lld",&l3);
		for(i=0;i<l3;i++)
		{
			scanf("%lld",&c[i]);
		}
		new[l2]=0;
//o=search(&b[0],c,0,(l3-1));
//printf("value of o %lld\n",o);
		for(i=l2-1;i>=0 ;i--)
		{
		//	for(k=i;k<l3;k++)
			if(i<l3 && c[l3-1]>=b[i])
			{	p=search(&b[i],c,i,(l3-1));
//printf("value of p %lld\n",p);
				new[i]=new[i+1]+l3-p;
//printf("%lld\n",new[i]);
}
else
{new[i]=new[i+1];}
		//	}
		}
//printf("value of new0 %lld",new[0]);
//for(i=l2-1;i>=0;i--)
//{
//printf("value of new %lld",new[i]);
//}
//printf("\n");
		for(m=0;m<l1 ;m++)
		{
//printf("value of m %lld\n",m);
if(m<l2 && b[l2-1]>=a[m])
{
			f=search(&a[m],b,m,(l2-1));
//printf("loop\n");
//printf("value of f %lld",f);
			sum=sum+new[f];
}
}
printf("%lld\n",sum);
}
return 0;
}
