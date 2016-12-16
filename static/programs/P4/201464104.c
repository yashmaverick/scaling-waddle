#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*long long int split ( long long int a[ ], long long int lower, long long int upper )
{
        long long int i, p, q, t ;

        p = lower + 1 ;
        q = upper ;
        i = a[lower] ;

        while ( q >= p )
        {
                while ( a[p] < i )
                        p++ ;

                while ( a[q] > i )
                        q-- ;

                if ( q > p )
                {
                        t = a[p] ;
                        a[p] = a[q] ;
                        a[q] = t ;
                }
        }

        t = a[lower] ;
        a[lower] = a[q] ;
        a[q] = t ;

        return q ;
}
void quicksort ( long long int a[ ], long long int lower, long long int upper )
{
        long long int i ;
        if ( upper > lower )
        {
                i = split ( a, lower, upper ) ;
                quicksort ( a, lower, i - 1 ) ;
                quicksort ( a, i + 1, upper ) ;
        }
}*/
int comp (const void * a, const void * b)
{
                   return ( *(int*)a - *(int*)b );
}

int main()
{
        int s[100000],t,i,j,k,ans,c;
        char a[100000];
        scanf("%d",&t);
        while(t--)
        {
                ans=0;c=1;
                scanf("%s",a);
                int l=strlen(a);
                s[0]=0;
                switch(a[0])
                {
                        case 'J':s[1]=989898;break;
                        case 'M':s[1]=10102;break;
                        case 'R':s[1]=-1000000;break;
                }
                for(i=1;i<l;i++)
                {
                        if(a[i]=='J')
                                s[i+1]=989898;
                        else if(a[i]=='M')
                                s[i+1]=10102;
                        else
                                s[i+1]=-1000000;
                        s[i+1]+=s[i];
                }
//                for(i=0;i<=l;i++)
  //                      printf("%d ",s[i]);
                qsort(s,l+1,sizeof(int),comp);
    //            for(i=0;i<=l;i++)
      //                  printf("%d ",s[i]);
                k=s[0];
                for(i=1;i<=l;i++)
                {
                        //if(s[i]==0)
                          //      ans++;
                        if(s[i]==k)
                                c++;
                        else
                        {
                                k=s[i];
                                ans+=(c*(c-1))/2;
                                c=1;
                        }
                }
                ans+=(c*(c-1))/2;
                printf("%d\n",ans);
        }
        return 0;
}
