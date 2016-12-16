#include<stdio.h>
#include<stdlib.h>
typedef struct ll{
	int val;
	struct ll* next;
}ll;

ll *arr[10000];
ll *arr2[10000];

int s;
int ans;
int v[10000];
int v2[10000];
int c;
int nr;

void dfsrev(int a)
{
//	printf("rev %d\n",a);
	ll *temp=arr2[a];
		if(v2[a]==0)
		{
			v2[a]=1;
//			ans++;
	//		printf("v 2 %d\n",temp->val);
//			v2[temp->val]=1;
			while(temp!=NULL)
			{

				dfsrev(temp->val);
				temp=temp->next;
			}
		}
	
}


void dfs(int a)
{
	ll * temp=arr[a];
	int i;
		if(v[a]==0)
		{
//			printf("v 1 %d\n",a);
			v[a]=1;
//			printf("c %d\n",c);
//			printf("c %d\n",c);
			c++;
//			printf("c %d\n",c);
			while(temp!=NULL)
			{
				dfs(temp->val);
				temp=temp->next;
			}
		}
	
}

void find()
{
	int i,k;
	c=0;
	for(i=1;i<=nr;i++)
		v[i]=0;
	for(i=1;i<=nr;i++)
	//	if(v[i]==0)
		{
			c=0;
			for(k=1;k<=nr;k++)
				v[k]=0;
			s=i;
			dfs(s);
//			printf("s %d c %d\n",s,c);
			if(c==nr)
			{
//			printf("found\n");
				ans=0;
				for(i=1;i<=nr;i++)
					v2[i]=0;
//				printf("s %d\n",s);
				if(s<=nr)
				dfsrev(s);
				break;
			}
		}
}



void add(int t,int d,int f)
{
	if(f)
	{
	ll * temp;
	temp=(ll *)malloc(sizeof(ll));
	
	temp->val=d;
	temp->next=arr[t];
	arr[t]=temp;
	}
	else
	{
	ll * temp;
	temp=(ll *)malloc(sizeof(ll));
		temp->val=t;
		temp->next=arr2[d];
		arr2[d]=temp;
	}

}
	int main()
	{
		int t,n,node,i;
		scanf("%d",&t);
		while(t--)
		{
			ans=0;
			scanf("%d",&nr);
			for(i=1;i<=nr;i++)
			{
				scanf("%d",&n);
				while(n--)
				{
					scanf("%d",&node);
					add(node,i,0);
					add(node,i,1);
				}
				
			}
			int k;
/*			for(k=1;k<=nr;k++)
			{
				ll * temp=arr[k];
				ll * temp2=arr2[k];
				while(temp!=NULL)
				{
					printf("ar1 %d ",temp->val);
					temp=temp->next;
				}
				printf("\n");
				while(temp2!=NULL)
				{
					printf("ar2 %d ",temp2->val);
					temp2=temp2->next;
				}
				printf("\n");
			}*/
			find();
			ans=0;
			for(k=1;k<=nr;k++)
				ans += v2[k];
			printf("%d\n",ans);
			for(k=0;k<10000;k++)
			{
				
				arr[k]=NULL;
				arr2[k]=NULL;
			}


		}



		return 0;
	}
