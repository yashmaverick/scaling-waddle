#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	struct ll *next;
	int data;
}node;

node *b[100005];
int dep[100005];
int i, htop, a[500000];

node *inser(int c, int d)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->data=d;
	tmp->next=b[c];
	b[c]=tmp;
	return b[c];
}

void shuffleup(int i)
{
	int tmp;
	if(i!=0)
	{
		if(a[i]<a[i/2])
		{
			tmp=a[i];
			a[i]=a[i/2];
			a[i/2]=tmp;

			shuffleup(i/2);
		}
	}
}

void insert(int x)
{
	i++;
	a[i]=x;
	shuffleup(i);
}

void shuffledown(int j)
{
	int temp;
	if(a[2*j]!=-1 && a[2*j+1]!=-1)
	{
		if(a[2*j]<a[j]  || a[2*j+1] < a[j])
		{
			if(a[2*j] < a[2*j+1])
			{
				temp=a[2*j];
				a[2*j]=a[j];
				a[j]=temp;
				shuffledown(2*j);
			}
			else
			{
				temp=a[2*j+1];
				a[2*j+1]=a[j];
				a[j]=temp;
				shuffledown(2*j+1);
			}
		}
	}
	else if(a[2*j]!=-1 && a[2*j+1]==-1)
	{
		if(a[2*j] < a[j])
		{
			temp=a[2*j];
			a[2*j]=a[j];
			a[j]=temp;
		}
	}
}

void deletemin()
{
	htop=a[1];
	a[1]=a[i];
	a[i]=-1;
	i--;
	shuffledown(1);
}

void display()
{
	int k;
	for(k=1;k<=i;k++)
	{
		printf("i %d val %d\n",k,a[k]);
	}
}

int main()
{
	for(i=0;i<500000;i++)
		a[i]=-1;
	i=0;
	
	int n,m,x,y,q,i,j,count=0;
	scanf("%d %d",&n,&m);
	for(q=0;q<=n;q++)
	{
		b[q]=NULL;
		dep[q]=0;
	}
	for(q=1;q<=m;q++)
	{
		scanf("%d %d",&x,&y);
		dep[y]++;
		b[x]=inser(x,y);
	}
	for(q=1;q<=n;q++)
	{
		if(dep[q]==0)
			insert(q);
	}
//	display();
	while(a[1]!=-1)
	{
		deletemin();
		printf("%d",htop);
		count++;
		if(count!=n)
			printf(" ");
		while(b[htop]!=NULL)
		{
			dep[b[htop]->data]--;
			if(dep[b[htop]->data] == 0)
				insert(b[htop]->data);

			b[htop]=b[htop]->next;
		}
	}
	printf("\n");
	return 0;
}
