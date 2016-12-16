#include<stdio.h>
#define mod 1000000007
long long int heap[200003],heap2[2000005];
long long int point,point2;
void insertmin(int val)
{
	point++;
	heap[point]=val;
	int index=point;
	while(index>1)
	{
		if(heap[index]<heap[index/2])
		{
			int temp=heap[index];
			heap[index]=heap[index/2];
			heap[index/2]=temp;
		}
		index=index/2;
	}
}
void deletemin()
{

	heap[1]=heap[point];
	point--;
	int index=1;
	if(index>point)
		return;
	while(1)
	{

		int maxindex=2*index;
		if(maxindex>point)
			return;
		if(heap[maxindex]>heap[maxindex+1] && maxindex+1<=point)
		{
			maxindex++;
		}
		if(heap[index]>heap[maxindex])
		{
			int temp=heap[index];
			heap[index]=heap[maxindex];
			heap[maxindex]=temp;
		}
		index=maxindex;
		if(index>point)
			break;

	}
}
void insertmax(int val)
{
	point2++;
	heap2[point2]=val;
	int index=point2;
	while(index>1)
	{
		if(heap2[index]>heap2[index/2])
		{
			int temp=heap2[index];
			heap2[index]=heap2[index/2];
			heap2[index/2]=temp;
		}
		index=index/2;
	}
}
void deletemax()
{

	heap2[1]=heap2[point2];
	point2--;
	int index=1;
	if(index>point2)
		return;
	while(1)
	{

		int maxindex=2*index;
		if(maxindex>point2)
			return;
		if(heap2[maxindex]<heap2[maxindex+1] && maxindex+1<=point2)
		{
			maxindex++;
		}
		if(heap2[index]<heap2[maxindex])
		{
			int temp=heap2[index];
			heap2[index]=heap2[maxindex];
			heap2[maxindex]=temp;
		}
		index=maxindex;
		if(index>point2)
			break;

	}
}
long long int mid;
void getmid()
{
	if(point==0 || point2==0)
	{
		if(point!=0)
		{
			mid=heap[1];
		}
		else
		{
			mid=heap2[1];
		}
	}
	else if(point==point2)
	{
		mid=heap2[1];
	}
	else if(point2>point)
	{
		mid=heap2[1];
	}
	else
	{
		mid=heap[1];
	}
}
int main()
{
	long long int j,test,t,a,b,c,n,i,sum,val;
	scanf("%lld", &test);
	for(t=0;t<test;t++)
	{
		point=0;
		point2=0;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
		sum=1;point=0;
		for(i=1;i<=n;i++)
		{
			heap[i]=0;
		}
		insertmax(sum);
		for(i=2;i<=n;i++)
		{
			getmid();
			val=((((a%mod)*(mid%mod))%mod) + ((b%mod)*(i%mod))%mod + c)%mod;
	//		printf("%lld\n", val);
			insertmax(val);
	//		for(j=1;j<=point;j++)
	//		{
	//			printf("%lld->", heap[j]);
	//		}
	//		printf("\n");
	//		for(j=1;j<=point2;j++)
	//		{
	//			printf("%lld->", heap2[j]);
	//		}
	//		printf("\n");
//			printf("%lld %lld\n",point2,point);
			if((point2 - point) >1 || (point != 0 && heap2[1]>heap[1]))
			{
				int top = heap2[1];
				deletemax();
				insertmin(top);
			}
			if((point !=0 && (point - point2)>1))
			{
				int top = heap[1];
				deletemin();
				insertmax(top);
			}
		//	for(j=1;j<=point;j++)
		//	{
		//		printf("%lld->", heap[j]);
		//	}
		//	printf("\n");
		//	for(j=1;j<=point2;j++)
		//	{
		//		printf("%lld->", heap2[j]);
		//	}
		//	printf("\n");
			sum=sum+val;

		}
		printf("%lld\n", sum);
	}
	return 0;
}
