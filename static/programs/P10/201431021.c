
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,N,i,end=0,start=0, sad,size=0;
    char c,d,a[10005][105],e[1];
    scanf("%d",&N); //N--;
    while (1) {
        scanf("%s",e);
        if (e[0]=='A') {
            scanf("%d",&n);
            //size=size+n;
           // if (size>N)
           // {
             //   size=N;
                
            //}
            end=start+size;
            int zz=end;
            for (i = 0; i < n; ++i)
            {

                end=zz+i;
                if (end>=N)
                {
                    end=end%N;

                    /* code */
                }
                size++;
                if (size>N)
                {

                    start++;
                    start%=N;
                    size=N;
                    /* code */
                }
                scanf("%s",a[end]);
                /* code */
            }
        }
          //  for (i=0; i<n; i++) {
        /*   if (end<N) {
                    end++;
                    if(end==start)
                    {
                         start++;
                        if (start>N-1) {
                            start=0;
                        }
                    }
                    scanf("%s",a[end]);
                }
                else if(end>=N){
                    end=0;
                    if (end==start) {
                        start++;
                        
                        if(start>N-1)
                        start=0;
                    }
                    scanf("%s",a[end]);
                }*/
                     //for(sad=0; sad<n; sad++)printf("%s ", a[sad]); printf("EVIL\n");
                
  //          }
   //         
   //         }
        else if(e[0]=='R')
        {
           // printf("start1 %d %d\n",start,end);
            scanf("%d",&n);
            size=size-n;
            start=start+n;
            start%=N;
           // for(i=0;i<n;i++)
            //{
               // printf("%d\n",i);
                //if (start<N) {
              //      if(start!=end){start++; start=start%N;}
                //    else start=(start+1)%N;
                
            //}

         //   printf("start2 %d %d\n",start,end);
        }
        else if(e[0]=='L')
        {
            //if (start>end)                                                                                                                                          
            //{
                for (i = 0; i <size; ++i)
                {
                    printf("%s\n",a[(i+start)%(N)]);
                }

                //for (i = 0; i <=end; ++i)
                //{
                //    printf("%s\n",a[i]);
                //}
                //for(i=0;i<n;i++)
               // {
                //    printf("%s ",a[i] );
                //}
            //}
        //else
        //{
          //  for (i=start+1; i<=end; i++) {
            //    printf("%s\n",a[i]);
                
            //}
            //}   
        }   
        else if(e[0]=='Q')
        {
            break;
        }
            
    }
    

    return 0;
}
