#include<stdio.h>
#define MAXSIZE 200010
#define parent(i) ((i)/2)
#define left(i) (2*i)
#define right(i) (2*i+1)
#define min(a,b) ((a<b)? a:b)
#define M 1000000007
#define ll int
#define lli long long int
void swap(lli* x, lli* y)
{
        lli temp=*x;
        *x=*y;
        *y=temp;
}
lli fnmin[MAXSIZE];
lli fnmax[MAXSIZE];
ll size_min=0,size_max=1;
lli sum=1,a,b,c,f;
lli get_median()
{
        if(size_min<size_max)
                return fnmax[1];
        else
                return fnmin[1];
}
void coke(ll i)
{
        ll lc=left(i);
        ll rc=right(i);
        ll min=i;
        if(lc<=size_min&&fnmin[lc]<fnmin[i])
                min=lc;
        if(rc<=size_min&&fnmin[rc]<fnmin[min])
                min=rc;
        if(min!=i)
        {
                swap(&fnmin[i],&fnmin[min]);
                coke(min);
        }
} 
void chocolate(ll i)
{
        ll lc=left(i);
        ll rc=right(i);
        ll max=i;
        if(lc<=size_max&&fnmax[lc]>fnmax[i])
                max=lc;
        if(rc<=size_max&&fnmax[rc]>fnmax[max])
                max=rc;
        if(max!=i)
        {
                swap(&fnmax[i],&fnmax[max]);
                chocolate(max);
        }
}
lli pepsi()
{
        if(size_min<=0)
                return;
        if(size_min==1)
        {
                size_min--;
                return fnmin[1];
        }
        ll root=fnmin[1];
        fnmin[1]=fnmin[size_min];
        size_min--;
        coke(1);
        return root;
}
lli blahblah()
{
        if(size_max<=0)
                return;
        if(size_max==1)
        {
                size_max--;
                return fnmax[1];
        }
        lli temp=fnmax[1];
        fnmax[1]=fnmax[size_max];
        size_max--;
        chocolate(1);
        return temp;
}
void jelly_min(lli key)
{
        fnmin[size_min+1]=key;
        size_min++;
        ll i=size_min;
        while(i>1&&fnmin[parent(i)]>fnmin[i])
        {
                swap(&fnmin[i],&fnmin[parent(i)]);
                i=parent(i);
        }
}
void jelly_max(lli key)
{
        fnmax[size_max+1]=key;
        size_max++;
        ll i=size_max;
        while(i>1&&fnmax[parent(i)]<fnmax[i])
        {
                swap(&fnmax[i],&fnmax[parent(i)]);
                i=parent(i);
        }
}
void jelly(long long int key)
{
        //lli curr_median=get_median();
//        printf("%llu %llu\n",curr_median,key);
        /*if(key>curr_median)
          jelly_min(key);
          else
          jelly_max(key);*/
        //    printf("%d %d\n",fnmax[1],fnmax[2]);
        //printf("%d %d %d\n",fnmin[1],fnmin[2],fnmin[3]);
        /*if(size_min>size_max+1)
          {
        //while(size_min>size_max+1)
        //{

        jelly_max(pepsi());
        //}
        }*/
        if(size_max>=size_min+1)
        {
                //while(size_max>size_min+1)
                //{
                //key=blahblah();
                if(key<fnmax[1])
                {
                        lli temp=blahblah();
                        jelly_min(temp);
                        jelly_max(key);
                }
                else
                        jelly_min(key);
        }
        else if(size_min>=size_max)
        {
                if(key>=fnmin[1])
                {
                        lli temp=pepsi();
                        jelly_max(temp);
                        jelly_min(key);
                }
                else
                        jelly_max(key);
        }
       /* else
        {
                if(key<curr_median)
                        jelly_min(key);
                else
                        jelly_max(key);
        }*/


        //}

}
int main()
{
        ll i,j,n,t,key;
        
        scanf("%d",&t);

        //                        printf("hello\n");
        for(j=0;j<t;j++)
        {


                sum=1;
                size_max=1;
                size_min=0;
                scanf("%lld%lld%lld%d",&a,&b,&c,&n);
                for(i=0;i<=n;i++)
                {
                        fnmin[i]=0;
                        fnmax[i]=0;
                }
                fnmax[1]=1;

                //                      printf("hello\n");
                for(i=2;i<=n;i++)
                {
//                        for(j=1;j<=n;j++)
  //                      {
      //                          printf("%llu ",fnmax[j]);
    //                           printf("%llu ",fnmin[j]);
          

        ///                }

                        //ll curr_median=get_median();  
 //                       printf("%llu ",curr_median);

                        //                    printf("hello\n");
                        f=((a*fnmax[1])+(b*i)+c)%M;
                        sum=(sum+f);
                        jelly(f);
//                        printf("%llu ",sum);
                }
                printf("%lld\n",sum);
        }
        return 0;
}
