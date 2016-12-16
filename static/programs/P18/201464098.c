#include<stdio.h>
#include<stdlib.h>
#define gi(x) scanf("%d",&x) ;
typedef struct node{
	int data;
	struct node * next;
}node;
int main()
{
	int test,i,j,g;
	gi(test);
	for(g=0;g<test;g++)
	{
		int no,m,a;
		gi(no);
		node *arr[no+1];
		for(i=1;i<=no;i++)
		{
			arr[i]=(node *)malloc(sizeof(node));
		//	l=arr[i];
			arr[i]->data = i;
			arr[i]->next=NULL;
		}
		for(i=1;i<=no;i++)
		{
			gi(m);
		//	arr[i]=(node *)malloc(sizeof(node));
			for(j=0;j<m;j++)
			{
				gi(a);
				node *l;
				l=arr[a];
				if(l->next==NULL)
				{
					l->next=(node *)malloc(sizeof(node));
					l=l->next;
					l->data=i;
					l->next=NULL;
				}
				else
				{
					node *p;
					p=(node *)malloc(sizeof(node));
					p->data=i;
					p->next=l->next;
					l->next=p;
				}
			}
		}
		/*for(i=1;i<=no;i++)
		{
			l=arr[i];
			//if((l->next)!=NULL)
			//l=l->next;
			//printf("%d ---->",i);
			while((l->next)!=NULL)
			{
				//if((l->data)!=i)
				printf("%d ",l->data);
				l=l->next;
			}
			//if(l-)
			printf("%d",l->data);
			printf("\n");
		}*/
		int aaa,s,count=0;
		node *l;
		for(aaa=1;aaa<=no;aaa++)
		{
			int q[no+1],visited[no+1],flag=0;
			for(i=1;i<=no;i++)
			{
				q[i]=0;
				visited[i]=0;
			}
			s=aaa;
	//		visited[s]=0;
			j=0;
			q[j]=s;
			int rear=1;
			while(j!=no&& j< rear)
			{
					l=arr[q[j]];
				visited[l->data]=1;

				//printf("q[j]=%d  j=%d   rear-1=%d     q[rear-1]=%d \n",q[j],j,rear-1,q[rear-1]);
				//l=arr[q[j]];
				while(l!=NULL)
				{
					//printf("%d\n",l->data );
					
					if(visited[l->data]==0)
					{
						//printf("rear=%d q[rear]%d\n",rear,q[rear] );
						q[rear]=l->data;
						//printf("rear=%d q[rear]=%d\n",rear,q[rear] );
						visited[l->data]=1;
						rear++;
					}
					l=l->next;
				}
				j++;
			}
			for(i=1;i<=no;i++)
			{
				if(visited[i]==0)
				{	flag=1;break;}
			}
			if(flag==1)
			{
				flag=0;
			}
			else
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}