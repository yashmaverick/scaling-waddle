#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int val;
	node *down;
};
node *poi[100001]={NULL};
int min_H[100001],min;
node *insert(node *head,int x)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->val=x;
	tmp->down=head;
	return tmp;
}
void del_min()
{
	if(!min)
		return;
	min_H[1]=min_H[min--];
	long long int i=1,t;
	while(i<=min)
	{
		if(2*i>min)
			break;
		else if(2*i+1>min)
		{
			if(min_H[2*i]<min_H[i])
			{
				t=min_H[2*i];
				min_H[2*i]=min_H[i];
				min_H[i]=t;
				i*=2;
			}
			else 
				break;
		}
		else
		{
			if(min_H[2*i]>min_H[i]&&min_H[2*i+1]>min_H[i])
				break;
			if(min_H[2*i]<min_H[(2*i)+1])
			{
				t=min_H[2*i];
				min_H[2*i]=min_H[i];
				min_H[i]=t;
				i*=2;
			}
			else
			{
				t=min_H[(2*i)+1];
				min_H[(2*i)+1]=min_H[i];
				min_H[i]=t;
				i=(i*2)+1;
			}
		}
	}
	return;
}
void ins_min(long long int x)
{
	long long int i,t;
	min++;
	i=min;
	min_H[i]=x;
	while(i!=1 && min_H[i/2]>min_H[i])
	{
		t=min_H[i];
		min_H[i]=min_H[i/2];
		min_H[i/2]=t;
		i=i/2;
	}
	return;
}
int main()
{
	int n,m,i,a,b,j,k;
	scanf("%d%d",&n,&m);
	int par[100001]={0};
	int ans[100001];
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		poi[a]=insert(poi[a],b);
		par[b]++;
	}
	min=0;
	for(i=1;i<=n;i++)
	{
		if(!par[i])
			ins_min(i);
	}
	k=0;
	while(min)
	{
		while(min)
		{
			ans[k++]=min_H[1];
			node *tmp;
			tmp=poi[min_H[1]];
			del_min();
			while(tmp)
			{
				par[tmp->val]--;
				if(par[tmp->val]==0)
					ins_min(tmp->val);
				tmp=tmp->down;
			}
		}
	}
	for(i=0;i<k-1;i++)
		printf("%d ",ans[i]);
	printf("%d",ans[i]);
	printf("\n");
	return 0;
}
