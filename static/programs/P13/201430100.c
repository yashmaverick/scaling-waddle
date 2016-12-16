#include<stdio.h>
int deep=0;
int smallest=0;
int pointer;
int n;

void magic(int a[],int previous,int count,int depth)
{	
	if(pointer<0) return;

	int x=a[pointer];
	pointer--;
	if(deep<=depth) { deep=depth; smallest=x; }
	int left,right;

	if(x>previous) { left=x-previous-1; right=count-1-left; }
	else { right=previous-x-1; left=count-1-right; }

	//printf("left:%d right:%d x:%d previous:%d count:%d depth:%d\n",left,right,x,previous,count,depth);

	if(right>0) 
	{
		if((depth+right)>=deep)
		magic(a,x,right,depth+1);
		else pointer-=right;
	}

	//printf("==>left:%d right:%d x:%d previous:%d count:%d depth:%d\n",left,right,x,previous,count,depth);

	if(left>0)
	{
		if((depth+left)>=deep)
		magic(a,x,left,depth+1);
		else pointer-=left;
	}
}

int main()
{
	int test,i;
	scanf("%d",&test);

	for(i=0;i<test;i++)
	{	
		
		scanf("%d",&n);

		deep=0;
		smallest=0;
		pointer=n-1;

		int j,a[n];
		for(j=0;j<n;j++) scanf("%d",&a[j]);

		magic(a,0,n,0);

		printf("%d %d\n",smallest,deep);
	}
	return 0;
}