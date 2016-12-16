#include<stdio.h>
long long int size,a[200010],size1,b[200010];
void min_insert(long long int x)
{
	long long int i,temp;
	i = size+1;
	//	printf("size=%d\n",size);
		a[i]=x;
		size++;
		while(i>1)
		{
			if(a[i]<a[i/2])
			{
				temp = a[i];
				a[i]=a[i/2];
				a[i/2]=temp;
			}
			else
			{
				break;
			}
			i = i/2;
		}
	/*for(i=1;i<=size;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	//return 0;
}
void max_insert(long long int x)
{
	//printf("x=%d\n",x);
	long long int i,temp;
	i = size1+1;
	//      printf("size=%d\n",size)
		b[i]=x;
		size1++;
		while(i>1)
		{
			if(b[i]>b[i/2])
			{
				temp = b[i];
				b[i]=b[i/2];
				b[i/2]=temp;
			}
			else
			{
				break;
			}
			i = i/2;
		}
	
	/*for(i=1;i<=size1;i++)
		printf("%d ",b[i]);
	printf("\n");*/
}
long long int min_delete()
{
	long long int temp,j,i;
	temp = a[1];
	j = a[1];
	a[1] = a[size];
	a[size]=temp;
	i = 1;
	size--;
	while(1)
	{
		if( (2*i) > size && (2*i+1) > size )
			return j;
		if(2*i==size)
		{
			if(a[i] > a[2*i])
			{
				temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;
				i = 2*i;

			}
			else
				return j;
		}
		else if(a[i] < a[2*i+1] && a[i] < a[2*i])
			return j;
		else
		{
			if( a[2*i] < a[2*i+1] )
			{
				temp = a[2*i];
				a[2*i] = a[i];
				a[i] = temp;
				i = 2*i;
			}
			else
			{
				temp = a[2*i+1];
				a[2*i+1] = a[i];
				a[i] = temp;
				i = 2*i+1;
			}
		}
	}
	//size--;
}
long long int max_delete()
{
	long long int temp,j,i;
	temp = b[1];
	j = b[1];
	b[1] = b[size1];
	b[size1]=temp;
	i = 1;
	size1--;
	while(1)
	{
		if( (2*i) > size1 && (2*i+1) > size1 )
			return j;
		if(2*i==size1)
		{
			if(b[i] < b[2*i])
			{
				temp = b[2*i];
				b[2*i] = b[i];
				b[i] = temp;
				i = 2*i;

			}
			else
				return j;
		}
		else if(b[i] > b[2*i+1] && b[i] > b[2*i])
			return j;
		else
		{
			if( b[2*i] > b[2*i+1] )
			{
				temp = b[2*i];
				b[2*i] = b[i];
				b[i] = temp;
				i = 2*i;
			}
			else
			{
				temp = b[2*i+1];
				b[2*i+1] = b[i];
				b[i] = temp;
				i = 2*i+1;
			}
		}
	}
	//size--;
}

int main()
{
	long long int t,x,A,B,C,n,ans,count,f,med,i;
	scanf("%lld",&t);
	while(t--)
	{
		long long int mod = 1000000007;
		scanf("%lld%lld%lld%lld",&A,&B,&C,&n);
		size=0;size1=0;
		count=1;
		f=1;
		max_insert(f);
		x=max_delete();
		min_insert(x);
		med = a[1];
		ans = 1;
		for(i=2;i<=n;i++)
		{
			f = (A*med)%mod;
			f = (f + (B*i)%mod)%mod;
			f = (f + C%mod)%mod;
			//f = ( (A*med) + (B*i) + C)%mod;
			ans = ans + f;
		//	printf("f=%d\n",f);
			if(count%2==0)
			{
				if( f > b[1] )
					x = f;
				else
				{
					max_insert(f);
					x=max_delete();
				}
				min_insert(x);
			}
			else
			{
				if( f < a[1])
					x = f;
				else
				{
					min_insert(f);
					x=min_delete();
				}
				max_insert(x);
			}
			if(size>size1)
				med = a[1];
			else
				med  = b[1];
			count++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
