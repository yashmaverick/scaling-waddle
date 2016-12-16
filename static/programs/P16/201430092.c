#include<stdio.h>
#include<math.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
	int Q,H,mid;
	scanf("%d",&Q);
	H = log(Q)/log(2);
        mid = (pow(2,H)*3-1)/2;
        if(Q==1)
           printf("0\n");
	else if(Q<=mid)
	    printf("%d\n",2*H-1);
	else if(Q>mid)
	    printf("%d\n",2*H);
    }
	return 0;
}
