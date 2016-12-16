#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int x;
	int y;
	int w;
}node;

node arr[1000007];
int s[100000];
int n;

int cmp(const void *p,const void *q)
{
	int l=((node *)p)->w;
	int r = ((node *)q)->w;
	return l-r;
}

void setunion(int x,int y)
{
	if(s[y]<s[x])
		s[x]=y;
	else
	{
		if(s[x]==s[y])
			s[x]=s[x]-1;
		s[y]=x;
	}
}

int find(int x)
{
	if(s[x]<=0)
		return x;
	else
	{
		s[x]=find(s[x]);
		return s[x];
	}

}


int main()
{
	int m,x,y,w,i,j,sum,count,vis[1000000]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].w);

	qsort(arr,m,sizeof(node),cmp);
	for(i=1;i<=n;i++)
		s[i]=0;
	sum=0;
	count=0;
//	for(i=0;i<m;i++)
//			printf("x %d y %d w %d\n",arr[i].x,arr[i].y,arr[i].w);
	for(i=0;i<m;i++)
	{
//		for(j=1;j<=n;j++)
//			printf("j %d s %d\n",j,s[j]);
//			printf("x %d y %d f[x] %d f[y] %d\n",arr[i].x,arr[i].y,find(arr[i].x),find(arr[i].y));
		if(find(arr[i].x)!=find(arr[i].y))
		{
			setunion(find(arr[i].x),find(arr[i].y));
//	printf("x %d y %d w %d c %d\n",arr[i].x,arr[i].y,arr[i].w,count);
			sum+=arr[i].w;
			count++;
	
		if(count==n-1)
			break;
		}
	}
	if(count==n-1)
	printf("%d\n",sum);
	else
		printf("-1\n");
return 0;
}
