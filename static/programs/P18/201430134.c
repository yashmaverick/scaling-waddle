#include<stdio.h>
#include<stdlib.h>
typedef struct l{
	int data;
	struct l* nxt;
}link;
typedef link* list;
int f1,f2;
void adjins(int s,int w,list ar[])
{
	list temp;
	temp=(list)malloc(sizeof(link));
	temp->data=w;
	temp->nxt=ar[s];
	ar[s]=temp;
}
/*void pri(list ar[],int n)
{
	int i;
	list te;
	for(i=1;i<=n;i++)
	{
		te=ar[i];
		while(te!=NULL)
		{
			printf("%d ",te->data);
			te=te->nxt;
		}
		printf("\n");
	}
}*/
void f(list p,int i,list ar[],int b[],int c[])
{
	//b[i]=1;
	//int temp;
	if(p==NULL)
	{
		return;
	}
	/*else if(p==NULL && no==0)
	{
		return 1;
	}*/
	else
	{
		while(p!=NULL)
		{
			if(b[p->data]==0 && p->data!=i)
			{
				/*if(c[p->data]==1)
				{
					f2=1;
					return;
				}*/
				b[p->data]=1;
				f(ar[p->data],i,ar,b,c);
				/*if(f2==1)
				{
					return;
				}*/
				p=p->nxt;
			}
			else
			{
				p=p->nxt;
			}
		}
		return;
	}
}
int main()
{
	int t,n,i,j,m,cnt,s;
	list ar[1005];int kha[1005];int k,l;
	int b[1005];int c[1005];
	scanf("%d",&t);
	while(t>0)
	{
		for(i=0;i<1005;i++)
		{
			c[i]=0;
		}
		cnt=0;f1=0;f2=0;
		for(i=0;i<1005;i++)
		{
			ar[i]=NULL;
		}
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&s);
				adjins(s,i,ar);
			}
		}
		//pri(ar,n);
		for(i=1;i<=n;i++)
		{
			f1=0;f2=0;
			for(j=1;j<=n;j++)
			{
				b[j]=0;
			}
			f(ar[i],i,ar,b,c);
			/*if(f2==1)
			{
			//	printf("oooo\n");
				cnt++;
			}*/
			for(j=1;j<=n;j++)
			{
				if(b[j]==0 && j!=i)
				{
					f1=1;
					break;
				}
			}
			if(f1==0)
			{
				//printf("%d\n",i);
				c[i]=1;
				cnt++;break;
			}
		}
		kha[0]=i;kha[1]=-1;k=0;l=0;
		while(kha[k]!=-1){
		for(j=i+1;j<=n;j++)
		{
			list ter;
			ter=ar[j];
			if(c[j]==0){
			while(ter!=NULL)
			{
				if(ter->data==kha[k])
				{
					l++;
					cnt++;
					//printf("%d\n",j);
					c[j]=1;
					kha[l]=j;
					kha[l+1]=-1;
					break;
				}
				else
				{
					ter=ter->nxt;
				}
			}
			}
		}
		k++;
		}
		printf("%d\n",cnt);
		t--;
	}
	return 0;
}

