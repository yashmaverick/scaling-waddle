#include<stdio.h>
#include<stdlib.h>
typedef struct egde{
     int u;int v;int w;
}eg;
int comp(const void* a,const void *b)
{
     eg* p,*q;
     p=(eg*)a; q=(eg*)b;

     if(p->w > q->w)
          return 1;
     else
          return -1;
}

eg a[1000011];
int pr[100011][3]={0};

long long int kruskal(int n,int m)
{    int i,j=0,ct=1,u=0,v=0;
     long long int sum=0;
     for(i=1;i<=n;i++)
     {    pr[i][1]=i;
          pr[i][2]=1;
     }
     while(ct<=n-1)
     {
          if(j>m)
          {
              return -1;
          }
          u=a[j].u; v=a[j].v;
        while(u!=pr[u][1])
        {
             u=pr[u][1];
        }
        while(v!=pr[v][1])
        {
             v=pr[v][1];
        }

        if(u!=v)
        {
             sum+=a[j].w;
             if(pr[u][2] > pr[v][2])
             {
                  pr[u][2]+=pr[v][2];
                  pr[v][1]=u;
             }
             
             else
             {
                  pr[v][2]+=pr[u][2];
                  pr[u][1]=v;
             }
                ct++;
        }
        j++; 
    // for(i=1;i<=m;i++)
      //    printf("%d %d \n",pr[i][1],pr[i][2]);
    // printf("\n");
     }
        return sum;
}

int main (){
     int n,m,u=0,v=0,w=0,i=0;
     scanf("%d%d",&n,&m);

     for(i=0;i<m;i++)
     {
          scanf("%d%d%d",&u,&v,&w);
          a[i].u=u;a[i].v=v;a[i].w=w;
     }

     if(m < n-1)
          printf("-1\n");
     else
     {

     qsort(a,m,sizeof(eg),comp);
  // printf("\n");
    // for(i=0;i<m;i++)
      //      printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
     
     printf("%lld\n",kruskal(n,m));
    }
     return 0;
}

