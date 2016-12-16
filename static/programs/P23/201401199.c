#include<stdio.h>
#include<stdlib.h>
#define size 100005

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
typedef node* link;

link head[size];
int in[size],nodes;
int min[size],end=0;
int ans[size],aptr=0;
void showh();

void swap(int a,int b)
{
    int temp;
    temp=min[a];
    min[a]=min[b];
    min[b]=temp;
}

void reset()
{
    int i;
    for(i=0;i<size;i++)
	head[i]=NULL;

    for(i=0;i<=nodes;i++)
	in[i]=0;
}

void minin(int number)
{   
    min[++end]=number;
    int cur=end,temp;
    while(cur > 1 && min[cur/2] > number)
    {
	swap(cur,cur/2);
	cur/=2;
    }
    //   printf("minheap - \n");
    //    show(min);
}

void mindel()
{
    //    printf("deleting %d\n",min[1]);
    min[1]=min[end];
    end--;
    int cur=1;
    while(((cur*2)<=end && (min[cur]>=min[cur*2])) || ((min[cur]>=min[(cur*2)+1]) && ((cur*2)+1<=end)))
    {
	int index=0,temp;
	if((cur*2)+1>end)
		index=cur*2;
	else
	    index=min[cur*2]<=min[(cur*2)+1]?cur*2:((cur*2)+1);
	//	printf("swp ind -  %d<---> %d\n",cur,index);
	swap(cur,index);
	cur=index;
    }
    //    printf("end cur = %d\n",cur);
}

void showh()
{
    printf("heap\n");
    int i;
    for(i=1;i<=end;i++)
    {
	printf("  %d\n",min[i]);
    }
}

link insert(link head,int val)
{
    link temp = (link) malloc(sizeof(node));
    temp->data=val;
    temp->next=head;
    head=temp;
    return head;
}

void show(link head)
{
    if(head==NULL)
	return;
    show(head->next);
    printf("%d ",head->data);
}

void func(int on)
{
    link temp=head[on];
//    printf("func on = %d\n",on);
    while(temp!=NULL)
    {
	in[temp->data]--;
	if(in[temp->data]==0)
	{
//	    printf("became 0 adding %d to min\n",temp->data);
	    minin(temp->data);
//	    printf("end=%d\n",end);
	}
	temp=temp->next;
    }
}

int main()
{
    int n,m,q,i,x,y;

    scanf("%d%d",&n,&m);
    nodes=n;
    reset();

    for(i=0;i<m;i++)
    {
	scanf("%d%d",&x,&y);
	in[y]++;
	head[x]=insert(head[x],y);
    }
    /*
       printf("showing\n");
       for(i=1;i<=n;i++)
       {
       printf("show for i=%d\n",i);
       show(head[i]);
       printf("\n");
       }

       printf("in[]\n");
       for(i=1;i<=n;i++)
       printf("%d ",in[i]);
       printf("\n");
     */
    for(i=1;i<=n;i++)
    {
	if(in[i]==0)
	{
//	    printf("adding %d to min\n",i);
	    minin(i);
	}
    }

    int on;
    while(end>0)
    {
//	printf("\nbegin ");
//	showh();
	on=min[1];
	mindel();
//	printf("add %d to ans\n",on);
	ans[aptr++]=on;
	func(on);

    }
    for(i=0;i<aptr;i++)
    {
	printf("%d",ans[i]);
	if(i!=(aptr-1))
	    printf(" ");
    }
    printf("\n");
    return 0;
}
