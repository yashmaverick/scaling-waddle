#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
		int d;
		struct ll* next;
}ll;

int n;
int vs[1002];
int vb[1002];
int s[1002];
int count=0;

void dfs(ll* a[],int data);

int main()
{
		int test;
		scanf("%d",&test);
		while( test-- )
		{
				ll* a[1002];
				ll* b[1002];
				scanf("%d",&n);
				int i;
				int ans=0;
				for( i=1 ; i<=n ; i++)
						s[i]=0;
				for( i=1 ; i<=n ; i++ )
				{
						a[i]=(ll*)malloc(sizeof(ll));
						a[i]->next=NULL;
						b[i]=(ll*)malloc(sizeof(ll));
						b[i]->next=NULL;
				}
				for( i=1 ; i<=n ; i++ )
				{
						int m;
						scanf("%d",&m);
						while( m-- )
						{
								int j;
								scanf("%d",&j);
								ll* temp;

								temp=(ll*)malloc(sizeof(ll));
								temp->d=i;
								temp->next=a[j]->next;
								a[j]->next=temp;
						
								ll* temp2;

								temp2=(ll*)malloc(sizeof(ll));
								temp2->d=j;
								temp2->next=b[i]->next;
								b[i]->next=temp2;
						}
				}

				/*int q;
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
			
				ll* t1;
				for(q=1;q<=n;q++)
				{
						t1=b[q]->next;
						printf("%d:   ",q);
						while(t1!=NULL)
						{
								printf("%d ",t1->d);
								t1=t1->next;
						}
						printf("\n");
				}*/


				for( i=1 ; i<=n ; i++)
				{
						int k;
						for(k=1;k<=n;k++)
								vs[k]=0;
						vs[i]=1;
						count=0;
						dfs(a,i);
						//printf("\n");
						if( count == n )
						{
								break;
						}
				}
				count=0;
				if(i<=n)
				{
						int k;
						for(k=1;k<=n;k++)
								vs[k]=0;
						vs[i]=1;
					//	printf("yo %d\n",i);
						dfs(b,i);
				}
				printf("%d\n",count);
		}
		return 0;
}

void dfs(ll* c[],int data)
{
		ll* temp;
		temp=c[data]->next;
	//	printf("%d ",data);
		count++;
		while( temp!=NULL )
		{
				if( vs[temp->d]!=1 )
				{
						vs[temp->d]=1;
						dfs(c,temp->d);
				}
				temp=temp->next;
		}
}

