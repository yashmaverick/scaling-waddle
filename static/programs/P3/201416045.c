#include<stdio.h>
int main()
{
	int m,i,j,temp,k,n,a[1000000],max=0,q;
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		max=0;q=0,temp=0;
		scanf("%d",&n);
		for(k=0;k<n;k++)
		{
			scanf("%d",&a[k]);
		}
               // for(k=0;k<n;k++)
                //{
                 // printf("a:%d",a[k])
		for(m=n-1;m>0;m--)
		//	q=0;max=0;
                {
                  //printf("m:%d\n",m);
		
			if(a[m]>a[m-1])
			{	
				q=a[m]-a[m-1];
				//printf("q:%d\n",q);
				if(max<q)
				{
					max=q;
				}
				temp=a[m-1];
				a[m-1]=a[m];
				a[m]=temp;
		}
			//printf("%d ",q);
		}


		if(max<0)
		{
			printf("0");
		}
		else
		{
			printf("%d\n",max);
		}
	}
	return 0;
}






