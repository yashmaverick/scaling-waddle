#include<stdio.h>


int det(int b[6][6],int size);
//void postorder(struct node *r);
int main()
{
	int t,u,v,w,j,i,n,c=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&j);
		c=0;
		if(j==1)
		{
			printf("%d\n",0);
			continue;
		}
		else
		{
			if(j==2)
			{
				printf("%d\n",1);
				continue;
			}
			else
			{
				if(j==3)
				{
					printf("%d\n",2);
					continue;
				}
			}
		}
		while(j>3)
		{
			j=j/2;
			c++;

		}
		if(j==2)	
			printf("%d\n",(c+1)*2-1);
		else if(j==3)
			printf("%d\n",(c+1)*2);
	}
	return 0;
}


/*void postOrder(struct node* r)
{

         if(r==NULL)
                 return;
        else
        {
                postOrder(r.left);
                postOrder(r.right);
                printf("%d\n", r.value);
        }
        return;
}



*/
int det(int b[6][6],int size)
{
        int i,j,k,l,d=0;
        int minor[6][6];
        if(size==2)
                d=b[0][0]*b[1][1]-b[1][0]*b[0][1];
        else
        {
                d=0;
                for(k=0;k<size;k++)     //for each element of 1st row
                {
                        for(i=1;i<size;i++)     //copying consecutive rows into minor matrix    
                        {
                                l=0;                    //by default while filling matrix second index always starts from 0,keep incrementing
                                for(j=0;j<size;j++)     //second index of b matrix
                                {
                                        if(j==k)        //not copying columns which we are cancelling
                                                continue;
                                        minor[i-1][l]=b[i][j];  //deleting columns of j
                                        l++;
                                }
                        }
                        if(k%2==0)
                        d=d+b[0][k]*det(minor,size-1);
                        else
                        d=d-b[0][k]*det(minor,size-1);
                }
        }
        return d;
}

                                                                                              
