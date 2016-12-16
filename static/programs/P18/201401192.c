// Data Structures Assignment, P18

#include <stdio.h>
#include <stdlib.h>

#define MAXREALMS 1000

typedef struct warrior
{
    int warNo;
    struct warrior *next;
}warrior;

int testCases, realms, nofStronger, warNo, visited[MAXREALMS], visitCount;
warrior *wT[MAXREALMS], *sT[MAXREALMS];

void add_wT(int x, int y)
{
    warrior *new;
    new = (warrior*) malloc(sizeof(warrior));
    new->warNo = y;
    if(wT[x-1] == NULL)
    {
        new->next = NULL;
        wT[x-1] = new;
    }
    else
    {
        new->next = wT[x-1];
        wT[x-1] = new;
    }
    return;
}

void add_sT(int x, int y)
{
    warrior *new;
    new = (warrior*) malloc(sizeof(warrior));
    new->warNo = y;
    if(sT[x-1] == NULL)
    {
        new->next = NULL;
        sT[x-1] = new;
    }
    else
    {
        new->next = sT[x-1];
        sT[x-1] = new;
    }
    return;
}

void dfs_sT(int curNode)
{
    if(visited[curNode-1])
    {
//        printf("already visited\n");
        return;
    }
    visited[curNode-1] = 1;
    visitCount++;
//    printf("visitCount incremented to %d\n", visitCount);
    warrior *trav;
    trav = sT[curNode-1];
    while(trav != NULL)
    {
//        printf("going to child %d\n", trav->warNo);
        dfs_sT(trav->warNo);
        trav = trav->next;
    }
    return;
}

void dfs_wT(int curNode)
{
    if(visited[curNode-1])
    {
//        printf("already visited\n");
        return;
    }
    visited[curNode-1] = 1;
    visitCount++;
//    printf("visitCount incremented to %d\n", visitCount);
    warrior *trav;
    trav = wT[curNode-1];
    while(trav != NULL)
    {
//        printf("going to child %d\n", trav->warNo);
        dfs_wT(trav->warNo);
        trav = trav->next;
    }
    return;
}

void clearVisited(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    int i, j, found;
    scanf("%d", &testCases);
    while(testCases--)
    {
        visitCount = 0;
        found = 0;
        scanf("%d", &realms);
        for(i = 0; i < realms; i++)
        {
            scanf("%d", &nofStronger);
            while(nofStronger--)
            {
                scanf("%d", &warNo);
                add_wT(i+1, warNo);
                add_sT(warNo, i+1);
            }
        }
//        printf("who beat everyone?\n");
        for(i = 0; i < realms; i++)
        {
//            printf("was it %d\n", i+1);
            dfs_sT(i+1);
            clearVisited(realms);
            if(visitCount == realms)
            {
//                printf("it was!\n");
                found = 1;
                break;
            }
            visitCount = 0;
        }
        visitCount = 0;
        if(found)
        {
            clearVisited(realms);
//            printf("who all can beat %d?\n", i+1);
            dfs_wT(i+1);
        } 
        printf("%d\n", visitCount);
        for(j = 0; j < realms; j++)
        {
            visited[j] = 0;   
            wT[j] = NULL;
            sT[j] = NULL;
        }       
    }
    return 0;
}
