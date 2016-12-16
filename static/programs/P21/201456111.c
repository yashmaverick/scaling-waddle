#include<stdio.h>
#include<stdlib.h>
struct node{
	int c;
	long long int mass;
	struct node* next;
};
struct heap{
	int c;
	long long int weight;
};
struct node* a[1000000];
struct heap cs[1000000];
int top;
void check(int top)
{
	int number;
	long long int w;
	if(top==1)
		return;
	if(cs[top].weight<cs[top/2].weight)
	{
		number=cs[top].c;
		cs[top].c=cs[top/2].c;
		cs[top/2].c=number;
		w=cs[top].weight;
			cs[top].weight=cs[top/2].weight;
			cs[top/2].weight=w;
			check(top/2);

	}
	return;
}
void push(struct node* x)
{
	top++;
	cs[top].c=x->c;
	cs[top].weight=x->mass;
	if(top==1)
	{
	//printf("after push x i.e %d cs[1] %d\n",x->c,cs[1].weight);
		return;
	}
	if(cs[top].weight<cs[top/2].weight)
	{
		check(top);
	}
	//printf("after push x i.e %d cs[1] is %d\n",x->c,cs[1].weight);
	return;


}
/*void check(int top)
{
	int number;
	int w;
	if(top==1)
		return;
	if(cs[top].weight<cs[top/2].weight)
	{
		number=cs[top].c;
		cs[top].c=cs[top/2].c;
		cs[top/2].c=number;
		w=cs[top].weight;
			cs[top].weight=cs[top/2].weight;
			cs[top/2].weight=w;
			check(top/2);

	}
	return;
}*/
void downcheck(int x)
{
	//printf("x n downc is %d\n",x);
	//printf("top is %d\n",top);
	
	long long int helpnum;
	int helpw;
	int d=0;
	int f=0;
	if(((2*x)+1)>top)
		return;
	if(cs[x].weight>cs[2*x].weight)
	{
		d=1;
	}
	if(cs[x].weight>cs[(2*x)+1].weight)
	{
		f=1;
	}
	if(d==1&&f==1)
	{
		if(cs[2*x].weight<cs[(2*x)+1].weight)
		{
			helpnum=cs[2*x].weight;
			cs[2*x].weight=cs[x].weight;
			cs[x].weight=helpnum;
			helpw=cs[2*x].c;
			cs[2*x].c=cs[x].c;
			cs[x].c=helpw;
			downcheck(2*x);
			return;

		}
		else
		{
			helpnum=cs[(2*x)+1].weight;
			cs[(2*x)+1].weight=cs[x].weight;
			cs[x].weight=helpnum;
			helpw=cs[(2*x)+1].c;
			cs[(2*x)+1].c=cs[x].c;
			cs[x].c=helpw;
			downcheck((2*x)+1);
			return;
			
		}
	}
	if(d==1&&f==0)
	{
			helpnum=cs[2*x].weight;
			cs[2*x].weight=cs[x].weight;
			cs[x].weight=helpnum;
			helpw=cs[2*x].c;
			cs[2*x].c=cs[x].c;
			cs[x].c=helpw;
			downcheck(2*x);
			return;

	}
	if(f==1&&d==0)
	{
			helpnum=cs[(2*x)+1].weight;
			cs[(2*x)+1].weight=cs[x].weight;
			cs[x].weight=helpnum;
			helpw=cs[(2*x)+1].c;
			cs[(2*x)+1].c=cs[x].c;
			cs[x].c=helpw;
			downcheck((2*x)+1);
			return;

	}
	return;

}

struct heap* findmin()
{
	struct heap* ret;
	struct heap* swap;
	//printf("%d %d at begim\n",cs[1].c,cs[1].weight);
	//ret=&cs[1];
	ret=malloc(sizeof(struct heap));
	ret->c=cs[1].c;
	ret->weight=cs[1].weight;
	//printf("%d %d ret\n",ret->c,ret->weight);
	swap=&cs[top];
	cs[1].c=swap->c;
	cs[1].weight=swap->weight;
	top--;
	if(top>1)
	{
	downcheck(1);
	}
	//printf("returning ret->c as %d and ret->weight as %d\n",ret->c,ret->weight);
	return ret;
}
long long int visit[1000000];
int main()
{
	int n,m,u,v,s,t,p,l;
	long long int w;
	top=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(p=0;p<=1000000;p++)
	{
		visit[p]=-1;
	}
	for(l=0;l<m;l++)
	{
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%lld",&w);
		struct node* temp;
		temp=malloc(sizeof(struct node));
		temp->c=v;
		temp->mass=w;
		temp->next=NULL;
		if(a[u]==NULL)
		{
			a[u]=temp;
		}
		else
		{
			temp->next=a[u];
			a[u]=temp;

		}


	}
	scanf("%d",&s);
	scanf("%d",&t);
	visit[s]=0;
	struct node* aid;
	aid=a[s];
	while(aid!=NULL)
	{
		aid->mass=visit[s]+aid->mass;
		//printf("befor push 1st time aid->mass is %d\n",aid->mass);
		push(aid);
		aid=aid->next;

	}
	while(top>0)
	{
		struct heap* small;
		small=findmin();
		if(visit[small->c]!=-1)
			continue;
		if(visit[small->c]==-1)
		{
		visit[small->c]=small->weight;
		
		}
		
		
		//printf("from findmin visit[%d] is %d\n",small->c,small->weight);
		if(small->c==t)
			break;
		struct node* vams;
		vams=a[small->c];
		while(vams!=NULL)
		{
			if(visit[vams->c]!=-1)
			{
				vams=vams->next;
				continue;
			}
			else
			{
				vams->mass=vams->mass+visit[small->c];
			}
			//printf("befor push 2 time edge is %d\n",vams->mass);
			push(vams);
			vams=vams->next;

		}

	}
	if(visit[t]==-1)
	{
		printf("NO\n");
	}
	else
	printf("%lld\n",visit[t]);
	return 0;

}
