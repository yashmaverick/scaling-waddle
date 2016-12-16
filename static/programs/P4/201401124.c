#include<stdio.h>
int compa(const void* a,const void * b)
{
	return(*(int*)a - *(int*)b);
}
/*void qso(long long int l,long long int r,long long c[])
{
	//printf("kajjndkjsd\n");
	if(l==r)
	{
		return;
	}
	long long int i,w=l,temp;
	for(i=l;i<r;i++)
	{
		if(c[i]<=c[r])
		{
			temp=c[i];
			c[i]=c[w];
			c[w]=temp;
			w++;
		}
		
	}
	temp=c[w];
	c[w]=c[r];
	c[r]=temp;
	qso(l,w-1,c);
	qso(w,r,c);
}*/

int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
		int i,c[6],b[1000007],ans=0,sum=0,n,k,count=0;
		char a[100006];
		scanf("%s",a);
		b[0]=0;
		k=1;
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='J')
				sum=sum+(-1);
			else if(a[i]=='M')
				sum=sum+(100000+1);
			else if(a[i]=='R')
				sum=sum+(-100000);
			b[k++]=sum;
		}
	//	for(i=0;i<6;i++)
	//	{
	//		scanf("%lld",&c[i]);
	//	}
	//	qso(0,5,c);
	//	for(i=0;i<6;i++)
	//		printf("%lld ",c[i]);
	//	printf("\n");
	//	printf("%lld\n",k);
		//qso(0,k-1,b);
		qsort(b,k,sizeof(int),compa);
		for(i=0;i<k;i++)
		{
			if(b[i]!=b[i+1])
			{	
				count++;
				ans=ans+(count*(count-1)/2);
				count=0;
			}
			else
				count++;
		}
		printf("%d\n",ans);
		t--;

	}
	return 0;
}
