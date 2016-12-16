#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int data;
	struct node * next;
}node;
int main()
{
	long long int test;
	scanf("%lld",&test);
	long long int i,j,g;
	for(g=0;g<test;g++)
	{
		long long int n;
		scanf("%lld",&n);
		node *arr[n+1],*l,*p;
		for(i=1;i<=n;i++)
		{
			arr[i]=(node *)malloc(sizeof(node));
			l=arr[i];
			l->data=i;
			l->next=NULL;
		}
		for(i=0;i<n-1;i++)
		{
				long long int a,b;
				scanf("%lld %lld",&a,&b);
				l=(node *)malloc(sizeof(node));
				l=arr[a];
				if(l->next==NULL)
				{
					l->next=(node *)malloc(sizeof(node));
					l=l->next;
					l->data=b;
					l->next=NULL;
				}
				else
				{
					l=arr[a];
					p=(node *)malloc(sizeof(node));
					p->data=b;
					p->next=l->next;
					l->next=p;
				}
				l=arr[b];
				if(l->next==NULL)
				{
					l->next=(node *)malloc(sizeof(node));
					l=l->next;
					l->data=a;
					l->next=NULL;
				}
				else
				{
					l=arr[b];
					p=(node *)malloc(sizeof(node));
					p->data=a;
					p->next=l->next;
					l->next=p;
				}
		}
		/*for(i=1;i<=n;i++)
		{
			l=arr[i];
			//if((l->next)!=NULL)
			//l=l->next;
			printf("%lld ---->",i);
			while(l!=NULL)
			{
				//if((l->data)!=i)
				printf("%lld ",l->data);
				l=l->next;
			}
			//if(l-)
			//printf("%d",l->data);
			printf("\n");
		}*/
		long long int s=0;
		int q[n+1],visited[n+1],dis[n+1];
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			dis[i]=99999;
		}
		j=1;
		q[j]=1;
		visited[1]=1;
		dis[1]=1;
		int rear=2;
		//bfs code
		node * r;
		while(j!=(n+1) && j<rear)
		{
			r=arr[q[j]];
			visited[r->data]=1;
			while(r!=NULL)
			{
				if((visited[r->data])==0)
				{
					q[rear]=r->data;
					dis[r->data]=dis[q[j]]+1;
					visited[r->data]=1;
					rear++;
				}
				r=r->next;
			}
			j++;
		}
		long long int max=0,k=0;
		//printf("%d\n",dis[3]);
		for(i=1;i<=n;i++)
		{
			int dd=q[i];
			int fuc=dis[dd];
			if(fuc > max)
			{
				max=dis[q[i]];
				k=q[i];
			}
		}
		//printf("%lld\n",k);
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			dis[i]=99999;
		}
		j=1;
		q[j]=k;
		visited[k]=1;
		dis[k]=1;
		rear=2;
		node * w;
		while(j!=(n+1) && j<rear)
		{
			w=arr[q[j]];
			visited[w->data]=1;
			while(w!=NULL)
			{
				if((visited[w->data])==0)
				{
					q[rear]=w->data;
					dis[w->data]=dis[q[j]]+1;
					visited[w->data]=1;
					rear++;
				}
				w=w->next;
			}
			j++;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			int gg=q[i];
			int sw=dis[gg];
			if(sw > max)
				max=sw;
		}
		printf("%lld\n",max);
	}
	return 0;
}