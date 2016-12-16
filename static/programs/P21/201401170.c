#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int visited[1000007],exist[1000007],pos[1000007],end=0,flag,count=0,n,x,start,t,ans=-1;
typedef struct node
{
	long long int val;
	long long int wei;
	struct node*next;
}node;
typedef struct node2
{
	long long int ind;
	long long int len;
}node2;
node2 b[1000007];
node*a[1000007];
node*temp;
node2 temp1;
node*insert(node*head,long long int data,long long int length)
{
	node*start=head;
	node*temp=(node*)malloc(sizeof(node));
	temp->val=data;
	temp->wei=length;
	temp->next=head->next;
	head->next=temp;
	return start;
}
void insert2(long long int x,long long int y)
{
	node2 temp1;
	long long int i,j;
	end++;
	b[end].ind=x;
	b[end].len=y;
	j=end;
	while(j/2>0)
	{
		if(b[j/2].len>b[j].len)
		{
			temp1=b[j/2];
			b[j/2]=b[j];
			b[j]=temp1;
			pos[b[j].ind]=j;
			pos[b[j/2].ind]=j/2;
		}
		else
			break;
		j=j/2;
	}
	return;
}
long long int del()
{
	long long int req=b[1].len;
	b[1]=b[end];
	pos[b[1].ind]=1;
	long long int i=1,j;
	end--;
	while(2*i<=end)
	{
		if(2*i==end)
		{
			j=2*i;
		}
		else if(b[2*i+1].len<b[2*i].len)
		{
			j=2*i+1;
		}
		else
		{
			j=2*i;
		}
		if(b[i].len>b[j].len)
		{
			temp1=b[i];
			b[i]=b[j];
			b[j]=temp1;
			pos[b[i].ind]=i;
			pos[b[j].ind]=j;
			i=j;
		}
		else
			break;
	}
	return req;
}
void prims(long long int s)
{
	while(end!=0)
	{
		long long int x;
/*		if(visited[s]==1)
		{
			x=del();
			s=b[1].ind;
			continue;
		}*/
		visited[s]=1;
		temp=a[s];
		x=del();
		if(temp!=NULL)
			temp=temp->next;
		while(temp!=NULL)
		{
			if(visited[temp->val]==0)
			{
				if(!exist[temp->val])
				{
					insert2(temp->val,(temp->wei)+x);
					pos[temp->val]=end;
					exist[temp->val]=1;
				}
				else
				{
					b[pos[temp->val]].len=fmin(b[pos[temp->val]].len,(temp->wei)+x);
				}
			}
			temp=temp->next;
		}
		s=b[1].ind;
		if(s==t)
		{
			ans=b[1].len;
			break;
		}
	}
}
node*print(node*head)
{
	node*start=head;
	while(start!=NULL)
	{
		printf("%lld",start->val);
		start=start->next;
	}
	return head;
}
int main()
{
	long long int m,i,j,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		a[i]->val=i;
		a[i]->wei=0;
		a[i]->next=NULL;
		visited[i]=0;
		exist[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x]=insert(a[x],y,z);
	}
	scanf("%lld%lld",&start,&t);
	b[++end].ind=start;
	b[end].len=0;
	prims(start);
/*	for(i=1;i<=n;i++)
		if(visited[i]==1)
			count++;*/
	if(ans==-1)
		printf("NO\n");
	else
		printf("%lld\n",ans);
	return 0;
}
