#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i=0,n,m,j,l=0,num=0,num1,num2,k;
  scanf("%d",&n);
  char c,d,**s;
  scanf("%c",&c);
  s=(char **)malloc(sizeof(char*)*n);
  for(k=0;k<n;k++)
    {
      s[k]=(char *)malloc(sizeof(char)*100);
    }
  while(1)
    {
      
      scanf("%c",&d);
      if(d == 'A')
	{
	  scanf("%d%c",&m,&c);
	  while(m--)
	    {
	      //	      s[i]=(char *)malloc(sizeof(char)*100);
	      scanf("%s",s[i]);
	      //   printf("s[%d] is:%s\n",i,s[i]);
	      i=(i+1)%n;
	      //  printf("i is:%d\n",i);
	      num++;
	    }
	  //printf("num is:%d\n",num);
	  if(num >= n)
	    {
	      //printf("l is:%d\n",l);
	     
	      l=(l+num-n)%n;
	      num=n;
	      // printf("new l is:%d new num is:%d\n",l,num);

	    }
	}
      else if(d == 'L')
	{
	  scanf("%c",&c);
	  // printf("num is %d l is:%d\n",num,l);
	  num1=num;
	  num2=l;
	  while(num1--)
	    {
	      printf("%s\n",s[num2]);
	      num2=(num2+1)%n;
	    }
	}
      else if(d == 'R')
	{
	  scanf("%d",&m);
	  l=(l+m)%n;
	  num-=m;
	  //printf("l is:%d\n",l);
	  scanf("%c",&c);
	}
      else if(d == 'Q')
	{
	  return 0;
	}
    }
  free(s);
  return 0;
}
