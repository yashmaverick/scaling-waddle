#include<stdio.h>
#include<string.h>
void SWAP(int a[],int left,int right)
{
	int t;
	t=a[left];
	a[left]=a[right];
	a[right]=t;
	return;
}
int partition(  int a[100000], int low, int high )
{
	int left, right;
	int pivot_item;
	pivot_item = a[low];
	left = low;
	right = high;
	while ( left < right ) {
		/* Move left while item < pivot */
		while( a[left] <= pivot_item ) left++;
		/* Move right while item > pivot */
		while( a[right] > pivot_item ) right--;
		if ( left < right ) SWAP(a,left,right);
	}
	/* right is final position for the pivot */
	a[low] = a[right];
	a[right] = pivot_item;
	return right;
}
quicksort( int a[1000000], int low, int high )
{
	int pivot;
	/* Termination condition! */
	if ( high > low )
	{
		pivot = partition( a, low, high );
		quicksort( a, low, pivot-1 );
		quicksort( a, pivot+1, high );
	}
}
int main()
{
	int test,count;
	scanf("%d",&test);
	for(count=0;count<test;count++)
	{
		int size,i,j,k,sum,flag=0,c;
		char a[1000000];
		scanf("%d %d",&size,&sum);
		int b[size];
		for(i=0;i<size;i++)
		{
			scanf("%s",a);
			scanf("%d",&b[i]);
		}
		/*	for(i=0;i<size;i++)
			{
			printf("%s",a);
			printf("%d",b[i]);
			}*/
		quicksort(b,0,size-1);
		for(i=0;i<size-2;i++)
		{
			j=i+1;
			k=size-1;
			while(j<k)
			{     
				if(b[i]+b[j]+b[k]==sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if(b[i]+b[j]+b[k]<sum)
				{
					j++;
				}
				else if(b[i]+b[j]+b[k]>sum)
				{
					k--;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
		{
			printf("NO\n");
						
		}
        }
return 0;
}
