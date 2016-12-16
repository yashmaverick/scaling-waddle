#include<stdio.h>
void merge_sort(long int a[],long int fi,long int la);
void merge(long int a[],long int l,long int r);
long int n,temp[1000001],a[1000001];
int main()
{
	long int t;
	scanf("%ld",&t);
	while(t--)
	{ long int n,i;
		long int cnt=0,ans=0;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{ scanf("%d",&a[i]);
		}
		merge_sort(a,0,n-1);
//		printf("Sorted array is: ");
//		for(i=0; i<n; i++)
//			printf("%d ", a[i]);
//		printf("\n");


		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1] && a[i]==a[i+2]&& i!=n-2)
			{
				cnt++;
				//      printf("First case\n");
			}
			if(a[i]==a[i+1] && a[i+1]!=a[i+2]&& i!=n-2)
			{
				cnt=cnt+2; //printf("Second case\n");
			}
			if(i==n-2 && a[i]==a[i+1])
			{       cnt=cnt+2;// printf("End condition\n");  
				ans=ans+(cnt*(cnt-1))/2;
			}

			if(a[i]!=a[i+1])
			{  if(cnt>=2)
				{
					ans+=(cnt*(cnt-1))/2;
					//printf("Current ans is %ld \n", ans );
				}
				cnt=0;
			}
		}
		//if(cnt>=2)
		// ans+=(cnt*(cnt-1))/2;
		printf("%ld\n",ans);
	}
	return 0;
}
void merge_sort(long int a[],long int fi,long int la)
{// int n=fi-la;
	if(fi>=la)
		return;
	if (fi<la)
	{ long int mid=(fi+la)/2;
		merge_sort(a,fi,mid);
		merge_sort(a,mid+1,la);
		merge(a,fi,la);
	}
}
void merge(long int a[],long int l,long int r)
{ 
	long int i,mid=(l+r)/2;
	long int j=mid+1,k=0;
	//nl=mid-l+1;
	//nr=r-mid+1;
	//for(i=0;i<nl;i++)

	//	left[i]=a[l+i];
	//for(i=0;i<nr;i++)
	//    	right[i]=a[mid+l+i];
//	printf("%d l %d r\n",l,r);
//	for(i=l;i<mid+1;i++)
//	printf("%d ",a[i]);
//	printf("left\n");
//	for(i=mid+1;i<=r;i++)
//	printf("%d ",a[i]);
//	printf("right\n");
	i=l;
	while(i<=mid && j<=r)
	{ 
		if(a[i]<=a[j])
		{ 
			temp[k]=a[i];
			k++;
			
//		printf("%d ",a[i]);
			i++;
		}
		if(a[i]>a[j])
		{ 
			temp[k]=a[j];
//			printf("%d ",a[j]);
			k++;
			j++;
		}
	}
	while(i<=mid)
	{ temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=r)
	{ temp[k]=a[j];
		k++;
		j++;
	}
//	k=l; 
	k=0;
	for(i=l;i<=r;i++)
	{ a[i]=temp[k]; 
//		printf("%d ",a[i]); 
		k++;
	}
//	printf("%d\n",a[i]);
//	printf("\n");
}
