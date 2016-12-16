#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
int k;
int bs(long long int *array,int value)
{
	int mid,low=0,high=k-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(array[mid]<value)
		{
			low=mid+1;
		}
		else if(array[mid]==value)
		{
			return mid;
		}
		else
			high=mid;
	//	printf("exe\n");
	}
	return high-1;
}


int main()
{
	long long int n;
	int value;
	long long int array[100],i;
	lldin(n);
	array[0]=1;
	for(k=1;k<32;k++)
		array[k]=array[k-1]*2;

	//for(i=0;i<30;i++)
	//	printf("%d->%d ",i,array[i]);
	for(i=0;i<n;i++)
	{
		din(value);
		int index=bs(array,value);// returns i where i is the power of two
		//dout(index);
		int count=2*(index-1);
		if((array[index]+array[index+1])/2>value)
			count++;
		else
			count+=2;
		dout(count);
	}







	return 0;
}
