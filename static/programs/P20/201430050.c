#include<stdio.h>
#include<stdlib.h>
typedef struct node
{int val;
struct node* next;
}node;
int visar[1000010]={0};
int h=0;
int h1=0;
int c[1000010];
//int d[10000];
node* a[1000010];
int max1=0;
int maxleafnode;
void dfs(int v)
{
	c[h++]=v;
	visar[v]=1;
	int flag=0;
	node* tmp3=(node*)malloc(sizeof(node));
	tmp3=a[v];
	//printf("i\n");
	while(tmp3->next!=NULL)
	{
		if(visar[tmp3->next->val]==0)
		{       //printf("dfs=%d\n",tmp3->next->val);
			flag=1;
			dfs(tmp3->next->val);
		}
		tmp3=tmp3->next;
	}
	if(flag==0 || tmp3->next==NULL)
		{//d[h1++]=h;
			if(h>max1)
			{	max1=h;
                                maxleafnode=c[h-1];
                               
                         }			//printf("paths=%d\nd[h1-1]);
			h--;
	         }
	return;
}
int main()
{int t,n,i,u,v;
	scanf("%d",&t);
	while(t--)
        {
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{	a[i]=(node*)malloc(sizeof(node));
		        a[i]->val=i;
			a[i]->next=NULL;
			}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u,&v);
			node* tmp=(node*)malloc(sizeof(node));
			tmp->val=v;
			tmp->next=NULL;
			//printf("a\n");
			if(a[u]->next==NULL)
	        	{	a[u]->next=(node*)malloc(sizeof(node));
		                a[u]->next=tmp;
			//printf("b\n");
			}
			else
			{node* tmp1=(node*)malloc(sizeof(node));
				tmp1=a[u]->next;
				a[u]->next=tmp;
				tmp->next=(node*)malloc(sizeof(node));
				tmp->next=tmp1;
			//printf("c\n");
			}
			node* tmp2=(node*)malloc(sizeof(node));
			tmp2->val=u;
			tmp2->next=NULL;
			if(a[v]->next==NULL)
	        	{	a[v]->next=(node*)malloc(sizeof(node));
		                a[v]->next=tmp2;
			//printf("d\n");
			}
			else
			{node* tmp4=(node*)malloc(sizeof(node));
				tmp4=a[v]->next;
				a[v]->next=tmp2;
				tmp2->next=(node*)malloc(sizeof(node));
				tmp2->next=tmp4;
			}
	
            	}
		int j1=0;
			      dfs(1);
			      for(j1=0;j1<=n;j1++)
				      visar[j1]=0;
			      h=0;
		      dfs(maxleafnode);
		 for(i=0;i<=n;i++)
		 visar[i]=0;
		 printf("%d\n",max1);
		 max1=0;
		 h1=0;
	}
	return 0;
}
