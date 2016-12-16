#include<stdio.h>
#include<ctype.h>
#define true 1
#define false 0 

void Quicksort(int *a,int low,int high)
{
	if(low>=high)
		return;
	int pivot=a[high];
	int i,wall,temp;
	wall=low;
	for(i=low;i<high;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[wall];
			a[wall]=a[i];
			a[i]=temp;
			wall=wall+1;
		}
	}
	temp=a[wall];
	a[wall]=a[high];
	a[high]=temp;
	//recursion
	Quicksort(a,low,wall-1);
	Quicksort(a,wall+1,high);
}

int check(int *A,int size,int value)
{
	int left,right,a,b;
	for(a=0;a<size-2;a++)
	{
		left=a+1;
		right=size-1;
		while(left<right)
		{
			if(A[a]+A[left]+A[right]==value)
				return true;
			else if(A[a]+A[left]+A[right]<value)
				left++;
			else
				right--;
		}
	}
	return false;
}


int main()
{
	int t,n,k,i,j,total;
	char name[100];
	int EV[1000];
	//t->test cases
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		//n->number of nights
		scanf("%d",&total);
		for(j=0;j<n;j++)
		{
			scanf("%s",name);
			scanf("%d",&EV[j]);
		}
		Quicksort(EV,0,n-1);
		k=check(EV,n,total);
		if(k==true)
			printf("YES\n");
		else if(k==false)
			printf("NO\n");
	}

	return 0;
}



