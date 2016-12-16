#include<stdio.h>
#include<stdlib.h>
typedef struct stroke
{
  char c;
  int war;
  struct stroke *next[11];
  
}stroke;

int path=2;
void try(stroke *room,char str[11],int x)

{
  if(str[x]!='\0')
    {
      int i;
      int no=str[x]-'0';
      if(room->next[no]!=NULL && room->next[no]->c==str[x])
	{
	  path=1;
	}
      else
	{
	  stroke *new=(stroke*)malloc(sizeof(stroke));
	  new->war=0;
	  new->c=str[x];
	  room->next[no]=new;
	  if(room->war==0 && path==1)
	    {
	      path=1;
	    }
	  else
	    {
	      path=0;
	    }
	  room->war=1;
	}
      try(room->next[no],str,x+1);
    }
  else
    if(room->war==1)
      path=1;
}

int main()
{
  int t,n,i,j;
  char str[100];
  scanf("%d",&t);
  while(t!=0)
    {
      scanf("%d",&n);
      path=2;
      stroke *room=(stroke*)malloc(sizeof(stroke));
      room->war=0;
      room->c='$';
      for(i=0;i<n && n>1;i++)
	{
	  scanf("%s",str);
	  if(path!=1)
	    try(room,str,0);
	}
      if(n>1)
	{
	  if(path==1)
	    printf("NO\n");
	  else
	    printf("YES\n");
	}
      else
	printf("YES\n");
      t--;
    }
  return 0;
}
