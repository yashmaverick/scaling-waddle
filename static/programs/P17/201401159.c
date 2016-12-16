#include <stdio.h>
#include <stdlib.h>

int pre[1000100];
int i[1000100];

int main()
{
  int n,test,l,j,k,a,b,c,pr;
  scanf("%d",&n);
  for(l=0;l<n;l++)
      scanf("%d",&pre[l]);
  for(l=1;l<=n;l++)
    {
      scanf("%d",&c);
      i[c]=l;
    }
  scanf("%d",&test);
  for(l=0;l<test;l++)
    {
      scanf("%d %d",&a,&b);
      j=c=0;
      while(j<n)
	{
	  if(i[a]<=i[pre[j]] && i[pre[j]]<=i[b] || i[b]<=i[pre[j]] && i[pre[j]]<=i[a])
	    break;
	  else if(i[a]<i[pre[j]] && i[b]<i[pre[j]])
	    j++; //printf("one %d\n",j);}
	  else if(i[a]>i[pre[j]] && i[b]>i[pre[j]])
	    {
	      pr=i[pre[j]];
	      j+=i[pre[j]]-c;	
	      c=pr;
	      //printf("two %d\n",c);
	    }
	}
      printf("%d\n",pre[j]);
    }
  return 0;
}
