#include<stdio.h>
#include<stdlib.h>

typedef struct node node;

struct node{
  int val;
  node *next;
};

node *push(node *root,int data)
{
  node *tmp=(node *)malloc(sizeof(node));
  tmp->val=data;
  tmp->next=root;
  return tmp;
}
int n;
int flag=0;
int number_of_wining_relams=0;
int count=0;
void dfs(node **a,int i,int *visited)
{
  node *tmp=a[i];
  if(tmp == NULL)
    {
      // printf("tmp is NULL returning\n");
      return;
    }
  else
    {
      //printf("came to dfs for :%d with count is:%d\n",tmp->val,count);
      if(visited[tmp->val] == 0 && flag == 0)
	{
	  if(count == n-1)
	    {
	      flag=1;
	      //	      printf("came to raise flag\n");
	      return;
	    }
	  count++;
	  //printf("increased count to :%d\n",count);
	  visited[tmp->val]=1;
	  dfs(a,tmp->val,visited);
	}
      while(tmp !=NULL && flag == 0)
	{
	  tmp=tmp->next;
	  if(tmp != NULL && visited[tmp->val] == 0)
	    {
	      // printf("came to dfs for:%d with count is:%d\n",tmp->val,count);
	      if(count == n-1)
		{
		  flag=1;
		  // printf("came to raise flag\n");
		  return;
		}
	      count++;
	      // printf("increased count to %d\n",count);
	      visited[tmp->val]=1;
	      dfs(a,tmp->val,visited);
	    }
	}
    }
}


void dfs2(node **a,int i,int *visited)
{
  // printf("came  to do dfs2\n");
  if(a[i] == NULL)
    {
      // printf("came to dfs with NULL\n");
      return;
    }
  else
    {
      //  printf("came to else of dfs2 with a[%d]->val is:%d visited[a[i]->val] is:%d\n",i,a[i]->val,visited[a[i]->val]);
      if(visited[a[i]->val] == 0)
	{
	  //  printf("came inside if of else  with a[%d]->val is:%d\n",i,a[i]->val);
	  visited[a[i]->val]=1;
	  number_of_wining_relams++;
	  // printf("nom of r is:%d\n",number_of_wining_relams);
	  dfs2(a,a[i]->val,visited);

	}
       if(visited[a[i]->val] == 1)
	{
	  while(a[i] != NULL)
	    {
	      if(visited[a[i]->val] == 0)
		{
		  // printf("came inside else if of else  with a[%d]->val is:%d\n",i,a[i]->val);
		  visited[a[i]->val]=1;
		  number_of_wining_relams++;
		  //	  printf("nom of r is:%d\n",number_of_wining_relams);
		  dfs2(a,a[i]->val,visited);
		}
	      a[i]=a[i]->next;
	    }
	}
    }
}

int main()
{
  int i,t;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {
      number_of_wining_relams=0;
      flag=0;
      node **a,**b;
      int j,k,r,s;
      scanf("%d",&n);
      int *visited,**vtd;
      a=(node **)malloc(sizeof(node*)*(n+1));
      b=(node **)malloc(sizeof(node*)*(n+1));
      visited=(int *)malloc(sizeof(int)*(n+1));
      vtd=(int **)malloc(sizeof(int *)*(n+1));
      for(j=1;j<=n;j++)
	{
	  a[j]=NULL;
	  b[j]=NULL;
	  visited[j]=0;
	  vtd[j]=(int *)malloc(sizeof(int)*(n+1));
	  for(k=1;k<=n;k++)
	    {
	      vtd[j][k]=0;
	    }
	}
      for(j=1;j<=n;j++)
	{
	  scanf("%d",&r);
	  for(k=0;k<r;k++)
	    {
	      scanf("%d",&s);
	      a[s]=push(a[s],j);
	      b[j]=push(b[j],s);
       	    }
      	}
      node *tmp;
      // printf("came to print a\n");
      /* for(j=1;j<=n;j++) */
      /* { */
      /* 	tmp=a[j]; */
      /* 	while(tmp != NULL) */
      /* 	{ */
      /* 		printf("%d ",tmp->val); */
      /* 		tmp=tmp->next; */
      /* 	} */
      /* 	printf("\n"); */
      /* } */
      /* printf("came to print b\n"); */
      /* for(j=1;j<=n;j++) */
      /* { */
      /* 	tmp=b[j]; */
      /* 	while(tmp != NULL) */
      /* 	{ */
      /* 		printf("%d ",tmp->val); */
      /* 		tmp=tmp->next; */
      /* 	} */
      /* 	printf("\n"); */
      /* } */
      k=1;
      flag=0;
      count=0;
      while(k<=n)
	{
	  count=0;
	  if(flag == 0)
	    {
	      //	      printf("started dfs with k is:%d and count is:%d\n",k,count);
	      dfs(a,k,vtd[k]);
	      // printf("dfs over with k is:%d and count is:%d\n",k,count);
	      if(count == n-1)
		{
		  // printf("came to raise flag\n");
		  flag=1;
		  break;
		}
	      if(flag == 0)
		k++;
	      else
		{
		  break;
		}
	    }
	}
      //printf("a[%d]->val is:%d\n",k,a[k]->val);
      visited[k]=1;
      if(flag == 0)
	{
	  printf("0\n");
	  continue;
	}
      else
	{
	  number_of_wining_relams=1;
	  dfs2(b,k,visited);
	}
      printf("%d\n",number_of_wining_relams);
    }
  return 0;
}
