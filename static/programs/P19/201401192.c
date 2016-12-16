//Data Structures Assignment, P19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int end;
    struct node *next[10];
}node;

int testCases, nos; 
char number[10]; 
node *root;

int checkBuildTry(node *cur_node, char *no)
{
    int digit, i, res = 1;
    node *new;
    digit = no[0]-'0';
//    printf("digit is %d\n", digit);
    if(cur_node->next[digit] == NULL)
    {
        res = 0;
//        printf("path to %d doesn't exist; creating...\n", digit);
        new = (node*) malloc(sizeof(node));
        new->end = 0;
        for(i = 0; i < 10; i++)
        {
            new->next[i] = NULL;
        }
        cur_node->next[digit] = new;
        cur_node = new;
//        printf("assigned to cur_node\n");
        if(strlen(no) != 1)
        {
//            printf("going to next digit\n");
            res = checkBuildTry(cur_node, no+1);
        }
    }
    else
    {
//        printf("path to %d exists; continuing...\n", digit);
        cur_node = cur_node->next[digit];
        if(cur_node->end)
        {
//            printf("prefix found\n");
            return 1;
        }
        if(strlen(no) != 1)
        {
            res = checkBuildTry(cur_node, no+1);
        }
    }
    if(strlen(no) == 1)
    {
//        printf("end of number\n");
        cur_node->end = 1;
    }
    return res;
}

void freeTree(node *cur_node)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        if(cur_node->next[i] != NULL)
        {
            freeTree(cur_node->next[i]);
        }
    }
    free(cur_node);
    return;
}

int main()
{
    int i, isPrefix;
    scanf("%d", &testCases);
    while(testCases--)
    {
        root = (node*) malloc(sizeof(node));
        root->end = 0;
        for(i = 0; i < 10; i++)
        {
            root->next[i] = NULL;
        }
        scanf("%d", &nos);
        isPrefix = 0;
        while(nos--)
        {
            scanf("%s", number);
            if(!isPrefix)
            {
                isPrefix = checkBuildTry(root, number);
            }
        }
        if(!isPrefix)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        freeTree(root);
    }
    return 0;
}
