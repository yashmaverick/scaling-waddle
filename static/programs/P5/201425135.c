#include<stdio.h>
#include<string.h>
int  sum(int [],int,int);
void quicksort(int [],int,int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,p;
		scanf("%d%d",&n,&k);
		int i,x[n];
		char c[100000];
		for(i=0;i<n;i++)
			scanf("%s%d",c,&x[i]);

		quicksort(x,0,n-1);
		int m,v,flag=0,j,g=0,z;
		for(i=0;i<n-2;i++)
		{
			m=i+1;
			v=n-1;
			while(m<v)
			{
				if(x[i]+x[m]+x[v]==k)
				{
					g=1;
					break;
				}
				else if(x[i]+x[m]+x[v]<k)
					m++;
				else if(x[i]+x[m]+x[v]>k)
					v--;

			}
			if(g)
				break;

		}
		if(g)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}

void quicksort(int x[],int first,int last)
{
	int pivot,j,temp,i;
	if(first>=last)
		return;

	pivot=first;
	i=first;
	j=last;

	while(i<j)
	{
		while(x[i]<=x[pivot]&&i<last)
			i++;
		while(x[j]>x[pivot])
			j--;
		if(i<j)
		{
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


