#include<stdio.h>
#include<stdlib.h>
int flag[1004]={0};
int man[1004],top=-1,count=0;
void push(int i)
{
	top++;
	man[top]=i;
	count++;
	flag[i]=1;
	return ;
}
void pop()
{
	top--;
	return ;
}
typedef struct link
{
	int vl; 
	struct link *next;

}link;
typedef struct array
{
	struct link *new;
	struct link *itr;
	struct link *head,*r;
}array;
struct array *jo,*jo1;
void dfs(int i)
{
	if(flag[i]==0)	
	{
		if(jo[i].head==NULL)
		{
			//pop();
			flag[i]=1;
			jo[i].itr=jo[i].head;
		}	
		else
		{
			while(jo[i].head!=NULL)
			{
				flag[i]=1;
				if(flag[jo[i].head->vl]==0)
				{
					//		//	push(jo[i].head->vl);
					count++;
				//	printf(" dfs: %d ",count);
				}
				//printf("%d ",top);
				dfs(jo[i].head->vl);
				jo[i].head=jo[i].head->next;
			}
			//jo[i].r=jo[i].head;
		}
	}

}

void dfs1(int i)
{
	if(flag[i]==0)
	{
		if(jo1[i].head==NULL)
		{
			//pop();
			flag[i]=1;
			jo1[i].itr=jo1[i].head;
		}
		else
		{
			while(jo1[i].head!=NULL)
			{
				flag[i]=1;
				if(flag[jo1[i].head->vl]==0)
				{
					//              //      push(jo[i].head->vl);
					count++;
					//printf(" dfs: %d ",count);
				}
				//printf("%d ",top);
				dfs1(jo1[i].head->vl);
				jo1[i].head=jo1[i].head->next;
			}
			//jo[i].r=jo[i].head;
		}
	}
}
	int main()
	{
		int test=0;	
		scanf("%d",&test);
		while(test--)
		{
			int  x,y,i,n,m,v,s,ans=0,st=0,h,e;
			//	struct link *next=NULL,*itr=NULL,*new=NULL;
			scanf("%d",&m);
			
			jo=malloc(sizeof(array)*1004);
			jo1=malloc(sizeof(array)*1004);
			
			for(i=1;i<=1004;i++)
				flag[i]=0;
			for(i=1;i<=m;i++)
			{
				scanf("%d",&s);
				while(s--)
				{
					scanf("%d",&v);	
					jo[i].new=malloc(sizeof(link));
					jo[i].new->vl=v;

					jo1[v].new=malloc(sizeof(link));
					jo1[v].new->vl=i;
					if(jo[i].head==NULL)
					{
						jo[i].head=jo[i].new;
						jo[i].itr=jo[i].new;
						jo[i].r=jo[i].new;
					}
					else
					{
						jo[i].itr->next=jo[i].new;
						jo[i].itr=jo[i].itr->next;
					}
					//jo1[v].new=malloc(sizeof(link));
					//jo1[v].new->vl=i;
					if(jo1[v].head==NULL)
					{
						jo1[v].head=jo1[v].new;
						jo1[v].itr=jo1[v].new;
						jo1[v].r=jo1[v].new;
					}
					else
					{
						jo1[v].itr->next=jo1[v].new;
						jo1[v].itr=jo1[v].itr->next;
					}






				}
			}
			/*	for(i=1;i<=m;i++)
				{
				jo[i].itr=jo[i].head;
				while(jo[i].itr!=NULL)
				{
				printf("%d ",jo[i].itr->vl);
				jo[i].itr=jo[i].itr->next;
				}
				printf("\n");

				}*/
			for(i=1;i<=m;i++)
			{
				count=0;	
				dfs1(i);
				//printf(" %d\n ",count);
				if(count==m-1)
					{
					st=1;
					ans=1;
					}
				for(h=1;h<=m;h++)
					flag[h]=0;
				for(e=1;e<=m;e++)
				{
					jo[e].head=jo[e].r;

					jo1[e].head=jo1[e].r;
				}
				if(st==1)
					break;
		
		
		
			}
			count=0;
			dfs(i);
		printf("%d\n",(count+ans));
		}
			return 0;
	}














	//	for(i=1;i<=n;i++)
	//	{
	//		printf("%d->",i);
