#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	int val;
	struct ll *l;
	struct ll *r;
}node;

int main()
{
	int x,t,i,j,ptr=0,k,n,m,val,level,a[100000],h[100000],l[100000],r[100000],p[100000],lev[100000];
	node *st[100000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
		scanf("%d",&a[i]);
	for(i=0;i<t;i++)
	{
		scanf("%d",&val);
		h[val]=i;
	}
	level=0;
	for(i=0;i<t;i++)
	{
		val=a[i];
		x=h[val];
		if(ptr==0)
		{
			st[ptr]=(node *)malloc(sizeof(node));
			l[val]=-1;
			r[val]=t;
			p[val]=0;
			lev[val]=0;
			st[ptr]->val=val;
			ptr++;
			level++;
		}
		else
		{
			while(x<l[st[ptr-1]->val] || x>r[st[ptr-1]->val])
			{
				ptr--;
				level--;
				if(ptr==0)
					break;
			}
			if(x<h[st[ptr-1]->val])
			{
				st[ptr]=(node *)malloc(sizeof(node));
				st[ptr]->val=val;
				st[ptr-1]->l=st[ptr];
				l[val]=l[st[ptr-1]->val];
				r[val]=h[st[ptr-1]->val];
				p[val]=st[ptr-1]->val;
				lev[val]=level;
				ptr++;
				level++;
			}
			else if(x>h[st[ptr-1]->val])
			{
				st[ptr]=(node *)malloc(sizeof(node));
				st[ptr]->val=val;
				st[ptr-1]->r=st[ptr];
				r[val]=r[st[ptr-1]->val];
				l[val]=h[st[ptr-1]->val];
				p[val]=st[ptr-1]->val;
				lev[val]=level;
				ptr++;
				level++;
			}
		}
	}
	int q,a1,b;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a1,&b);
		while(1)
		{
			if(a1==b)
				break;
			else if(lev[a1]>=lev[b])
			{
				a1=p[a1];
			}
			else
				b=p[b];
//			printf("  %d%d %d%d  \n",lev[a1],lev[b],a1,b);
		}
		printf("%d\n",a1);
	}

	
	return 0;
}





