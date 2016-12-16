#include<stdio.h>
#include<string.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;


}/*
    void q_sort(long long int a[],int left,int right)
    {
    int i,j,pivot;
    if(left>=right)
    return;
    pivot=left;
    i=left;
    j=right;
    while(i<j)
    {
    while(a[i]<=pivot && i<=right)
    i=(i+1);
    while(a[j]>a[pivot])
    j=(j-1);
    if(i<j)
    swap(&a[i],&a[j]);
    }
    swap(&a[pivot],&a[j]);
    q_sort(a,j+1,right);
    q_sort(a,left,j-1);
//q_sort(a,j+1,right);
}*/		
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int flag=0;
		char c[1000]; 
		int i,j,l;
		int a[100000],n,k,sum;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",c);
			scanf("%d",&a[i]);
		}
		//q_sort(a,0,n-1);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
					swap(&a[i],&a[j]);
		for(i=0;i<n-2;i++)
		{
			j=i+1;
			l=n-1;
			while(j<l)
			{
				if(a[i]+a[j]+a[l]>k)
					l--;
				else if(a[i]+a[j]+a[l]<k)
					j++;
				else 
				{
					printf("YES\n");
					flag=1;
					break;
				}
			}	
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");	
	} 
	return 0;
}
