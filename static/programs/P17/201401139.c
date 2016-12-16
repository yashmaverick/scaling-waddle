#include <stdio.h>

int main()
{
  int arr[100000],posarr[100000],pos2arr[100000];
  int root,pos,val,flag;
  int node1,node2;
  int cond1,cond2;
  int a=0,b,c;
  int n,t;
  scanf("%d",&n);
  while(a<n)
    {
      scanf("%d",&arr[a]);
      pos2arr[arr[a]]=a;
      a++;
    }
  a=0;
  while(a<n)
    {
      scanf("%d",&val);
      posarr[val]=a;
      a++;
    }

  scanf("%d",&t);
  a=0;
  
  while(a<t)
    {
      root=arr[pos];
      scanf("%d%d",&node1,&node2);
      b=0;
      while(b<n)
	{
	  root=arr[b++];
	  flag=0;
	  if((posarr[node1]<=posarr[root]&& posarr[node2]>=posarr[root] )||(posarr[node1]>=posarr[root]&& posarr[node2]<=posarr[root]))
	    {
	      flag=1;
	      
	    }
	  if(flag==1 && pos2arr[root]<=pos2arr[node1] && pos2arr[root] <= pos2arr[node2])
	    {
	      printf("%d\n",root);
	      break;
	    }
	}
      a++;
    }
  return 0;
}
