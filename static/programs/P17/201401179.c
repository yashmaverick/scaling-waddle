#include<stdio.h>
#include<stdlib.h>

int Preorder[100002],Inorder[100002],Position[100002];

int  Quickinbuilt(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int Nodes,i,Root;
	scanf("%d",&Nodes);
	for(i=0;i<Nodes;i++)
		scanf("%d",&Preorder[i]);

	for (i = 0; i < Nodes; i++)
	{
		scanf("%d",&Inorder[i]);
		if(Inorder[i]==Preorder[0])
			Root=i;
	}	
	
	for(i=0;i<Nodes;i++)
		Position[Preorder[i]]=i;

	int Test,Jon,walk,Jonpos,walkpos,min;
	
	scanf("%d",&Test);
	
	while(Test-- > 0)
	{
		scanf("%d%d",&Jon,&walk);
		for(i=0;i<Nodes;i++)
		{
			if(Inorder[i]==Jon)
				Jonpos=i;
			if(Inorder[i]==walk)
				walkpos=i;		
		}

		/*printf("Root=%d\n",Root);
		printf("Jonpos= %d  walkpos=%d\n",Jonpos,walkpos);*/

		if(walkpos == Root || Jonpos== Root)
			printf("%d\n",Preorder[0]);
		
		else if(walkpos==Jonpos)
			printf("%d\n",walk);
		
		else if(walkpos < Root && Jonpos > Root)
			printf("%d\n",Preorder[0]);
		else if (walkpos > Root && Jonpos < Root)
			printf("%d\n",Preorder[0]);
		
		else if(walkpos < Jonpos)
		{
			min=Position[Inorder[walkpos+1]];

			for (i = walkpos+1; i < Jonpos; i++)
				if(Position[Inorder[i]] < min)
					min=Position[Inorder[i]];

			if(min >=  ( Position[walk]>Position[Jon]? Position[Jon]:Position[walk] ) )
				printf("%d\n",Preorder[( Position[walk]>Position[Jon]? Position[Jon]:Position[walk] )]);
			else
				printf("%d\n",Preorder[min]);
		}
		else if(walkpos > Jonpos)
		{
			min=Position[Inorder[Jonpos+1]];

			for (i = Jonpos+1; i < walkpos; i++)
				if(Position[Inorder[i]] < min)
					min=Position[Inorder[i]];
			if(min >=  ( Position[walk]>Position[Jon]? Position[Jon]:Position[walk] ) )
				printf("%d\n",Preorder[( Position[walk]>Position[Jon]? Position[Jon]:Position[walk] )]);
			else		
				printf("%d\n",Preorder[min]);
		}
	}

	return 0;
}


/*int Nodesearch(int m,int n)
{
	int l=0,u=n-1,c,mid;
    while(l<=u){
         mid=(l+u)/2;
        printf("Inorder[%d]=%d m=%d\n",mid,Inorder[mid],m);
         if(m==Inorder[mid])
         {
             c=1;
             break;
         }

        else if(m<Inorder[mid])
            l=mid+1;
        
        else
            u=mid-1;
    }
    if(c!=0)
    	return mid;         
}*/





