#include <stdio.h>

int main()
{
  int i,j,k,test,c;
  scanf("%d",&test);
  for(i=0;i<test;i++)
    {
      scanf("%d",&j);
      k=2;c=1;
      while(j>k-1)
	{
	  k=k*2;
	  c+=1;
	}
      j=j-(k/2);
      if(j<k/4)
	printf("%d\n",(c-2)*2+1);
      else
	printf("%d\n",(c-2)*2+2);
    }
  return 0;
}
