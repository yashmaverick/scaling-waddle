#include<stdio.h>
int mains[1000000];//important concept
int front[1000000];
int stack[1000000];//stack is key.. $star is the counter for stack
int reverse[1000000];
int lashit[1000000];
int main()
{
	//int test;
	//scanf("%d",&test);
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		//	printf("\n");
		scanf("%d",&mains[0]);
		stack[0]=mains[0];
		int star=1,starwar,i,j;
	//	int jugad=0;
	//	for(i=0;i<n;i++)
	//		lashit[i]=-1;
		lashit[0]=0;
		//new +1--\|/
		//         v
		front[0]=-1;
		for(i=1;i<n;i++)
		{
			int flag=0;
			scanf("%d",&mains[i]);
			starwar=star;
			while(starwar--)
			{
				if(mains[i]>stack[star-1])
				{
					front[i]=lashit[star-1];//stack[star-1];
					star++;
					stack[star-1]=mains[i];
					lashit[star-1]=i;
					flag=1;
				//	jugad=1;
				}
				else
				{
					stack[star-1]=0;
					lashit[star-1]=-1;
					star--;
				//	jugad=0;
				}
				if(flag==1)
					break;
			}
			if(flag==0)
			{
				stack[0]=mains[i];
				lashit[0]=i;
				front[i]=-1;//new line added
				star++;
			}
		}
	//	for(i=0;i<n;i++)
	//		lashit[i]=-1;
		lashit[0]=n-1;
		stack[0]=mains[n-1];
		reverse[n-1]=-1;
		star=1;
		for(i=n-2;i>=0;i--)
		{
			int flag=0;
			starwar=star;
			while(starwar--)
			{
				if(mains[i]>stack[star-1])
				{
					reverse[i]=lashit[star-1];//stack[star-1];
					star++;
					stack[star-1]=mains[i];
					lashit[star-1]=i;
					//	jugad=1;
					flag=1;
				}
				else
				{
					stack[star-1]=0;
					lashit[star-1]=i;
					//	jugad=0;
					star--;
				}
				if(flag==1)
					break;
			}
			if(flag==0)
			{
				stack[0]=mains[i];
				lashit[0]=i;
				star++;
				reverse[i]=-1;
			}
		}
		//	printf("\n");
		long long int max=-3;
		long long int ans;
		for(i=0;i<n;i++)
		{

			//		printf("\n\n%d====%d====%d\n\n\n",mains[i],front[i],reverse[i]);
		//	ans=reverse[i]-front[i]-1;
			//if(front[i]==-1)
			//	front[i]=0;
			if(reverse[i]==-1)
				reverse[i]=n;
			ans=reverse[i]-front[i]-1;
			ans=ans*mains[i];
			if(ans>max)
				max=ans;
			//printf("%d\n",ans);
			//		if(i==1)
			//			printf("\n\n%d====%d\n\n\n",front[i],reverse[i]);
			//		printf("%d\n",reverse[i]);
		}
		printf("%lld\n",max);
	}
	return 0;
}
