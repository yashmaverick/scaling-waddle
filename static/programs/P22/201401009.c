#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
long long int l[300000],r[300000],m=0,lheap=-1,rheap=-1;

int comp(long long int a,long long b){
        if(a==b)
                return 0;
        else if(a>b)
                return 1;
        else
                return -1;
}
void minheapify(long long int i){
        long long int p=(i-1)/2;
//        printf("a\n");      
//        printf("%lld %lld %lld %lld %lld\n",r[p],r[i],p,i,r[0]);
        if(i<=0)
                p=-1;
        if(p>=0 && r[p]>=r[i]){
                long long int t=r[p];
                r[p]=r[i];
                r[i]=t;
//                if(rheap>=6){
  //                      printf("%lld %lld %lld %lld\n",r[p],r[i],p,i);
  //              }
                minheapify(p);
        }
}
void minheapify1(long long int i){
        long long int q,w,e,t;
        e=i;
        q=2*i+1;
        w=2*i+2;
        if(r[q]<r[e] && q<=rheap)
                e=q;
        if(r[w]<r[e] && w<=rheap)
                e=w;
        if(e!=i){
                t=r[i];
                r[i]=r[e];
                r[e]=t;
                minheapify1(e);
        }
}

void maxheapify1(long long int i){
        long long int q,w,e,t;
        e=i;
        q=2*i+1;
        w=2*i+2;
        if(l[q]>l[e] && q<=lheap)
                e=q;
        if(l[w]>l[e] && w<=lheap)
                e=w;
        if(e!=i){
                t=l[i];
                l[i]=l[e];
                l[e]=t;
                maxheapify1(e);
        }
}

void maxheapify(long long int i){
        long long int p=(i-1)/2;
        if(i<=0)
                p=-1;
        if(p>=0 && l[p]<=l[i]){
                long long int t=l[p];
                l[p]=l[i];
                l[i]=t;
                maxheapify(p);
        }
}

void insertl(long long e){
        lheap++;
        l[lheap]=e;
        maxheapify(lheap);
}

void insertr(long long int e){
        rheap++;
        r[rheap]=e;
    //    printf("\n\n%lld %lld\n\n",rheap,r[0]);
        minheapify(rheap);
}

long long int extracttopl(void){
        long long int q=-1;
        if(lheap>-1){
                q=l[0];
                long long int t=l[0];
                l[0]=l[lheap];
                l[lheap]=0;
                lheap--;
                maxheapify1(0);
                
        }
        return q;
}

long long int extracttopr(void){
        long long int q=-1;
        if(rheap>-1){
                q=r[0];
                long long int t=r[0];
                r[0]=r[rheap];
                r[rheap]=INT_MAX;
                rheap--;
                minheapify1(0);
                
        }
        //        printf("###%lld#%lld#%lld##",q,r[0],r[1]);
        return q;
}

long long int gettopl(){
        long long int q=-1;
        if(lheap>=0){
                q=l[0];
        }
        return q;
}

long long int gettopr(){
        long long int q=-1;
        if(rheap>=0)
                q=r[0];
        return q;
}

long long int count(long long w){
        return w+1;
}
long long int getmed(long long int i,long long med,long long int l[],long long int r[]){
        int si=comp(count(lheap),count(rheap));
        long long int me;
      //  printf("%lld\n",i);
      //  printf("%lld--%lld--%d--",lheap+1,rheap+1,si);
        if(si==1){
                if(i<=med){
                        insertr(extracttopl());
                        insertl(i);
                }
                else{
                        insertr(i);
                }
                me=gettopl();
                //              printf("  %lld  ",l[0]);
        }
        else if(si==0){
                if(i<=med){
                        insertl(i);
                        me=gettopl();
                        //                    printf("  %lld  ",l[0]);
                }
                else{
                        insertr(i);
                        me=gettopr();
                        //                  printf("  %lld  ",r[0]);
                }
        }
        else if(si==-1){
                if(i<=med){
                        insertl(i);
                }
                else{
                        insertl(extracttopr());
                        //              printf("@@@%lld@@@",gettopr());
                        insertr(i);
                }
                me=gettopl();
                //        printf("  %lld  ",l[0]);
        }
//        printf("topr--%lld--",gettopr());
        return me;
}

void print(long long int *q,long long int n){
        int i;
        for(i=0;i<=n;i++){
                printf("%lld ",q[i]);
        }
        printf("\n");
}

int main(){
        long long int test;
        scanf("%lld",&test);
        while(test--){
                long long int a,b,c,n,y,u;
                scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
//                f=(long long int *)malloc((n+1)*sizeof(long long int));
                y=1;
                //l=(long long int *)malloc((n+1)*sizeof(long long int));
                //r=(long long int *)malloc((n+1)*sizeof(long long int));
                long long int i;
                for(i=0;i<n;i++){
                    l[i]=INT_MIN;
                    r[i]=INT_MAX;
                }
                long long sum=0;
                m=1,lheap=-1,rheap=-1;
                for(i=2;i<=n;i++){
                        m=getmed(y,m,l,r);
                        y=a*m+b*i+c;
                        y=y%1000000007;
                        sum=sum+y;
//                        printf("med:%lld f[i]:%lld\n",m,f[i]);
  //                      printf("%lld\n",sum);
//                        print(l,lheap);
  //                      print(r,rheap);
                }
                printf("%lld\n",sum+1);
        }
        return 0;
}
