#include <stdio.h>

#define NODE struct node
#define LINK struct node*

typedef struct node {
    int used;
    char str[107];
    struct node* next;
};

struct node* head;
struct node* tail;

int n, size;

void input()
{
    size = 0;
    scanf("%d",&n);
}
void prep()
{
    int i;
    
    head = malloc(sizeof(NODE));
    tail = head;
    head->used = 0;
    
    for(i=1;i<n;++i)
    {
        LINK new = malloc(sizeof(NODE));
        new->used = 0;
        
        tail->next = new;
        tail = new;
    }
    
    tail->next = head;
    tail = head;
}
void solve()
{
    while(1)
    {
        char command;
        scanf(" %c",&command);
        
        if(command == 'A')
        {
            int m, i;
            scanf("%d",&m);
            
            for(i=0;i<m;++i)
            {
                if(tail->next == head)
                {
                    head = head->next;
                }
                tail->used = 1;
                scanf(" %s",tail->str);
                
                tail = tail->next;
            }
        }
        else if(command == 'R')
        {
            int m, i;
            scanf("%d",&m);
            
            for(i=0;i<m;++i)
            {
                head->used = 0;
                head = head->next;
            }
        }
        else if(command == 'L')
        {
            LINK ptr = head;
            while(ptr!=tail)
            {
                printf("%s\n",ptr->str);
                ptr = ptr->next;
            }
        }
        else
            return;
    }
}

int main()
{
    input();
    prep();
    solve();
    
    return 0;
}