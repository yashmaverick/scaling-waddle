#include<stdio.h>
#define g(x) scanf("%lld",&x)
long long int max_left,max_right,query;
void make_tree(long long int value,long long int level)
{
    if(value>query)
    {
        if(level>max_left)
            max_left=level;
        return ;
    }

        level++;
        make_tree(2*value,level);
//        make_tree(2*value+1,level);
}
void make_trees(long long int value,long long int level)
{//printf("%lld ",level);

    if(value>query)
    {
        if(level>max_right)
            max_right=level;
        return ;}
    
        level++;
        make_trees(2*value,level);
  //      make_trees(2*value+1,level);
    }
int main()
{
    long long int t,n,i,j,level;
    g(t);
    for(i=0;i<t;i++)
    {g(query);
        max_left=0;
        max_right=0;
        level=0;
        make_trees(2,level);
        make_tree(3,level);
        printf("%lld\n",max_left+max_right);
    }
    return 0;
}






