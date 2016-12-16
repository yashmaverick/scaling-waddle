#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct edgeweight
{
    int v1;
    int v2;
    int wt;
}edgeweight;

edgeweight arr[1000010];
int parentarr[1000010];

int parent(int parentarr[],int i)
{
    if(parentarr[i]==i)
        return i;
    return parent(parentarr,parentarr[i]);
}

int cmpfunc(const void *p, const void *q)
{
    int m,n;
    m=((edgeweight *)p)->wt;
    n=((edgeweight *)q)->wt;
    return m-n;
}

int main()
{

    int N,M,x,y,w,i,j,k,r,s;
    long long int sum,p;
   // for(i=1;i<=N;i++)
   // {
 //       edgeweight arr[i]=(edgeweight)malloc((sizeof(edgeweight)));
   // }

            

    p=0;    
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        arr[i].v1=x;
        arr[i].v2=y;
        arr[i].wt=w;
    }
    sum=0;
    qsort((void*)arr,M,sizeof(arr[0]),cmpfunc);
    
    for(i=1;i<=N;i++)
        parentarr[i]=i;
 //   for(i=0;i<=N;i++)
   //     printf("%d",parentarr[i]);
  //  for(i=0;i<M;i++)
//        printf("%d ",arr[i].wt);
    int flag=0;
    for(i=0;i<M;i++)
    {
        r=parent(parentarr,parentarr[arr[i].v1]);
        s=parent(parentarr,parentarr[arr[i].v2]);
//        printf("%d %d\n",r,s);
        if(r!=s)
        {
//printf("fdf");
         parentarr[r]=parentarr[s];
            sum=sum+arr[i].wt;
            p++;
            if(p==N-1)
            {
                flag=1;
                break;
      //      parentarr[r]=parentarr[s];
            
        }
           
        }
    }
        if(flag!=1 && p<N-1)
            printf("-1\n");
        else
            printf("%lld\n",sum);


return 0;
}
