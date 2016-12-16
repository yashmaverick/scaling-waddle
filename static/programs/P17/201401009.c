#include<stdio.h>
#include<stdlib.h>
int main(){
        int n,i;
        scanf("%d",&n);
        int *a,*b;
        a=(int *)malloc(n*sizeof(int));
        b=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++){
                scanf("%d",&b[i]);
        }
        int q;
        scanf("%d",&q);
        while(q--){
                int w,e,i,h,k=0,j,*c,flag=0;
                c=(int *)malloc(n*sizeof(int));
                scanf("%d %d",&w,&e);
                for(i=0;i<n;i++){
                        if(b[i]==w || b[i]==e){
                                j=i;
                                if(b[i]==w)
                                        flag=1;
                                break;
                        }
                }
                if(flag==1){
                        while(b[i]!=e){
                                c[k]=b[i];
                                k++;
                                i++;
                        }
                        c[k]=b[i];
                        k++;
                        i++;
                }
                else{
                        while(b[i]!=w){
                                c[k]=b[i];
                                k++;
                                i++;
                        }
                        c[k]=b[i];
                        k++;
                        i++;
                }
                flag=0;
                for(i=0;i<n;i++){
                        for(h=0;h<k;h++){
                                if(a[i]==c[h]){
                                        printf("%d\n",a[i]);
                                        flag=1;
                                        break;
                                }
                        }
                        if(flag==1){
                                break;
                        }
                }
        }
        return 0;
}
