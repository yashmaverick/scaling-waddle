//GABBAR STUDIOWORKS
//DS lab
#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int w;
	int src;
	int dst;
}node;
int arr[1000001];
int *rank;
int size[1000001];
int find(int x)
{
	//	while(arr[x]!=x)
	//	{ 
	// arr[x]=arr[arr[x]];
	//	if(arr[x]!=x)
	//	{
	if(arr[x]==x)
		return x;
	arr[x]=find(arr[x]);
	return arr[x];
}
int check(int x,int y)
{
	int par1=find(x);
	int par2=find(y);
	if(par1==par2)
		return 1;
	else
		return 0;
}
void merge(int x,int y)
{
	//x=find(y);
	//return;
	int p1=find(x);
	int p2=find(y);
	if(size[p1]>=size[p2])
	{
		arr[p2]=p1;
		size[p1]=size[p1]+size[p2];

	}
	else if(size[p2]>size[p1])
	{
		arr[p1]=p2;
		size[p2]=size[p2]+size[p1];
	}
}
int cmp(const void*a,const void*b)
{
	int p = ((node *)a)->w;
	int q = ((node *)b)->w;
	return p-q;
}
node brr[1000001];
int main()
{
	int n,m,i;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<1000001;i++)
	{
		size[i]=1;
		arr[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&brr[i].src);
		scanf("%d",&brr[i].dst);
		scanf("%d",&brr[i].w);
	}
	qsort(brr,m,sizeof(node),cmp);
	int answer=0;
	int count=0;
	for(i=0;i<m;i++)
	{
		int e=check(brr[i].src,brr[i].dst);
		if(count==n-1)
			break;
		if(e==1)
			continue;
		else
		{
			merge(brr[i].src,brr[i].dst);
			answer=answer+brr[i].w;
			count++;
		}
	}

	//if(answer!=0 && i<m)
	if(count==n-1)
	printf("%d\n",answer);	
	else
		printf("-1\n");
/*	for(i=0;i<m;i++)
	  {
	  printf("%d-",brr[i].w);
	  printf("%d-",brr[i].src);
	  printf("%d\n",brr[i].dst);
	  printf("%d\n",arr[i]);
	  }
	*/
//	for(i=0;i<10;i++)
//		printf("%d--",arr[i]);
	return 0;
}
