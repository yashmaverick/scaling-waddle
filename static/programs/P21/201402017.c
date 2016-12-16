#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
int n;
struct node{
	int data;
	int wgt;
	struct node *next;
};
struct heap{
	int data;
	int wgt;
};
struct node *arr[100004];
struct heap min[100004];
int pos[100004]={0};
int heapsize=0;int len=0;
int dis[100004]={0},vis[100004]={0};
struct node *insert(int v,int w,struct node *root)
{
	struct node *temp=(struct node*)(malloc(sizeof(struct node)));
	temp->data=v;
	temp->wgt=w;
	temp->next=root;
	return temp;
}
void insert2(struct heap x)	
{
	int par,i,temp2,flag=0;
	struct heap temp1;
	heapsize++;
	min[heapsize]=x;
	pos[x.data]=heapsize;
	/*int now=heapsize;
	  while(min[now/2].wgt>x.wgt)
	  {
	  min[now]=min[now/2];
	  now=now/2;
	  }
	  min[now]=x;*/
	i=heapsize;
	while(i!=1 && flag!=1)
	{
		par=i/2;
		if(min[par].wgt>min[i].wgt)
		{
			temp1=min[i];
			min[i]=min[par];
			min[par]=temp1;
			temp2=pos[min[i].data];
			pos[min[i].data]=pos[min[par].data];
			pos[min[par].data]=temp2;
		}
		else
			flag=1;
		i=par;
	}
	return;

}
struct heap del()
{
	
		int temp1,temp2;
		struct heap p,q;
		struct heap t1=min[1];
		min[1]=min[heapsize];
		pos[min[1].data]=1;
		pos[t1.data]=0;
		heapsize=heapsize-1;
		int i=1;
		while(i<=heapsize/2 && i>0 && (min[i].wgt>min[2*i].wgt || min[i].wgt>min[2*i+1].wgt))
		{
			if(min[2*i].wgt<min[2*i+1].wgt)
			{
				temp1=pos[min[i].data];
				pos[min[i].data]=pos[min[2*i].data];
				pos[min[2*i].data]=temp1;
				p=min[i];
				min[i]=min[2*i];
				min[2*i]=p;
				i=2*i;
			}
			else
			{
				temp2=pos[min[i].data];
				pos[min[i].data]=pos[min[2*i+1].data];
				pos[min[2*i+1].data]=temp2;
				q=min[i];
				min[i]=min[2*i+1];
				min[2*i+1]=q;
				i=(2*i+1);
			}
		
		}
	return t1;
	
}
void dij(int s)
{
	int i;
	struct heap temp;
	for(i=1;i<=100004;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	dis[s]=0;
	for(i=1;i<=n;i++)
	{
		temp.data=i;
		temp.wgt=dis[i];
		insert2(temp);
	}
	while(heapsize)
	{

		//printf("%d\n",heapsize);
		struct heap t2=del();
	//	printf("%d=== %d\n",heapsize,t2.data);
		struct node *itr=arr[t2.data];
		vis[t2.data]=1;
		int tmp1;
		struct heap tmp2;
		while(itr!=NULL)
		{
			int par,flag=0;
			if(dis[itr->data]>dis[t2.data]+itr->wgt && vis[itr->data]==0)
			{
			//	printf("tt");
				dis[itr->data]=dis[t2.data]+itr->wgt;
				i=pos[itr->data];
				min[i].wgt=dis[itr->data];
				while(i!=1 && flag!=1)
				{
					par=i/2;
					if(min[i].wgt<min[par].wgt)
					{
						tmp1=pos[min[i].data];
						pos[min[i].data]=pos[min[par].data];
						pos[min[par].data]=tmp1;
						tmp2=min[i];
						min[i]=min[par];
						min[par]=tmp2;

					}
					else
						flag=1;
					i=par;
				}

			}
			itr=itr->next;
		}
	}

}	
int main()
{
	int s,t,m,i,u,v,w;
	scanf("%d %d",&n,&m);
	for(i=0;i<100004;i++)
	{
		arr[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		arr[u]=insert(v,w,arr[u]);
	}
	scanf("%d %d",&s,&t);
	dij(s);
	if(dis[t]!=INT_MAX)
	printf("%d\n",dis[t]);
	else
		printf("NO\n");
	return 0;
}



