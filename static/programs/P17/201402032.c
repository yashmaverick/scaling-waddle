#include<stdio.h>
int main()
{
	int pre[1000010];
	int ino[1000010];
	int nodes;
	scanf("%d",&nodes);
	int i;
	for(i=0;i<nodes;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<nodes;i++)
		scanf("%d",&ino[i]);
	int t,q1,q2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&q1,&q2);
		int flag1=0,flag2=0,start,end;
		for(i=0;i<nodes;i++)
		{
			if(ino[i]==q1)
			{
				start = i;
				flag1=1;
			}
			if(ino[i]==q2)
			{
				end = i;
				flag2=1;
			}
			if(flag1==1 && flag2==1)
				break;
		}
		int temp;
		if(start>end)
		{
			temp = end;
			end = start;
			start = temp;

		}
		int lca,j,lflag=0;
		for(j=0;j<nodes;j++)
		{
			for(i=start;i<=end;i++)
			{
				if(pre[j]==ino[i])
				{
					lca = j;
					lflag=1;
					break;

				}
			}
			if(lflag==1)
				break;
		}
		printf("%d\n",pre[lca]);
	}
		
	return 0;
	}




