#include<stdio.h>
#include<stdlib.h>
typedef struct node
{int val;
	struct node* next;
}node;
int tops=-1;
int stac[1010];
void push(int val)
{
	tops++;
	stac[tops]=val;
}
int pop()
{
	tops--;
	return stac[tops+1];
}
int j=0;
int c[1011];
int state[1011]={0};
int quick[1011]={0};
int count=0;
int  dfs(node* a[],int v)
{       c[j++]=pop();
	if(quick[c[j-1]]==1)
	{		count++;
		//printf("node=%d\n",v);
		quick[v]=1;
		return 0;
	}
	node* tmp4=(node*)malloc(sizeof(node));
	tmp4=a[c[j-1]];
	while(tmp4->next!=NULL) 
	{       if(state[tmp4->next->val]==0)
		{push(tmp4->next->val);
			state[tmp4->next->val]=1;
		}
		tmp4=tmp4->next;
	}
	return 1;
}
int main()
{int t,n,i,x,j1,y,h;
	node* a[1010];
	scanf("%d",&t);
	while(t--)
	{ 
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{	a[i]=(node*)malloc(sizeof(node));
			a[i]->val=i;
			a[i]->next=NULL;
		}
		for(i=1;i<=n;i++)
		{       scanf("%d",&x);
			for(j1=1;j1<=x;j1++)
			{       scanf("%d",&y);
				node *tmp=(node*)malloc(sizeof(node));
				tmp->val=i;
				tmp->next=NULL;
				if(a[y]->next==NULL)
				{   a[y]->next=(node*)malloc(sizeof(node));
				    a[y]->next=tmp;
				}
				else
				{    node *tmp1=(node*)malloc(sizeof(node));
					tmp1=a[y]->next;
					a[y]->next=tmp;
					tmp->next=(node*)malloc(sizeof(node));
					tmp->next=tmp1;
				}
                	}	
		}
		//int count=0;
		int flag=0;
		int index;
		int check;
		for(h=1;h<=n;h++)
		{       flag=0;
			push(a[h]->val);
			state[a[h]->val]=1;
			while(tops!=-1)
			{check=dfs(a,h);
				//printf("h=%d check=%d\n",h,check);
				if(check==0)
					break;
			}
				if(check==1)
				{for(i=1;i<=n;i++)
					{   if(state[i]!=1)
						 flag=1;    
					}
                                        if(flag==0)
					{	     count++;
						//printf("node=%d\n",h);
						quick[h]=1;
					}
				}
			for(i=1;i<=n;i++)
			    state[i]=0;
			
			j=0;
			tops=-1;
		}

		j=0;
		tops=-1;
		for(i=0;i<=1001;i++)
		{		     state[i]=0;
			quick[i]=0;
		}
		printf("%d\n",count);
		count=0;
	}
	return 0;
}
