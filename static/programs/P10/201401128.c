
/*
_____________________________________________

PURPOSE : 

		created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    char str[101];
    struct node *next;
};

typedef struct node ELEMENT;
typedef ELEMENT* LINK;

LINK head,START,END;

void append(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(START==NULL)
        {
            START=head;
            scanf("%[^\n]",START->str);
            getchar();
            END=START;
        }
        else
        {
          if(END->next==START)
              START=START->next;
          END=END->next;
          scanf("%[^\n]",END->str);
          getchar();
        }
    }
}

void Remove(int n)
{
        
    if(START==NULL)
            return;
    int i;
    for(i=0;i<n;i++)
    {
        if(START==END)
        {
            START=END=NULL;
            break;
        }
        START=START->next;
    }
}

void print()
{
    LINK temp;
    temp=START;
    while(temp!=END)
    {
        printf("%s\n",temp->str);
        temp=temp->next;
    }
    if(temp!=NULL)
    printf("%s\n",temp->str);
}


int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    //printf("%lu %lu\n",sizeof(ELEMENT),sizeof(LINK));

    START=END=NULL;
    LINK prev,cur;
    cur=(LINK)malloc(sizeof(ELEMENT));
    cur->next=NULL;
    head=cur;

    int i;
    for(i=1;i<n;i++)
    {
      prev=cur;
      cur=(LINK)malloc(sizeof(ELEMENT));
      cur->next=NULL;
      prev->next=cur;
    }
    cur->next=head;
    
    char input;
    int arg;
    while((input=getchar())!='Q')
    {
        getchar();
        switch(input)
        {
            case 'A':
                     scanf("%d",&arg);
                     getchar();
                     append(arg);
                     break;
            case 'R':
                     scanf("%d",&arg);
                     getchar();
                     Remove(arg);
                     break;
            case 'L':
                     print();
        }
    }


return 0;
}
