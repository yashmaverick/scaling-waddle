#include <stdio.h>
void quicksort(int a[],int first,int last);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		 int m;
		scanf("%d%d",&n,&m);//getchar();
		int a[n];
		char s[1000];
		int i;
		for(i=0;i<n;i++)
		{scanf("%s",s);
			scanf("%d",&a[i]);
		}
		quicksort(a,0,n-1);
		int j,k,flag=0;
		for(i=0;i<n-1;i++)
		{j=i+1;
			k=n-1;
			if(j==k)
				continue;
			while(k>j)
			{
				if((a[i]+a[j]+a[k])==m)
				{printf("YES\n");
					flag=1;
					break;
				}
				else if((a[i]+a[j]+a[k])>m)
					k--;
				else
					j++;
			}
			if(flag==1)
				break;
	}
			if(flag==0)
				printf("NO\n");
	}
	return 0;
}

void quicksort(int a[],int first,int last)
{
	int pivot,i,j,temp;

	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;

		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
			{
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
