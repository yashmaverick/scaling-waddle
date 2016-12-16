#include<stdio.h>
void quicksort(int [], int,int);
int main()
{
	int list[100000];
	char night[100000];
	int size,i,n,test,k;
	scanf("%d",&test);
	while(test--)
	{
		int flag=0;
		scanf("%d %d",&size,&k);
		for(i=0;i<size;i++)
		{	
			scanf("%s",night);
			scanf("%d",&list[i]);
		}
		quicksort(list,0,size-1);
	//	for(i=0;i<size;i++)
	//		printf("%d ",list[i]);
		for(i=0;i<size;i++)
		{
			int l=list[i];
			int p1=i+1;
			int p2=size-1; 
			while(p2>p1)
			{
				if(l+list[p1]+list[p2]==k)
				{
					flag=1;
					printf("YES\n");
					break;
				}
				if(l+list[p1]+list[p2]<k)
					p1++;
				if(l+list[p1]+list[p2]>k)
					p2--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
		/*for(i=0;i<size;i++)
		  {
		  printf("%d ",list[i]);
		  }*/
		//printf("%d\n",list[no-1]);
	}
	return 0;

}
void quicksort(int list[],int low,int high)
{
	int pivot,i,j,temp;

	if(low<high)
	{
		pivot=low;
		i=low;
		j=high;
		while(i<j)
		{
			while(list[i]<=list[pivot]&&i<=high)
			{
				i++;
			}
			while(list[j]>list[pivot]&&j>=low)
			{
				j--;
			}
			if(i<j)
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
		temp=list[j];
		list[j]=list[pivot];
		list[pivot]=temp;
		quicksort(list,low,j-1);
		quicksort(list,j+1,high);
	}
}
