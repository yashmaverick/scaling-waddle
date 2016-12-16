#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct node
{
    long long int no;
    long long int w;
    struct node *next;
}node;
node *list[1000005];
long long int heap[2][1000005],fag,sum=0,last=0,visit[1000005],sweight[1000005],keys[1000005];
void insertli(long long int v1,long long int v2,long long int we)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->no=v2;
    temp->w=we;
    temp->next=list[v1];
    list[v1]=temp;
   temp=(node *)malloc(sizeof(node));
    temp->no=v1;
    temp->w=we;
    temp->next=list[v2];
    list[v2]=temp;
  

}
void inserthp(long long int v,long long int w)
{
    long long int temp,t1,t2;
    last++;
    temp=last;
    heap[1][temp]=v;
    heap[0][temp]=w;
    keys[v]=temp;
    if(temp>1)
    {
     while((heap[0][temp/2]>heap[0][temp])&&(temp>1))
     {
            t1=heap[0][temp];
            t2=heap[1][temp];
           heap[0][temp]=heap[0][temp/2];
           heap[1][temp]=heap[1][temp/2];
         heap[0][temp/2]=t1;
         heap[1][temp/2]=t2;
         temp=temp/2;
    }
    }     

}
void heapify(long long int v)
{
    
long long int i,temp,t1,t2,k;
   temp=v;
  // printf("lmysa%lld-%lld\n",heap[1][temp/2],heap[1][temp]);
   while((temp>1)&&(heap[0][temp/2]>heap[0][temp]))//Could be problem
   {
       
//       printf("heapifying%lld\n",heap[1][temp]);
       
         t1=heap[0][temp];
         t2=heap[1][temp];
         heap[0][temp]=heap[0][temp/2];
         heap[1][temp]=heap[1][temp/2];
         heap[0][temp/2]=t1;
         heap[1][temp/2]=t2;

         k=keys[heap[1][temp]];
         keys[heap[1][temp]]=keys[heap[1][temp/2]];
         keys[heap[1][temp/2]]=k;

       temp=temp/2;

   }
  // printf("after heaping%lld-%lld\n",heap[1][1],sweight[heap[1][1]]);

}
void delmin()
{
    long long int t1,t2,i,temp,k;
   t1=heap[0][last];
   t2=heap[1][last];
   heap[0][last]=heap[0][1];
   heap[1][last]=heap[1][1];
   heap[0][1]=t1;
   heap[1][1]=t2;
   heap[0][last]=INT_MAX;
   k=keys[heap[1][last]];
         keys[heap[1][last]]=keys[heap[1][1]];
         keys[heap[1][1]]=k;
//       printf("key1%lld-key2%lld",heap[1][last],heap[1][1]);


   temp=1;
   last--;
   while(((heap[0][temp*2]<heap[0][temp])||(heap[0][(temp*2)+1]<heap[0][temp]))&&(temp*2<last))
   {
       if((heap[0][temp*2]<heap[0][temp])&&(heap[0][(temp*2)+1]>heap[0][temp*2]))
       {
           t1=heap[0][temp];
           t2=heap[1][temp];
           heap[0][temp]=heap[0][temp*2];
           heap[1][temp]=heap[1][temp*2];
           heap[0][temp*2]=t1;
           heap[1][temp*2]=t2;
          
           k=keys[heap[1][temp]];
         keys[heap[1][temp]]=keys[heap[1][temp*2]];
         keys[heap[1][temp*2]]=k;

           temp=temp*2;

       }
       else if(heap[0][(temp*2)+1]<heap[0][temp])
       {
           t1=heap[0][temp];
           t2=heap[1][temp];
           heap[0][temp]=heap[0][(temp*2)+1];
           heap[1][temp]=heap[1][(temp*2)+1];
           heap[1][(temp*2)+1]=t2;
           heap[0][(temp*2)+1]=t1;
           
          k=keys[heap[1][temp]];
         keys[heap[1][temp]]=keys[heap[1][(temp*2)+1]];
         keys[heap[1][(temp*2)+1]]=k;

           temp=(temp*2)+1;
      
       }
             //ADD modificatin  of keys

   }
if((temp*2==last)&&(heap[0][temp*2]<heap[0][temp]))
   {

          t1=heap[0][temp];
           t2=heap[1][temp];
           heap[0][temp]=heap[0][temp*2];
           heap[1][temp]=heap[1][temp*2];
           heap[0][temp*2]=t1;
           heap[1][temp*2]=t2;
          
           k=keys[heap[1][temp]];
         keys[heap[1][temp]]=keys[heap[1][temp*2]];
         keys[heap[1][temp*2]]=k;


   }
   
}
void initz(long long int n)
{
    long long int i;
    for(i=0;i<=n;i++)
    {
        sweight[i]=INT_MAX;//Coulld be a problem
    }
  

}
void djs(long long int n,long long int v1,long long int v2)
{
    long long int temp,d,i,perm;
    node *tempnode;
    initz(n);
    for(i=0;i<=n;i++)//
    {
      heap[0][i]=INT_MAX;
      heap[1][i]=i;
      keys[i]=i;

    }
    last=n;
    temp=last;
    heap[1][1]=v1;
    heap[0][1]=0;
    sweight[v1]=0; 
    heap[1][v1]=1;
    
    keys[v1]=1;
    keys[1]=v1;
    while(temp!=0)
    {
      //  printf("newhp%lld\n",heap[1][1]);
          
       
                         
                   if(sweight[heap[1][1]]==INT_MAX)
                   {
                       printf("-1\n");
                       fag=1;
                       break;
                   }
               
         tempnode=list[heap[1][1]];
             perm=heap[1][1];
           visit[heap[1][1]]=1;
           sum=sum+heap[0][1];
       delmin();
    //  printf("afterdel%lld",heap[1][1]);
              temp--;
       
       while(tempnode!=NULL)
       {
         //  printf("lola%lld\n",sweight[perm]+tempnode->w);
           
           if((tempnode->w<sweight[tempnode->no])&&(visit[tempnode->no]!=1))    
           {                   
  //             printf("changing-%lldweightis-%lld\n",tempnode->no,sweight[perm]+tempnode->w);
               sweight[tempnode->no]=tempnode->w;
               heap[0][keys[tempnode->no]]=sweight[tempnode->no];
                        heapify(keys[tempnode->no]);
//                  printf("newhp2%lld-\n",heap[1][1]);
             
              
               
           }
               tempnode=tempnode->next;

       }

    }


}
int main ()
{
   long long int n,i,v1,w,v2,p,e,k;
   
   
   
   scanf("%lld%lld",&n,&e);
   for(i=0;i<e;i++)
   {
       scanf("%lld%lld%lld",&v1,&v2,&w);
       insertli(v1,v2,w);
   }
  //  scanf("%lld%lld",&v1,&v2);
    djs(n,v1,v2);
    if(fag!=1)
        printf("%lld\n",sum);
   
   
   

   return 0;
}

