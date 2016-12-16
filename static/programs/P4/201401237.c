#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{

    int i,t;
    char s[100000];
    int scon[100000];
    scanf("%d",&t);

    while(t--)
    {
        int dup,count=0;
        scanf("%s",s);
        //printf("Print string %s",s);
        int n=strlen(s);

        //convert characters to numbers
        for(i=0;i<n;i++)
        {
            if(s[i]=='J')
                scon[i]=-100002;
            if(s[i]=='M')
                scon[i]=100001;
            if(s[i]=='R')
                scon[i]=1;
        }
        //form sums
        int min,max;
        min=scon[0];
        max=scon[0];
        for(i=1;i<n;i++)
        {
            scon[i]+=scon[i-1];
            if(scon[i]<min)
                min=scon[i];
            if(scon[i]>max)
                max=scon[i];
        }        
        //sort
        int flag=0;
        dup=1;
        qsort(scon,n,sizeof(int),cmpfunc);
        count=0; 
        for(i=0;i<n-1;i++)
        {
            if(scon[i]==0)
                count++;
            if(scon[i]==scon[i+1])
            {
                dup++;
                flag=1;
            }
            else
            {
                flag=0;
            }
            if(dup>1 && flag==0)
            {
                count+=(dup*(dup-1))/2;
                dup=1;
            }
        }
        if(scon[n-1]==0)
            count++;
        count=count+dup*(dup-1)/2;
        printf("%d\n",count);
    }
    return 0;
}
