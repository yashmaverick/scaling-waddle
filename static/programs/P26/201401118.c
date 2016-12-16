#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct ll
{
	struct ll *next;
	int val;
	int weight;
}list;
int b[4],c[4],que[10000],front=0,end=0;
list *s[10000];
void tod(int t[],int k)
{
	int a,b,c,d;
	d=k%10;
	c=(k/10)%10;
	b=(k/100)%10;
	a=k/1000;
	t[0]=a;
	t[1]=b;
	t[2]=c;
	t[3]=d;
	return;
}
int jod(int t[])
{
	int a,b,c,d;
	a=t[0]*1000;
	b=t[1]*100;
	c=t[2]*10;
	d=t[3];
	return (a+b+c+d);
}
void insert(int i, int j)
{
	list *ins;
	ins=(list *)malloc(sizeof(list));
	ins->val=j;
	ins->weight=0;
	ins->next=s[i]->next;
	s[i]->next=ins;
	return;
}
int main()
{
	int a[10000],i,j,l,m,n;
	for(i=0;i<10000;i++)
		a[i]=1;
	for(i=2;i<=sqrt(9999);i++)
	{
		for(j=2;j<=9999/i;j++)
		{
			a[i*j]=0;
		}
	}
/*	for(i=1000;i<=9999;i++)
	{
		if(a[i]==1)
			printf("%d ",i);
	}
	printf("\n");*/
	for(i=1000;i<=9999;i++)
	{
		s[i]=(list *)malloc(sizeof(list));
		s[i]->val=i;
		s[i]->weight=-1;
		s[i]->next=NULL;
	}
	for(i=1000;i<=9999;i++)
	{
		if(a[i]==1)
		{
			tod(b,i);
			for(j=0;j<4;j++)
			{
				m=0;
				if(j==0)
					m++;
				n=b[j];
				while(m<=9)
				{
					b[j]=m;
					l=jod(b);
					if(a[l]==1 && l!=i)
						insert(i,l);
					m++;
				}
				b[j]=n;
			}
		}
	}
	list *temp;
/*	for(i=1000;i<=9999;i++)
	{
		if(a[i]==1)
		{
			temp=s[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->val);
				temp=temp->next;
			}
			printf("\n");
		}
	}*/
	int t,f,d,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&f,&d);
		s[f]->weight=0;
		que[end]=f;
		k=f;
		while(que[end]!=d)
		{
			temp=s[k];
			temp=temp->next;
			while(temp!=NULL)
			{
				if(s[temp->val]->weight==-1)
				{
					s[temp->val]->weight=s[k]->weight+1;
					end++;
					que[end]=temp->val;
				}			
				if(temp->val==d)
					break;
				temp=temp->next;	
			}
			front++;
			k=que[front];
		}
		printf("%d\n",s[d]->weight);
		front=0;
		end=0;
		for(i=1000;i<=9999;i++)
			s[i]->weight=-1;
	}
	return 0;
}
