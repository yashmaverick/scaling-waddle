#include<stdio.h>
void quicksort(int a[10],int first,int last){
	int pivot,j,temp,i;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}

		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);

	}
}
int func(int a[],int start,int end,int k)
{
	int i,j,flag;
	if(start<end-1)
	{
		i=0;
		j=0;
		flag=0;
		while(a[end-i]!=a[start+j+1])
		{
			if((a[start]+a[start+j+1]+a[end-i])<k)
				j++;
			else if((a[start]+a[start+j+1]+a[end-i])>k)
				i++;
			else if((a[start]+a[start+j+1]+a[end-i])==k)
			{flag=1;
				break;}
		}
		if(flag!=1)
			return func(a,start+1,end,k);
		else if(flag==1)
			return 1;
	}
	else
		return 0;
}
int main()
{
	int i,n,a[10001],k,test,t;
	char c[10001];
	scanf("%d",&test);
	for(t=0;t<test;t++)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{	scanf("%s",c);
			scanf("%d",&a[i]);
		}
		quicksort(a,0,n-1);
		if(func(a,0,n-1,k)==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
