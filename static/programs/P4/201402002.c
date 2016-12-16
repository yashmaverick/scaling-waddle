#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct doub{
    long long int A;
    long long int B;
};

struct doub u[1000000];

void merge(struct doub *s,long long int start,long long int mid,long long int end)
{
    long long int l,k=start,i=start,j=mid+1;
    while(i<=mid && j<=end)
    {
        if(s[i].A<s[j].A || ((s[i].A==s[j].A)&&(s[i].B<s[j].B)) )
        {
            u[k].A=s[i].A;
            u[k].B=s[i].B;
            i++;
            k++;
        }
        else 
        {
            u[k].A=s[j].A;
            u[k].B=s[j].B;
            j++;
            k++;

        }
    }
    if(i>mid)
    {
        while(j<=end)
        {
            u[k].A=s[j].A;
            u[k].B=s[j].B;
            j++;
            k++;
        }
    }
    if(j>end)
    {
        while(i<=mid)
        {
            u[k].A=s[i].A;
            u[k].B=s[i].B;
            i++;
            k++;
        }
    }
    for(l=start;l<=end;l++)
    {
        s[l].A=u[l].A;
        s[l].B=u[l].B;
        //printf("%lld %lld\n",s[l].a,s[l].b);
    }
    return ;
}
void merge_sort(struct doub *s,long long int start,long long int end)
{
    long long int mid;
    if(start>=end)
        return ;
    else
    {
        mid=(start+end)/2;
        merge_sort(s,start,mid);
        merge_sort(s,mid+1,end);
        merge(s,start,mid,end);
        return ;
    }
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char str[1000050];

        scanf(" %[^\n]",str);
        long long int length=strlen(str);

        long long int j=0,m=0,r=0;
        long long int f,count=1;
        struct doub index[length+1];

        index[0].A=index[0].B=0;
        for(f=0;f<length;f++)
        {
            if (str[f]=='J')
                j++;
            else if (str[f]=='M')
                m++;
            else if (str[f]=='R')
                r++;
            index[f+1].A=j-m;
            index[f+1].B=j-r;
//            printf("Index of index[%lld].A=%lld, Index of index[%lld].B=%lld\n",f+1 ,index[f+1].A, f+1 ,index[f+1].B);
        }

        merge_sort(index,0,length);

//                int rq=0;
//                for(rq=0;rq<=length;rq++)
//                    printf("Elem is (%lld, %lld)\n",index[rq].A ,index[rq].B);

        long long int w,ans=0;
        for(w=0;w<length;w++)
        {
            long long int low=1;
            while(index[w].A == index[w+1].A && index[w].B == index[w+1].B)
            {
                low++;
                w++;
            }
            ans+=((low)*(low-1))/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
