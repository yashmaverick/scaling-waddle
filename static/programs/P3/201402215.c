#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		long long int a[100000],b[100000];
		int size,i,j;
		scanf("%d",&size);
		 for(i=0;i<size;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int flag=0,virtmax=0,realmax=0;
		for(i=0;i<size-1;i++)
		{
			
		b[i]=a[i+1]-a[i];
		}
//	int virtmax=0,realmax=0;
		for(i=0;i<size-1;i++)
			{		
				virtmax+=b[i];
				if(virtmax<0)
				virtmax=0;
			//	printf("%lld ",virtmax);
				if(virtmax>realmax)
				realmax=virtmax;
}
					

//				if(a[i+1]<a[i])
//{					flag=1;
//			printf("%d ",i);
//}
//				if(a[i+1]>a[i])
///					flag=0;
//				if(flag==0)
//				virtmax+=a[i+1]-a[i];
//		printf("%lld ",flag);	
//if(flag==1)
//{
//		if(virtmax>realmax)
//	{		realmax=virtmax;
	//		printf("%lld ",virtmax);
//		flag=0;

//		virtmax=0;
//	}

		
		
		
	//	if(virtmax>realmax)
	//		realmax=virtmax;

//		for(i=0;i<size;i++)
//		{	if(a[i]>a[max])
//			max=i;
//	}
//	/		printf("%d\n",max);
//		int min=0;
	//	for(i=0;i<max;i++)
	//	{
	//		if(a[i]<a[min])
	//		min=i;
	//	}
		printf("%lld\n",realmax);
	}
	return 0;
}
	
