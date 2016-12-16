#include<stdio.h>
#define MAX 1000000
int main()
{
	int n,i,j;
	int k,x,y; 		//x and y are the positions
	int v,w;		//Pre order index storage
	int c,d;		//In order index storage
	//int flag=0;
	int a[MAX],b[MAX];
	scanf("%d", &n);		//No. of nodes in the tree
	for(i=0;i<n;i++)
		scanf("%d", &a[i]); 	//Pre order Traversal,a[0] is the root
	for(j=0;j<n;j++)
		scanf("%d", &b[j]);	//In order traversal
	scanf("%d", &k); 		//Test cases
	while(k--)
	{
		int flag=0,e=0;
		scanf("%d%d", &x,&y);	//the positions of snow and walker
		if(x==y)
			printf("%d\n",x);
		else
		{
			for(i=0;i<n;i++)
			{
				if(a[i]==x)			
					v=i; 		// storing the index of the element in preorder
				if(a[i]==y)
					w=i;		//storing the element of the second element in preorder
			}
			//printf("\n");
			//printf("%d %d\n", v,w);
			for(j=0;j<n;j++)
			{
				if(b[j]==x)  		//storing the index of element in inorder
					c=j;
				if(b[j]==y)
					d=j;		//storing the index of element in inorder
			}
			//printf("%d %d\n", c,d);
			if(v>w)
			{
				for(i=0;i<=w;i++)
				{	
					if(c>d)
					{
						for(j=d;j<=c;j++)
						{
							if(a[i]==b[j])
							{
								e=a[i];
								flag=1;
								break;
							}
						}
					}
					if(flag==1)
						break;
					else
					{
						for(j=c;j<=d;j++)
						{						
							if(a[i]==b[j])
							{
								e=a[i];
								flag=1;
								break;
							}
						}
					}
					if(flag==1)
						break;
				}
			}
			else if(v<w)
			{
				for(i=0;i<=v;i++)
				{
					if(c>d)
					{
						for(j=d;j<=c;j++)
						{
							if(a[i]==b[j])
							{
								e=b[j];
								flag=1;
								break;
							}
						}
					}
					if(flag==1)
						break;
					else
					{
						for(j=c;j<=d;j++)
						{
							if(a[i]==b[j])
							{
								e=b[j];
								flag=1;
								break;
							}
						}
					}
					if(flag==1)
						break;
				}
			}
			printf("%d\n",e);
		}
		//printf("%d\n",e);
	}
	return 0;
}	
