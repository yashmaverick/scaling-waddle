#include<stdio.h>
#include<stdlib.h>
struct data
{
	int *input;
	int value;
};
typedef struct data data;
data *dealer;
int n;
/*void mergeSort(int low,int mid,int high);
void partition(int low,int high);
void partition(int low,int high){

	int mid;

	if(low<high){
		mid=(low+high)/2;
		partition(low,mid);
		partition(mid+1,high);
		mergeSort(low,mid,high);
	}
}
data temp[1010];
void mergeSort(int low,int mid,int high){
	int i,m,k,l;
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high)){
		if(dealer[l].value<=dealer[m].value){
			temp[i]=dealer[l];
			l++;
		}
		else{
			temp[i]=dealer[m];
			m++;
		}
		i++;
	}
	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=dealer[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=dealer[k];
			i++;
		}
	}
	for(k=low;k<=high;k++){
		dealer[k]=temp[k];
	}
}
void goodsort()
{
	partition(0,n-1);
	return ;
}*/


void goodsort()
{
	int c,d;
	data temp;
	for(c=0;c<(n-1);c++)
	{
		for(d=0;d<(n-c-1);d++)
		{
			if (dealer[d].value> dealer[d+1].value) 
			{
				temp       = dealer[d];
				dealer[d]   = dealer[d+1];
				dealer[d+1] = temp;
			}
		}
	}
	return ;
}
int main()
{
	int mod;
	scanf("%d%d",&n,&mod);
	int i,j,temp1,count;
	dealer=(data*)malloc(sizeof(data)*n);
	for(i=0;i<n;i++)
	{
		int m,temp;
		temp=0;
		count=1;
		scanf("%d",&m);
		(dealer[i].input)=(int *)malloc(sizeof(int)*(m+2));
		while(m--)
		{
			scanf("%d",&(dealer[i].input[count]));
			temp=((((temp)%mod)+((dealer[i].input[count])%mod))%mod);
			count++;
		}
		(dealer[i].input[count])=-23;
		(dealer[i].value)=temp;
	}
	goodsort();
	for(i=0;i<n;i++)
	{
		printf("%d\n",dealer[i].value);
		count=1;
		while((dealer[i].input[count])>=0)
		{
			printf("%d\n",(dealer[i].input[count]));
			count++;
		}
		printf("\n");
	}
	return 0;
}




