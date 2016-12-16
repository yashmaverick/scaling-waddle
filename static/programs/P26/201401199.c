#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10004

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;
typedef node* link;
int price[size];
link head[size];
int f=0,e=0,qu[size],v[size],fl=1;
int pr[size];

int seive()
{
    int i,j;
    for(i=2;i*i<=size;i++)
	if(pr[i]=1)
	    for(j=2*i;j<=size;j+=i)
		pr[j]=0;
}

void show(link head)
{
    if(head==NULL)
	return;
    printf(" %d\n",head->data);
    show(head->next);
}
link insert(link head,int val)
{
    link temp = (link) malloc(sizeof(node));
    temp->data=val;
    temp->next=head;
    head=temp;
    return head;
}
void tostr(int num,char str[])
{
    int d,in=4;
    while(num)
    {
	d=num%10;
	str[in]='0'+d;
	num/=10;
	in--;
    }
}

int toint(char s[])
{
    int i,mul=10,num=0;
    for(i=1;i<=4;i++)
	num=(num*mul)+(s[i]-'0');
    return num;
}

void print(char s[])
{
    int i;
    for(i=1;i<=4;i++)
    {
	printf(" %c ",s[i]);
    }
    printf("\n");
}
void gengraph()
{
    int num=1001,in;
    while(num<=size)
    {
	if(pr[num]==1)
	{
//	    printf("for %d\n",num);
	    char str[5],tstr[5];
	    tostr(num,str);
	    for(in=4;in>=1;in--)
	    {
		//		print(str);
		strcpy(tstr,str);
		//		print(tstr);
		tstr[in]='0';
		while(tstr[in]<='9')
		{
		    int tn;
		    tn=toint(tstr);
		    //		    printf("tn=%d\n",tn);
		    if(tn>1000 && pr[tn]==1 && tn!=num)
		    {
//			printf("  inserting %d\n",tn);
			head[num]=insert(head[num],tn);
			head[tn]=insert(head[tn],num);
		    }
		    tstr[in]++;
		}
	    }
	}
	num++;
    }
}

//BFS
void bfs(int cur,int end)
{
    qu[e++]=cur;
    v[cur]=1;
    price[cur]=0;
    while(f!=e)
    {
	cur=qu[f++];
	link temp=head[cur];
	while(temp!=NULL)
	{
	    if(v[temp->data]==0)
	    {
		v[temp->data]=1;
		price[temp->data]=price[cur]+1;
		qu[e++]=temp->data;
	    }
	    if(temp->data==end)
		return;
	    temp=temp->next;
	}
    }
}
//END HERE


int main()
{
    int i;
    for(i=2;i<size;i++)
	pr[i]=1;
    for(i=0;i<size;i++)
	head[i]=NULL;
    seive();
    gengraph();
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
	f=0;e=0;
	for(i=999;i<=size;i++)
	{
	    v[i]=0;
	    price[i]=-1;
	}
	int start,end;
	scanf("%d%d",&start,&end);
	bfs(start,end);
	if(v[end]==0)
	    printf("Impossible\n");
	else
	    printf("%d\n",price[end]);
    }
    return 0;
}
