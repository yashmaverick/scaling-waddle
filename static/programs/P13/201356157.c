#include<stdio.h>
#include<stdlib.h>
int array2[100000],array1[100000];;
int l, r, i;

struct stack{
	struct stack* p;
	int num;
	int numb;
	int min;
}banana;
long long got=-1,ans;
void godown(int l,int r,int i,int array1[100000])
{
	int p,s;
	int numb;
	numb=i;
	if(l<0 || l>r)
		return;
	if(l!=r)
	{
		numb++;
		godown(array2[r]+1,r-1,numb,array1);
		godown(l,array2[r],numb,array1);
		
	}
	else
	{
		if(numb<got)
		{
			if(numb==got)
			{
				if(array1[l]<ans)
					ans=array1[l];

			}
			
		}
		else
		{
			got=numb;
			ans=array1[l];
		}
		return;

	}
	return;
}

struct stack* createstack()
{
struct stack* lala;
lala=(struct stack*)malloc(sizeof(struct stack));
return lala;
}

struct stack* start=NULL;
void gotoend(int r)
{
while((start->num)>=r)
{
	start=start->p;
	if(start==NULL)
	break;

}
}


void assignstack(struct stack* lala,int a,int b,int c,struct stack* lala1,struct stack* t)
{
//lala=createstack();
lala->num=a;
lala->numb=b;
lala->min=c;
lala->p=lala1;
start=t;
}

void sum(int r,int s,int l, int i)
{
	if(start==NULL)
	{
	       struct stack* c;
		c=createstack();
		assignstack(c,r,s,-1,NULL,c);

	}
	else
	{
		if((start->num)>r)
		{
			gotoend(r);
			struct stack* f;
			f=createstack();
			if(start!=NULL)
				assignstack(f,r,s,start->numb,start,f);
			else
				assignstack(f,r,s,-1,start,f);
		}
		else if((start->num)<r)
		{
                      struct stack* new;
		      new=createstack();
		      assignstack(new,r,s,start->numb,start,new);
		}
		
	}

	array2[s]=start->min;
return;

}
int main()
{
int t;
scanf("%d",&t);
while(t--){
int n;
	scanf("%d",&n);
	for(l=0;l<n;l++)
	{
		scanf("%d",&array1[l]);
		sum(array1[l],l, 0,0);
	}
	l=0;
	r=n-1;
	i=0;
	godown(l,r,i,array1);
	printf("%lld %lld\n",ans,got);
	got=-1;
	
	r=0;l=0;i=0;
	free(start);
	for(i=0;i<100000;i++)
{
array1[i]=0;
array2[i]=0;
}
}
return 0;
}
