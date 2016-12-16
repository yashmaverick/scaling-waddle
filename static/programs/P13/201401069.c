#include<stdio.h>
typedef struct number{
    int nu;
    int depth;
}A;
int B[100001],t,N,count=0,i,max_depth=0,in_dex,min_nu=1000000;
A C[100001];
void check()
{
    if(C[count].depth>max_depth)
    {
	   max_depth=C[count].depth;
	   min_nu=C[count].nu;
	   in_dex=count;
    }
    else if(C[count].depth==max_depth && C[count].nu<min_nu)
    {
	   in_dex=count;
	   min_nu=C[count].nu;
    }
//    printf("min_nu=%d max_depth=%d\n",min_nu,max_depth);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
    	   min_nu=1000000;
    	   max_depth=0;
	   count=0;
	   scanf("%d",&N);
	   for(i=(N-1);i>=0;i--)
	   {
		  scanf("%d",&B[i]);
	   }
	   C[count].nu=B[0];
	   C[count].depth=0;
	   check();
	   for(i=1;i<N;i++)
	   {
		  if(B[i]>C[count].nu)
		  {
			 count++;
			 C[count].nu=B[i];
			 C[count].depth=(C[count-1].depth)+1;
			 check();
		  }
		  else
		  {
			 while(B[i]<C[count].nu)
			 {
				count--;
				if(count==-1)
				    break;
			 }
			 count++;
			 C[count].nu=B[i];
			 C[count].depth+=1;
			 check();
		  }
	   }
	   printf("%d %d\n",min_nu,max_depth);
    }
    return 0;
}
