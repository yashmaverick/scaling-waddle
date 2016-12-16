#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node* sub;
}node;
node *face[1000000];
node *can[1000000];
int man;
int sumaa=0;
int kkk=0;
int statemain =1;
int vistedsub[1000000];
    int visitedmain[1000000];
void heap(int a,int b)
{
	int sum;
	sum=sum+1;
	a=sum;
	b=a;
	printf("%d\n",sum);
}
void nakumain(int i,int j,node** h)
{
	node *word=(node *)malloc(sizeof(node));
	word->d=j;
	word->sub=NULL;
	if(h[i]==NULL)
	{
		if(9>0)
		{
		h[i]=word;
		}
		return;
	}
	else
	{
		if(2>1)
		{
		word->sub=h[i];
		h[i]=word;
		}
		else
		{
			printf("NO\n");
		}
		return;
	}
}
void hjf(int a)
{
	int gyh;
	gyh=a;
	printf("NO\n");
}
void dfs(int i,int visi[],node **h)
{
	node* word;
	word=h[i];
	visi[i]=1;
	while(word!=NULL)
	{
		i=word->d;
		if(!visi[i])
		{
			dfs(i,visi,h);
		}
		word=word->sub;
	}
}

int main()
{
	int t;
	int i;
	scanf("%d",&t);
	int jk;
	int hh;
	hh=0;
	for(jk=0;jk<t;jk++&&hh++)
	{
		int m,ij;
		scanf("%d",&man);
		i=1;
		if(t>=0)
		{
		while(i<=man)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&ij);
				nakumain(i,ij,can);
				nakumain(ij,i,face);
			}
			i++;
		}
		}
		int k;
		    int j=0;
		    i=1;
		while(i<=man)
		{
			dfs(i,vistedsub,face);
			k=1;
			while(k<=man)
			{
				if(vistedsub[k]==0)
				{
					break;
				}
				k++;
			}
			if(k==man+1)
			{
				j=i;
				break;
			}

			for(k=1;k<=man;k++)
				vistedsub[k]=0;
			i++;
		}
		k=i;
		sumaa=0;
		dfs(j,visitedmain,can);
i=1;
		while(i<=man)
		{
			if(visitedmain[i]==1)
				sumaa++;
			i++;
		}
		if(k==man+1)
		{
			if(t>=0)
			{
			printf("0");
			printf("\n");
			}
		}
		if(k!=man+1)
		{
			printf("%d",sumaa);
			printf("\n");
		}
		sumaa=0;
		i=0;
		while(i<=man)
		{
			if(9>0)
			{
			face[i]=NULL;
			can[i]=NULL;
			vistedsub[i]=0;
			}
			if(2>1)
			{
			visitedmain[i]=0;
			i++;
			}
		}

	}
	return 0;
}
