#include<stdio.h>
#include<string.h>

int main (){
     int test,n,a[100010],st[100010],i,tp,ct,i1,i2,mx,ans,j,i3,in[100010];
     char m[100010]={'\0'};
     scanf("%d",&test);

     for(i1=0;i1<test;i1++)
     {    i2=0; ct=0; mx=0; tp=0;
          scanf("%d",&n);
          memset(m,'\0',sizeof(m));
          for(i=0;i<n;i++)
          {
               scanf("%d",&a[i]);
          }

          if(n==1)
               printf("%d 0\n",a[0]);
          if(n==2)
               printf("%d 1\n",a[0]);
          
          else if(n>2)
          {
            i2=0; st[i2++]=0; in[0]=0;
            for(i=1;i<n;i++)   
            {  

                if(a[st[i2-1]] < a[i])
                 {
                      in[i]=0;
                      st[i2++]=i;
                 }
                 else
                 {    tp=0; ct=0;
                      while(a[st[i2-1]] >= a[i] && i2>0 )
                      {
                           ct++;
                           tp+=in[st[i2-1]]; i2--;
                           if(i2==0)
                                break;
                      }
                   //   if(i2<0) in[i]=st[i2-1];
                    //  else in[i]=-1;
                    st[i2++]=i;
                    in[i]=ct+tp;
                 }
            }
           // for(i=0;i<n;i++) printf("%d ",in[i]); printf("\n");
        

            for(i=n-1;i>=0;i--)
            {
                // if(in[i]!=0)
               //  {
                      in[i]=i-(in[i]+1);
                      if(m[in[i]]=='1')
                           in[i]=-1;
                      else
                      m[in[i]]='1';
                 //}
               //  else in[i]=-1;
            }
            
          // for(i=0;i<n;i++)
          // {  printf("%d ",in[i]);} printf("\n"); 
               
            ct=0; i2=0;            
            st[i2++]=n-1; 
            ct++;   st[i2++]=n-2; 
          for(i=n-3;i>=0;i--)
          { //for(j=0;j<i2;j++) printf("%d ",a[st[j]]); printf("\n");
              // printf("a[i]=%d , ct=%d  max=%d\n",a[i],ct,mx);
               if(i2==1)
               {
                    st[i2++]=i;
                    ct++;  ;
                    if(ct>=mx)
                    {
                         mx=ct;
                         ans=i;
                    }
                                  
                    continue;
               }
                      
               if(a[i] > a[st[i2-1]])
               {                                            //       printf("push1\n");
                    ct++;
                    
                    if(ct >= mx)
                    { 
                         mx=ct;
                         ans=i;
                    }
                    st[i2++]=i;
               }
                    
               else if(a[i] < a[st[i2-1]] )//&& st[i2-1] > st[i2-2])
               {           //  printf("pop\n");
                  while(a[i] < a[st[i2-1]] && i2>0) //&& st[i2-1] > st[i2-2])                
                   {  
                        if(in[st[i2-1]]==i &&in[st[i2-1]]!=-1 )
                             break;
                        ct--;
                        i2--;        
                   
                   }
                  
                   st[i2++]=i;
                   ct++; 
                   if(ct>=mx)
                   {
                        mx=ct;
                        ans=i;
                   }
               }

               else if(a[i] < a[st[i2-1]] && a[i] > a[st[i2-2]] )
               {                                                 //     printf("push2\n");
                    st[i2++]=i;
                    ct++;
                    if(ct>=mx)
                    {
                         mx=ct;
                         ans=i;
                    }
               }

               else if(a[i] < a[st[i2-1]] && a[st[i2-2]] > a[st[i2-1]])
               {                                                   //    printf("push3\n");
                    st[i2++]=i;
                    ct++;
                    if(ct>=mx)
                    {
                         mx=ct;
                         ans=i;
                    }
               }
          }

          printf("%d %d\n",a[ans],mx);

          }
     }
return 0;
}

