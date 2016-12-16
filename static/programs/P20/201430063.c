#include<stdio.h>
#include<stdlib.h>
int a[2000005];
int visited[1000005]={0};
int top=-1;
typedef struct bfs
{
	struct bfs *next;
	int val;
	int height;

 }bfs;
bfs *head[1000005];
void create(int n)
{int i;
	for(i=0;i<=n;i++)
	{head[i]=(bfs*)malloc(sizeof(bfs));
		head[i]->next=NULL;
		head[i]->val=i;
                
}
}
void insert(int u,int v)
{
	bfs *temp;
	bfs *temp1;
	temp1=head[u];
//	 head[u]->count++;
	temp=temp1->next;
	temp1->next=(bfs*)malloc(sizeof(bfs));
	temp1->next->val=v;
	temp1->next->next=temp;
	//printf("%d\n",head[u]->next->val);
}

int main()
{
	int n,u,v,i,t;
scanf("%d",&t);
while(t--)	
{top=-1;
              scanf("%d",&n);
if(n!=1)	
{
		create(n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
		insert(v,u);
	}
	int c=0,d;
            bfs *temp=head[1];
	top++;
	a[top]=head[1]->val;
	int lower=0;
	head[1]->height=0;
	visited[1]=1;
	while(top!=n)
	{
		temp=head[a[lower]];
		while(temp!=NULL)
		{
			if(visited[temp->val]==0)
			{
				visited[temp->val]=1;
				top++;
				a[top]=temp->val;
				head[temp->val]->height=head[a[lower]]->height+1;
			        //printf("%d%d\n",temp->val,head[temp->val]->height);
                          }
			temp=temp->next;
		}
		lower++;
	}
	for(i=1;i<=n;i++)
if(c<head[i]->height)
	              {
                          d=i;
                          c=head[i]->height;
}   
	
//printf("%d\n",d);
top=-1;
for(i=0;i<=n;i++)
visited[i]=0;
temp=head[d];
        top++;
        a[top]=head[d]->val;
         lower=0;
        head[d]->height=0;
        visited[d]=1;
        while(top!=n)
        {
                temp=head[a[lower]];
                while(temp!=NULL)
                {
                        if(visited[temp->val]==0)
                        {
                                visited[temp->val]=1;
                                top++;
                                a[top]=temp->val;
                                head[temp->val]->height=head[a[lower]]->height+1;
                                //printf("%d%d\n",temp->val,head[temp->val]->height);
                          }
                        temp=temp->next;
                }
                lower++;
        }

	for(i=1;i<=n;i++)
if(c<head[i]->height)
	              {
                          d=i;
                          c=head[i]->height;
}
printf("%d\n",c+1);
for(i=1;i<=n;i++)
{
while(head[i]!=NULL)
{
temp=head[i];
head[i]=head[i]->next;
//temp=head[i];
free(temp);
}
}
}
else
printf("1\n");

for(i=0;i<=n;i++)
visited[i]=0;
}
return 0;
}

