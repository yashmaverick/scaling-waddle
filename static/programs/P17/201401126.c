#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;

ll preorder[1000000],inorder[1000000];
ll pmin,pmax;
ll l,r;
ll min,max;

int main()
{
    ll n,i,j,a,b,lca,t; // a -> 1st node input ; b -> 2nd node input

    int flag=0;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&preorder[i]);
    for(i=0;i<n;i++)
        scanf("%lld",&inorder[i]);

//    scanf("%lld %lld",&a,&b);

    scanf("%lld",&t);

    while(t-->0)
    {
        scanf("%lld %lld",&a,&b);

        flag=0;

        for(i=0;i<n;i++)
        {
            if(preorder[i]==a)
            {
                pmin=i;
                min=a;
                max=b;
                break;
            }
            else if(preorder[i]==b)
            {
                pmin=i;
                min=b;
                max=a;
                break;
            }
        }

        for(i=0;i<n;i++)
        {
            if(inorder[i]==min || inorder[i]==max)
            {
                l=i;
                break;
            }
            /*
            if(inorder[i]==max)
            {
                r=i;
                break;
            }
            */
        }

        
        for(i+=1;i<n;i++)
        {
            if(inorder[i] == min || inorder[i] == max)
            {
                r=i;
                break;
            }
        }

        flag=0;

        for(i=0;i<=pmin && flag==0;i++)
        {
            for(j=l;j<=r && flag==0 ;j++)
            {
                if(preorder[i]==inorder[j])
                {
                    lca=inorder[j];
                    //printf("%lld\n",lca);
                    flag=1;
                    break;
                }
            }
        }

        //printf("pmin= %lld; min= %lld; max= %lld; l= %lld; r= %lld; lca= %lld\n",pmin,min,max,l,r,lca);
        printf("%lld\n",lca);
    }

    return 0;
}
