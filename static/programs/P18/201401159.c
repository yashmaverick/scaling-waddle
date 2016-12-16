#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct node {
  int x;
  struct node* next;
} node;

//node* arr[MAX];
//node* ra[MAX];
int arv[MAX];
//int q[MAX];
int arr[MAX][MAX];
int ra[MAX][MAX];
int h;

void dfs(int i,int vit[MAX][MAX],int n)
{
  if(arv[i]==0)
    {
      arv[i]=1;
      h++;
      //printf("%d ",i);
      /*node* temp=vit[i]->next;
      while(temp!=NULL)
	{
	  dfs(temp->x,vit,d+1);
	  temp=temp->next;
	  }*/
      int j,k;
      for(j=1;j<=n;j++)
	{
	  if(vit[i][j]==1)
	    {
	      dfs(j,vit,n);
	    }
	}
    }
  else
    return;
}

int main()
{
  int i,j,k,n,test,a,m,l,hud;
  scanf("%d",&test);
  for(m=0;m<test;m++)
    {
      hud=0;
      scanf("%d",&n);
      /*for(i=1;i<=n;i++)
	{
	  arr[i]=(node*)malloc(sizeof(node));
	  ra[i]=(node*)malloc(sizeof(node));
	  }*/
      for(i=1;i<=n;i++)
	{
	  scanf("%d",&k);
	  for(l=1;l<=k;l++)
	    {
	      scanf("%d",&a);
	      arr[a][i]=1;
	      ra[i][a]=1;
	    }
	  /*node* prev=arr[k];
	  node *sec;
	  for(l=0;l<k;l++)
	    {
	      node* temp=(node*)malloc(sizeof(node));
	      node* rtemp=(node*)malloc(sizeof(node));
	      scanf("%d",&a);
	      temp->x=a;
	      prev->next=temp;
	      prev=prev->next;
	      rtemp->x=k;
	      sec=ra[a];
	      while(sec->next!=NULL)
		sec=sec->next;
	      sec->next=rtemp;
	      }*/
	}
      for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	    arv[j]=0;
	  h=0;
	  dfs(i,arr,n);
	  //printf("test %d\n",h);
	  if(h==n)
	    {
	      hud=1;
	      break;
	    }
	}
      //printf("test %d\n",i);
      h=0;
      for(j=1;j<=n;j++)
	arv[j]=0;
      dfs(i,ra,n);
      if(hud==1)
	printf("%d\n",h);
      else
	printf("0\n");
      for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	    {
	      arr[i][j]=0;
	      ra[i][j]=0;
	    }
	}
    }
  return 0;
}
