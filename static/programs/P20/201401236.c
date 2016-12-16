#include<stdio.h>
#include<stdlib.h>
typedef struct array
{
	struct link *new;
	struct link *itr;
	struct link *head,*r;
}array;
typedef struct link
{
	int vl;
	struct link *next;

}link;
array *jo;
int count=0,ans=0,flag[1000005]={0},max=0;
void dfs(int i)
{
	if(flag[i]==0)
	{
		if(jo[i].head==NULL)
		{
			flag[i]=1;
			jo[i].head=jo[i].r;
		}
		else
		{
			while(jo[i].head!=NULL)
			{
				flag[i]=1;
				if(flag[jo[i].head->vl]==0)
					count++;
				//printf("i:%d count: %d\n",i,count);
				dfs(jo[i].head->vl);
				jo[i].head=jo[i].head->next;
			}
			if(jo[i].head==NULL)
			{
			if(max<count)
			{
				max=count;
				
				ans=i;
			//	printf("%d %d\n",max,ans);
			}
			count--;
			}
			}
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	int  x,y,i,n,m ,j;
	scanf("%d",&n);
	jo=malloc(sizeof(array)*1000005);
	for(i=1;i<=(n-1);i++)
	{
		scanf("%d%d",&x,&y);
		jo[x].new=malloc(sizeof(link));
		jo[x].new->vl=y;
		if(jo[x].head==NULL)
		{
			jo[x].head=jo[x].new;
			
			jo[x].itr=jo[x].new;
			jo[x].r=jo[x].new;
		}
		else
		{
			jo[x].itr->next=jo[x].new;
			jo[x].itr=jo[x].itr->next;
		
		}
		jo[y].new=malloc(sizeof(link));
		jo[y].new->vl=x;
		if(jo[y].head==NULL)
		{
			jo[y].head=jo[y].new;
			
			jo[y].itr=jo[y].new;
			jo[y].r=jo[y].new;
		}
		else
		{
			jo[y].itr->next=jo[y].new;
			jo[y].itr=jo[y].itr->next;
		}
	}
	/*for(i=1;i<=n;i++)
	{
	while(jo[i].head!=NULL)
	{
	printf("%d ",jo[i].head->vl);
	jo[i].head=jo[i].head->next;
	
	}
	printf("\n");
	}*/
	count=0;
	max=0;
	for(i=1;i<=n;i++)
		flag[i]=0;
	dfs(1);
//	printf("%d %d\n",max,ans);
	for(i=1;i<=n;i++)
		flag[i]=0;
	count=0;
	max=0;
	for(j=1;j<=n;j++)
		jo[j].head=jo[j].r;
	

	
	
	dfs(ans);
	printf("%d\n",max+1);

	}
	return 0;
}
