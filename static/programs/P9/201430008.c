#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int s;
	int f;
	int l;
}node;
struct node c[1000];
       void bsort(node c[],int n)
        {
                 int i,j;
                 for(i=0;i<n;i++)
                 for(j=0;j<n-i-1;j++)
                        if(c[j].s>c[j+1].s)
                        {
                              struct node temp=c[j];
                               c[j]=c[j+1];
                               c[j+1]=temp;
                        }
         }

int main()
{
	int n,i,q=0,v=0,r=0,a[1000001],x=0,y=0,sum=0,g,h,M,p=0;
	scanf("%d %d",&n,&M);
	int b[2*n];
	for(i=0;i<n;i++)
	{
		int m,j;
		scanf("%d",&m);
		sum=0;
                for(j=0;j<m;j++)
		{
			int w;
			scanf("%d",&w);
			a[q]=w;
			sum=(sum%M+a[q]%M)%M;
			q++;
			
		}
	//	v=j+m;
	//	q=v;
	        b[r]=x;
		b[r+1]=b[r]+m-1;
	x=m+x;
		c[y].s=sum;
		c[y].f=b[r];
		c[y].l=b[r+1];
		y++;
		r=r+2;
	}
 bsort(c,n);
	 for(g=0;g<n;g++)
	 {
		 printf("%d\n",c[g].s);
		 for(h=c[g].f;h<=c[g].l;h++)
		 {
			 printf("%d\n",a[h]);
		 }
		 printf("\n");
	 }
return 0;
}

