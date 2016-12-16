#include<stdio.h>
void highestsum(int array[],int nights,int k);
void sort(int x[],int first,int last);
char name[1001];
int array[1001];
int main()
{
	int testcase,nights,k;
	int i,j;
	scanf("%d",&testcase);
	for(i=0;i<testcase;i++)
	{
		scanf("%d",&nights);
		scanf("%d",&k);
		for(j=0;j<nights;j++)
		{
			scanf("%s",name);
			scanf("%d",&array[j]);
		}
		highestsum(array,nights,k);
	}
	return 0;
}
void highestsum(int array[],int nights,int k)
{
	int first= 0;
	int last= nights-1;
	sort(array,first,last);
	int w,i;
	/*for(i=0;i<nights;i++)
	  printf("%d ",array[i]);
	  printf("\n");*/
	w = 0;
	int beg, end;
	for(i=0;i<nights-2;i++)
	{
		beg= i+1;
		end= nights-1;
		while(beg<end)
		{
			if(array[i]+array[beg]+array[end]==k)
			{
				w= 1;
				printf("YES\n");
				break;
			}
			else if(array[i]+array[beg]+array[end]<k)
				beg++;
			else
				end--;
		}
		if(w==1)
			break;
	}	
	if(w==0)
		printf("NO\n");
}

void sort(int x[],int first,int last)
{
	int pivot,j,temp,i;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(x[i]<=x[pivot]&&i<last)
				i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		sort(x,first,j-1);
		sort(x,j+1,last);
	}
}
