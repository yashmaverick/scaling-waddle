#include <stdio.h>
#include <stdlib.h>
#define MAX 100100

int arr[MAX];
int min=-1,mlv=-1;
int top=-1;

void push(int k)
{
  if(top==(MAX-1))
    return;
  else
    {
      top++;
      arr[top]=k;
    }		
  return;
}

void pop()
{
  if(top==-1)
    return;
  else
    top--;
}

int topp()
{
  return arr[top];
}
/*int bin(int *arv,int n,int s,int e)
  {
  if(s>e)
  return -1;
  if(s==e)
  {
  if(arv[s]>n)
  return s;
  else
  return s+1;
  }
  else
  {
  int mid=(s+e)/2;
  if(arv[mid]>n)
  return bin(arv,n,s,mid);
  else
  return bin(arv,n,mid+1,e);
  }
  }*/

void convert(int *arv,int s,int e,int lv,int *ari)
{
  if(s>e)
    return;
  int i,j,k,lt,rt;
  if(s==e)
    {
      if(lv>mlv)
	{
	  //	  printf("this %d\n",s);
	  min=arv[s];
	  mlv=lv;
	}
      return;
    }
  //for(i=e-1;arv[i]>arv[e]&&i>=s;i--);
  //i++;
  //i=bin(arv,arv[e],s,e-1);
  i=ari[e];
  convert(arv,s,i-1,lv+1,ari);
  convert(arv,i,e-1,lv+1,ari);
}

int main()
{
  int test,i,j,k,l,arv[MAX],n,ari[MAX];
  scanf("%d",&test);
  for(i=0;i<test;i++)
    {
      min=-1,mlv=-1,top=-1;
      scanf("%d",&n);
      for(j=0;j<n;j++)
	scanf("%d",&arv[j]);
      //l=bin(arv,arv[n-1],0,n-2);
      //if(arv[0]>arv[n-1])
      //printf("%d %d\n",arv[0],n-1);
      //else
      //{
      k=n-1;
      while(k>=0)
	{
	  if(top==-1||arv[k]>arv[topp()])
	    {
	      push(k--);
	    }
	  else
	    {
	      l=topp();
	      ari[l]=k+1;
	      pop();
	    }
	}
      while(top!=-1)
	{
	  ari[topp()]=0;
	  pop();
	}
      ari[0]=0;
      convert(arv,0,n-1,0,ari);
      //for(j=0;j<n;j++)
      //printf("this %d\n",ari[j]);
	 printf("%d %d\n",min,mlv);
      //}
	 // printf("\n");
    }
  return 0;
}
