#include <stdio.h>
void quickSort(int *, int, int);
void find3Numbers(int A[], int arr_size, int sum)
{
    int l,r,i,flag=0;
    quickSort(A, 0, arr_size-1);
    for (i = 0; i < arr_size - 2; i++)
    {
	l=i+1;
	r=arr_size-1;
	while (l < r)
	{
	    if( A[i] + A[l] + A[r] == sum)
	    {
		//printf("YES\n");
		flag=1;
		break;
	    }
	    else if (A[i] + A[l] + A[r] < sum)
		l++;
	    else if (A[i] + A[l] + A[r] > sum)
		r--;
	}
    }
if (flag ==1)
printf("YES\n");
if (flag==0)
printf("NO\n");
}

void swap ( int* a, int* b ) 
{
    int t = *a; 
    *a = *b; 
    *b = t;
}
int partition ( int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1); 
    int j;
    for ( j = l; j <= h- 1; j++)
    {   
	if (arr[j] <= x)
	{
	    i++;
	    swap (&arr[i], &arr[j]);
	}
    }   
    swap (&arr[i + 1], &arr[h]);
    return (i + 1); 
}

void quickSort(int arr[], int l, int h)
{
    int p;
    if(l< h)
    {
	p = partition(arr, l, h);
	quickSort(arr, l, p - 1);
	quickSort(arr, p + 1, h);
    }
}

int main()
{
    int arr[100000];
    int i,n,value,test,e,sum;
    char string[200];
    scanf("%d",&test);
    for(e=1;e<=test;e++)
    {
	scanf("%d %d",&n,&sum);
	for (i=0;i<n;i++)
	{   
	    scanf("%s %d",&string,&arr[i]);
	}   
	quickSort( arr, 0, n - 1 );
	find3Numbers(arr,n,sum);
    }
    return 0;
}

