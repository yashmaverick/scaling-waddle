#include<stdio.h>
#include<stdlib.h>
int det(int b[6][6],int size);
struct StackItem
{
       long long int index;
       long long int height;
	long long int value;
};


int main()
{
		long long int t,top,ci,o,m;
		scanf("%lld",&t);
	while(t!=0)
	{
		long long int Y[t+1],c[t+1],k,j;
		float tr,g,h,d;
		for(o=0;o<t;o++)
			scanf("%lld",&Y[o]);
		o=0;

		ci=0;
	
		top=-1;
		while(o<t)
{
	
	if(top==-1 || Y[c[top]] >= Y[o])
{
			top++;
		c[top]=o++;
/*if(max<=q)
				{
					max=q;
				}
				temp=a[n-m];
				a[n-m]=a[n-m-1];
				a[n-m-1]=temp;

		*/
if(top>1)
	{
					k=top;
			for(m=k-1;m>0;m--)
			{
				if(Y[c[m]]>Y[c[k]])
				{
					ci=ci+m;
					break;
				}
			}
	}
/* while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop();  Remove ) */
       
		}
			else
			{
				ci=ci+t-1-o;
		top--;
			}
		}
		printf("%lld\n",ci);
		scanf("%lld",&t);
	}
	return 0;
}

int det(int b[6][6],int size)
{
	int i,j,k,l,d=0;
	int minor[6][6];
	if(size==2)
		d=b[0][0]*b[1][1]-b[1][0]*b[0][1];
	else
	{
		d=0;
		for(k=0;k<size;k++)	//for each element of 1st row
		{
			for(i=1;i<size;i++)	//copying consecutive rows into minor matrix	
			{
				l=0;			//by default while filling matrix second index always starts from 0,keep incrementing
				for(j=0;j<size;j++)	//second index of b matrix
				{
					if(j==k)	//not copying columns which we are cancelling
						continue;
					minor[i-1][l]=b[i][j];	//deleting columns of j
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
		
