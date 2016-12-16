#include<stdio.h>
long long int a[1000001];
long long int l[1000001];
long long int R[1000001];
void merge(long long int p,long long int q,long long int r)
{
	long long int n1,n2,i,j,k,max=1000000005;
	n1=q-p+1;
	n2=r-q;
	/*for(i=p;i<=r;i++)
	  printf("%d ",a[i]);*/
	//printf("\n");
	for(i=1;i<=n1;i++)
		l[i]=a[p+i-1];
	for(i=1;i<=n2;i++)
		R[i]=a[q+i];
	l[n1+1]=max;
	R[n2+1]=max;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(l[i]<=R[j])
		{

			a[k]=l[i];
			//printf("%d %d\n",a[k],l[i]);
			i++;
		}
		else
		{
			a[k]=R[j];
			//printf("%d %d\n",a[k],R[j]);
			j++;
		}
		//printf("%d ",a[k]);

	}
	//printf("\n");

}
void merge_sort(long long int p,long long int r)
{
	//printf("ok");
	long long int q;
	//printf("%d %d\n",p,r);
	if(p<r)
	{
		//      printf("ok\n");
		q=(p+r)/2;

		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}
}
int main()
{
	long long int t,n,i,count,store,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		merge_sort(0,n-1);
		/*for(i=0;i<n;i++)
			printf("%d ",a[i]);*/
		//printf("\n");
		count=1;
		store=a[0];
		ans=0;
		for(i=1;i<n;i++)
		{
			if(store==a[i])
				count++;
			else 
			{
				ans=ans+count*(count-1)/2;
				count=1;
				store=a[i];
			}
		}
		ans=ans+count*(count-1)/2;
		printf("%lld\n",ans);

	}
	return 0;
}
