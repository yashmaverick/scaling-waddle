#include<stdio.h>

typedef struct node
{
    int val;
    int idx;
}node;

int main()
{
    int n,i,t,x,y;
    scanf("%d",&n);
    node pre[n],in[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&pre[i].val);
        pre[pre[i].val].idx=i;
    }
    node root;

    root.val=pre[0].val;

    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i].val);
        if(in[i].val==root.val)
            root.idx=i;
        in[in[i].val].idx=i;
    }
    //    printf("root:%d\n",root.val);
    
    for(scanf("%d",&t);t--;)
    {
        scanf("%d%d",&x,&y);
        //        printf("x_idx:%d y_idx:%d root_idx:%d\n",in[x].idx,in[y].idx,root.idx);
       
        if((in[x].idx>=root.idx && in[y].idx<=root.idx) || (in[x].idx<=root.idx && in[y].idx>=root.idx))
        {
            //      printf("IN IF\n");
            printf("%d\n",root.val);
        }
        
        else
        {
            int s,e,lca;
            s=in[x].idx < in[y].idx ? in[x].idx:in[y].idx;
            e=in[x].idx < in[y].idx ? in[y].idx:in[x].idx;
            i=s;
            int j=e;
            //          printf("s:%d e:%d\n",s,e);
            int s1=pre[in[s].val].idx,s2=pre[in[e].val].idx;
            //          printf("s1:%d s2:%d\n",s1,s2);
            while(i!=j+1)
            {
                //                  printf("%d\n",pre[in[i].val].idx);
                if(pre[in[i].val].idx<=s1 && pre[in[i].val].idx<=s2)
                    lca=in[i].val;
                i++;
            }
            printf("%d\n",lca);
        }
    }        
    return 0;
}



