#include <stdio.h>
void quicksort(long long int a[],long long int first,long long int last)
{
	long long int pivot,j,temp,i;
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
				temp=a[i];a[i]=a[j];a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
	return ;
}
int main()
{
	long long int t,n,k,i,j,x[10000],beg,end,sum,first,last,pres,fg;
	char a[1000];
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%s",a);
			scanf("%lld",&x[j]);
		}
		quicksort(x,0,n-1);
		fg=0;
                for(j=0;j<n-2;j++)
		{
			beg=j+1;end=n-1;
			while(beg<end){
				first=x[beg];
				last=x[end];
				sum=x[j]+first+last;
				if(sum>k)
					end--;
				else if(sum<k)
					beg++;
				else
				{
					fg=1;
					break;
				}
			}
			if(fg==1)
				break;
		}
		if(fg==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
