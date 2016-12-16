#include<stdio.h>
#include<stdlib.h>

int i;
#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)
#define outstr(str) printf("%s\n" , str)
#define loop(initial , final , jump) for(i=initial ; i<final ; i=i+jump)
#define iter(end) loop(0 , end , 1)
int pre[10005];
int in[10005];
int candid[10005];

int main()
{
    int N , t , node1 , node2 ;
    ini(N);
    iter(N)
        ini(pre[i]);
    iter(N)
        ini(in[i]);
    ini(t);
    while(t--)
    {
        int k = 0 , j = 0 , flag = 0;
        ini(node1);
        ini(node2);
        if(node1 == node2)
            outi(node1);
        else
        {
            while(in[j]!=node1 && in[j]!=node2)
                j++;
            candid[k++] = in[j++];
            while(in[j]!=node1 && in[j]!=node2)
                candid[k++] = in[j++];
            candid[k++] = in[j++];
//             iter(k)
//                 outi(candid[i]);
//                 outstr("");
            for(j=0 ; j<N && flag == 0 ; j++)
            {
                iter(k)
                {
                    if(candid[i] == pre[j])
                    {
                        outi(candid[i]);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}