#include<stdio.h>
#include<malloc.h>
int arr[100010],location=0;
struct link
{
	int data;
	int indegree;
	struct link *next;
}*shubh[100010];
void insert(int value)
{

	arr[0]=-1;
	location++;
	arr[location]=value;
	long long int x=location;
	while(arr[x/2]>value)
	{
		arr[x]=arr[x/2];
		x/=2;
	}
	arr[x]=value;

}
void deletemin()
{
	long long int k,minelement=arr[1],lastelement=arr[location--],child;


	for(k=1;2*k<=location;k=child)
	{
		child=k*2;
		if(child!=location && arr[child+1]<arr[child])
		{
			child++;
		}
		if(lastelement>arr[child])
		{
			arr[k]=arr[child];
		}
		else
			break;
	}
	arr[k]=lastelement;

}
int main()
{
	int m,n,i,j,k,brr[100010];
	//arr[0]=-1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		shubh[i]=malloc(sizeof(struct link));
		shubh[i]->data=i;
		shubh[i]->indegree=0;
		shubh[i]->next=NULL;
	}
	struct link *temp;
	for(k=0;k<m;k++)
	{
		scanf("%d%d",&i,&j);
		temp=malloc(sizeof(struct link));
		temp->data=j;
		shubh[j]->indegree++;

		temp->next=shubh[i]->next;
		shubh[i]->next=temp;
	}
	/*for(i=1;i<=n;i++)
	{
		temp=shubh[i]->next;
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
		printf("\nthe degree is=%d\n",shubh[i]->indegree);
	}
	printf("\n");*/
	for(i=1;i<=n;i++)
	{
		if(shubh[i]->indegree==0)
		{
			insert(shubh[i]->data);

		}
	}
	int t=0;
	while(location!=0)
	{
		int y=arr[1];
		brr[t]=y;
		t++;
		//if(location!=1)
		//{
		//	printf("%d ",arr[1]);
		//}
		//if(location==1)
		//{
		//	printf("%d",arr[1]);
		//}
		deletemin();
		temp=shubh[y]->next;
		while(temp!=NULL)
		{
			shubh[temp->data]->indegree--;
			if(shubh[temp->data]->indegree==0)
			{
				insert(shubh[temp->data]->data);
			}
			temp=temp->next;
		}
	}
	int l;
	for(l=0;l<t-1;l++)
	{
		printf("%d ",brr[l]);
	}
	printf("%d",brr[l]);
	printf("\n");
	return 0;
}






