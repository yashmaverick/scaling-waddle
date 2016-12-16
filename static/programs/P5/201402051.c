#include<stdio.h>
void quicksort(int a[],int first,int last);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1000];
		int n,k,a[1005],i,sum,b,c,d,m;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			scanf("%d",&a[i]);
		}
		m=0;
		quicksort(a,0,n-1);
		for(b=0;b<n-2;b++)
		{
			c=b+1;
			d=n-1;
			while(c<d)
			{
				sum=a[b]+a[c]+a[d];
				if(sum<k)
				{
					c++;
				}
				if(sum>k)
				{
					d--;
				}
				if(sum==k)
				{
					m=1;
					break;
				}
			}
			if(m==1)
				break;
		}
		if(m==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}
void quicksort(int x[],int first,int last){
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

