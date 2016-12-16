#include<stdio.h>
#include<stdlib.h>
//#include<ctype.h>

int main()
{
	int test,nodes,*Po,*Io,least;
	int first,last,one,two,i,j,k,temp,flag;
	scanf("%d",&nodes);
	Io=malloc(nodes*sizeof(int));
	Po=malloc(nodes*sizeof(int));
	for(i=0;i<nodes;i++)
		scanf("%d",&Po[i]);
	for(i=0;i<nodes;i++)
		scanf("%d",&Io[i]);
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d %d",&one,&two);
		for(j=0;j<nodes;j++)
		{
			if(Io[j]==one)
				first=j;
			if(Io[j]==two)
				last=j;
		}
		//	printf("%d %d\n",first,last);
		//		for(k=0;k<nodes;k++)
		//		{
		//			if(Po[k]==Io[first])
		//				least=k;
		//		}
		//	printf("%d\n",least);
		if(first>last)
		{
			temp=first;
			first=last;
			last=temp;
		}
		flag=0;
		//		printf("%d %d\n",first,last);
		for(k=0;k<nodes;k++)
		{
			for(j=first;j<=last;j++)
			{
				if(Po[k]==Io[j])
				{
		//					printf("k=%d j=%d",k,j);
		//		printf("Po[k]=%d Io[j]=%d\n",Po[k],Io[j]);
					flag=1;
					least=k;
					break;
				}
			}
			if(flag==1)
				break;
		}
		/*for(j=first+1;j<=last;j++)
		  {
		  for(k=0;k<nodes;k++)
		  {
		  if(Po[k]==Io[j] && k<least)
		  {
		  least=k;
		  }
		  }
		  }
		  else
		  {
		  for(j=first-1;j>=nodes;j--)
		  { 
		  for(k=0;k<nodes;k++)
		  {
		  if(Po[k]==Io[j] && k<least)
		  {
		  least=k;
		  }
		  }
		  }
		  for(j=0;j<=last;j++)
		  { 
		  for(k=0;k<nodes;k++)
		  {
		  if(Po[k]==Io[j] && k<least)
		  {
		  least=k;
		  }
		  }
		  }
		  }*/
		printf("%d\n",Po[least]);
	}
	return 0;
}
