#include<stdio.h>
int a[100000];

void quick(int l,int n)
{
	if(l+1>=n)
		return;

	int i,x;
	int wall=l;
	for(i=l;i<n-1;i++)
	{
		if(a[i]>a[n-1])
			continue;
		else
		{
			x=a[i];
			a[i]=a[wall];
			a[wall]=x;
			wall++;
		}
	}
	x=a[n-1];
	a[n-1]=a[wall];
	a[wall]=x;

	quick(l,wall);
	quick(wall+1,n);
}

int bins(int a[],int m,int low,int high)
{
	if(low>high)
		return -1; 

	int mid=(high+low)/2;
	if(a[mid]==m)
		return mid;

	if(a[mid]>m)
		return bins(a,m,low,mid-1);

	else
		return bins(a,m,mid+1,high);

}


int main()
{
	int test,jaa;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int n,k,i,j;
		char s[10000];
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s%d",s,&a[i]);
		}
		quick(0,n);
		/*	for(i=0;i<n;i++)
			{
			printf("%d ",a[i]);
			}
			printf("\n");
		*/

		int rest,r,flag=0;
		for(i=0;i<n-2;i++)
		{
			for(j=i+1;j<n-1;j++)
			{
				rest=k-a[i]-a[j];
				r=bins(a,rest,j+1,n-1);
				//printf("rest: %d r: %d\n",rest,r);
				if(r>=0)
				{
					printf("YES\n");
					flag=1;
					break;
				}
				
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			printf("NO\n");
	}
	return 0;
}

