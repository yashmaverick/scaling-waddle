#include<stdio.h>
int main()
{
	int i,t,o,n,q,min,max,g,b[100000],c[100000],maxd,a[100000];
	
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{  scanf("%d",&n);
		for(q=0;q<n;q++)
		  {
			scanf("%d",&a[q]);
		  }  
		min=a[0];
		b[0]=a[0];
		for(q=1;q<n;q++)
		  {
			if(a[q]<min)
			{	min=a[q];
				b[q]=min; 
			}
			else
				b[q]=min;
		  }
		max=a[n-1];
		c[n-1]=max;
		for(q=n-1;q>=0;q--)
		{     if(a[q]>max)
			{
				max=a[q];
			        c[q]=max;
			}
			else 
				c[q]=max;
		}
		maxd=0;
		for(g=0;g<n;g++)
		{if(c[g]-b[g]>=maxd)
			maxd=c[g]-b[g];
		}/*for(o=0;o<n;o++)
		{printf("%d ",b[o]);}
		printf("\n");
		for(o=0;o<n;o++)
               {printf("%d ",c[o]);}*/


		printf("%d\n",maxd);
	}
	return 0;

	}




