#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
		int d;
		struct ll* next;
}ll;

int vs[1000006];
int max;
int node;

void dfs(ll* a[],int data,int count)
{
		ll* temp;
		ll* tmp;
		tmp=a[data];
		temp=a[data]->next;
	//	printf("dfs %d\n",data);
		while( temp!=NULL )
		{
				if( vs[temp->d]!=1 )
				{
						//printf("hello\n");
						vs[temp->d]=1;
						dfs(a,temp->d,count+1);
				}
				temp=temp->next;
				tmp=tmp->next;
				//printf("yo %d\n",tmp->d);
		}
		if(count>max)
		{
				//printf("ydjaso %d\n",data);
				max=count;
				node=data;
		}
}


int main()
{
		int test;
		scanf("%d",&test);
		while(test--)
		{
				int n;
				scanf("%d",&n);
				ll* a[1000006];
				int i;
				for(i=1;i<=n;i++)
				{
						a[i]=(ll*)malloc(sizeof(ll));
						a[i]->next=NULL;
				}
				int x=n-1;
				while(x--)
				{
						int u,v;
						scanf("%d%d",&u,&v);
						ll* temp1;
						ll* temp2;

						temp1=(ll*)malloc(sizeof(ll));
						temp1->d=u;
						temp1->next=a[v]->next;
						a[v]->next=temp1;

						temp2=(ll*)malloc(sizeof(ll));
						temp2->d=v;
						temp2->next=a[u]->next;
						a[u]->next=temp2;
				}

			/*	int q;
				ll* t;
				for(q=1;q<=n;q++)
				{
						t=a[q]->next;
						printf("%d:   ",q);
						while(t!=NULL)
						{
								printf("%d ",t->d);
								t=t->next;
						}
						printf("\n");
				}
				*/

				for(i=1;i<=n;i++)
						vs[i]=0;
				vs[1]=1;
				max=0;
				dfs(a,1,0);
				max=0;
				for(i=1;i<=n;i++)
						vs[i]=0;
				vs[node]=1;
				dfs(a,node,0);
				printf("%d\n",max+1);
		}
		return 0;
}
