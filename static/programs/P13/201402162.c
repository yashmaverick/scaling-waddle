#include<stdio.h>
#include<stdlib.h>
typedef struct lashit
{
       int depth;
       int value;
}lashit;   
lashit utr;
void find(int* post,int ref,int low,int high,int deep)
{
	int hin,node;
	int index;
	if(high==low)
	{
		deep++;
		if(utr.depth<deep)
		{
			utr.depth=deep;
			utr.value=low;
		}
		return ;
	}
	deep++;
	hin=ref+high-low;
	node=post[hin];
	if(low<node)
	{
	//	printf("hello\n");
		find(post,ref,low,node-1,deep);
	}
	if(high>node)
	{
	//	printf("high\n");
	//	printf("%d",node);
		find(post,hin-high+node,node+1,high,deep);
		// 3+3+1-4=	REF=3 LOW=4 HIGH=5 ALL RIGHT...
		//NEXT CALL TO FIND() .. NODE=POST[3+5-4]=POST[4]=4 :) LOW=4...IF CONDN DONE.. IF 5>4  .. 4-5+4+1=4..**... AGAIN WILL ENTER TO NODE 3 AND KEEP CALLING IT INFINITE TIMES...
	}
	return;
}
int main()
{
	int t,n,i;
	int in[100001],post[100001];
	scanf("%d",&t);
	while(t--)
	{
		utr.depth=0;
		utr.value=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&post[i]);
		}
		find(post,0,1,n,0);
		printf("%d %d\n",utr.value,(utr.depth)-1);
	}
	return 0;
}
