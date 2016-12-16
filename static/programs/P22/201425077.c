#include<stdio.h>

#define MAX 1000000007

long long int f[1000001],median,heapmax[1000001],maxtop=0,mintop=0,heapmin[1000001];

void swap(long long int *a, long long int *b)
{
	long long int temp=*a;
	*a=*b;
	*b=temp;

}

void pushminheap(long long int n)
{
	mintop++;
	heapmin[mintop]=n;

	long long int temp=mintop;

	while(temp > 1)
	{
		long long int parent=temp/2;

		if(heapmin[parent] > heapmin[temp])
		{
			swap(&heapmin[temp],&heapmin[parent]);
			temp=parent;
		}

		else
			break;
	}
}

void pushmaxheap(long long int n)
{
	maxtop++;
	heapmax[maxtop]=n;

	long long int temp=maxtop;

	while(temp > 1)
	{
		long long int parent=temp/2;

		if(heapmax[parent] < heapmax[temp])
		{
			swap(&heapmax[temp],&heapmax[parent]);
			temp=parent;
		}

		else
			break;
	}

}


long long int popminheap()
{
	long long int min=heapmin[1];
	heapmin[1]=heapmin[mintop];
	
	long long int index=1;

	while ( index <= (mintop-1)/2 && (heapmin[index] > heapmin[2*index] || heapmin[index] > heapmin[2*index+1]) )
	{
		long long int temp=2*index;
		if(heapmin[2*index] > heapmin[2*index+1])
			temp++;

		if(heapmin[temp] < heapmin[index])
		{
			swap(&heapmin[index],&heapmin[temp]);
			index=temp;
		}

		else
		{
			mintop--;
			return min;
		}
	}

	mintop--;
	return min;
}

long long int popmaxheap()
{
	long long int min=heapmax[1];
	heapmax[1]=heapmax[maxtop];
	
	long long int index=1;

	while ( index <= (maxtop-1)/2 && (heapmax[index] < heapmax[2*index] || heapmax[index] < heapmax[2*index+1]) )
	{
		long long int temp=2*index;
		if(heapmax[2*index] < heapmax[2*index+1])
			temp++;

		if(heapmax[temp] > heapmax[index])
		{
			swap(&heapmax[index],&heapmax[temp]);
			index=temp;
		}
		else
		{
			maxtop--;
			return min;
		}
	}

	maxtop--;
	return min;
}


void updatemedian(long long int n,long long int i)
{
/*
	if(i%2==0)
	{
		if(f[i] >= median)
			pushminheap(f[i]);
		else
		{
			pushmaxheap(median);
			pushmaxheap(f[i]);
			median=popmaxheap();
		}
	}
	else
	{
		if(f[i] > median)
		{
			pushminheap(f[i]);
			pushmaxheap(median);
			median=popminheap();
		}
		else if(f[i] <= median )
		{
			pushmaxheap(f[i]);
		}
	
	}
*/


	if(maxtop==mintop)
	{
		if(f[i] >= median)
			pushminheap(f[i]);
		else
		{
			pushmaxheap(f[i]);
			pushminheap(median);
			median=popmaxheap();
		}
	}
	else
	{
		if(f[i] >= median)
		{
			pushmaxheap(median);
			pushminheap(f[i]);
			median=popminheap(f[i]);
		}
		else
		{
			pushmaxheap(f[i]);
			pushminheap(median);
			median=popminheap();
		}
	
	}
	

}

int main()
{
	long long int t;
	scanf("%lld",&t);

	while(t--)
	{
		mintop=maxtop=0;

/*		long long int n,i;
		scanf("%lld",&n);

		for(i=0;i<n;i++)
		{
			long long int a;
			scanf("%lld",&a);
			pushmaxheap(a);
		}



		printf("ht%lld\n",maxtop);

		for(i=1;i<=n;i++)
			printf("y`%lld\n",heapmax[i]);

		while(maxtop)
		{
			printf("%lld \n",popmaxheap());
		}
*/

		long long int n,a,b,c;
		scanf( "%lld %lld %lld %lld",&a,&b,&c,&n );

//		a%=MAX; b%=MAX; c%=MAX;

		if(n<=0)
		{
			printf("0\n");
			goto end;		
		}

		long long int ans,i,j;
		median=0;
		f[1]=1; median=1; ans=1;

//		printf("%lld ",f[1]);
		for(i=2;i<=n;i++)
		{	
			
//			printf("m%lldm",median);
//			f[i]= ( ( (( a%MAX * median%MAX ) %MAX) + ( b%MAX * i%MAX ) %MAX )%MAX  + c%MAX )%MAX;

			f[i]= ( a*median + b*i + c)%MAX;
					
			
//			printf("%lld ",f[i]);

			updatemedian(n,i);


		
			ans+=f[i];

			
		}

//		for(i=1;i<=maxtop;i++)
//			printf("mh%lldmh",heapmax[i] );
	//	ans+=a*median+b*(i+1)+c;
//		for(i=1;i<=mintop;i++)
//			printf("h%lldh",heapmin[i] );
	
//		for(i=1;i<=mintop;i++)
//			printf("%lld ",heapmin[i]);

//		for(i=1;i<=maxtop;i++)
//			printf("%lld ",heapmax[i]);
		printf("%lld\n",ans);

end:;
	
	}


	
	return 0;
}
