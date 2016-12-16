#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void quick_sort(int a[],int low,int high)
{
	if(low>=high)
		return;
	int pivot=high;
	int i,j;
	j=low;
	for(i=low;i<pivot;i++)
	{
		if(a[i]<a[pivot])
		{
			swap(a,i,j);
			j++;
		}
	}
	swap(a,j,pivot);
	quick_sort(a,low,j-1);
	quick_sort(a,j+1,high);
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int h,k,i;
		char a[10000];
		scanf("%d %d",&h,&k);
		int *b;
		b=(int*)malloc(1000*sizeof(int));
		for(i=0;i<h;i++)
			scanf("%s %d",a,&b[i]);
		quick_sort(b,0,h-1);
		int* a1;
		int* a2;
		int* a3;
		a1=b;
		a3=b+h-1;
		a2=a1+1;
		int state=0;
		while(1)
		{
			while(a3-a2>0)
			{
				if(*a1+*a2+*a3==k)
				{
					printf("YES\n");
					state=1;
					break;
				}
				else if(*a1+*a2+*a3<k)
				{
					a2++;
				}
				else
				{
					a3--;
				}
			}
			a1++;
			a3=b+h-1;
			a2=a1+1;
			if(state==1||a3-a2==0)
				break;
		}
		if(state==0)
			printf("NO\n");
	}
	return 0;
}







