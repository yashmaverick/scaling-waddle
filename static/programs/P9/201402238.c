#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
struct evil
{       ll  out;
        ll  count;
        ll *weigh;    
};
int main()
{  ll n,odd,m,a,i,j,temp;

        struct evil arr[1000],lol;        
        
        scanf("%lld %lld",&n,&odd);
                for(i=0;i<n;i++)
                {       scanf("%lld",&m);
                                arr[i].count=m;
                        arr[i].weigh=(ll*)malloc(sizeof(ll)*m);
                        arr[i].out=0;
                        while(m--)
                        {       scanf("%lld",&a);
                                arr[i].weigh[m]=a;
                                arr[i].out+=a;
                                arr[i].out=arr[i].out%odd;
                        }
                }
                
                for(i=1;i<n;i++)
                {       temp=arr[i].out;lol=arr[i];
                for(j=i;j>0 && arr[j-1].out>temp;j--)
                        arr[j]=arr[j-1];
                        
                                        arr[j].out=temp;
                                              arr[j]=lol;  
                }
                
                for(i=0;i<n;i++)
                {      printf("%lld\n",arr[i].out);
                        for(j=(arr[i].count-1);j>=0;j--)
                                printf("%lld\n",arr[i].weigh[j]);
                                printf("\n");
                }
                
return 0;
}
