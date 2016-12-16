#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int u[100010],v[100010],w[100010];
void merge(int start,int mid,int end);
typedef struct link
{
	int data;
	int length;
	struct link *next;
}node;
node *arr[100010];
typedef struct items
{
	int u;
	int v;
	int w;
}item;
item a[1000010];
int func(const void *a,const void *b)
{
	item *p,*q;
	p=(item*)a;
	q=(item*)b;

	return p->w - q->w;
}

/*void part( int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		part(start,mid);
		part(mid+1,end);
		merge(start,mid,end);
        }
}	
void merge( int start, int mid, int end)
{
	int m=mid+1,temp1[100010],temp2[100010],temp3[100010], k=start,t, j=start, size=end-start+1;
	while(k<=mid && m<=end)
	{
		if(w[k]<=w[m])
		{
			temp1[j]=w[k];
		        temp2[j]=u[k];
                        temp3[j]=v[k];
			k++;	
		}
		else
		{
			temp1[j]=w[m];
			temp2[j]=u[k];		
			temp3[j]=v[k];			
				m++;
		}
	j++;
	}
       while(k<=mid)
       {
	       temp1[j++]=w[k++];
		temp2[j++]=u[k++];
		temp3[j++]=v[k++];		
	}
       while(m<=end)
       {
	       temp1[j++]=w[m++];
               temp2[j++]=u[m++];
	       temp3[j++]=v[m++];
       }
       for(t=start;t<=end;t++)
       {
	       w[t]=temp1[t];
              u[t]=temp2[t];
	      v[t]=temp3[t];
       }

}*/
//int func(const void *a,const void *b)
//{
	//return ((*(item*)(a->w))-(*(item *)(b->w)));
//	item t=(item*)(a->w);
  //          item g=(item*)(b->w);
//	int t=((item *)a)->w;
//int g=((item *)b)->w;
//	    return t-g;
//
//}
int main()
{
	int m,n,k,sum=0,i,x,y,z;
	//item a[10010];
	//node *arr[10010],
	node *temp;
	temp=malloc(sizeof(node));
	int p[100010];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		arr[i]=malloc(sizeof(node));
		arr[i]->length=1;
		arr[i]->next=malloc(sizeof(node));
		arr[i]->next->data=i;
		arr[i]->next->next=NULL;
	}
	a[0].u=-6;
	a[0].v=-7;
	a[0].w=-10;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[i].u=x;
		a[i].v=y;
		a[i].w=z;

	}
	qsort(a,m+1,sizeof(item),func);

	//part(1,m);
	/*for(i=1;i<=m;i++)
	{
		printf("%d%d%d\n",u[i],v[i],w[i]);
	}*/

	for(i=1;i<=m;i++)
	{
		//printf("the first is%d and second is %d\n",p[u[i]],p[v[i]]);
		//printf("the first length is%d \n",arr[1]->length);
		if(p[a[i].u]!=p[a[i].v])
		{
			sum+=a[i].w;
			//printf("the sum becomes=%d\n",sum);
			if(arr[p[a[i].u]]->length>=arr[p[a[i].v]]->length)
			{
				node *temp=malloc(sizeof(node));
				temp=arr[p[a[i].u]]->next;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=malloc(sizeof(node));
				temp->next=arr[p[a[i].v]]->next;
				node *temp1=malloc(sizeof(node));
				temp1=arr[p[a[i].v]]->next;
				
				arr[p[a[i].u]]->length+=arr[p[a[i].v]]->length;
				arr[p[a[i].v]]->length=0;
				//printf(" let%d\n",p[u[i]]);
				
				//arr[p[u[i]]]->length+=arr[p[v[i]]]->length;
				while(temp1!=NULL)
				{
					p[temp1->data]=p[a[i].u];
					temp1=temp1->next;
				}
				//arr[p[u[i]]]->length+=arr[p[v[i]]]->length;
				//arr[p[v[i]]]->length=0;
			}
			else
			{

			
				node *temp=malloc(sizeof(node));
				temp=arr[p[a[i].v]]->next;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=malloc(sizeof(node));
				temp->next=arr[p[a[i].u]]->next;
				node *temp1=malloc(sizeof(node));
				temp1=arr[p[a[i].u]]->next;
				
				arr[p[a[i].v]]->length+=arr[p[a[i].u]]->length;
				arr[p[a[i].u]]->length=0;
				while(temp1!=NULL)
				{
					p[temp1->data]=p[a[i].v];
					temp1=temp1->next;
				}
			}
		}
	}
	
	/*for(k=1;k<=n;k++)
	{
		temp=arr[k]->next;
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}*/
	int flag=0,j;	
	
	for(k=1;k<=n;k++)
	{
		if(arr[k]->length==n)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("%d\n",sum);
	}
	if(flag==0)
	{
		printf("-1\n");
	}
	return 0;
}






