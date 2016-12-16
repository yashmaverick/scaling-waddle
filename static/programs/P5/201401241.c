#include<stdio.h>
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
int main()
{
	int k,i,n,t,p1,p2,p3,j;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int merge[n];		
char str[10000];		
for(i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%d",&merge[i]);
		}

		partition(merge,0,n-1);
		int flag=1;
		for(j=0;j<n-2;j++)
		{
			p2=j+1;
			p3=n-1;
			while(p2<p3)
			{
				if((merge[j]+merge[p2]+merge[p3])==k)
				{
					flag=2;
					break;
				}
				if((merge[j]+merge[p2]+merge[p3])>k)
					p3--;
				else if((merge[j]+merge[p2]+merge[p3])<k)
					p2++;
			}
			if(flag==2)
				break;
		}
		if(flag==2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

void partition(int arr[],int low,int high)
{

	int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(int arr[],int low,int mid,int high)
{

	int i,m,k,l,temp[high+10];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high))
	{

		if(arr[l]<=arr[m])
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

	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
	}
}

