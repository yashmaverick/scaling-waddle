#include<stdio.h>
#include<stdlib.h>
long long int count;
int new[100000];
void create(long long int val,long long int** b)
{
	long long int i,j,k;
	i=1;
	while(val/i!=0)
	{
		b[count]=(long long int *)(malloc(sizeof(long long int)*2));
		j=val/i;
		if(i==1)
		{
			b[count][1]=1;
		}
		else
		{
			b[count][1]=0;
		}
		b[count][0]=j;
		count++;
		i=i*10;
	}
}
/*void quicksort(long long int **x,long long int first,long long int last)
  {
  long long int pivot,j,i;
  long long int *temp;
  if(first<last)
  {
  pivot=first;
  i=first;
  j=last;

  while(i<j)
  {
  while(x[i][0]<=x[pivot][0]&&i<last)
  i++;
  while(x[j][0]>x[pivot][0])
  j--;
  if(i<j){
  temp=x[i];
  x[i]=x[j];
  x[j]=temp;
  }
  }
  temp=x[pivot];
  x[pivot]=x[j];
  x[j]=temp;
  quicksort(x,first,j-1);
  quicksort(x,j+1,last);
  }
  }*/ 
void mergeSort(long long int **arr,long long int low,long long int mid,long long int high);
void partition(long long int **arr,long long int low,long long int high)
{

	long long int mid;

	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(long long int **arr,long long int low,long long int mid,long long int high)
{

	long long int i,m,k,l,**temp;
	temp=(long long int **)(malloc(sizeof(long long int *)*count));
	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high))
	{

		if(arr[l][0]<=arr[m][0])
		{
			temp[i]=arr[l];
			l++;
		}
		else
		{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}

	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	int nf=0;
	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
		
	}
	free(temp);
}
long long int main()
{
	long long int t;
	scanf("%lld",&t);
		long long int a[1000000];
		long long int **b;
		b=(long long int **)malloc(sizeof(long long int *)*1000000);
	while(t--)
	{
		long long int n;
		count=0;
		scanf("%lld",&n);
		long long int i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			long long int m;
			m=a[i];
			create(m,b);
		}
	//	quicksort(b,0,count-1);
		partition(b,0,count-1);
		long long int flag=0;
		for(i=0;i<count-1;i++)
		{
				if(b[i][1]==1||b[i+1][1]==1)
			{
			if(b[i][0]==b[i+1][0])
				{
					flag=1;
					break;
				}
			}
		}
		//prlong long intf("\n");
		/*for(i=0;i<count;i++)
		  {
		  prlong long intf("%lld	",b[i][0]);
		  }
		  prlong long intf("\n");
		  for(i=0;i<count;i++)
		  {
		  prlong long intf("%lld	",b[i][1]);
		  }
		  prlong long intf("\n");*/
		if(flag==1)
		{
			printf("NO\n");
		}
		else if(flag==0)
		{
			printf("YES\n");
		}
	}
	return 0;
}
