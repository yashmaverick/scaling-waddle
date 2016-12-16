#include<stdio.h>
#define mod 1000000007;
long long int heapmi[200005],heapma[200005],mid;
int heapSizema,heapSizemi;
void Insertmi(long long int ele)
{
	heapSizemi++;
	heapmi[heapSizemi] = ele; 
	int n = heapSizemi;
	long long int temp;
	while(heapmi[n]<heapmi[n/2] && n!=1) 
	{
		temp=heapmi[n];
		heapmi[n] = heapmi[n/2];
		heapmi[n/2]=temp;
		n /= 2;
	}
	//heapmi[n] = ele;
}
void Insertma(long long int ele)
{
	heapSizema++;
	heapma[heapSizema] = ele;
	int n=heapSizema;
	while(heapma[n]>heapma[n/2] && n!=1)
	{
		long long int tmp;
		tmp=heapma[n/2];
		heapma[n/2] = heapma[n];
		heapma[n] = tmp;
		n/=2;
	}
}

long long int DeleteMin()
{
	long long int min,last,temp;
	int n,child;
	min = heapmi[1];
	last= heapmi[heapSizemi--];
	for(n = 1; n*2 <= heapSizemi ;n = child)
	{
		child = n*2;
		if(child != heapSizemi)
		{
			if( heapmi[child+1] < heapmi[child] ) 
			{
				child++;
			}
		}
		if(last > heapmi[child])
		{
			temp=heapmi[n];
			heapmi[n] = heapmi[child];
			heapmi[child]=temp;
		}
		else 
		{
			break;
		}
	}
	temp=heapmi[n];
	heapmi[n] = last;
	last=temp;
	return min;
}


long long int DeleteMax()
{
	long long int min,last,temp;
	int n,child;
	min = heapma[1];
	last= heapma[heapSizema--];
	for(n = 1; n*2 <= heapSizema ;n= child)
	{
		child=n*2;
		if(child != heapSizema )
		{
			if( heapma[child+1] > heapma[child] )
			{
				child++;
			}
		}
		if(last < heapma[child])
		{
			temp=heapma[n];
			heapma[n] = heapma[child];
			heapma[child]=temp;
		}
		else
		{
			break;
		}
	}
	temp=heapma[n];
	heapma[n] = last;
	last=temp;
	return min;
}

void ins2()
{

	if(heapSizema>heapSizemi)
		mid=heapma[1];
	else if(heapSizemi>heapSizema)
		mid=heapmi[1];
	else
	{
		if(heapma[1]>heapmi[1])
			mid=heapmi[1];
		else
			mid=heapma[1];
	}
}



int main()
{
	int flag,t,i,n,j;
	long long int a,b,c,ans,co;
	/*	long long int p,ele;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
		{
		scanf("%lld",&ele);
		Insertmi(ele);
		Insertma(ele);
		}
		for(i=0;i<p;i++)
		{
		printf("%lld ",DeleteMin());
		}
		printf("\n");
		for(i=0;i<p;i++)
		{
		printf("%lld ",DeleteMax());
		}
		printf("\n");*/

	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		flag=0;
		heapSizema=0;
		heapSizemi=0;
		ans=1;
		mid=1;
		scanf("%lld%lld%lld%d",&a,&b,&c,&n);
		Insertma(1);
		j=2;
		while(j<=n)
		{
			co=(a*mid+b*j+c)%mod;
			if(mid<co)
			{

				flag=1;
				if((heapSizemi-heapSizema)<0 || (heapSizemi-heapSizema)>=0 && (heapSizemi-heapSizema)!=1)
				{
					Insertmi(co);

					ins2();
				}
				//if((heapSizemi-heapSizema)==1)
				else
				{
					Insertma(DeleteMin());
					Insertmi(co);

					ins2();
				}

			}
			else
			{
				flag=0;
				if((heapSizema-heapSizemi)<0 || (heapSizema-heapSizemi)>=0 && (heapSizema-heapSizemi)!=1)
				{
					//	Insertmi(DeleteMax());
					Insertma(co);


					ins2();
				}
				else
				{

					Insertmi(DeleteMax());
					Insertma(co);

					ins2();
				}
			}
			ans=ans+co;
			j++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}




















