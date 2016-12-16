#include<stdio.h>
#include<stdlib.h>
struct node
{       long long int visit;
	long long int data;
	struct node *child[10];
};
typedef struct node noddy;
noddy *root=NULL;
noddy *q=NULL;
long long int as=0,a[16],go=0;
void change(long long int e)
{
	if(e==0)
		return;
	change(e/10);
	a[as]=e%10;
	as++;
	return;
}
noddy* create()
{       long long int i;
	noddy *thing;
	thing=(noddy*)malloc(sizeof(noddy));
	//thing=malloc(sizeof(noddy*));
	thing->data=0;
	thing->visit=1;
	for(i=0;i<=9;i++)
	{
		thing->child[i]=NULL;
	}
	return thing;
}
noddy* wow(long long int qw,long long int flag,long long int d)
{

	if(root==NULL)
	{ root=create();
		q=create();
		q=root;}
	
	if(q->child[qw]==NULL)
	{ 	q->child[qw]=create();
                //q->child[qw]->data=d;
		if(flag==0)
			q->child[qw]->data=1;
	}
	else
	{	if((q->child[qw])->data==1)
		      { //printf("yayaya\n");
			      //printf("%lld\n",go);
			      go=1;
      			      return root;}
	   if(d==as-1)
	   {   
		   if(q->visit==1)
	              {go=1;return root;}
	   }
	}
	
	//printf("==%lld==\n",q->child[qw]->data);
	q=q->child[qw];
	return root;
}

int main()
{
	long long int qw,g,t,fl,n,i,k,e;
	scanf("%lld",&t);
        
	for(i=1;i<=t;i++)
	{ root=NULL;go=0;  		
		scanf("%lld",&k);
		for(g=1;g<=k;g++)
		{       
			q=root;
			fl=1;
			as=0;
			scanf("%lld",&e);
			if(e!=0)
			change(e);
			else if(e==0)
			{a[0]=0;as=1;}
			for(qw=0;qw<as;qw++)
			{//printf("==%lld==\n",a[qw]);
				
			     	if(qw==as-1)
				{fl=0;}
				wow(a[qw],fl,qw);
				a[qw]=0;
			//	printf("=%lld=",go);
			}
		//	printf("\n");

		}
		if(go==1)
			printf("NO\n");
		else
			printf("YES\n");
                    

	}
	return 0;
}
