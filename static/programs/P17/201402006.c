#include<stdio.h>
#include<stdlib.h>
int n;
int search(int in[], int n1)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(in[i] == n1)
			return i;
	}
}
/*int min(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
}
int max(int a, int b)
  {
  if(a > b)
  return a;
  else
  return b;
  }
 */
int main()
{
	int k;
	int i,j,lca,idx1,idx2,index1,temp,index2,n1,n2,pre[10000],in[10000];
	int flag,test;
	scanf("%d",&n);    
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&test);
	for(k=0;k<test;k++)
	{
		flag = 0;
		scanf("%d %d",&n1,&n2);
		index1 = search(in,n1);
		index2 = search(in,n2);
		//	printf("indexes =  %d %d\n",index1,index2);
		if(index1 > index2)
		{
			idx1 = index2;
			idx2 = index1;
		}
		else
		{
			idx1 = index1;
			idx2 = index2;
		}
		//	printf("%d %d\n",idx1,idx2);
		for(i=0;i<n;i++)
		{
			//	printf("i = %d\n",i);
			for(j=idx1;j<=idx2;j++)
			{
				//		printf("j = %d\n",j);
				//		printf("%d",in[j]);
				//		printf("%d -> %d\n",pre[i],in[j]);
				if(pre[i] == in[j])
				{
					//			printf("%d -> %d\n",pre[i],in[j]);
					lca = pre[i];
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				break;
			//		printf("\n");
		}
		printf("%d\n",lca);
	}
	return 0;
}

//	idx1 = min(index1,index2);
