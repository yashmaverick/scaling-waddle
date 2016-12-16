#include<stdio.h>
#include<stdlib.h>
int main()
{int n,i,t,x,y,k,c[100010],a[100010],b[100010],index1,index2,min,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&t);
	while(t--)
	{  scanf("%d%d",&x,&y);
	   for(i=0;i<n;i++)
	   {	   if(b[i]==x)
			   index1=i;
	            if(b[i]==y)
			    index2=i;
	    }
	   k=0;
	   if(index1==index2)
			   printf("%d\n",b[index1]);
	   else
               {if(index1<index2)
	   {	   for(i=index1;i<=index2;i++)
			   c[k++]=b[i];
	   }

	   if(index1>index2)
	   {	   for(i=index2;i<=index1;i++)
			   c[k++]=b[i];
	   }
	   //min=100020;
	  int h,flag=0; 
	   for(i=0;i<n;i++)
	   {for(j=0;j<k;j++)
	   {      if(a[i]==c[j])
		   {h=a[i];
			   flag=1;
			   break;
		   }
	   }
		   if(flag==1)
			   break;
	   }
	   
          printf("%d\n",h);
	}
	}
return 0;
}
