#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nn
{
    int data;
    int end;
    struct nn *values[11];
}node;

node *makeNode();
int insert_Num(char word[] ,node *root);

int main()
{
    int i , cases ,test;
    char word[11];
    int answer = 0;
    scanf("%d",&test);
    while(test--)
    {   
        node *root=makeNode();
        answer = 0;
        scanf("%d",&cases);
        while(cases--)
        {
            scanf("%s",word);
            answer = answer + insert_Num(word,root);
        }
        if(answer == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

node *makeNode()
{
    int i;

    node *Node=(node*)malloc(sizeof(node));
    Node->data= -1;
    Node->end = -1;

    for(i=0;i<11;i++)
        Node->values[i]=NULL;

    return Node;
}

int insert_Num(char word[] ,node *root)
{
    node *Trie=root;
    int length=strlen(word);
    int i=0;
    int index;
    int control = 0;

    for(i=0;i<length;i++)
    {
        index = (int)(word[i]-'0');

        if(Trie->end != 1)
            Trie->end = 0;

        if(Trie->end == 1)
            control = 1;


        if((Trie->values[index])==NULL)
            Trie->values[index]=makeNode();

        Trie=Trie->values[index];
    }

    if (control == 1)
        return control;

    if(Trie->end == 0)
    {
        Trie->end = 1;
        return 1;
    }

    if(Trie->end == 1)
        return 1;

    else
    {
        Trie->end = 1;
        return 0;
    }
    Trie->data=i;
}
