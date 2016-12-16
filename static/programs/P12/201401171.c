#include<stdio.h>
#define maxN 500005

typedef struct abc
{
    long long int val,occ;
}abc;

long long int arr[maxN],n,end=0;
abc stc[maxN];

void push(abc i){stc[++end]=i;}
abc pop(){return stc[end--];}
abc top(){return stc[end];}
long long int empty(){return end==-1;}
long long int size(){return end;}
long long int max(long long int a,long long int b){if(a>b)return a;else return b;}
long long int cmpstur(abc a, abc b){return (a.val-b.val);}
abc makestc(long long int a,long long int b){abc temp;temp.val=a;temp.occ=b;return temp;}

int main()
{
    scanf("%lld",&n);
    while(n)
    {
        long long int i,ans=0,maximus;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        maximus=arr[0];
        for(i=1;i<n;i++)
        {
            if(arr[i]>=maximus)
                maximus=arr[i];
            else    
                ans++;
        }
        maximus=arr[n-1];
        for(i=n-2;i>-1;i--)
        {
            if(arr[i]>=maximus)
                maximus=arr[i];
            else    
                ans++;
        }
        end=-1;
        for(i=0;i<n;i++)
        {
            void update()
            {
                abc temp=pop();
                ans=ans+(temp.occ++);
                push(temp);
            }
            if(empty()==1){push(makestc(arr[i],1));continue;}
            abc temp=makestc(arr[i],1);
            long long int cmp=cmpstur(top(),temp);
            if(cmp>0)
                push(temp);
            else if(cmp<0)
            {
                while(cmpstur(temp,top())>0 && end!=-1)
                {
                    pop();
                }
                if(cmpstur(temp,top())==0)
                    update();
                else
                    push(temp);
            }
            else
                update();         
        }
        printf("%lld\n",(n*(n-1))/2-ans);
        scanf("%lld",&n);
    }
    return 0;
}
