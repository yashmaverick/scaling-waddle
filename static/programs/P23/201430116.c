#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	int inconnected;
	struct list *next;
};
typedef struct list element;
typedef element *link;
int end;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void shuffledownmin(int max[],int p)
{
     int i,j;
     i=2*p;
     while(i<(end)&&((max[p])>(max[i])||(max[p])>(max[i+1])))
     {
     	if((max[i])<(max[i+1])){
     		swap(&max[i],&max[p]);
     		p=i;
     		i=2*p;
     	}
     	else{
     		swap(&max[i+1],&max[p]);
     		p=i+1;
     		i=2*p;
     	}
     }
   //  if(i==(end-1)&&(max[p])>(max[i]))
     //{
     //	swap(&max[i],&max[p]);
     //}

}
void deletemin(int max[])
{
	max[1]=max[((end)-1)];
	(end)--;
    shuffledownmin(max,1);
}
void heapifymin(int a,int max[])
{
	int j,k;
	max[(end)]=a;
	(end)++;
	j=(end)-1;
    k=j/2; // hp mei vrtx
    while(k>0&&(max[k])>(max[j]))
    {
       	swap(&max[j],&max[k]);
        j=k;
        k=j/2;
    }  
}
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	link *a;
	a=malloc((n+1)*sizeof(link));
	int *max;
	max=malloc((n+1)*sizeof(int));   // max as min heap
	for(i=1;i<=n;i++)
	{
		a[i]=malloc(sizeof(element));
		a[i]->data=i;
		a[i]->inconnected=0;
		a[i]->next=NULL;
	}
	int v1,v2;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&v1,&v2);
		link temp;
		temp=malloc(sizeof(element));
		temp->data=v2;
		temp->next=a[v1]->next;
		a[v1]->next=temp;
		(a[v2]->inconnected)++;
	}
	end=1;
	for(i=1;i<=n;i++)
	{
		if((a[i]->inconnected)==0)
		{
			heapifymin(a[i]->data,max);
		}
	}
	link temp;
//	for(i=1;i<end;i++)
	long long int love[100004];
	long long int r=0;
	while(end>1)
	{
		//printf("%d ",max[1]);
		love[r++]=max[1];
		temp=a[max[1]];
		deletemin(max);
		temp=temp->next;
		while(temp!=NULL)
		{
			//printf("***%d\n",temp->data);
			(a[temp->data]->inconnected)--;
			if(a[temp->data]->inconnected==0)
			{
				//printf("^^%d\n",temp->data);
				heapifymin(temp->data,max);
			}
			temp=temp->next;
		}
	}
	for(end=0;end<r-1;end++)
		printf("%lld ",love[end]);
	printf("%lld\n",love[r-1]);
	//printf("\n");
	return 0;
}
