#include<stdio.h>
#define mod 1000000007
long long int size1=1;
long long int size2=1;
long long int a[1000000];
long long int b[1000000];
long long int f[1000000];
void minin(long long int v)
{
	size1++;
	a[size1]=v;
	long long int now =size1;
	while(a[now/2]>v && now/2>0)
	{
		a[now]=a[now/2];
		now=now/2;
	}
	a[now]=v;
}
long long int delmin()
{
	long long int min=a[1],now,child;
	long long int last=a[size1];
	size1=size1-1;
	//b[1]=last;
	for(now=1;2*now<=size1;now=child)
	{
		child=now*2;
		if(child !=size1)
		{
			if(a[child+1]<a[child])
				child++;
		}
		if(last>a[child])
			a[now]=a[child];
		else
			break;
	}
	a[now]=last;
	return min;
}
void maxin(long long int v)
{
	size2++;
	b[size2]=v;
	long long int now=size2;
	while(b[now/2]<v && now/2>0)
	{
		b[now]=b[now/2];
		now=now/2;
	}
	b[now]=v;
}
long long int delmax()
{
	long long int max=b[1],child,now;
	long long int last=b[size2];
	size2=size2-1;
	//b[1]=last;
	for(now=1;now<=2*size2;now=child)
	{
		child=(now*2)%mod;
		if(child!=size2)
		{
			if(b[child]<b[child+1])
				child++;
		}
		if(b[child]>last)
			b[now]=b[child];
		else
			break;
	}
	b[now]=last;
	return max;
}
/*void func(int n1,int n2,int n3)
{
	//maxin(f[1]);
	size=size2-size1;
	if(size==1||size==0)
	{
		if(size==0)
		{
			if(b[1]>element)
				maxin(f[i]);
			else
			{
				int d=delmin();
				minin(element);
				maxin(d);
			}
		}
		if(size==1)
		{
			if(b[1]>element)
			{
				int d=delmax();
				maxin(element);
				minin(d);
			}
			else
			{
				minin(element);

			}

		}

	}

		//f[2]=(a+(b*2)+c)%mod;
			f[1]=1;
			if(n%2==0)
			{
			int n1=n/2;
			for(i=1;i<=n1;i++)
			minin(f[i]);
			for(i=n1+1;i<=n;i++)
			maxin(f[i]);
			}
			printf("%d\n",f[2]);
}*/
int main()
{
	long long int i,j,y,k,n,m,t,x,c,element;
	scanf("%lld",&t);
	while(t--)
	{
		 long long int sum=0,size;
		 for(i=0;i<1000000;i++)
		 {
			 a[i]=0;
			 b[i]=0;
			 f[i]=0;
		 }
		 size1=0;
		 size2=0;
		scanf("%lld%lld%lld%lld",&y,&x,&c,&n);
		f[1]=1;
		//printf("aaya1\n");
		maxin(f[1]);
		//printf("f[1]%lld\n",f[1]);
		f[2]=(y+(2*x)+c)%mod;
		//printf("f[2]%lld\n",f[2]);
		minin(f[2]);
			//printf("median1 %d\n",b[1]);
		//printf("aaya2\n");
		sum=f[1]+f[2];
		for(i=3;i<=n;i++)
		{
			element=(y*b[1]+x*i+c)%mod;
		//	printf("element %lld\n",element);
		//	printf("median %lld\n",b[1]);
			size=size2-size1;
		//	printf("sz %lld\n",size);
			if(size==1||size==0)
			{
				if(size==0)
				{
					if(b[1]>=element)
						maxin(element);
					else
					{
						minin(element);
						long long int d=delmin();
					//	printf("delmin %lld\n",d);
					//	printf("aa");
						maxin(d);
					//	printf("max idaaf %lld\n",b[1]);
					}
				}
				else if(size==1)
				{
					if(b[1]>element)
					{
						maxin(element);
						long long int d=delmax();
						minin(d);
					}
					else
					{
						minin(element);
					}

				}

			}
			sum=(sum+element);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
