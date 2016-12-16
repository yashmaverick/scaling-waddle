#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;

}node;
node *a[100003];
int num[100003],size=0,min[100003];
void insert(int x,int y)
{
	node *new;
	new=malloc(sizeof(node));
	new->val=y;
	new->next=a[x];
	a[x]=new;
	num[y]++;
}
void insertmin(int x)
{
	size++;
	int r=size,temp;
	if(size==1)
		min[size]=x;
	else
	{
		min[r]=x;
		while(r>1)
		{
			if(min[r]<min[r/2])
			{
				temp=min[r/2];
				min[r/2]=min[r];
				min[r]=temp;
				r=r/2;
			}
			else
				break;
		}
	}
}
int removemin()
{
	int o=min[1];
	min[1]=min[size];
	size--;
	int p=1,temp;
	while(p<=size/2)
	{
		if(2*p==size)
		{
			if(min[2*p]<min[p])
			{
				temp=min[p];
				min[p]=min[2*p];
				min[2*p]=temp;
				p=2*p;
			}
			return o;
		}
		else if((size>=2*p+1)&&min[2*p]<min[p]||min[2*p+1]<min[p])
		{
			if(min[2*p+1]<min[2*p])
			{
				temp=min[p];
				min[p]=min[2*p+1];
				min[2*p+1]=temp;
				p=2*p+1;
			}
			else
			{
				temp=min[p];
				min[p]=min[2*p];
				min[2*p]=temp;
				p=2*p;
			}
		}
		else
			break;
	}
	return o;
}
int main()
{
	int n,m,x,y,i,j,k,t,ans[1000001];
	k=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<=100002;i++){
		a[i]=NULL;
		num[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(i=1;i<=n;i++)
	{
		if(num[i]==0)
		{
			insertmin(i);
		}
	}
	/*for(i=1;i<=size;i++)
		printf("%d ",min[i]);
	printf("\n");
	*/
	while(size!=0)
	{
		t=removemin();
		//printf("deleting %d\n",t);
		ans[k]=t;
		k++;
		node *tmp;
		tmp=a[t];
		while(tmp!=NULL)
		{
			num[tmp->val]--;
			if(num[tmp->val]==0)
			{
				//printf("inserting %d \n",tmp->val);
				insertmin(tmp->val);
				//for(i=1;i<=size;i++)
				//	printf("%d ",min[i]);
				//printf("\n");
			}
			tmp=tmp->next;
		}
	}
	for(j=0;j<k;j++)
	{
		if(j==k-1)
			printf("%d\n",ans[j]);
		else
			printf("%d ",ans[j]);
	}
	return 0;
}
