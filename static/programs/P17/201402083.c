/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
int pre_hash[1000005];
int inorder[1000005];
int main()
{
    int t,n,i,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        pre_hash[temp]=i;
    }
    for(i=0;i<n;i++) scanf("%d",&inorder[i]);
    scanf("%d",&t);
    while(t--)
    {
        int min=1000000000;
        int node1,node2,val=0;
        scanf("%d %d",&node1,&node2);
        int index1;
        int index2;
        for(i=0;i<n;i++)
        {
            if(inorder[i]==node1) index1=i;
            if(inorder[i]==node2) index2=i;
        }
        int start=index1<index2?index1:index2;
        int end=index1>index2?index1:index2;
        for(i=start;i<=end;i++)     if(pre_hash[inorder[i]]<min) {min=pre_hash[inorder[i]]; val=inorder[i];}
        printf("%d\n",val);
    }
return 0;
}
