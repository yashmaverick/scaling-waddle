#include<stdio.h>		
#include<string.h>		
int main()			
{				
	int T,n,m,i,j,k,flag=0;
	scanf("%d ",&T);	
	char aa[T][101],ch[101],c;
	int end=-1,begin=0,size=0;	
	while(1)		
	{			
		scanf("%c",&c);
		if(c=='A')
		{	
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%s",ch);
				end=(end+1)%T;
				strcpy(aa[end],ch);	
				if(size==T)
					begin=(begin+1)%T;	
				if(size<T)size++;
			}
			//printf("%d",begin);
		}
		else if(c=='R')
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				begin=(begin+1)%T;
				size--;
			}
		}	
		else if(c=='L')
		{
			for(k=begin;k!=end && size!=0;k=(k+1)%T)
			{
				printf("%s\n",aa[k]);
			}
			if(k==end && size!=0)
				printf("%s\n",aa[k]);
		}	
		else if(c=='Q')
		{	
			break;
		}	
	}			
	return 0;		
}				
