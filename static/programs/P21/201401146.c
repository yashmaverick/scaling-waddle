#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
struct node
{
	int val;
	int w;
	node *next;
};
node *poi[100001];
int a[100001],n,b[100001];
int vis[100001],dis[100001];
void reset(int v)
{
	int i;
	for(i=0;i<=v;i++)
	{
		poi[i]=NULL;
		vis[i]=0;
		dis[i]=1000000009;
	}	
	n=0;
	return;
}
void insert(int x,int val)
{
    a[++n]=x;
    b[n]=val;
    int t,i=n,tmp;
    while(a[i/2]>a[i] && i!=1)
    {
        t=a[i];
        a[i]=a[i/2];
        a[i/2]=t;
	tmp=b[i];
	b[i]=b[i/2];
	b[i/2]=tmp;
        i=i/2;
    }
    return;
}
void del()
{
    int t;
    a[1]=a[n];
    b[1]=b[n];
    int i=1,tmp;
    while((a[2*i]<a[i] || a[(2*i)+1]<a[i]) && (2*i+1)<=n)
    {
        if(a[2*i]<a[i] && a[2*i]<a[(2*i)+1])
        {
            t=a[(2*i)];
            a[(2*i)]=a[i];
            a[i]=t;
            tmp=b[(2*i)];
            b[(2*i)]=b[i];
            b[i]=tmp;
            i*=2;
        }
        else
        {
            t=a[(2*i)+1];
            a[(2*i)+1]=a[i];
            a[i]=t;
            tmp=b[(2*i)+1];
            b[(2*i)+1]=b[i];
            b[i]=tmp;
            i=(2*i)+1;
        }
    }
    n--;
}
node *insertLL(node *head,int v,int w)
{
	if(!head)
	{
		node *tmp;
		tmp=(node*)malloc(sizeof(node));
		tmp->val=v;
		tmp->w=w;
		return tmp;
	}
	else
		head->next=insertLL(head->next,v,w);
	return head;
}
void print(int v)
{
	node *tmp;
	int i;
	for(i=1;i<=v;i++)
	{
		tmp=poi[i];
		while(tmp)
		{
			printf("A=%d val=%d w=%d\n",i,tmp->val,tmp->w);
			tmp=tmp->next;
		}
	}
	return;
}
void dijk(int A,int v)
{
	int s,i,min;
	node *tmp;
	insert(dis[A],A);
	while(n)
	{
		if(!vis[b[1]])
		{
			min=a[1];
			s=b[1];
			del();
			vis[s]=1;
			tmp=poi[s];
			while(tmp)
			{
				if((min+tmp->w) < dis[tmp->val])
				{
					dis[tmp->val]=min+tmp->w;
					insert(dis[tmp->val],tmp->val);
				}
				tmp=tmp->next;
			}
		}
		else
			del();
	}
}
int main()
{
	int i,a,b,c,A,B,j,k,v;
	scanf("%d%d",&v,&k);
	reset(v);
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		poi[a]=insertLL(poi[a],b,c);
	}
	//print(v);
	scanf("%d%d",&A,&B);
	dis[A]=0;
	dijk(A,v);
	//for(i=1;i<=v;i++)
	//	printf("%d ",dis[i]);
	//printf("\n");
	if(dis[B]==1000000009)
		printf("NO\n");
	else
		printf("%d\n",dis[B]);
	return 0;
}
