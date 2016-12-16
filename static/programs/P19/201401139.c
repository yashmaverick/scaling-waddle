#include <stdio.h>
#include <stdlib.h>

typedef struct dabba
{
  struct dabba *arr[10];
}node;

node *headarr[10];

int check(node* temp)
{
  int a;
  for(a=0;a<11;a++)
    {
      if(temp->arr[a]!=NULL)
	return 1;
    }
  return 0;
}

int main()
{
  int a,b,c,num,d;
  int flag,flag2,mainflag,n,t;
  char digit[12];
  node *temp,*temp2;
  scanf("%d",&t);
  c=0;
  while(c<t)
    {
      scanf("%d",&n);
      
      for(a=0;a<11;a++)
	headarr[a]=NULL;
      mainflag=0;
      for(b=0;b<n;b++)
	{
	  scanf("%s",digit);
	  flag2=flag=0;	  
	  if(headarr[digit[0]-'0']==NULL)
	    {
	      flag2=flag=1;
	      temp2=(node*)malloc(sizeof(node));
	      headarr[digit[0]-'0']=temp2;
	    }
      	
	  temp=headarr[digit[0]-'0'];       
	  for(a=1;digit[a];a++)
	    {
	      num=digit[a]-'0';
	    
	      if(temp->arr[num]==NULL)
		{
		  if(flag2==0)
		    {
		      if(check(temp)==1)
			flag2=1;
		    }
		  flag=1;
		  temp2=(node*)malloc(sizeof(node));
		  temp->arr[num]=temp2;
		}
	      temp=temp->arr[num];
	    }
	  if(flag==0 || flag2==0)
	    mainflag=1;
	}
      if(mainflag==1)
	printf("NO\n");
      else
	printf("YES\n");
      c++;
    }
  return 0;
}
