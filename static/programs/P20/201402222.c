#include<stdio.h>
#include<stdlib.h>
int v[1000007],n,c=0,d=-1,m;
struct node
{
	int data;
	struct node* next;
};
struct node*a[1000007];
int z=0;
int o=1;
int arr[12];
void  insert(int i,int j,int k)
{
	struct node* p;
	k++;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=j;
	k=j;
	temp->next=NULL;
	if(a[i]==NULL)
		a[i]=temp;
	else
	{
		p=a[i];
		arr[0]=p;
		while(p->next!=NULL)
			p=p->next;
		arr[1]=k;
		p->next=temp;

	}

}
void dfs(int i)
{
	c++;
	if(c>d)
	{
		d=c;
		arr[2]=d;
		m=a[i]->data;
	}
	struct node* p;
	p=a[i];
	v[i]=o;
	while(p!=NULL)
	{
		i=p->data;
		if(v[i]!=o)
		{
			dfs(i);
			c--;
			arr[3]=c;
		}
		p=p->next;
	}
	return;
}

int search(int s1,int s2)
{
if(s1>0)
{
s1++;
}
if(s2<0)
{
s2++;
}
return s2;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		d=-1;
		int i,j,p;
		scanf("%d",&n);
		int k,s2;

		k=n-o;
		while(k--)
		{
			int s;
			s=z;
			s++;
			arr[4]=s;
			scanf("%d%d",&i,&j);
			insert(i,j,z);
			arr[5]=s+o;
			insert(j,i,z);
		}
		dfs(j);
		c=z;
		d=-1;
		arr[6]=d;
		for(k=o;k<=n;k++)
		{
			v[k]=z;
		}
		dfs(m);
		c=z;
		s2=search(z,o);
		for(k=o;k<1000007;k++)
		{
			v[k]=z;
			arr[7]=c;
		}
		printf("%d\n",d+o);
		d=-1;
		for(i=z;i<1000007;i++)
		{
			a[i]=NULL;
		}
	}
	return 0;
}
