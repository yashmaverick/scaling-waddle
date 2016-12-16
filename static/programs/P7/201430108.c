#include<stdio.h>
#include<stdlib.h>
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	int a[1000001];
	int i,n,temp,j;
	long long int c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//partition(a,0,n-1);
    qsort(a,n,sizeof(int),cmpfunc);
	c=1;
	long long int sum=0;
	int flag=0;
	for(i=0,j=0;i<n-1;i++)
	{
		temp=a[i];
		if(a[i+1]==a[i])
			{
				//c++;
                c++;
			//	flag=1;
			}

		else //if(flag==1)
		{	
			//flag=0;
			sum+=(c*(c-1))/2;
			
			c=1;
		}
	}
	sum+=(c*(c-1))/2;
	/*for(i=0;i<=j;i++)
	{
		sum+=p[i]*(p[i]-1)/2;
	}*/
	printf("%lld\n",sum);
}
return 0;
}