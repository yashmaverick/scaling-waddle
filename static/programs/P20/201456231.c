#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int visited[MAX];
int heightarray[MAX];

struct node
{
    int val;
    struct node* next;
};

struct node* varray[MAX];

struct node* insert(struct node* root,int n)
{
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->val=n;
    temp->next=root;
    return temp;
}

void print(struct node* array)
{
    struct node* tmp=array;
    while(tmp != NULL)
    {
        printf("%d\n",tmp-> val);
        tmp = tmp-> next;
    }
}

void dfs(int x,int height)
{
    height++;
   // printf("%d ",x);
    struct node* tmp=varray[x];
    visited[x]=1;
    heightarray[x]=height;
    while (tmp != NULL)
    {
        if (visited[tmp -> val] == 0)
        {
            dfs(tmp->val,height);
            visited[tmp -> val] = 1;
        }
        tmp = tmp -> next;
    }
}
    
    
    
    

int main()
{
    int T, i, a, b;
    int n;
        
    scanf("%d", &T);
        
    while (T--)
    {
        scanf("%d", &n);
        
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            varray[i]=NULL;
        }
        
        
        
        for (i = 0; i < n-1; i++)
        {
            scanf("%d%d", &a, &b);
            varray[a]=insert(varray[a], b);
            varray[b]=insert(varray[b], a);        
        }
        
        dfs(1,0);
        memset(visited,0,sizeof(visited));
       
        int max = 0;
        int chut;
        
        for(i=1;i<=n;i++)
        {
            if (heightarray[i] > max)
            {
                max = heightarray[i];
                chut=i;
            }
        }
        memset(heightarray,0,sizeof(heightarray));
        dfs(chut,0);
        for(i=1;i<=n;i++)
        {
            if (heightarray[i] > max)
            {
                max = heightarray[i];
            }
        }
        printf("%d\n",max);
        
    }
    
    
    
    
    return 0;
}
