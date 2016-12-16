#include<stdio.h>
//#include<conio.h>
void pushtop(int *q,int *top,int val)
{
        (*top)++;
	q[*top]=val;

}
void poptop(int *top)
{
     (*top)--;
}
void popbottom(int *bottom)	
{   
	(*bottom)++;
}
int main()
{int t;
        
	scanf("%d",&t);
	while(t--)
	{int top=-1,bottom=0;
	int n,k,i,a[100010],q[100010];
	scanf("%d%d",&n,&k);
	a[0]=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	pushtop(q,&top,1);
	for(i=2;i<=k;i++)
	{	while((top!=-1)  && a[i]<=a[q[top]])
		{
			poptop(&top);
		
		}
	
	pushtop(q,&top,i);
	}
	  
int j;	
	for(j=i;j<=n;j++)
        {
		printf("%d ",a[q[bottom]]);
		while((bottom<=top) && q[bottom]<=j-k)
			popbottom(&bottom);
		while((top>=bottom) && a[j]<=a[q[top]])
			poptop(&top);
		pushtop(q,&top,j);
	}
	printf("%d",a[q[bottom]]);
	printf("\n");
	}
	return 0;
}
