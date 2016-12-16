#include<stdio.h>

int quick_sort(int a[],int wall,int pivot)
{
	int low,high,c,d;
	low=wall;
	high=pivot;
	if(wall==pivot)
	{
		return;
	}
    	while(pivot!=wall)
    	{
		if(a[wall]>a[pivot])
		{
        		c=a[wall];
        		a[wall]=a[pivot-1];
			d=a[pivot];
			a[pivot]=c;
			a[pivot-1]=d;
			pivot=pivot-1;
    		}
		else
		{ 
			wall=wall+1;
		}
	}
	if(high!=pivot)
		quick_sort(a,pivot+1,high);
	if(low!=wall)
		quick_sort(a,low,pivot-1);
}


int main()
{
    int t,h;
    scanf("%d",&t);
    for(h=0;h<t;h++)
    {
    	int n,i,j,k,p,ans=0;
	char c;
	scanf("%d%d",&n,&k);
	int a[n];
    	for(i=0;i<n;i++)
	{
		while((c=getchar())!=' ')
		{
		}
        	scanf("%d",&a[i]);
	}
    	quick_sort(a,0,n-1);
/*	int l;
	for(l=0;l<n;l++)
	{
		printf("%d ",a[l]);
	}
	printf("\n"); */
	i=0;
	j=1;
	p=n-1;
	while(i!=p-1)
	{
		if(j==p)
		{
			i++;
			j=i+1;
			p=n-1;
			continue;
		}
		ans=a[i]+a[j]+a[p];
		if(ans==k)
			break;
		if(ans<k)
			j++;
		if(ans>k)
			p--;
	}
//	printf("%d\n",ans);
	if(ans==k)
		printf("YES\n");
	else
		printf("NO\n");
	
    }
    return 0;
}
