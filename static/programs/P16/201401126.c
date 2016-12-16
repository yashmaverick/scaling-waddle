/* ALGORITHM:
 * Find the number of levels in the tree using the formula, 
 *                              number of levels = log2(q); (where q -> query)  // function used to perform this in the program is level()
 * Now the diameter of a binary tree is basically the maximum distance between 2 nodes, of which one is in the left subtree and the other is the
 * right subtree via the root.
 *
 * The left-most element on each level is an integral power of 2. Also, this element is equal to the number of elements present at that
 * particular level.
 *
 * The diameter of the BT(Binary Tree) depends on whether the deepest leaf node ( with value equal to that of the query ) is in the left-subtree
 * or right-subtree wrt to the root node. If the leaf node is in the left subtree then,
 *                                      diameter = ( 2 * levels ) - 1
 *                              else if it is in the right subtree then.
 *                                      diameter = ( 2 * levels)
 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef unsigned long long int ll;

ll powmod(ll a,ll b);//Lalit Kundu DS Lab

ll level(ll q)
{
    ll count=0;

    while(q>1)
    {
        q/=2;
        count++;
    }

    return count;
}

int main()
{
    ll n,q,temp,x,diameter,urange,lrange;

    scanf("%llu",&n);

    while(n-->0)
    {
        scanf("%llu",&q);

        if(q==1)
            diameter=0;
        else
        {

            x=level(q);

            lrange=powmod(2,x);// lower range for left subtree values
            urange=3*(lrange/2);// lower range for right subtree values

            if(lrange<=q && q<urange)
                diameter=(2*x)-1;
            else
                diameter=(2*x);
        }

        printf("%llu\n",diameter);

    }

    return 0;
}

ll powmod(ll a,ll b)//Lalit Kundu DS Lab
{
    if(b==0)
        return  1;
    if(b==1)
        return a;
    ll x=powmod(a,b/2);
    ll y=(x*x);
    if(b%2)
        return (a*y);
    return y;
}
