#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node node;

struct node {
  char dgt;
  node *arr[10];
};

void frp(node *head)
{
  if(head==NULL)
    return;
  int i=0;
  for(i=0;i<10;i++)
  {
    frp(head->arr[i]);
  }
  free(head);
}

void print(node *head)
{
  if(head==NULL)
    return;
  printf("%c ",head->dgt);
  int i=0;
  for(i=0;i<10;i++)
  {
    print(head->arr[i]);
  }
}

node *insert(node *root,char data)
{
  int i;
  if(root == NULL)
  {
    // printf("came to insert %c in if\n",data);
    node *tmp=(node *)malloc(sizeof(node));
    tmp->dgt=data;
    for(i=0;i<10;i++)
    {
      tmp->arr[i]=NULL;
    }
    return tmp;
  }
  else
  {
    i=data-'0';
    //printf("i is:%d\n",i);
    if(root->arr[i] != NULL)
    {
      // printf("came to insert %c in else if\n",data);
      return root->arr[i];
    }
    if(root->arr[i] == NULL)
    {
      //printf("came to insert %c in else if2\n",data);
      root->arr[i]=insert(root->arr[i],data);
      return root->arr[i];
    }
  }
}


int main()
{
  int i,t,n,j;
  char c,d;
  char b[11];
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
    node *root=(node *)malloc(sizeof(node));
    root->dgt='A';
    for(j=0;j<10;j++)
      root->arr[j]=NULL;
    scanf("%d",&n);
    int flag=0,k,counter=0;
    while(n--)
    {
      node *tmp=root;
      scanf("%s",b);
        j=0;
      while((c=b[j])!='\0')
      {
        if(tmp->arr[0] != NULL && tmp->arr[0]->dgt != '.' && flag == 0)
        {
        //  printf("camt to insert from first c is:%c\n",c);
          tmp=insert(tmp,c);
        }
        else if(tmp->arr[0] == NULL && flag == 0)
        {
       //   printf("came to insert from second c is:%c\n",c);
          tmp=insert(tmp,c);
        }
        else
        {
         // printf("came to last c is:%c\n",c);
          flag=1;
        }
        j++;
      }
      counter=0;
      if(flag == 0)
      {
        for(k=0;k<10;k++)
        {
          if(tmp->arr[k] != NULL)
          {
            flag=1;
            break;
          }
          else
          {
            counter++;
          }
        }
        if(counter == 10)
        {
          node *end=(node*)malloc(sizeof(node));
          end->dgt='.';
          for(k=0;k<10;k++)
          {
            end->arr[k]=NULL;
          }
          tmp->arr[0]=end;
        }
      }
    }
    if(flag == 0)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
    // print(root);
    frp(root);
  }
  return 0;
}
