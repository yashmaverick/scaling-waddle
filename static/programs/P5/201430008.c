#include<stdio.h>
#include<string.h>
void quicksort(int x[],int first,int last)
{
	int pivot,j,temp,i;
	if(first>=last)
		return;
	j=first;
	pivot=last;
	for(i=first;i<last;i++)
	{
		if(x[i]<x[pivot])
		{
			temp=x[j];
			x[j]=x[i];
			x[i]=temp;
			j++;
		}
	}
	temp=x[pivot];
	x[pivot]=x[j];
	x[j]=temp;
	quicksort(x,first,j-1);
	quicksort(x,j+1,last);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1000];
		int x[1007];
		int total,n,p=0,i,j,k;
		scanf("%d%d",&n,&total);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&x[i]);
		}
		quicksort(x,0,n-1)	;
		for (i=0;i<n-2; i++)
		{
			j=i+1;
			k=n-1;
			while(j<k)
			{
				if(x[i]+x[j]+x[k]==total)
				{
					p=1;
					break;
				}
				else if(x[i]+x[j]+x[k]<total)
					j++;
				else
					k--;
			}
		}

		if(p==1)
		{
			printf("YES\n");
		}
		if(p==0)
		{
			printf("NO\n");
		}
	}
	return 0;
}
