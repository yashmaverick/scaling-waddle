#include<stdio.h>
#include<string.h>

//const int MAX=1000000;
char myqueue[10005][105];
int start=-1,end=-1;
int size;
void append(char word[])
{
    if(start==-1 && end==-1)
    {
        start=end=0;
        strcpy(myqueue[start],word);
    }
    else if(end==size-1 && start==0)
    {
        strcpy(myqueue[start],word);
        end=start;
        start++;
    }
    else if(end==start-1)
    {
        strcpy(myqueue[start],word);
        end=start;
        if(start==size-1)
            start=0;
        else
        start++;
    }
    else if(end==size-1)
    {
        end=0;
        strcpy(myqueue[end],word);
    }
    //else if(start==size-1)

    else
    {
        end++;
        strcpy(myqueue[end],word);
    }
//    printf("%d %d\n",start,end);
}

void rem()
{
    if(start==-1)
       return;

    if(start==end)
        start=end=-1;
    else if(start!=size-1)
        start++;
    else if (start==size-1)
        start=0;

}

void list()
{
    int pos=start;
    int i;
    if(start!=-1 && end!=-1)
    {
        if(start<=end)
        {
            for(i=start;i<=end;i++)
                printf("%s\n",myqueue[i]);
        }
        else 
        {
            for(i=start;i<size;i++)
                printf("%s\n",myqueue[i]);
                
            for(i=0;i<=end;i++)
                printf("%s\n",myqueue[i]);
        }
    }
    fflush(stdout);
}

int main()
{
    char choice;
    int n;
    char word[105];
    scanf("%d",&size);
    int i;

    do
    {
        scanf("%c",&choice);
        if(choice=='A')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%s",word);
                append(word);
            }
        }
        else if(choice=='R')
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                rem();
        }
        else if(choice=='L')
            list();
        else if(choice=='Q')
           break;
     }while(choice!='Q');
    return 0;
}
