// #Authored : Jaipal Singh Goud
// Part of : DS Assignment  
// Date : 3/4/2015
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int main()
{
    int i ,j ,k ,num ,x ,y ,test;
    scanf("%d",&num);
    int preorder[100];
    int inorder[100];
    for(i=0;i<num;i++)
        scanf("%d",&preorder[i]);

    for(i=0;i<num;i++)
        scanf("%d",&inorder[i]);

    //node *root = buildTree(inorder , preorder , 0 , num);
    //node *root = create_bintree(preorder , inorder , num);
    //printInorder(root);
    //node *common;
    
    int common;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&x,&y);
        common = leastCommonAncestor(inorder , preorder , x , y, num);
        printf("%d\n",common);
    }
    return 0;
}

int leastCommonAncestor(int inorder[], int preorder[] ,int x , int y,int num)
{
    int index1 , index2;
    int i,j;
    int min = num;
    int index;
    for(i=0;i<num;i++)
    {
        if(inorder[i] == x)
            index1 = i;
        if(inorder[i] == y)
            index2 = i;
    }
    int temp;
    if(index2 < index1)
    {
        temp = index1;
        index1 = index2;
        index2 = temp;
    }
    for(i=index1;i<=index2;i++)
    {
        for(j=0;j<num;j++)
        {
            if(preorder[j] == inorder[i])
            {
                index = j;
                if(j < min)
                    min = j;
            }
        }
    }
    return preorder[min];
}

typedef struct nn
{
    int data;
    struct nn *left;
    struct nn *right;
}node;

node *makeNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data  = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
   int pos;
   int iterator = 0;
   node * makeTree(int inorder[], int preorder[], int start, int end)
   {
   if(start>end)
   return NULL;
   node *new = makeNode(preorder[iterator]);
   iterator = iterator + 1;
   if(start == end)
   return new;
   pos = search(inorder,new->data,start,end);
   new->left = makeTree(inorder , preorder , start , pos - 1);
   new->right = makeTree(inorder , preorder , pos+1 , end);
   return new;
   }
   */
/*int search(int inorder[] , int x , int start , int end)
  {
  int i;
  for(i=start;i<=end;i++)
  if(inorder[i]== x)
  return i;
  }
  */
node* buildTree(int in[], int pre[], int start, int end)
{
    static int iterator = 0;
    printf("%d\n",iterator);
    if(start > end)
        return NULL;
    node *newNode = makeNode(pre[iterator++]);
    if(start == end)
        return newNode;
    int pos = search(in, start, end, newNode->data);
    newNode->left = buildTree(in, pre, start, pos-1);
    newNode->right = buildTree(in, pre, pos+1, end);
    return newNode;
}

int search(int inorder[],int x, int start, int end)
{
    int i;
    for(i = start; i <= end; i++)
        if(inorder[i] == x)
            return i;
}

void printInorder(node *n)
{
    if (n == NULL)
        return;

    printInorder(n->left);
    printf("%d ", n->data);
    printInorder(n->right);
}

int getIndex(int* arr, int val, int size)
{
    int i;
    for( i=0; i<size;i++) {
        if(arr[i] == val) 
            return i;
    }
    return -1;
}

node * create_bintree(int* parray, int* iarray, int size)
{
    printf("Making\n");
    if(size == 0) return NULL;
    int rootVal = parray[0];
    node* root  = makeNode(rootVal);
    int newIdx = getIndex(iarray, rootVal, size);
    root->left = create_bintree(parray+1, iarray, newIdx);
    root->right = create_bintree(parray+newIdx+1, iarray+newIdx+1, size-newIdx-1);
    return root;            
}
