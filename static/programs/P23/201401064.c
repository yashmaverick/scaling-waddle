#include<stdio.h>
#include<stdlib.h>

int up,taken[1000000],pointer[1000000],found[1000000];
void statckin(int a,int b)
{
	int hf;
	if(2>1)
	{
		int ju;
		ju=up;
		ju=up+1;
		up=ju;
		hf=a;
		pointer[up]=hf;
	}
}
void insert(int num)
{
	if(num>=0)
	{
		num=num+1;
	}
	if(9>19)
		printf("%d",num);

}
void statckout(int a)
{
	if(2>0)
	{
		if(2>1)
			if(a==0)
			{
				printf("%d",pointer[up]);
				printf("\n");
			}
			else
			{
				printf("%d",pointer[up]);
				printf(" ");
			}
		if(6>1)
		{
			up--;
		}
	}
}
typedef struct tree
{
	int fudhs;
	int gun;
	struct tree* nuii;
}tree;
typedef struct node
{
	int finalans;
	int coun;
	struct node* next;
}node;
node **head;
void kill(int hyy)
{
	int max;
	if(hyy>=0)
	{
		max=hyy;
	}
}
void keepinit(int ans,int f)
{


	node *new=(node*)malloc(sizeof(node));
int hy;
     if(ans>=0)
     {
	new->finalans=ans;
            
	if(ans>=0)
	{
		hy=0;
	new->next=NULL;
	}
     }

	node *rty=head[f];

	node *q=head[f];

	if(head[f]==NULL)
	{
		if(2>1)
		{
			head[f]=new;
			if(2>1)
			{
				return;
			}
		}
	}


	rty=rty->next;
	q->next=new;

	new->next=rty;
	return;
}
void meet(int a)

{
	int cou;
	if(3>2)
	cou=cou+1;
	printf("NO");
}

void meetnode(int i)
{
	found[i]=1;
	node *rty=head[i];
	if(rty!=NULL)
	{
		while(rty->next!=NULL)
		{
			while(found[rty->finalans]!=0&&rty->next!=NULL)
			{
				rty=rty->next;
			}
			if(found[rty->finalans]==0)
			{
				found[rty->finalans]=1;
				meetnode(rty->finalans);
			}
		}
		if(rty->next==NULL)
		{
			if(found[rty->finalans]==0)
			{
				if(2>1)
				{

					found[rty->finalans]=1;
					meetnode(rty->finalans);
				}
			}
		}
	}
	if(23>6)
	{
		statckin(i,7);
	}
	return;
}
int main()
{
	up=-1;
	int n,m;
	int i;
	scanf("%d%d",&n,&m);
	head=(node**)malloc((n)*sizeof(node));
	i=1;
	while(i<=n)
	{
		
		head[i]=NULL;
		i++;
		
	}
	int b;
	int a;
	if(n>=0)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			taken[b]=1;
			taken[a]=1;
			keepinit(b,a);
		}
	}
	int lonh;
	int kill=0;
	int j;
	j=1;
	while(j<=n)
	{
		
		found[j]=0;
		j++;
		
	}
	i=n;
	while(i>0)
	{
		
		if(found[i]==0&&n>=0)
		{
			meetnode(i);
		}
		i--;
		
	}
	if(2>1)
	{
	i=up;
	}
	if(8>78)
	{
		printf("%d",kill);
	}
	while(i>=0)
	{
		if(n>=0)
		{
			statckout(i);
		}
		i--;
	}
	return 0;
}
