#include<stdio.h>
#include<stdlib.h>
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
int main()
{
	int i,j;
	int isprime[10007]={0};
	int vis[1200]={0};
	for(i=2;i<10007;i++)
	{
		if(isprime[i]==0)
		{
			for(j=2*i;j<10007;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
	isprime[0]=1;
	isprime[1]=1;

	j=0;
	int primnum[1200];
	int primback[10007];
	list* alst[1200];
	for(i=1000;i<10001;i++)
	{
		if(isprime[i]==0)
		{	primnum[j]=i;
			primback[i]=j;
			j++;
		}
	}
	int countprime=j;
//	printf("%d\n",countprime);
	for(i=0;i<countprime;i++)
		alst[i]=NULL;
	for(i=0;i<countprime;i++)
	{
		for(j=i+1;j<countprime;j++)
		{
			int pr1=primnum[i];
			int pr2=primnum[j];
			int cnt=0;
			while(pr1!=0&&pr2!=0)
			{
				if(pr1%10==pr2%10)
					cnt++;
				pr1=pr1/10;
				pr2=pr2/10;
			}
			if(cnt==3)
			{
				list* tmp;
				tmp=(list*)malloc(sizeof(list));
				tmp->value=j;
				tmp->next=alst[i];
				alst[i]=tmp;
				list* tm;
				tm=(list*)malloc(sizeof(list));
				tm->value=i;
				tm->next=alst[j];
				alst[j]=tm;
			}
			
		}
	}
	int test;
	int queue[10000];
	int dist[10000];
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<1100;i++)
			vis[i]=0;
		int p1,p2;
		scanf("%d %d",&p1,&p2);
		int pb1,pb2;
		pb1=primback[p1];
		pb2=primback[p2];
	//	printf("%d %d\n",pb1,pb2);
		queue[0]=pb1;
		int start=0;
		int end=0;
		dist[pb1]=0;
		vis[pb1]=1;
		while(start<=end)
		{
			int u=queue[start];
			start++;
			list* it=alst[u];
			while(it!=NULL)
			{
				int v=it->value;
				if(vis[v]==0)
				{
				//	printf("%d ",v);
					vis[v]=1;
					end++;
					queue[end]=v;
					dist[v]=dist[u]+1;
				}
				it=it->next;
			}

		}
		printf("%d\n",dist[pb2]);
		
	}
	return 0;
}
