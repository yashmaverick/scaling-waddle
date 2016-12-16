#include<stdio.h>
#include<stdlib.h>

struct bag
{
	int item;
	int *list;
	int weight;
	int index;
}obj[1000];


void mergeSort(int a[][2],int low,int mid,int high)
{

	int i,m,k,l,temp[1000][2];

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high)){

		if(a[l][0]<=a[m][0]){
			temp[i][0]=a[l][0];
			temp[i][1]=a[l][1];
			l++;
		}
		else{
			temp[i][0]=a[m][0];
			temp[i][1]=a[m][1];
			m++;
		}
		i++;
	}

	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i][0]=a[k][0];
			temp[i][1]=a[k][1];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i][0]=a[k][0];
			temp[i][1]=a[k][1];
			i++;
		}
	}

	for(k=low;k<=high;k++){
		a[k][0]=temp[k][0];
		a[k][1]=temp[k][1];
	}
}
void partition(int a[][2],int low,int high)
{

	int mid;

	if(low<high)
	{
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergeSort(a,low,mid,high);
	}
}

int main()
{
	int n,mod,i,j;
	scanf("%d %d",&n,&mod);
	int weight[n][2];
	for(i=0;i<n;i++)
	{
		obj[i].weight=0;
		scanf("%d",&obj[i].item);
		obj[i].list=(int *)malloc(sizeof(int)*obj[i].item);
		for(j=0;j<obj[i].item;j++)
		{
			scanf("%d",&(obj[i].list[j]));
			obj[i].weight=(obj[i].weight+(obj[i].list[j]))%mod;
		}
		weight[i][0]=obj[i].weight;
		obj[i].index=i;
		weight[i][1]=i;
	}
	partition(weight,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",weight[i][0]);
		for(j=0;j<obj[weight[i][1]].item;j++)
			printf("%d\n",(obj[weight[i][1]].list[j]));
		printf("\n");
	}
return 0;
}

