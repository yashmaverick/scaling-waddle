#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int preorder[100000];
	int inorder[100000];
	int i;
	for (i=1; i<=n; i++ )
	{
		scanf("%d", &preorder[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d", &inorder[i]);
	}
	int t;
	scanf("%d", &t);
	while (t-- )
	{
		int a, b;
		scanf("%d%d",&a,&b);
		int j, k;
		for (i=1; i<=n; i++)
		{
//			printf("hi\n");
			if(inorder[i]==a)
			{
				//			int j;
//				printf("hi\n");
				j=i;
//				printf("%d", j);
			}
			if(inorder[i]==b)
			{
				//			int k;
				k=i;
//				printf("%d", k);
			}
		}
		//int subarray[10000];
		int index=n+1;
		if (j<k)
		{
			for(i=j; i<=k; i++)
			{
				int x;
				for (x=1; x<=n; x++)
				{
					if (preorder[x]==inorder[i])
					{
						if (index>x)
							index=x;
					}
				}
			}
		}
		else
		{
			for (i=k; i<=j; i++)
			{
				int x;
				for(x=1; x<=n; x++ )
				{
					if (preorder[x]==inorder[i])
					{
						if (index>x)
							index=x;
					}
				}
			}
		}
		printf("%d\n", preorder[index]);
	}
	return 0;
}
