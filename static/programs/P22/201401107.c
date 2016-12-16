#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long long int heap1[200005];

long long int end1=1;


void swap1(long long int val1,long long int val2)
{
	long long int temp=heap1[val1];
	heap1[val1]=heap1[val2];
	heap1[val2]=temp;
	return;
}

void upchecker()
{
	long long int val=end1-1;
	while(val>1&&heap1[val]<heap1[val/2])
	{
		swap1(val,val/2);
		val=val/2;
	}
	return;
}


void downchecker(long long int dval)
{
	if(dval==end1-1||2*dval>end1-1)
		return;
	long long int sval;
	long long int flag=0;
	if(2*dval+1>end1-1)
	{
		if(heap1[dval]>heap1[2*dval])
		{
			swap1(dval,2*dval);
		}
		return;
	}
	if(heap1[dval]>heap1[2*dval])
	{
		if(heap1[2*dval]>heap1[2*dval+1])
			sval=2*dval+1;
		else
			sval=2*dval;
		swap1(sval,dval);
		flag=1;
	}
	else if(heap1[dval]>heap1[2*dval+1])
	{
		//if(heap[2*dval]<heap[2*dval+1])
		//	sval=2*dval;
		sval=2*dval+1;
		swap1(sval,dval);
		flag=1;
	}
	if(flag)
		downchecker(sval);
	return;
}

void insert1(long long int val)
{
	//printf("inserted\n");
	heap1[end1++]=val;
	upchecker();
	return;
}

long long int mindelete()
{
	//printf("deleted\n");
	long long int temp=heap1[1];
	heap1[1]=heap1[end1-1];
	if(end1!=1)
		end1--;
	downchecker(1);
	return temp;
}

void minprint()
{
	long long int i=1;
	for(i=1;i<end1;i++)
	{
		printf("%lld ",heap1[i]);
	}
}

long long int heap2[200005];

long long int end2=1;


void swap2(long long int val1,long long int val2)
{
	long long int temp=heap2[val1];
	heap2[val1]=heap2[val2];
	heap2[val2]=temp;
	return;
}

void uchecker()
{
	long long int val=end2-1;
	while(val>1&&heap2[val]>heap2[val/2])
	{
		swap2(val,val/2);
		val=val/2;
	}
	return;
}






void mchecker(long long int dval)
{
	if(dval==end2-1||2*dval>end2-1)
		return;
	long long int sval;
	long long int flag=0;
	if(2*dval+1>end2-1)
	{
		if(heap2[dval]<heap2[2*dval])
		{
			swap2(dval,2*dval);
		}
		return;
	}
	if(heap2[dval]<heap2[2*dval])
	{
		if(heap2[2*dval]<heap2[2*dval+1])
			sval=2*dval+1;
		else
			sval=2*dval;
		swap2(sval,dval);
		flag=1;
	}
	else if(heap2[dval]<heap2[2*dval+1])
	{
		//if(heap[2*dval]<heap[2*dval+1])
		//	sval=2*dval;
		sval=2*dval+1;
		swap2(sval,dval);
		flag=1;
	}
	if(flag)
		mchecker(sval);
	return;
}


void insert2(long long int val)
{
	//printf("inserted\n");
	heap2[end2++]=val;
	uchecker();
	return;
}

long long int maxdelete()
{
	//printf("deleted\n");
	long long int temp=heap2[1];
	heap2[1]=heap2[end2-1];
	if(end2!=1)
		end2--;
	mchecker(1);
	return temp;
}

void maxprint()
{
	long long int i=1;
	for(i=1;i<end2;i++)
	{
		printf("%lld ",heap2[i]);
	}
}
#define mod 1000000007
int main()
{
	long long int i,j,k,T,a,b,c,d,n,prev;
	//	insert1(1);
	//	insert1(2);
	//	insert1(10);
	//	insert1(7);
	//	minprint();
	scanf("%lld",&T);
	long long int zt;
	long long int median;
	for(i=0;i<T;i++)
	{
		end1=end2=1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		long long int sum=0,func;
		for(j=1;j<=n;j++)
		{
			if(j==1)
			{
				func=1;
				sum+=func;
				prev=func;
				insert2(func);
				continue;
			}
		/*	func=((a%mod)*(median%mod))%mod + ((b%mod)*(i%mod))%mod +c;
			sum += func;
			func%=mod;
			scanf("%lld", &zt);
			median = heap1[1]; zt=func;
			if(zt > median)insert1(zt);
			else insert2(zt);
			if(end1-end2>1){
				insert2(heap1[1]);
				mindelete();
			}
			else if(end2-end1>1){
				insert1(heap2[1]);
				maxdelete();
			}*/
			else
			{
			//1	printf("func is %d \n",func);
				func=((a%mod)*(heap2[1]%mod))%mod + ((b%mod)*(j%mod))%mod +c;
				func%=mod;
				sum=sum+func;

				if(end2>end1)
				{
					if(func>heap2[1])
					{

						insert1(func);
					}
					else
					{
						insert2(func);
						insert1(heap2[1]);
						maxdelete();
					}
				}
				else
				{
					if(func<=heap2[1])
					{
						insert2(func);
					}
					else
					{
						insert1(func);
						insert2(heap1[1]);
						mindelete();
					}
				}
			}

		//	printf("%lld ",heap2[1]);
		}

		printf("%lld\n",sum);
	}
	return 0;
}
						
						
						

					




			//printf("sum is %d\n",sum);



			

