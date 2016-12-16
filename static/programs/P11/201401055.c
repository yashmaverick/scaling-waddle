#include<stdio.h>
long long int e=1,top1=-1;
//int top=-1;
long long int a[100001];     //main input array
long long int bars[100001];  //stack
long long int n;

long long int calcarea()
{
	long long int max=0;
	long long int bar;
	long long int maxA;

	long long int i=0;
	//	for(i=0;i<n;i++)
	while(i<n)
	{
		//		scanf("%d",&a[i]);
		//		int x;
		//		x=bars[top1];
		if(e==1||a[bars[top1]]<=a[i])
		{
			top1++;
			bars[top1]=i;
			i++;
			/* correct			printf(" %d",bars[top1]);*/
			if(e==1)
				e=0;
		}
		else
			//			if(e!=1&&a[bars[top1]]>a[i])
		{
			//correct		printf("barstop%d\n",a[bars[top1]]);
			//			printf("\nhi");
			bar=bars[top1];
			top1--;
			if(top1==-1)
			{
				e=1;
				//	top1=0;
			}
			if(e==1)
				maxA=a[bar]*i;
			else
				maxA=a[bar]*(i-bars[top1]-1);
			//			printf("maxA=%d\n",maxA);
			if(max<maxA)
				max=maxA;
			//			printf("max=%d",max);
		}
	}

	while(e==0)
	{
		bar=bars[top1];
		top1--;
		if(top1==-1)
		{
			e=1;
			//			top1=0;

		}
		if(e==1)
			maxA=a[bar]*i;
		else
			maxA=a[bar]*(i-bars[top1]-1);
		//		printf("%d\n",maxA);
		if(max<maxA)
			max=maxA;
		//		printf("maxwhile:%d",max);
	}
	//	printf("\nmaxfinal:%d",max);
	return max;
}


int main()
{
	//	int n;
	while(1)
	{

		scanf("%lld",&n);
		if(n!=0)
		{
			long long int i;
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			long long int area;
			area=calcarea();
			printf("%lld\n",area);
		}
		else
			break;	
	}
	return 0;

}

