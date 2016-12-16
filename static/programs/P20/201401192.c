// Data Structures Assignment, P19

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXNODES 1000000

typedef struct node
{
    int nodeNo;
    struct node *next;
}node;

int testCases, nodes, vx, vy, pathLength, maxpath;
node *adjList[MAXNODES];

void addHalfEdge(int vx, int vy)
{
    node *new;
    new = (node*) malloc(sizeof(node));
    new->nodeNo = vy;
    if(adjList[vx-1] != NULL)
    {
        new->next = adjList[vx-1];
        adjList[vx-1] = new;
    }
    else
    {
        new->next = NULL;
        adjList[vx-1] = new;
    }
    return;
}

int deepestNode(int curNode, int parent)
{
//    printf("reached node %d\n", curNode);
    int res = INT_MIN, test_res;
    node *trav;
    pathLength++;
//    printf("path length is %d\n", pathLength);
    trav = adjList[curNode-1];
    while(trav != NULL)
    {
//        printf("going to child node %d and my parent is %d\n", trav->nodeNo, parent);
        if(trav->nodeNo != parent)
        {
            test_res = deepestNode(trav->nodeNo, curNode);
        }
        if(test_res > res)
        {
            res = test_res;
        }
        trav = trav->next;
    }
    if(pathLength > maxpath)
    {
        maxpath = pathLength;
        res = curNode;
//        printf("maxpath is %d, so ans is %d\n", maxpath, curNode);
    }
    pathLength--;
    return res;
}

int main()
{
    int root, first = 1, i, deep, moot;
    scanf("%d", &testCases);
    while(testCases--)
    {
        scanf("%d", &nodes);
        nodes--;
        if(!first)
        {
            for(i = 0; i < MAXNODES; i++)
            {
                adjList[i] = NULL;
            }
        }
        while(nodes--)
        {
            scanf("%d %d", &vx, &vy);
            addHalfEdge(vx, vy);
            addHalfEdge(vy, vx);
            if(first)
            {
                root = vx;
            }
            first = 0;
        }
//        printf("tree built\n");
//        printf("doing a dfs from root: %d\n", root);
        pathLength = -1;
        maxpath = INT_MIN;
        deep = deepestNode(root, -1);
//        printf("!!! deepest node from root is %d\n", deep);
        pathLength = -1;
        maxpath = INT_MIN;
        moot = deepestNode(deep, -1);
        printf("%d\n", maxpath+1);
    }
    return 0;
}
