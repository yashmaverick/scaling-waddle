#include<stdio.h>
#include<stdlib.h>
int A[100001],k=1,n,IN[100001]={0};
typedef struct adj{
	int val;
	struct adj* next;
}adj;
adj *B[100001];
void insert(int a,int b)
{
	adj *temp=(adj*)malloc(sizeof(adj));
	temp->val=b;
	temp->next=B[a];
	IN[b]++;
	B[a]=temp;
}
void shuffleup(int p)
{
	int temp;
	if(p>1)
	{
		if(A[p]>=A[p/2])
		{
			return ;
		}
		else
		{
			temp=A[p];
			A[p]=A[p/2];
			A[p/2]=temp;
			p=p/2;
			shuffleup(p);
		}
	}
}
void insertmin(int m)//places elements in array with order
{
	if(k==1)
	{
		A[k]=m;
		k=k+1;
	}
	else
	{
		A[k]=m;
		shuffleup(k);
		k=k+1;
	}
}
int deletemin()//deletes a number and arranges
{
	int i=1,j,ret=A[1];
	A[1]=A[k-1];
	k--;
	while(2*i<=k)
	{
		if(2*i==k)
			j=2*i;
		else if(A[2*i+1]>A[2*i])
			j=2*i;
		else
			j=2*i+1;
		if(A[i]>A[j])
		{
			int t;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
			i=j;
		}
		else
			break;
	}
	//printf("ret=%d ",ret);
	return ret;
}
int main()
{
	int n,m,i,a,b,c,u;
	adj *temp;
	scanf("%d%d",&n,&m);
	for(u=1;u<=n;u++)
	{
		IN[u]=0;
		B[u]=NULL;
	}
	for(u=1;u<=m;u++)
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
	}
	//for(i=1;i<=n;i++)
	//	printf("IN[%d]=%d\n",i,IN[i]);
/*	for(i=1;i<=n;i++)
	{
		printf("i:%d ",i);
		temp=B[i];
		while(temp!=NULL)
		{
			printf("%d-->",temp->val);
			temp=temp->next;
		}
		printf("\n");
	}*/
	//	printf("k=%d\n",k);
	for(u=1;u<=n;u++)
		if(IN[u]==0)
		{
			insertmin(u);
			IN[u]=-1;
		}
	/*for(u=1;u<k;u++)
		printf("A[%d]=%d\n",u,A[u]);*/
	while(k!=1)
	{
		c=deletemin();
		//printf("c=%d k=%d\n",c,k);
		adj *temp=B[c];
		while(temp!=NULL)
		{
			IN[temp->val]--;
			if(IN[temp->val]==0)
			{
				insertmin(temp->val);
				IN[temp->val]=-1;
			}
			temp=temp->next;
		}
		/*for(i=1;i<=n;i++)
		  if(IN[i]==0)
		  {
		  insertmin(i);
		  IN[i]=-1;
		  }*/
		//c=deletemin();
		if(k!=1)
			printf("%d ",c);
		else
			printf("%d\n",c);
	}
	//if(n!=0)
	//	printf("\n");
	return 0;
}
