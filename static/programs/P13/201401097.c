#include<stdio.h>

typedef struct node
{
	long long int no;
	long long int height;
}node;
int main ()
{
	long long int i,j,k,q,m,count=0,n,top=-1,height=0,hno=0,a[100005];

       	node node[100005];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		top=-1;
		height=0;
		
		for(j=0;j<k;j++)
		{
                    scanf("%lld",&a[j]);
		}
		hno=a[k-1];
		j=j-1;
		q=j;
		for(;(j>=0);--j)
		{

		   if(top==-1) 
		   {
			  
			   node[++top].no=a[j];
			   node[top].height=0;
		   }
		   else if(a[j]>node[top].no)
		   {
			   node[++top].no=a[j];
			   node[top].height=node[top-1].height+1;
			   if(node[top].height>=height)
			   {
				   if((node[top].height==height)&&(node[top].no<hno))
				   {
				   height=node[top].height;
				   hno=a[j];
				   }
				   else if(node[top].height!=height)
				   {
					   height=node[top].height;
				   hno=a[j];
				   

				   }
			   }

		   }
		   else if(a[j]<node[top].no)
		   {
			   while((a[j]<node[top].no)&&(top!=-1))
			   {
				  --top;

			   }
			    count=node[top+1].height;
 
			   node[++top].no=a[j];
			   node[top].height=count+1;
			   if(node[top].height>=height)
			   {
				    if((node[top].height==height)&&(node[top].no<hno))
				   {
				   height=node[top].height;
				   hno=a[j];
				   }
				   else if(node[top].height!=height)
				   {
					   height=node[top].height;
				   hno=a[j];
				   

				   }
				  
			   }




		   }
                    
		}
			   
/*	
		node[0].no=a[j];
		top=0;
		node[0].height=1;
		  if((node[top].height>=height)&&(j!=-1))
			   {
				   if((node[top].height==height)&&(node[top].no<hno))
				   {
				   height=node[top].height;
				   hno=a[j];
				   }
				   else if(node[top].height!=height)
				   {
					   height=node[top].height;
				   hno=a[j];
				   

				   }
			   }
			

		for(;j>=0;--j)
		{

		   if(top==-1) 
		   {
			  
			   node[++top].no=a[j];
			   node[top].height=0;
		   }
		   else if(a[j]>node[top].no)
		   {
			   node[++top].no=a[j];
			   node[top].height=node[top-1].height+1;
			   if(node[top].height>=height)
			   {
				   if((node[top].height==height)&&(node[top].no<hno))
				   {
				   height=node[top].height;
				   hno=a[j];
				   }
				   else if(node[top].height!=height)
				   {
					   height=node[top].height;
				   hno=a[j];
				   

				   }
			

				   
				   
			   }

		   }
		   else if(a[j]<node[top].no)
		   {
			   while((a[j]<node[top].no)&&(top!=-1))
			   {
				  --top;

			   }
			   count=node[top+1].height;
			   node[++top].no=a[j];

			   node[top].height=1+count;
			   if(node[top].height>=height)
			   {
					   if((node[top].height==height)&&(node[top].no<hno))
				   {
				   height=node[top].height;
				   hno=a[j];
				   }
				   else if(node[top].height!=height)
				   {
					   height=node[top].height;
				   hno=a[j];
				   

				   }

  
				   
			   }




		   }
                    
		}*/
		   printf("%lld %lld\n",hno,height);
	}

		return 0;
}
