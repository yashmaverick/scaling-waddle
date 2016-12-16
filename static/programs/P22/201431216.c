#include<stdio.h>
long long int na,nb;
void insertmin(long long int brr[],long long int element)
{
	brr[0]=-1;
//	arr[0]=-1;
	nb++;
	brr[nb]=element;
	long long int x=nb;
	while(brr[x/2]>element)
	{
		brr[x]=brr[x/2];
		x/=2;
	}
	brr[x]=element;
	//printf("xxxx\n");
}
void insertmax(long long int arr[],long long int element)
{
	arr[0]=1000000010;
	//brr[0]=1000000010;
	na++;
	arr[na]=element;
	long long int x=na;
	while(arr[x/2]<element)
	{
		arr[x]=arr[x/2];
		x/=2;
	}
	arr[x]=element;
	//printf("xx\n");
}
void deletemin(long long int brr[])
{
	long long int k,minelement=brr[1],lastelement=brr[nb--],child;
	//if(nb==0)
	//{
	//	return;
	//}
	//else
	{

		for(k=1;2*k<=nb;k=child)
		{
			child=k*2;
			if(child!=nb && brr[child+1]<brr[child])
			{
				child++;
			}
			if(lastelement>brr[child])
			{
				brr[k]=brr[child];
			}
			else
				break;
		}
		brr[k]=lastelement;
	}
}

void deletemax(long long int arr[])
{

	long long int k,minelement=arr[1],lastelement=arr[na],child;
	na=na-1;
	//if(na==0)
	//{
	//	return;
	//}
	//else
	{

		for(k=1;2*k<=na;k=child)
		{
			child=k*2;
			if(child!=na && arr[child+1]>arr[child])
			{
				child++;
			}
			if(lastelement<arr[child])
			{
				arr[k]=arr[child];
			}
			else
			{
				break;
			}
		}
		arr[k]=lastelement;
	}
}


int main()
{
	long long int test,i,j,f[200010],arr[200010],brr[200010],a,b,c,n;
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		long long int mod=1000000007; 
		na=0,nb=0;
		//arr[0]=-1;
		//brr[0]=-1;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		f[1]=1;
		insertmin(brr,f[1]);
		for(j=2;j<=n;j++)
		{
			//printf("%lld %lld \n",arr[1],brr[1]);
			if(na>nb)
			{
				f[j]=((a*arr[1])%mod+(j*b)%mod+c%mod)%mod;
			}
			if(nb>na)
			{
				f[j]=((a*brr[1])%mod+(j*b)%mod+c%mod)%mod;
			}
			if(nb==na)
			{

				f[j]=((a*arr[1])%mod+(j*b)%mod+c%mod)%mod;

			}
			if(j%2==0)
			{

				insertmax(arr,f[j]);	
				long long int y=arr[1];
				deletemax(arr);
				insertmin(brr,y);

			}
			if(j%2==1)
			{
				insertmin(brr,f[j]);
				long long int y=brr[1];
				deletemin(brr);
				insertmax(arr,y);
			}
			//printf("xxx");
		}
		//for(j=1;j<=(n/2+1);j++)
		//{
		//	printf("%lld x ",brr[j]);
		//}
		//printf("\n");
		long long int sum=0;
		//for(j=1;j<=n;j++)
		//{
		//	printf("%lld xx\n",f[j]);
		//}
		for(j=1;j<=n;j++)
		{
			sum+=f[j];
		}
		if(sum!=0)
		printf("%lld\n",sum);
	        else
			printf("1\n");
	}
	return 0;
}








