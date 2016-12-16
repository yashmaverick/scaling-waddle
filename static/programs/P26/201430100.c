#include<stdio.h>
#include<stdlib.h>
#define size 10005
#define ptotal 1061

typedef struct list
{
	int x;
	struct list *next;
	/* data */
}list;

typedef struct list *link;
int start=0,end=0;
int heap[ptotal];

//			bfs(ans,visit,tree,0);

void bfs(int ans[],int visit[],link tree[],int count)
{
	int p=heap[0];


	int x;
	x=heap[start];
	start++;

	if(x==-1) {  if(start==end) return; heap[end]=-1; end++; bfs(ans,visit,tree,count+1); }
	else
	{	
	//	printf("x:%d count:%d\n",x,count);
		ans[x]=count;
		link temp=tree[x];
		while(temp!=NULL)
		{
			int t=temp->x;
			if(visit[t]==0)
			{
				heap[end]=t;
				end++;
				visit[t]=1;
			}
			temp=temp->next;
		}
		bfs(ans,visit,tree,count);
	}	


}

int main()
{
	int preindex[size],postindex[ptotal],count=0;

	int i;
	for(i=0;i<size;i++) preindex[i]=1;

	preindex[0]=-1;
	preindex[1]=-1;

	for(i=2;i<size;i++)
	{
		if(preindex[i]==1)
		{
			int j;
			for(j=i+i;j<size;j=j+i)
			{
				preindex[j]=-1;
			}
		}
	}

	for(i=1000;i<size;i++)
	{
		if(preindex[i]==1){
		postindex[count]=i;
		preindex[i]=count;
		count++;
		}
	}

//	printf("%d\n",count);

	//for(i=1000;i<=9999;i++) printf("%d\n",preindex[i]);

	link tree[ptotal];

	for(i=0;i<ptotal;i++) { tree[i]=NULL;  }

	for(i=0;i<ptotal;i++)
	{
		int t1,t2,j,m,n;

		m=postindex[i];
		t1=m/10;
		t1=t1*10;

		for(j=0;j<10;j++)
		{	
			int t=t1+j;
			
//			printf("t:%d post:%d i:%d\n",t,postindex[i],i);

			n=preindex[t];

			if(t!=m && n!=(-1))
			{

				link temp;
				temp=malloc(sizeof(list));
				temp->x=n;
				temp->next=tree[i];
				tree[i]=temp;
			}
		}
		
		t2=m%10;
		t1=m/100;
		t1*=100;
		t1+=t2;

		for(j=0;j<10;j++)
		{	
			int t=t1+j*10;
			n=preindex[t];

			if(t!=m && n!=(-1))
			{

				link temp;
				temp=malloc(sizeof(list));
				temp->x=n;
				temp->next=tree[i];
				tree[i]=temp;
			}
		}

		t2=m%100;
		t1=m/1000;
		t1*=1000;
		t1+=t2;


		for(j=0;j<10;j++)
		{	
			int t=t1+j*100;
			n=preindex[t];

			if(t!=m && n!=(-1))
			{


				link temp;
				temp=malloc(sizeof(list));
				temp->x=n;
				temp->next=tree[i];
				tree[i]=temp;
			}
		}

		t1=m%1000;


		for(j=1;j<10;j++)
		{	

			int t=t1+j*1000;

			n=preindex[t];

			if(t!=m && n!=(-1))
			{

				link temp;
				temp=malloc(sizeof(list));
				temp->x=n;
				temp->next=tree[i];
				tree[i]=temp;
			}
		}

	}

	int *ans[ptotal];

	for(i=0;i<ptotal;i++) ans[i]=NULL;

		int zw=preindex[1033];

	int t;
	scanf("%d",&t);


	while(t--)
	{
		int x,y,p,q;
		scanf("%d %d",&x,&y);

		if(x==y) printf("0\n");
		else{

		p=preindex[x];
		q=preindex[y];
	//	printf("%d %d\n",p,q);
		int a1=-1,a2=-1;
		if(ans[p]!=NULL) a1=ans[p][q];
		if(ans[q]!=NULL) a2=ans[q][p];

		if(a1==0) printf("Impossible\n");
		else if(a1>0) printf("%d\n",a1);
		else if(a2==0) printf("Impossible\n");
		else if(a2>0) printf("%d\n",a2);
		else
		{
			int visit[ptotal];
			ans[p]=malloc(sizeof(int)*ptotal);
		
			int z;
			for(z=0;z<ptotal;z++) { visit[z]=0; ans[p][z]=0; }

			heap[0]=p;
			heap[1]=-1;
			start=0;
			end=2;
			visit[p]=1;

			bfs(ans[p],visit,tree,0);
			printf("%d\n",ans[p][q]);
		}
		}
	}

	return 0;
}
