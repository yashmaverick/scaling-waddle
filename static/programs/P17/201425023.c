#include<stdio.h>
int main()
{
        int n,t,p[100001],i[100001];
        int a,b,temp,ans;
        int j,k,z;
        int flag;
        scanf("%d",&n);
        j=n;
        for(j=0;j<n;j++) 
                scanf("%d",&p[j]);
        j=n;
        for(j=0;j<n;j++) 
                scanf("%d",&i[j]);
        scanf("%d",&t);
        for(z=0;z<t;z++)
        {
                int flag1=0;
                temp=0,ans=0,flag=0;
                scanf("%d %d",&a,&b);
                int c=0,d=0;
                for(j=0;j<n;j++) 
                {
                        if(i[j]==a)
                                c=j;
                        else if(i[j]==b)
                                d=j;
                }
                //                printf("%d %d\n",c,d);
                if(c>d)
                {
                        temp=c;
                        c=d;
                        d=temp;
                }
                //              printf("%d %d\n",c,d);
                j=n;
                int l=c;
                int new[d-c+1];
                for(k=0;k<(d-c+1);k++)
                {
                        new[k]=i[l];
                        l++;
                }
                for(k=0;k<n;k++)
                {   
                        for(l=0;l<(d-c+1);l++)
                        {
                                if(new[l]==p[k])
                                {
                                        flag=l;
                                        flag1=1;
                                        break;
                                }
                        }
                        if(flag1==1)
                                break;
                }
                ans=new[flag];
                if(a==b)
                        printf("%d\n",a);
                else
                        printf("%d\n",ans);
        }
        return 0;
}

























