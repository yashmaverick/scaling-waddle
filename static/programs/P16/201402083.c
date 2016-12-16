
/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,count,temp,n,q,height;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        count=0;
        scanf("%d",&q);
        temp=q;
        if(q==1) printf("0\n");
        else{
        while( (temp | 0) != 0) {temp=temp>>1; count++;}
        height=count-1;
        if( (q>> count-2) & 01 == 1) printf("%d\n",2*height);
        else printf("%d\n",2*height-1 );
        }
    }
return 0;
}
