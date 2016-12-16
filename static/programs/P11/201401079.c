#include<stdio.h>
#include<stdlib.h>
int main()
{
     long long int n,i,j,k,l,top=-1,t,z;
     int a[100010];
     int area[100010];
     int b[100010];
     //scanf("%d",&n);
     while(1)
     {
          scanf("%lld",&n);

//     a=(int*)malloc(n*sizeof(int));
  //   area=(int*)malloc(n*sizeof(int));
    // b=(int*)malloc(n*sizeof(int));
          if(n==0)
               break;
           for(i=0;i<n;i++)
           {
                scanf("%d",&a[i]);
           }
           top=-1;
           for(i=0;i<n;i++)
           {
                
                while(top!=-1)
           {    
                  
                if(a[i]<=a[b[top]])
                {
                     top--;
                  //   k=b[top];
                    
                }

                else
                     break;
           }
                if(top==-1)
                     t=-1;
                else
                     t=b[top];
                area[i]=i-t-1;
          
                top++;
           b[top]=i;
           }

           top=-1;
           for(i=n-1;i>=0;i--)
           {
                
                while(top!=-1)
           {
             //   k=b[top];
                if(a[i]<=a[b[top]])
                {
                     top--;
               //      k=b[top];
                }      
                else
                     break;
               
           }
            if(top==-1)
                 t=n;
            else
                 t=b[top];
            

           area[i]=area[i]+t-i-1;
           
                top++;
           b[top]=i;
           }
           long long int max=0;
           
           for(i=0;i<n;i++)
           {
         //       printf("%d" ,area[i]);
               k=area[i]+1;
               z=a[i]*k;
                if(z>max)
                max=z;
           }
           printf("%lld\n",max);

     }
     return 0;
}

     

