#include<stdio.h>
#include<stdlib.h>

typedef long long int LL;

int t;
char jmr[100001];
LL count,tempcount,min,n,j,m,r;

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int cmpfunc(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
    LL i;
    int x[100001];

    //j=-100002;
    j=-100001;
    m=1;
    r=100000;
    //r=100001;

    scanf("%d",&t);
    while(t-->0)
    {

        count=0;

        scanf("%s",jmr);

        n=1;

        //for(i=0;jmr[i]!='\0';i++)
            //x[i]=0;
        switch(jmr[0])
        {
            case 'J': x[0]=j;
                      break;
            case 'M': x[0]=m;
                      break;
            case 'R': x[0]=r;
                      break;
        }

        for(i=1;jmr[i]!='\0';i++)
        {
            if(jmr[i]=='J')
                x[i]=x[i-1]+j;
            else if(jmr[i]=='M')
                x[i]=x[i-1]+m;
            else if(jmr[i]=='R')
                x[i]=x[i-1]+r;

            n+=1;

            if(x[i]==0)
                ++count;
            /*if(i>=3)
                if(x[i]==x[i-3])
                    ++count;*/
        }

	qsort(x,n,sizeof(int),cmpfunc);
	
	min=0;
	tempcount=0;

        /*for(i=3;jmr[i]!='\0';i++)
        {
            if(x[i]==x[i-3])
                ++count;
        }*/

	for(i=1;i<n;i++)
         {
             if(x[i]==x[min])
             {
                 if(i==(min+1)) 
                     tempcount+=2;
                 else 
                     tempcount+=1;
             }	
             /*else if((x[i]==x[min]) && (x[i]==0))
             {
                 if(i==(min+1))
                     count+=2;
                 else
                     count+=1;
             }*/
             else
             { 
                 min=i;
                 count+=(tempcount*(tempcount-1))/2;
                 tempcount=0;
             }
         }
       // printf("%lld\n",count);

       // if((i==n) && (tempcount>0))
        //{
            count+=((tempcount*(tempcount-1))/2);
        //}

    //    printf("\n");
//        for(i=0;jmr[i]!='\0';i++)
  //          printf("%d ",x[i]);
        printf("%lld\n",count);
    }

    return 0;
}
