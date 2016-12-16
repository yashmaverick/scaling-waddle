#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    char str[100];
    struct node* next;
}node;
int main()
{
int n,N,s=0,i;
char c;
scanf("%d",&N);
node* end=(node*)malloc(sizeof(node));
node *begin=end;
for(i=0;i<N-1;i++)
{
end->next=(node*)malloc(sizeof(node));
end=end->next;
}
end->next=begin;
end=end->next;
scanf("%c",&c);
while(c!='Q')
{
    if(c=='A')
    { 
        scanf("%d",&n);
        while(n--)
        {   s++;
            if(s<=N)
            {
                scanf("%s",end->str);
                end=end->next;
            }
            else
            {   s=N;
               
                begin=begin->next;
                scanf("%s",end->str);
                end=end->next;
            }
        }
    }
    else if(c=='R')
    {
        scanf("%d",&n);
        s=s-n;
        while(n--)
        {
            begin=begin->next;
        }
        
    }
    else if(c=='L')
    {
        node* copy=begin;
        int k=s;
        if (k!=0)
        {
        while(k--)
        {
            printf("%s\n",copy->str);
            copy=copy->next;
        }
        }
    }
    scanf("%c",&c);
}

return 0;
}
