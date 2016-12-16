#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * a,const void * b)
{
	return ( *(long long*)a - *(long long*)b );
}
int main()
{
	 int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		long long int n,i,j,k,a[100001],b[100101],f,m,l,flag=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		j=0;
		//	printf("ak1\n");
		for(i=0;i<n;i++)
		{
			k=a[i];
			while(k!=0)
			{
				k=k/10;
				if(k!=0)
				{
					b[j]=k;
					j++;
				}
			}
		}
		//	printf("ak2\n");
		qsort(b,j,sizeof(b[0]),cmpfunc);	
		qsort(a,n,sizeof(a[0]),cmpfunc);
		//for(i=0;i<j;i++)
	//		printf("%d ",b[i]);
	//	printf("ak3\n");
	//		printf("n: %d\n",n);
		for(i=0;i<n;i++)
		{
//			printf("enter\n");
			if(a[i]==a[i+1])
				flag=1;
			if(flag==1)
				break;
		}
		if(flag==0)
		{	for(i=0;i<n;i++)
		{	f=0;
			l=j-1;
			m=(f+l)/2;
			while(f<=l)
			{
				if(a[i]<b[m])
					l=m-1;
				else if(a[i]==b[m])
					flag=1;
				else if(a[i] > b[m]) 
					f=m+1;
				m=(f+l)/2;
				if(flag==1)
					break;
			}
		//	printf("%d\n",flag);
		if(flag==1)
		break;
		}}
		//printf("ak4\n");
		if(flag==1)
			printf("NO\n");
		else if(flag==0)
			printf("YES\n");
	}
	return 0;
}
