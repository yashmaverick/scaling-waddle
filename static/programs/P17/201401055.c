#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nodes,t,pos1,pos2,p1,p2,k;
	int *pre,*in,*arr;
	scanf("%d",&nodes);
	pre=malloc(sizeof(int)*nodes);
	in=malloc(sizeof(int)*nodes);
	arr=malloc(sizeof(int)*nodes);
	int i,j,root1,root;
	for(i=0;i<nodes;i++)
		scanf("%d",&pre[i]);
/*	for(i=0;i<nodes;i++)
		printf("%d",pre[i]);
*/	for(i=0;i<nodes;i++)
		scanf("%d",&in[i]);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&pos1,&pos2);
//		printf("%d %d\n",pos1,pos2);
		root1=pre[0];
//		printf("rootval=%d\n",root);
		for(j=0;j<nodes;j++)
		{
			if(in[j]==pos1)
				p1=j;
			if(in[j]==pos2)
				p2=j;
			if(in[j]==root1)
			{
				root=j;
//				printf("%d %d\n",j,in[j]);
			}
		}
		arr[10];
		k=0;
		if(p1<=p2)
		{
			for(j=p1;j<=p2;j++)
			{
				arr[k]=in[j];
				k++;
			}
		}

		else
			if(p2<p1)
			{
				k=0;
				for(j=p2;j<=p1;j++)
				{
					arr[k]=in[j];
					k++;
				}
			}
		int size;
		j=0;
		size=k;
		int flag=0;
		for(j=0;j<nodes;j++)
		{
			for(k=0;k<size;k++)
			{
				if(pre[j]==arr[k])
				{
					printf("%d\n",pre[j]);
					flag=1;
				}
				if(flag==1)
					break;
			}
		if(flag==1)
			break;
		}
	}

	return 0;
}

			


