#include<stdio.h>
int quick_sort( int arr[1000005], int low,int high)
{
	int pivot,j,temp,i;
	if(low<high)
	{
		pivot=high;
		i=low;
		j=high;
		while(i<j)
		{
			while((arr[i]<=arr[pivot])&&(i<high))
			{
				i++;
			}
			while(arr[j]>arr[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[pivot];
		arr[pivot]=arr[j];
		arr[j]=temp;
		return quick_sort(arr,low,j-1);
		return quick_sort(arr,j+1,high);
	}
}
int main()
{
	int n,k,w,i,j,a[1100000],m,m1,sum,b[1010],l,p;
	scanf("%d%d",&n,&w);
	i=1;
	k=0;
	while(n--)
	{
		sum=0;
		scanf("%d",&m);
		a[i]=m;
		for(j=0;j<m;j++)
		{
			i++;
			scanf("%d",&m1);
			a[i]=m1;
			sum=(sum+m1)%w;
		}
		a[i-m-1]=sum;
		b[k++]=sum;
		i=i+2;
	}
	quick_sort(b,0,k-1);
	/*for(j=0;j<k;j++)
		printf("%d ",b[j]);
	printf("\n");
	for(j=0;j<i-1;j++)
		printf("%d ",a[j]);
	printf("\n");*/
	for(j=0;j<k;j++)
	{
		l=0;
		while(l<i-1)
		{
			if(b[j]==a[l])
			{
				//printf("b[%d]=%d a[%d]=%d\n",j,b[j],l,a[l]);
				printf("%d\n",a[l]);
				a[l]=0;
				for(p=0;p<a[l+1];p++)
					printf("%d\n",a[p+l+2]);
				printf("\n");
				break;
			}
			l=l+a[l+1]+2;
		}
	}
	return 0;
}

