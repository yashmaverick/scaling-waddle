#include<stdio.h>
#include<math.h>
#define max 100

int position(int a, int ar[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(ar[i]==a)
		{
//			printf("%d\n",i);
			return (i);
		}
	}
}

int main()
{
	int preorder[max],inorder[max],i,t,n,root,nodes[2],node1_index,node2_index,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d", &preorder[i]);
	for(i=0;i<n;i++)
		scanf("%d", &inorder[i]);
	scanf("%d",&t);
	while(t--){
		root=preorder[0];
		for(i=0;i<2;i++)
			scanf("%d",&nodes[i]);
/*		for(i=0;i<n;i++)
		{
			if(inorder[i]=nodes[0])
			{
				node1_index=i;
				break;
			}
		}

		for(i=0;i<n;i++)
		{
			if(inorder[i]=nodes[1])
			{
				node2_index=i;
				break;
			}
		}
		
*/		
		node1_index=position(nodes[0],inorder,n);
		node2_index=position(nodes[1],inorder,n);
//		printf("%d %d\n",node1_index,node2_index);
		int between_nodes[n];
		if(node2_index>node1_index)
		{
			//int j;
			j=0;
			for(i=node1_index;i<=node2_index;i++)
			{
				between_nodes[j]=inorder[i];
				j++;
			}
		}
		else
		{
			//int j;
			j=0;
			for(i=node2_index;i<=node1_index;i++)
			{
				between_nodes[j]=inorder[i];
				j++;
			}
		}
//		printf("%d\n",j);
//		for(i=0;i<j;i++)
//			printf("%d\t",between_nodes[i]);
//		printf("\n");
		int min=n+1;
		int pos;
		for(i=0;i<j;i++)
		{
		//	pos[i]=position(between_nodes[i],preorder,n);
			if((pos=position(between_nodes[i],preorder,n))<min)
				min=pos;
		}
		printf("%d\n",preorder[min]);
	}
	return 0;
}






	
