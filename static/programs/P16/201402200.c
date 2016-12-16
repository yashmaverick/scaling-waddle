#include<stdio.h>
int  power( int a ,  int b );
int main()
{
    int N,val;
    int i,diameter;
    scanf("%d",&N);
    while(N--)
    {
	scanf("%d",&val);
	for(i=0 ;;i++)
	{
	    if((val>power(2,i)) && (val < power(2,i+1)))
	    {
		if(val>= (power(2,i)+ power(2,i-1) ))
		{
		    diameter=i*2;
		    printf("%d\n",diameter);
			break;
		}
		else
		{
		    diameter=(2*i-1);
		    printf("%d\n",diameter);
		break;
		}

	    }
	    
	    if(val==power(2,i))
	    {
		if(i==0)
		{
		    diameter=0;
		    printf("%d\n",diameter);
			break;
		}

		else
		{
		    diameter=(2*i-1);
		    printf("%d\n",diameter);
			break;
		}


	    }

	}
	


	}

return 0;
    }

 int  power( int a ,  int b )
{  
  int x;
  if(b==0)
    return 1;
  x=power(a,b/2);
  if(b%2==0)
    return (x*x);
  else
    return (a*x*x);
}
