#include<stdio.h>
#include<stdlib.h>
//typedef long long int llu
typedef struct node1
{
long long int u;
long long int v;
long long int w;

}node1;
typedef struct node
{long long int val;
//int length;
struct node* next;
}node;
int cmpfunc (const void * a, const void * b)
{
	  
       	
        long long int l=((node1*)a)->w; 
        long long int r=((node1*)b)->w;	
	return (l-r);
}
node1 a[100010];
int main()
{  // node1 a[100010];
	long long int c[100010];
	node* b[100010];
	long long int l[100010];
//long long int state[100010];
	long long int i,n,m,j;
//for(i=1;i<100010;i++)
//		state[i]=0;
	scanf("%lld%lld",&n,&m);
	a[0].u=0;
	a[0].v=0;
	a[0].w=-1;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&(a[i].u),&(a[i].v),&(a[i].w));
	}
	qsort(a,m+1,sizeof(node1),cmpfunc);
	for(i=1;i<=n;i++)
	{
		c[i]=i;
		b[i]=(node*)malloc(sizeof(node));
		b[i]->val=i;
		//b[i]->length=1;
		b[i]->next=NULL;
		l[i]=1;
	
	}
	for(i=1;i<=n;i++)
 	{  node* tmp=(node*)malloc(sizeof(node));
		tmp->val=i;
		tmp->next=NULL;
		if(b[i]->next==NULL)
		{b[i]->next=(node*)malloc(sizeof(node));
		b[i]->next=tmp;
		}
		
         }
	long long int sum=0;
	for(i=1;i<=m;i++)
	{      if(c[a[i].u]!=c[a[i].v])
		{if(l[c[a[i].u]]<=l[c[a[i].v]])
			{
				node* tmp7=(node*)malloc(sizeof(node));
				tmp7=b[c[a[i].u]]->next;
				node* tmp9=(node*)malloc(sizeof(node));
				tmp9=b[c[a[i].u]];
				//printf("c[]%d\n",c[a[i].u]);
				//printf("b[]%d\n",b[c[a[i].u]]->next->val);
				long long int y5=l[c[a[i].u]];
				l[c[a[i].u]]=0;
				while(tmp9->next!=NULL)
				{
				//	printf("merging vertex%d\n",tmp9->next->val);
					c[tmp9->next->val]=c[a[i].v];
				//	printf("c[merging vertex]%d\n",c[tmp9->next->val]);
					tmp9=tmp9->next;
				
				}
				//printf("fuck\n");
				node* tmp11=(node*)malloc(sizeof(node));
				tmp11=b[c[a[i].v]]->next;
				b[c[a[i].v]]->next=tmp7;
				tmp9->next=(node*)malloc(sizeof(node));
				tmp9->next=tmp11;
				//b[c[a[i].u]]->next=NULL;
				l[c[a[i].v]]=l[c[a[i].v]]+y5;
			}
			else
				if(l[c[a[i].u]]>l[c[a[i].v]])
				{
				node* tmp7=(node*)malloc(sizeof(node));
				tmp7=b[c[a[i].v]]->next;
				node* tmp9=(node*)malloc(sizeof(node));
				tmp9=b[c[a[i].v]];
			long long int y6=l[c[a[i].v]];
				l[c[a[i].v]]=0;
			//	b[c[a[i].v]]->next=NULL;
				while(tmp9->next!=NULL)
				{
					c[tmp9->next->val]=c[a[i].u];
					tmp9=tmp9->next;
				
				}
				node* tmp11=(node*)malloc(sizeof(node));
				tmp11=b[c[a[i].u]]->next;
				b[c[a[i].u]]->next=tmp7;
				tmp9->next=(node*)malloc(sizeof(node));
				tmp9->next=tmp11;
	                                l[c[a[i].u]]=l[c[a[i].u]]+y6;
				}
                             sum=sum+(a[i].w);
		}
	}
	long long int flag=0;
	for(i=1;i<=n;i++)
	{
		if(l[i]==n)
		{	printf("%lld\n",sum);
			flag=1;
		break;
		}
	
	}
	if(flag==0)
	printf("-1\n");
return 0;
}
