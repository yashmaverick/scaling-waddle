#include<stdio.h>
#include<string.h>
#define pi(n) printf("%d ",n)

int a[100011];
void sieve()
{
     int i,j;
     for(i=1;i<=100001;i++)
          a[i]=i;
     a[0]=-1; a[1]=-1;

     for(i=2;i<=100001;i++)
     {
          if(a[i]!=-1)
          {
               for(j=2;j*i<=100001;j++)
                    a[i*j]=-1;
          }
     }

}

int qe[100011][2];
int vs[100100]={0};
int bfs(int val,int s)
{  
     int fr=0,ed=0,v,ct,ans=0,fl=0,r1,r2;
     int vc,vi,i;
     qe[ed][1]=0;
     qe[ed++][0]=val;
     vs[val]=1;
     ans=0;
     while(fr!=ed)
     {
          v=qe[fr][0];
          vi=v;
          //  qe[fr][0]=0;
          vc=qe[fr++][1];
          //printf("vi=%d  vc=%d\n",vi,vc);

          r1=v%10;
          v=v-r1;
          for(i=0;i<=9;i++)
          {
               if(a[v+i]!=-1 && vs[v+i]!=1)
               {
                    qe[ed][0]=v+i; vs[v+i]=1;
                    qe[ed++][1]=vc+1;
               }
               if(v+i==s)
               {    ans=vc+1;
                    fl=1;
               }
          }

          if(fl==0) 
          { r1=v%100; r2=r1/10;
               v=vi;
               v=v-r2*10;
               for(i=0;i<=9;i++)
               {
                    if(a[v+10*i]!=-1 && vs[v+10*i]!=1)
                    {
                         qe[ed][0]=v+10*i; vs[v+10*i]=1;
                         qe[ed++][1]=vc+1;
                    }
                    if(v+10*i==s)
                    {    ans=vc+1;
                         fl=1;
                    }
               }
          }

          if(fl==0)
          { r1=v%1000; r2=r1/100; 
               v=vi; v=v-r2*100;
               for(i=0;i<=9;i++)
               {
                    if(a[v+100*i]!=-1 && vs[v+100*i]!=1)
                    {
                         qe[ed][0]=v+100*i; vs[v+100*i]=1;
                         qe[ed++][1]=vc+1;
                    }
                    if(v+100*i==s)
                    {     ans=vc+1;      
                         fl=1;
                    }
               }
          }


          if(fl==0)
          {
               r2=v/1000;
               v=vi;  v=v-1000*r2;
               for(i=1;i<=9;i++)
               {
                    if(a[v+1000*i]!=-1 && vs[v+1000*i]!=1)
                    {
                         qe[ed][0]=v+1000*i; vs[v+1000*i]=1;
                         qe[ed++][1]=vc+1;
                    }
                    if(v+1000*i==s)
                    {    ans=vc+1;
                         fl=1;
                    }
               }
          }
          if(fl==1)
          { //   printf("%d -> %d\n",qe[s][0],qe[s][1]);
               return ans;
               //   break;
          }

          // for(i=fr;i<ed;i++)
          //    printf("%d ",qe[i][0]);
          //printf("\n");
     }
     return -1;
}


int main (){
     int test,n,s,i,j=0;
     sieve();
     //for(i=000;i<=1300;i++)
     //  printf("%d ",a[3733]);

     scanf("%d",&test);

     for(i=0;i<test;i++)
     {
          memset(vs,0,sizeof(vs));
          scanf("%d%d",&n,&s);
          if(n==s)
               printf("0\n");
          else
          {
               j=bfs(n,s);

               if(j==-1)
                    printf("Impossible\n");
               else
                    printf("%d\n",j);
          }
     }


     return 0;
}

