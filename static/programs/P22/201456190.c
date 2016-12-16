#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define MAX 200005
#define mod 1000000007
long long int count=0;
long long int minind=0;
long long int maxind=0;
long long int a[MAX];
long long int b[MAX];


void minheapinsert(long long int d)
{
	minind++;
	if(minind==1)
	{
		a[1]=d;
	}
	else
	{
		a[minind]=d;
		long long int j=minind;
		while(1)
		{
			long long int k;
			k=j;
			j=j/2;
			if(a[j]>a[k]&&j>0)
			{
				long long int temp;
				temp=a[k];
				a[k]=a[j];
				a[j]=temp;

			}
			else
			{
				a[k]=d;
				break;
			}
		}
	}  
	return;
}

void maxheapinsert(long long int d)
{
	maxind++;
	if(maxind==1)
	{
		b[1]=d;
	}
	else
	{
		b[maxind]=d;
		long long int j=maxind;
		while(1)
		{
			long long int k;
			k=j;
			j=j/2;
			if(b[j]<b[k]&& j>0)
			{
				long long int temp;
				temp=b[k];
				b[k]=b[j];
				b[j]=temp;

			}
			else
			{
				b[k]=d;
				break;
			}
		}
	}



	return;
}

long long int minheapdelete(long long int flag)
{
	long long int y=a[1];
	if(flag==1)
	{	
	long long int t=a[minind];
	a[1]=t;
	a[minind]=LLONG_MAX;
	long long int k=1;;
        long long int j=1;
	long long int g=1;
	while(1)
	{

		j=2*k;
		g=(2*k)+1;

		if(a[j]<a[k] && a[j]<a[g])
		{

			long long int temp;
			temp=a[k];
			a[k]=a[j];
			a[j]=temp;
			k=j;

		}
		else if(a[g]<a[k] && a[g]<a[j])
		{

			long long int tempo;
			tempo=a[k];
			a[k]=a[g];
			a[g]=tempo;
			k=g;
		}
		else{
          	minind=minind-1;
			break;
		}
	}
	}
       
	return y;
}
long long int maxheapdelete(long long int flag)
{
	long long int y=b[1];
	if(flag==1)
	{

	long long int t=b[maxind];
	b[1]=t;
	b[maxind]=0;
	long long int k=1;;
	long long int j=1;
	long long int g=1;
	while(1)
	{

		j=2*k;
		g=(2*k)+1;

		if(b[j]>b[k] && b[j]>b[g])
		{

			long long int temp;
			temp=b[k];
			b[k]=b[j];
			b[j]=temp;
                        k=j;
		}
		else if(b[g]>b[k] && b[g]>b[j])
		{

			long long int tempo;
			tempo=b[k];
			b[k]=b[g];
			b[g]=tempo;
			k=g;
		}
		else{
			maxind=maxind-1;
			break;
		}
	}}
       
	return y;
}


int main()
{

	int test;
	scanf("%d",&test);
	while(test--)
	{
        count=1;
	minind=0;
	maxind=0;
	long long  int p,q,r,s,n;
	scanf("%lld %lld %lld %lld",&p,&q,&r,&n);
	long long  int x,i;
	for(i=1;i<=MAX;i++)
	{
		a[i]=LLONG_MAX;
		b[i]=0;
	}   
	x=((p*1)+(q*2)+(r))%mod;
	
	if(x<1)
	{
		minheapinsert(1);
		maxheapinsert(x);
	}	

	else
	{
	
		minheapinsert(x);
		maxheapinsert(1);
	}
	count=count+x;
//        printf("%lld ",x);
	for(i=3;i<=n;i++)
	{
		long long int y=minind-maxind;
		long long int z;
	
		z=maxheapdelete(0);
	      
		x=((p*z)+(q*i)+(r))%mod;
//	        printf("%lld ",x);
		y=minind-maxind;
		if(y==0)
		{
			if(x<=b[1])
				maxheapinsert(x);
			else if(x>=a[1])
			{
				long long int l;
				l=minheapdelete(1);
				maxheapinsert(l);
				minheapinsert(x);
			}

			else 
				maxheapinsert(x);
		}
		else if(y==-1)
		{
			if(x>=a[1])
			minheapinsert(x);
		        else if(x<=b[1])
			   {
				   long long int l;
				   l=maxheapdelete(1);
				   minheapinsert(l);
				   maxheapinsert(x);
			   }
			else
			    minheapinsert(x);
		}
	/*	else if(y==1)
		{
			if(x<=b[1])
			maxheapinsert(x);
			else if(x>=a[1])
			{
				long long int l;
				l=minheapdelete(1);
		
				maxheapinsert(l);
				minheapinsert(x);
			}
			else 
				maxheapinsert(x);
		} */
	
		count=count+x;
		
		
	}
	if(n==1)
		printf("1\n");
	else

	printf("%lld\n", count);
	}
	return 0;
}
