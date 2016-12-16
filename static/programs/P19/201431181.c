#include<stdio.h>
long long int f=0;
void merge( long long int [] , long long int , long long int , long long int ); 
void part(long long int arr[],long long int min,long long int max)
{
	long long int mid;
	if(min<max)
	{
		mid=(min+max)/2;
		part(arr,min,mid);
		part(arr,mid+1,max);
		merge(arr,min,mid,max);
	}
}
void merge(long long int arr[],long long int min,long long int mid,long long int max)
{
	long long int tmp[100000];
	long long int i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++)
	{
		if(arr[j]<=arr[m])
		{
			tmp[i]=arr[j];
			j++;									
		}
		else
		{
			tmp[i]=arr[m];
			m++;
		}
	}
	if(j>mid)
	{
		for(k=m; k<=max; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=j; k<=mid; k++)
		{
			tmp[i]=arr[k];
			i++;
		}
	}
	for(k=min; k<=max; k++)
		arr[k]=tmp[k];
}
int BS( long long int P[] , long long int min , long long int max , long long int I )
{
//	printf("min max I %d %d %d\n",min,max,I);
	if( (min+max)/2!=min )
	{
		if( P[(min+max)/2]>I )
			BS( P,min,(min+max)/2,I );
		else if( P[(min+max)/2]==I )
		{
			printf("NO\n");
			f=1;
			return 0;
		}
		else
			BS( P,(min+max)/2,max,I );
	}
	else if( P[(min)]==I )
	{
		printf("NO\n");
		f=1;
		return 0;
	}
	else
		return 0;
}
int main()
{
	long long int i,j,n,t,T;
	scanf("%lld",&T);
	for( t=0 ; t<T ; t++ )
	{
		f=0;
		scanf("%lld",&n);
		long long int I[n],P[100000],p=0,tmp,a=0;
		for(i=0 ; i<n ; i++ )
		{
			scanf("%lld",&I[i]);
			tmp=I[i];
			if( tmp%10!=tmp )
			{
				for( j=0 ; j<10 ; j++ )
				{
					if( tmp%10==tmp && tmp!=0 )
					{
						if( a!=1 )
							P[p]=tmp;	
						a=1;
						break;
					}
					else
					{
						P[p]=tmp/10;
						tmp=tmp/10;
						p++;
						a=1;
					}
				}
			}
		}
	//	printf("%d\n",p);
		
			part( I,0,n-1 );
			part( P,0,p-1 );
			for( i=1 ; i<n ; i++ )
			{
				if( I[i]==I[i-1] )
				{
					printf("NO\n");
					f=1;
					break;
				}
			}
		if( a==1 && f!=1 )
		{
			/*for( i=0 ; i<n ; i++ )
				printf("%d ",I[i]);
			printf("\n");
			for( i=0 ; i<p ; i++ )
				printf("%d ",P[i]);
			printf("\n");*/
			if( f!=1 )
			for( i=0 ; i<n ; i++ )
			{
				//printf("sgas\n");
				if( f==1 )
					break;
				else
				{
					if( I[i]<P[p/2] )
						BS( P,0,p/2,I[i] );
					else if( I[i]==P[p/2] )
					{
						printf("NO\n");
						f=1;
						break;
					}
					else
						BS( P,p/2,p,I[i] );
				}
			}
		}
		/*else if(  )
		{
			printf("NO\n");
			f=1;	
		}*/
		if( f==0 )
			printf("YES\n");
	}	
	return 0;
}

