#include<stdlib.h>
#include<stdio.h>

long long int ans,me;
typedef struct ll{
	int val;
	struct ll * next;
}ll;

ll * arr[1000008];
int v[1000008];

void add(int t,int d)
{
	ll * temp;
	temp=(ll *)malloc(sizeof(ll));
	temp->val=d;
	temp->next=arr[t];
	arr[t]=temp;
}

void dfs(int e,int h,int max)
{
	ll * temp=arr[e];

	if(v[e]==0)
	{
		v[e]=1;
		h++;
		if(h>max)
		{
			me=e;
			max=h;
		}
		while(temp!=NULL)
		{
			dfs(temp->val,0,0);
			temp=temp->next;
		}
	}
}

void dfs2(int e,int h)
{
	ll * temp=arr[e];
	if(v[e]==0)
	{
		v[e]=1;
		h++;
//		printf("e %d a %d\n",e,h);
		if(h>ans)
			ans=h;
		while(temp!=NULL)
		{
			dfs2(temp->val,h);
			temp=temp->next;
		}
	}
}

int main()
{
	int t,n,n1,n2,i,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		me =0;
		if(n==1)
			printf("1\n");
		else
		{
		for(i=1;i<=n;i++)
			v[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&n1,&n2);
			add(n1,n2);
			add(n2,n1);
		}
		for(i=1;i<=n;i++)
		{
			if(arr[i]!=NULL)
			{
				dfs(i,0,0);
		for(k=1;k<=n;k++)
			v[k]=0;
				dfs2(me,0);
				break;
			}
		}
		int j;
		for(j=0;j<=1000000;j++)
			arr[j]=NULL;
		printf("%lld\n",ans);
		}
	}
	return 0;
}
