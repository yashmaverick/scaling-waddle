#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define s(n) scanf("%d",&n)

int partition(int A[],int l,int r)
{
	int pivot=(rand()%(r-l+1)+l);
	int wall=l,i,j,temp;
	temp=A[pivot];
	A[pivot]=A[r];
	A[r]=temp;pivot=r;
	for(i=l;i<r;i++)
	{
		if(A[i]<=A[pivot])
		{
			temp=A[i];
			A[i]=A[wall];
			A[wall]=temp;
			wall++;
		}
	}
	temp=A[wall];
	A[wall]=A[pivot];
	A[pivot]=temp;
	return wall;
}

void sort(int A[],int l,int r)
{
	if(l<r)
	{
		int pivot=partition(A,l,r);
		sort(A,l,pivot-1);
		sort(A,pivot+1,r);
	}
}

void FC(int A[],int n,int cu)
{
	int i,j,k,f=0;
	for(i=0;i<n-1;i++)
	{
		j=i+1;k=n-1;
		while(j<k)
		{
			if(A[i]+A[j]+A[k]==cu)
				{f=1;break;}
			if(A[i]+A[j]+A[k]>cu)
				k--;
			if(A[i]+A[j]+A[k]<cu)
				j++;
		}
	}
	if(f==1)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	srand(time(NULL));
	int t,i,n,k,u,j,A[1001];
	char dump[200];
	s(t);
	for(i=0;i<t;i++)
	{
		s(n);s(k);
		for(j=0;j<n;j++)
		{	
			scanf("%s %d",dump,&u);
			A[j]=u;
		}
		sort(A,0,n-1);
		FC(A,n,k);
	}
	return 0;
}