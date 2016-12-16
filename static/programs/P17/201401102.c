#include<stdio.h>
#define min(a,b) ((a<b)? a:b)
#define max(a,b) ((a>b)? a:b)
//Preorder=chocos
//Inorder=muesli
//Snow=flakes
//Flag=india
//White=milk
long long int chocos[1000000],muesli[1000000],i;
int main()
{
        long long int i,n,t,j,k,l,m,flakes,milk,flakes_index,milk_index,india;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
                scanf("%lld",&chocos[i]);
        for(i=0;i<n;i++)
                scanf("%lld",&muesli[i]);
        scanf("%lld",&t);
        for(i=0;i<t;i++)
        {
                scanf("%lld%lld",&flakes,&milk);
                for(j=0;j<n&&muesli[j]!=flakes;j++);
                flakes_index=j;
                for(j=0;j<n&&muesli[j]!=milk;j++);
                milk_index=j;
                j=min(flakes_index,milk_index);
                k=max(flakes_index,milk_index);
                india=0;
                for(l=0;l<n;l++)
                {
                        for(m=j;m<=k;m++)
                                if(chocos[l]==muesli[m])
                                {
                                        india=1;
                                        break;
                                }
                        if(india==1)
                                break;
                }
                printf("%lld\n",chocos[l]);
        }
        return 0;
}
