#include<stdio.h>
long long int charan;
void quicksort(long long int [100000],long long int,long long int);
int main()
{
	long long int test,hh;
	scanf("%Ld",&test);
	for(hh=0;hh<test;hh++)
	{
		long long int size,i,b[10000],start,end,temp,flag=0,sum,l,r;
		scanf("%lld",&size);
		scanf("%lld",&sum);
                long long int x[size];
		for(i=0;i<size;i++)
		{
			scanf("%s",b);
			scanf("%lld",&x[i]);
		}
		quicksort(x,0,size-1);
		for(i=0;i<size-2;i++)
		{
			l =i+1; 
			r =size-1;
			while(l<r)
			{
				if(x[i]+x[l]+x[r]==sum)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				else if (x[i]+x[l]+x[r]<sum)
					l++;
				else if(x[i]+x[l]+x[r]> sum)
					r--;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");

	}
	return 0;
}
void quicksort(long long int x[100000],long long int first,long long int last)
{
	long long int pivot,j,temp,i;
	if(first>=last)
		return;
	pivot=first;
	i=first;
	j=last;
	while(i<j){

		while(x[i]<=x[pivot]&&i<last)
			i++;
		while(x[j]>x[pivot])
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
