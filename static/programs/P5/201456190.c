#include<stdio.h>
int junction(int a[],int count,int number,int n)
{   
    int i;
    for(i=0;i<n-2;i++)
    {
	int low=i+1;
	int high=n-1;

	while(low<high)
	{
	    int x=a[i]+a[low]+a[high];
	    if(x==number)
	    {
		count++;
		goto end;
	    }
	    if(x<number)
	    {
		low++;
	    }
	    else if(x>number)
	    {
		high--;
	    }
          
	}
    
    }
end: ;
    return count;

}
void quicksort(int a[],int start,int end)
{
    if(end<=start)
	return;

    int temp;
    int i;
    int pivot=end;
    int wall=start;


    for(i=start;i<pivot;i++)
    {
	if(a[pivot]>a[i])
	{
	    temp=a[i];
	    a[i]=a[wall];
	    a[wall]=temp;
	    wall++;
	}
    }

    if(a[pivot]<a[wall])
    {
	temp=a[pivot];
	a[pivot]=a[wall];
	a[wall]=temp;
    }
    quicksort(a,start,wall-1);
    quicksort(a,wall+1,end);
}
int main()
{
    int a[100000];
    int test,q;
    scanf("%d",&test);
    for(q=0;q<test;q++)
    {
	int n, number;
	scanf("%d%d",&n,&number);
	int i,j,k;
	for(k=0;k<n;k++)
	{
	    char a1[1000];
	    scanf("%s",a1);
	    scanf("%d",&a[k]);
	}

	quicksort(a,0,n-1);
	int ans =junction(a,0,number,n);
	if(ans==0)
	    printf("NO\n");
	else
	    printf("YES\n");
    }
    return 0;
}
