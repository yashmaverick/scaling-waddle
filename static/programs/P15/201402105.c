#include<stdio.h>
int segmentmin(int narasimha,int finish,int qstart,int qend,int pointer,int *);
int virtualrange(int *p,int narasimha,int finish,int futurepointer,int *);
void enter()
{
printf("\n");
}
void space()
{
printf(" ");
}
int mid(int x,int y)
{
return (x+y)/2;
}
int mini(int x,int y)
{
        if(x<y)
                return x;
        else
                return y;
}
int segmentmin(int narasimha,int finish,int qstart,int qend,int pointer,int *virtual)
{
        if(qstart<=narasimha && qend>=finish)
        {
                return virtual[pointer];
        }
        if(finish<qstart || narasimha>qend)
                return 1000000000;
        int mid1=mid(narasimha,finish);
        return mini(segmentmin(narasimha,mid1,qstart,qend,2*pointer+1,virtual),segmentmin(mid1+1,finish,qstart,qend,2*pointer+2,virtual));
}
int virtualrange(int *p,int narasimha,int finish,int futurepointer,int *virtual)
{
        if(narasimha==finish)
        {
                virtual[futurepointer]=p[narasimha];
                return virtual[futurepointer];
        }
        int mid=(narasimha+finish)/2;
        virtual[futurepointer]=mini(virtualrange(p,narasimha,mid,((2*futurepointer)+1),virtual),virtualrange(p,mid+1,finish,2*futurepointer+2,virtual));
        return virtual[futurepointer];
}


int main()
{
        int numberoftestcases,n,interval,i,j,k,ans;
	int virtual[1000000];
        scanf("%d",&numberoftestcases);
        while(numberoftestcases)
        {
                scanf("%d %d",&n,&interval);
                int array[n];
                for(k=0;k<n;k++)
                {
                        scanf("%d",&array[k]);
                } 
                k=virtualrange(array,0,n-1,0,virtual);
                for(i=0;i<n-interval;i++)
{ans=segmentmin(0,n-1,i,i+interval-1,0,virtual);
                        printf("%d",ans);
			space();
}
ans=segmentmin(0,n-1,i,i+interval-1,0,virtual);
                        printf("%d",ans);
                 enter();
		numberoftestcases--;   
        }
        return 0;
}
