#include<stdio.h>
int main()
{ int t;
	scanf("%d",&t);
	while(t--)
{       long long int p,n,a,b,max=0,min=0,pro=0;        
        scanf("%lld",&n);
        scanf("%lld",&b);
        min=b;n--;
        max=b;
        while(n--)
      {  scanf("%lld",&a);
        if(min>a)
      {  min=a;
        max=0;
        }
        if(max<a)
        max=a;
        if(pro<(max-min))
                pro=(max-min);
        }
printf("%lld\n",pro);
}
return 0;
}
