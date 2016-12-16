#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minNode,maxDepth;

int leftTreeSize(int arr[],int left,int size, int nodeValue)
{
    int middle,right;
    right=left+size-1;

    // boundary condition
    if (size==0)
        return 0;
    else if (nodeValue<arr[left]) //right tree only
        return 0;
    else  if (nodeValue>arr[right])//left tree only
        return size;


   middle = (left+right)/2;

   if (nodeValue<arr[middle])
   {
       if (middle==left)
            return 0;
       else
          return leftTreeSize(arr,left,middle-left,nodeValue);
   }
   else
    {
        if (middle==right)
            return size;
        else
            return ((middle-left+1)+leftTreeSize(arr,middle+1,right-middle,nodeValue));
    }
}

void  searchTree(int arr[],int left,int size, int depth)
{

    if (size==0)
        return;

    int nodeValue=arr[left+size-1];

    //Set MinNode and MaxDepth
    if ((depth>maxDepth) || ((depth == maxDepth) && (nodeValue<minNode)))
    {
        maxDepth=depth;
        minNode=nodeValue;
    }

    //Find Left and Right SubTree
    int leftSize=leftTreeSize(arr,left,size-1, nodeValue);
    int rightSize=size-1-leftSize;

    //Create Left Tree
    if (leftSize>0)
        searchTree(arr,left,leftSize,depth+1);

    //Create Right Tree
    if (rightSize>0)
        searchTree(arr,left+leftSize,rightSize,depth+1);
}

int main()
{
    int n,t;
    scanf("%d",&t);

    while(t--)
    {// Initialize
        maxDepth=0,minNode=INT_MAX;
        // Read numbers
        scanf("%d",&n);
        int i, arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        //Create Binar
        searchTree(arr,0,n,0);
        printf("%d %d\n",minNode,maxDepth);
        //printf("\n");
    }
    return 0;
}
