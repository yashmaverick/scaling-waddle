#include<stdio.h>

int max1(int a, int b) {if(a>b) return a; else return b;}
int min1(int a, int b) {if(a<b) return a; else return b;}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int price,min=-1,max=0;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&price);
            if(min==-1)min=price;
            min = min1(min,price);
            max = max1(max,price-min);
        }
        printf("%d\n",max);
    }
}
