#include<stdio.h>
#include<stdlib.h>
struct bag{
	int sum;
	int size;
	int * b;
};
typedef struct bag bag;
typedef bag* bg;
void qs(bg bags,int i,int j);
int partition(bg bags,int i,int j);
int main()
{
	int N,i,j,m,id;
	int mod,wt;
	scanf("%d %d",&N,&mod);
	bg bags;
	bags=(bg)malloc(N*sizeof(bag));
	for(i=0;i<N;i++)
	{
		id=0;
		bags[i].sum=0;
		scanf("%d",&m);
		bags[i].size=m;
		bags[i].b=(int *)malloc(m*sizeof(int));
		for(j=0;j<m;j++)
		{
			scanf("%d",&wt);
			bags[i].sum=(bags[i].sum+wt)%mod;
			*(bags[i].b+id)=wt;
			id++;
		}
	}
	qs(bags,0,N-1);
	for(i=0;i<N;i++)
	{
		printf("%d\n",bags[i].sum);
		for(j=0;j<bags[i].size;j++)
		{
			printf("%d\n",*(bags[i].b));
			(bags[i].b)++;
		}
		printf("\n");
	}
	return 0;
}
void qs(bg bags,int i,int j)
{
	int z;
	if(i>=j)
	{
		return;
	}
	else
	{
		//printf("%d",i);
		//mid=(i+j)/2;
		z=partition(bags,i,j);
		qs(bags,i,z-1);
		qs(bags,z+1,j);
	}
}
int partition(bg bags,int i,int j)
{
	int pivot,s,e,temp,p,si;
	int* te;
	//printf("%d\n",i);
	pivot=bags[i].sum;
	e=j;
	for(p=i+1;p<=e;p++)
	{
		//printf("i=%d e=%d\n",i,e);
		if(bags[p].sum>=pivot)
		{
			temp=bags[e].sum;te=bags[e].b;si=bags[e].size;
			bags[e].sum=bags[p].sum;bags[e].b=bags[p].b;
			bags[e].size=bags[p].size;
			bags[p].sum=temp;bags[p].b=te;bags[p].size=si;
			e--;
			p--;
		}
	}
	temp=bags[e].sum;si=bags[e].size;te=bags[e].b;
	bags[e].sum=bags[i].sum;bags[e].size=bags[i].size;bags[e].b=bags[i].b;
	bags[i].sum=temp;bags[i].size=si;bags[i].b=te;
	return e;
}








