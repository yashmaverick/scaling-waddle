#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int sum;
	int *a;
	int items;
}node;
void mergeSort(int low,int mid,int high);
void partition(int low,int high);
void partition(int low,int high)
{

	int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(low,mid);
		partition(mid+1,high);
		
		mergeSort(low,mid,high);
	}
}
node *temp=NULL;
node *x=NULL;
void mergeSort(int low,int mid,int high)
{

	int i,m,k,l;
	l=low;
	i=0;
	m=mid+1;
	temp=malloc((high-low+1)*sizeof(node));
	while((l<=mid)&&(m<=high)){

		if(x[l].sum<=x[m].sum){
			temp[i].sum=x[l].sum;
			temp[i].a=x[l].a;
			temp[i].items=x[l].items;
			l++;
		}
		else{
			temp[i].sum=x[m].sum;
			temp[i].a=x[m].a;
			temp[i].items=x[m].items;
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i].sum=x[k].sum;
			temp[i].a=x[k].a;
			temp[i].items=x[k].items;
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i].sum=x[k].sum;
			temp[i].a=x[k].a;
			temp[i].items=x[k].items;
			i++;
		}
	}
	int sz=0;
	for(k=low;k<=high;k++,sz++){
		x[k].sum=temp[sz].sum;
		x[k].a=temp[sz].a;
		x[k].items=temp[sz].items;
	}
	free(temp);
}
int main()
{
	int n,mod;
	scanf("%d%d",&n,&mod);
	x=malloc(n*sizeof(node));
	int i=0;
	int c[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i].items);
		x[i].a=malloc(x[i].items*sizeof(int));
		x[i].sum=0;
		int j;
		for( j=0;j<x[i].items;j++)
		{
			scanf("%d",&x[i].a[j]);
			
			x[i].sum=(x[i].a[j]+x[i].sum)%mod;
		}
	}
	
	partition(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",(x[i].sum)%mod);
		int j=0;
		for(j=0;j<x[i].items;j++)
		{
			printf("%d\n",x[i].a[j]);
		}
		printf("\n");
	}


	return 0;
}







