#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int size,i;
		scanf("%d",&size);
		int arr[size],brr[size],crr[size];
		scanf("%d",&arr[0]);
		brr[0]=arr[0];
		for(i=1;i<size;i++)
		{
			scanf("%d",&arr[i]);
			if(arr[i]<brr[i-1])
				brr[i]=arr[i];
			else
				brr[i]=brr[i-1];
		}
		crr[size-1]=arr[size-1];
		for(i=size-2;i>=0;i--)
		{
			if(arr[i]>crr[i+1])
				crr[i]=arr[i];
			else
				crr[i]=crr[i+1];
		}
		int maxdiff=-1;
		for(i=0;i<size;i++)
		{
			if(crr[i]-brr[i]>maxdiff)
				maxdiff=crr[i]-brr[i];
		}
		printf("%d\n",maxdiff);
	}
	return 0;
}

		
