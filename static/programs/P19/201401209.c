#include<stdio.h>
#include<stdlib.h>
int ans=-1;
typedef struct node
{
    struct node* a[10];
    int end;
}node;
node* insert(node* root,char* str)
{
    int i;
    if(*str=='\0') 
    { 
       if(root->end==-1) { ans=0; return root;}
        for(i=0;i<10;i++) 
        {
            if(root->a[i]!=NULL)    {ans=0; return root;}  
        }    
        root->end=-1; return root;  
    }
    if(root->end==-1) { ans=0;  return root;}
    if(root->a[*str-'0']!=NULL){ root->a[*str-'0']=insert(root->a[*str-'0'],str+1); return root; }
    else
    {
        node* temp=malloc(sizeof(node));
        for(i=0;i<10;i++) temp->a[i]=NULL;
        root->end=0;
        root->a[*str-'0']=temp;
        root->a[*str-'0']=insert(root->a[*str-'0'],str+1);
        return root;
    }
}
void print(node* root)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(root->a[i]!=NULL) { printf("%d ",i); print(root->a[i]); }
    }
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int n,i,flag=0;
        ans=-1;
        scanf("%d",&n);
        node *root=malloc(sizeof(node));  
        for(i=0;i<10;i++) root->a[i]=NULL;
        root->end=0;
        while(n--)
        {
            char str[20];
            scanf("%s",str);
            root=insert(root,str);
            //print(root);
            if(ans==-1) continue;
            if(ans==0) { flag=1; }
        }

        if(flag==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
