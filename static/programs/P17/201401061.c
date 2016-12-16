#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,t,j=0,n,*a,*b,*c,x,y,m,k,f,z;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	c=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	while(j<t)
	{
	       	scanf("%d %d",&x,&y);
                i=0;
		z=0;
		m=0;
		while(i<n)
		{
			//printf("i=%d\n",i);
			if((b[i]==x||b[i]==y)&&(m==0))
			{
				//printf("blah");
				m++;
				if(b[i]==x)
					k=y;
				else
					k=x;
				c[0]=b[i];
				z++;
			}
			else if(m==1)
		        {
		              	c[z]=b[i];
				z++;
			}
			if(b[i]==k&&m==1)
				break;
		        i++;
		}
		//for(i=0;i<z;i++)
		//printf("c[i]=%d\n",c[i]);
	        i=0;
		f=0;
		while(i<n)
		{
			//printf("%d\n",a[i]);
			k=0;	
			while(k<z)
			{
				if(a[i]==c[k])
				{
					m=a[i];
					f++;
					break;
				}
				k++;
			}
			if(f==1)
				break;
			i++;
		}
		//else
		//	m=k;
		printf("%d\n",m);
		j++;
	}
        return 0;
}
