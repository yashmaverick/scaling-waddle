#include<stdio.h>
int a[200001];
int b[200001];
 long long int z;
long long int v;
void swap(int *a, int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void insertmaxheap (long long int y)
	
{
	long long int k;
	z++;
	k=z;
	a[z]=y;
	while(k > 1)
	{
		if(a[k/2] < a[k])
		{
			swap(&a[k],&a[k/2]);
			k=k/2;
		}
		else
			break;
	}
} 
int deletemaxheap()
{
      long long int c= a[1];
          swap(&a[1],&a[z]);
	  long long int k=1;
	  a[z]=-100000;
	  z--;
	  while(2*k<=z)
	  {
		  if(a[2*k] > a[2*k+1])
		  {
			  if(a[2*k] > a[k])
			  {
                               swap(&a[2*k],&a[k]);
			       k=k*2;
			       if(k > z)
				       break;
			  }
			  else
				  break;
		  }
		  else if(a[2*k+1] > a[k])
		   {
			   swap(&a[2*k+1],&a[k]);
			   k=2*k+1;
			   if(k > z)
				   break;
		   }
		  else
		    break;

	  }
	  return c;
}

void insertminheap (long long int y)
	
{
	long long int k;
	v++;
	k=v;
	b[v]=y;
	while(k > 1)
	{
		if(b[k/2] > b[k])
		{
			swap(&b[k],&b[k/2]);
			k=k/2;
		}
		else
			break;
	}
} 
int deleteminheap()
{
	long long int c= b[1];
          swap(&b[1],&b[v]);
	  long long int k=1;
	  b[v]=1000000008;
	  v--;
	  while(2*k<=v)
	  {
		  if(b[2*k] < b[2*k+1])
		  {
			  if(b[2*k] < b[k])
			  {
                               swap(&b[2*k],&b[k]);
			       k=k*2;
			       if(k > v)
				    break;   
			  }
			  else
				  break;
		  }
		  else if(b[2*k+1] < b[k])
		   {
			   swap(&b[2*k+1],&b[k]);
			   k=2*k+1;
			   if(k > v )
				   break;
		   }
		  else
		    break;

	  }
	  return c;
}
int main()
{
	long long int t,x,c,n,i,j,k,l,m,y,d;
	long long int sum;
//	int f[200001];
	scanf("%lld",&t);
//	a[0]=1000000008;
//	b[0]=-1000000;
	int mod=1000000007;
	while(t--)
	{
		z=0;
		v=0;
		scanf("%lld%lld%lld%lld",&x,&y,&c,&n);
		
		d=1;
		insertmaxheap(d);
		i=2;
		sum=1;
		while(i<=n)
		{
			m=a[1];
//			printf("%lld ",m);
			d=(x*m +y*i +c)%mod;
//			printf("%d ",f[i]);
			sum=sum+d;

			if(i%2 ==1 )
			{
				if(d > b[1])
					{

				insertminheap(d);
				l=deleteminheap();
				}
				else
					l=d;
				insertmaxheap(l);

			}
			else
			{
				if(d < a[1] )
				{
				insertmaxheap(d);
				l=deletemaxheap();
				}
	//			printf("%lld ",l);
				else
					l=d;
				insertminheap(l);
			}
		//	sum=sum+f[i];
			i++;
/*			for(j=1;j<=z;j++)
				printf("%d ",a[j]);
			printf("\n");
			for(j=1;j<=v;j++)
				printf("%d ",b[j]);
					printf("\n");*/
			
		}

		printf("%lld\n",sum);
	}
  return 0;	
}
