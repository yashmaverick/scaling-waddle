#include<stdio.h>
int main()
{
    int i,j,k,n,t,f1,f2,f3,i1,num1,num2,index1,index2,v1,v2;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
     scanf("%d",&t);
     while(t--)
      {
      //    int c[n];
          f1=0;f2=0;f3=0;
          scanf("%d%d",&v1,&v2);
          for(i=0;i<n;i++)
          {
              if(b[i]==v1)
              {
                  index1=i;
                  f1=1;
              }
              if(b[i]==v2)
              {
                  index2=i;
                  f2=1;
              }
              if(f1==1&&f2==1)
                  break;

          }
          if(index1>index2)
          {
              num1=index2;
              num2=index1;
          }
          else
          {
              num1=index1;
              num2=index2;

          }
          j=0;
          for(i=num1;i<=num2;i++)
            {
                c[j]=b[i];
                j++;
            }
        /*  for(i=0;i<j;i++)
              printf("%d  ",c[i]);
           printf("\n");*/

       for(i=0;i<=num2;i++)
       {
             for(i1=0;i1<j;i1++)
             {
                 if(c[i1]==a[i])
                 {
                     printf("%d\n",a[i]);
                     f3=1;
                     break;
                 }
             }
             if(f3==1)
                 break;
      }
          


      }
    return 0;
}
