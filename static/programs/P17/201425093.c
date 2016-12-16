#include<stdio.h>
#include<stdlib.h>
int x,i,test;
void scant(int *p)
{
	register int c = getchar_unlocked();
	int x = 0;
	for(;(c<48 || c>57);c = getchar_unlocked())
		;
	for(;c>47 && c<58;c = getchar_unlocked())
	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	*p = x;
}
int main()
{
	int preorder[100001];
	int inorder[100001];
	int index[100001];
//	indpre[1000010];
	scant(&x);
	int p,q;
	i=0;
	while(i<x)
	{
		scant(&preorder[i]);
		//indpre[preoder[i]]=i;
		i++;
	}
	i=0;
	while(i<x)
	{
		scant(&inorder[i]);
		index[inorder[i]]=i;
		i++;
	}
	scant(&test);
	int j;
	for(i=0;i<test;i++)
	{
		scant(&p);
		scant(&q);
		int k,l;
		int max=999999;
		int min;
		for(j=0;j<x;j++)
		{
			int temp=preorder[j];
			if((index[temp]>=index[p] && index[temp]<=index[q]) || (index[temp]>=index[q] && index[temp]<=index[p]))
			{
				 min=j;
				 if(min<max)
					 max=min;
			}
		}
		printf("%d\n",preorder[max]);	
	}
	return 0;
}
