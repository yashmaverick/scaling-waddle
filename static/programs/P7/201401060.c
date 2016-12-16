#include<stdio.h>
void merge(int A[],int,int,int );
void sort(int A[],int start, int end)
{
    int mid;
    if(start<end)
    {
	mid=(start+end)/2;
	sort(A,start,mid);
	sort(A,mid+1,end);
	merge(A,start,mid,end);
    }

}
void merge(int A[],int start, int mid ,int end)
{
    int temp[1000005];
    int i,j,k,l;
    k=start;
    l=mid+1;
    for(i=start;k<=mid && l<=end;i++)
    {
	if( A[k]<=A[l])
	{
	    temp[i]=A[k];
	    k++;
	}
	else
	{
	    temp[i]=A[l];
	    l++;
	}
    }
    while ( k>mid && l<=end)
    {
	temp[i]=A[l];
	i++;
	l++;
    }
    while(l>end && k<=mid)
    {
	temp[i]=A[k];
	i++;
	k++;
    }
    for(i=start;i<=end;i++)
	A[i]=temp[i];
}
/*void sort(int a[], int left, int right)
{
    int temp,pivot,i,j;
    if(left<right)
    {
	pivot=left;
	i=left;
	j=right;

	while(i<j)
	{
	    while(a[i]<=a[pivot] && i<right)
		i++;
	    while(a[j]>a[pivot] && j>left)
		j--;
	    if(i<j)
	    {
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	    }
	}
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;

	sort(a,left,j-1);

	sort(a,j+1,right);
    }

}*/

int main()
{
    int t;
    scanf("%d",&t);
    int n,arr[1000005];
   long long int count=0;
    int i,j,k,l;
    int temp;
//    int flag=0;
  long long int total=0;
  //  int totaltemp=0;
    for(i=0;i<t;i++)
    {
	scanf("%d",&n);
	for(j=0;j<n;j++)
	    scanf("%d",&arr[j]);
	sort(arr,0,n-1);
//	for(j=0;j<n;j++)
//	    printf("%d",arr[j]);
	//printf("\n");
	total=0;
//	totaltemp=0;

	for(l=0;l<n-1;)
	{
	    count=1;
	    temp=arr[l];
	    for(k=l+1;k<n;k++)
	    {
		if(arr[k]==temp)
		    count++;
		else
		    break;
	
	    }
	    if(count>=2)
	    total+=(count*(count-1))/2;
	    //if(count ==2)
	//	total++;
	    l=k;
	}

	//for(j=0;j<n;j++)
	//{
	    
	printf("%lld\n",total);
    }


    return 0;
}
