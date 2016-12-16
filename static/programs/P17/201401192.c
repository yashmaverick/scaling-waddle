//Data Structures Assignment, P17

#include<stdio.h>

int nodes, preOrder[1000001], inOrder[1000001], testCases, pos_js, pos_ww;

int main()
{
    int i, index;
    scanf("%d", &nodes);
    for(i = 0; i < nodes; i++)
    {
        scanf("%d", &preOrder[i]);
    }
    for(i = 0; i < nodes; i++)
    {
        scanf("%d", &index);
        inOrder[index] = i;
    }
/*    printf("index array: ");
    for(i = 0; i < nodes; i++)
    {
        printf("%d ", inOrder[i]);
    }
    printf("\n");*/
    scanf("%d", &testCases);
    while(testCases--)
    {
        scanf("%d %d", &pos_js, &pos_ww);
        for(i = 0; i < nodes; i++)
        {
            if(inOrder[preOrder[i]] <= inOrder[pos_js] && inOrder[preOrder[i]] >= inOrder[pos_ww])
            {
                printf("%d\n", preOrder[i]);
                break;
            }      
            if(inOrder[preOrder[i]] >= inOrder[pos_js] && inOrder[preOrder[i]] <= inOrder[pos_ww])
            {
                printf("%d\n", preOrder[i]);
                break;
            }
        }
    }
    return 0;
}
