#include<stdio.h>
int top, post[100001], depth[100001], stack[100001],ans,maxdepth;
void depthfunc(int N)
{
	int i,j, temp;
	for(i=N-1; i>=0; i--)
	{
		if(top==-1)
		{
			stack[++top]=post[i];
			depth[post[i]]=0;
			ans=post[i];
			maxdepth=0;
		}
		else
		{
			if(post[i]<stack[top])
			{
				while(post[i]<stack[top])
				{
					temp=depth[stack[top]];
					top--;
				}
				depth[post[i]]=temp+1;
			}
			else if(post[i]>stack[top])
			{
				stack[++top]=post[i];
				depth[stack[top]]=depth[stack[top-1]]+1;
			}
			if(depth[post[i]]>=maxdepth)
			{
				if(depth[post[i]]==maxdepth && ans>post[i])
					ans=post[i];
				else
				{
					maxdepth=depth[post[i]];
					ans=post[i];
				}
			}
			stack[++top]=post[i];
		}
	}

}

int main()
{
	int T, N, i,j;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(i=0; i<N; i++)
			scanf("%d", &post[i]);
		top=-1;		
		depthfunc(N);
		printf("%d %d\n", ans, maxdepth);


	}

	return 0;
}
