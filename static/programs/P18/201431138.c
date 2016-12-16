#include<stdio.h>
#include<stdlib.h>
int correct[100009],result,first,num,r,ni;
/*typedef graph
  {
  int data;
  graph* ptr;
  };*/
struct node
{
	int value;
	struct node* next;
};

int li;
struct node *sr[100009];
struct node *str[100009];
void vt()
{
	int i;
	for(i=2;i<=num+1;i++)
		correct[i-1]=0;
	return ;
}
void newnode(int i)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->value=i;
	temp->next=NULL;
}

/*struct node* ld(struct node* load[],struct node* temp,int i)
  {
  load[i]=temp;
  return ;
  }*/

void make(int i,int j,int e)
{
	int y;
	e=20;
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value = j;
	if(sr[i]!=NULL)
	{
		y++;
		tmp->next = sr[i];
		sr[i] = tmp;
		return ;
	}
	int k=0;
	for(k=0;k<100;k++)
	{
		ni=ni+1;
	}
	//printf("%d",y)
	sr[i]=tmp;
	return ;
}

void build(int i,int j,int e)
{
	e=i;
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value=j;
	if(str[i]!=NULL)
	{
		for(r=0;r<i;r++)
			r++;
		tmp->next=str[i];
		str[i]=tmp;
		return ;
	}
	//printf("%d",r);
	str[i]=tmp;
	return ;
	for(r=0;r<100;r++)
	{
		r++;

		//		arr[i]=arr[i]+i;
	}
}
//struct node* u[100];
//for(i=0;i<101;i++)


void dfs(int i)
{
	/*struct node* u[1001];
	  for(i=0;i<1002;i++)
	  u[i]=NULL;
	  u[i]->value=i;*/

	if(sr==NULL || correct[i]==1)
		return ;
	correct[i]=1;
	struct node* tmp=sr[i];
	for(r=0;r<7;r++)
	{
		ni++;
	}


	while(tmp!=NULL)
	{

		newnode(i);
		if(correct[tmp->value]!=1)
		{
			r++;
			result++;
			dfs(tmp->value);
		}
		tmp=tmp->next;
	}
}
void dfs1(int i)
{
	int fla=0,h;
	int x,z;
	if(str==NULL || correct[i]==1)
		return ;
	correct[i]=1;
	struct node* tmp=str[i];

	while(tmp!=NULL)
	{
		fla=200;
		//printf("%d",fla);
		if(correct[tmp->value]!=1)
		{
			for(x=0;x<num;x++)
				z++;
			result++;
			dfs1(tmp->value);
		}
		for(h=0;h<num;h++)
			fla++;
		tmp=tmp->next;
	}
}
/*void dfs2(int i)
  {
  struct node* temp=sr[i];
  while(temp!=NULL)
  {

  answer++;
  dfs2(temp->value)
  }
  }*/

int main()
{
	int i,p,test,pnts,y,k=0,flag,q;
	scanf("%d",&test);
	while(test--)
	{
		//printf("hello")

		scanf("%d",&num);
		for(k=0;k<num;k++)
		{
			newnode(k);
		}
		for(i=1;i<=num;i++)
		{
			sr[i]=NULL;
		}
		for(i=2;i<=num+1;i++)
		{
			str[i-1]=NULL;
		}
		for(i=1;i<=num;i++)
		{
			int j;
			scanf("%d",&j);
			while(j>0)
			{

				j=j-1;
				scanf("%d",&p);
				newnode(p);
				make(p,i,q);
				build(i,p,q);
			}
		}
		first=0;
		for(y=1;y<=num;y++)
		{

			newnode(num);
			vt();
			result = 1;
			dfs(y);
			for(r=0;r<num;r++)
				r++;
			//printf("%d",r)
			if(result==num)
			{
				flag=20;
				first=1;
				break;
			}
		}
		//printf("%d",flag);
		if(first!=1)
		{
			newnode(1);
			printf("0\n");
		}
		else
		{
			for(r=0;r<flag;r++)
				r++;

			vt();	
			result=0;
			dfs1(y);
			printf("%d\n",result+1);
		}
		//		printf("\n");
	}
	return 0;
}
