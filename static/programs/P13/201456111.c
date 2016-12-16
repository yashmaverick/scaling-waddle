#include<stdio.h>
#include<stdlib.h>
long long int glbc;
long long int fns;
int b[100000];
void deepnode(int l,int r,int i,int a[100000]);
void deepnode(int l,int r,int i,int a[100000])
{
	int p,s;
	int ind;
	ind=i;
	if(l<0 || l>r)
		return;
	if(l==r)
	{
		if(ind>glbc)
		{
			glbc=ind;
			fns=a[l];
		}
		else
		{
			if(ind==glbc)
			{
				if(a[l]<fns)
					fns=a[l];

			}
		}
		return;
	}
	else
	{
		ind++;
		deepnode(b[r]+1,r-1,ind,a);
		deepnode(l,b[r],ind,a);

	}
	return;
}
struct stack{
	int num;
	int ind;
	int min;
	struct stack* p;
};
struct stack* top;
void add(int r,int s)
{
	if(top==NULL)
	{
	       struct stack* c;
		c=(struct stack*)malloc(sizeof(struct stack));
		c->num=r;
		c->ind=s;
		c->min=-1;
		c->p=NULL;
		top=c;

	}
	else
	{
		if((top->num)<r)
		{
                      struct stack* u;
		      u=(struct stack*)malloc(sizeof(struct stack));
		      u->num=r;
		      u->ind=s;
		      u->min=top->ind;
		      u->p=top;
		      top=u;
		      
		}
		else
		{
			while((top->num)>=r)
			{

				top=top->p;
				if(top==NULL)
					break;

			}
			struct stack* f;
			f=(struct stack*)malloc(sizeof(struct stack));
			f->num=r;
			f->ind=s;
			if(top!=NULL)
			f->min=(top->ind);
			else
				f->min=-1;
			f->p=top;
			top=f;
		}
	}

b[s]=top->min;
return;

}
int main()
{
int t,k,n,l;
int a[100000];
scanf("%d",&t);
for(k=0;k<t;k++)
{
	top=NULL;
	glbc=-1;
	scanf("%d",&n);
	for(l=0;l<n;l++)
	{
		scanf("%d",&a[l]);
		add(a[l],l);
	}
	deepnode(0,n-1,0,a);
	printf("%lld %lld\n",fns,glbc);
	free(top);
}
return 0;
}
