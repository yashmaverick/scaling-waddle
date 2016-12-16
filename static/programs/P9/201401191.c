#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	int* arr;
};
node tmp[1001];
void merge(node* c,int start,int mid,int end)
{
	int i,j,k=start;
	i=start;j=mid+1;
	while(i<=mid&&j<=end)
	{
		if(c[i].val<=c[j].val)
		{
			tmp[k++]=c[i];
			i++;
		}
		else
		{
			tmp[k++]=c[j];
			j++;
		}
	}
	while(i<=mid)
	{
		tmp[k++]=c[i];
		i++;
	}
	while(j<=end)
	{
		tmp[k++]=c[j];
		j++;
	}
	for(i=start;i<=end;i++)
	{
		c[i]=tmp[i];
	}
	return;
}
void mergesort(node* master,int start,int end)
{
	int i,j,k;
	int mid;
	mid=(start+end)/2;
	if(start==end)
	{
		return;
	}
	mergesort(master,start,mid);
	mergesort(master,mid+1,end);
	merge(master,start,mid,end);
	return;
}
int main()
{
	node *master;
	int n,j,MOD,i,weight,m;
	scanf("%d%d",&n,&MOD);
	master=(node*)malloc(n*sizeof(node));
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		int tot=0;
		int k=0;
		master[i].arr=(int*)malloc((m+1)*sizeof(int));
		while(m--)
		{
			scanf("%d",&weight);
			tot=(tot+weight)%MOD;
			master[i].arr[k++]=weight;
		}
		master[i].arr[k]=-1;
		master[i].val=tot;
	}
//Bubble sort - may or may not be stable
	/*	for(i=0;i<n;i++)
	{
		for(j=i+i;j<n-1;j++)
		{
			if(master[j].val>master[j+1].val)
			{
				temp=master[j];
				master[j]=master[j+1];
				master[j+1]=temp;
			}
		}
	} */ 
	mergesort(master,0,n-1);	
	for(i=0;i<n;i++)
	{
		printf("%d\n",master[i].val);
		for(j=0;master[i].arr[j]>=0;j++)
		{
			printf("%d\n",master[i].arr[j]);
		}
		printf("\n");  
	}
	return 0;
}
