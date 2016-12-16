#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct something{
    char arr[101];
}something;

int main(){
    int n,head,tail,num,i,time;
    char str[101];
    char c[2];
    scanf("%d",&n);
    //  getchar();
    something a[10000];
    //  something* a=(something*)malloc(n*sizeof(something));
    head=-1;tail=-1;
    while(1){
        //printf("head %d tail %d--------\n",head,tail);
        scanf("%s",c);
        //  c=getchar();
        getchar();
        if(c[0]=='A'){
            //            printf("time?\n");
            scanf("%d",&time);
            while(time--){
                //                                          printf("time=%d\n",time);
                //           scanf("%s",str);
                //                printf("string scanned\n");
                if(n==0){
                    getchar();
                    while(getchar()!='\n');
                    continue;
                }
                if(head==tail && tail==-1){
                    head++;
                    tail++;
                    //                    printf("h%dt%d\n",head,tail);
                    //
                    //strcpy(str,a[i].arr);
                    scanf("%s",a[tail].arr);
                    //                    printf("h%dt%d\n",head,tail);
                }
                else{
                    tail++;
                    if(tail>n-1){
                        tail=0;
                    }
                    if(head==tail){
                        head++;
                    }
                    if(head>n-1)head=0;
                    scanf("%s",a[tail].arr);
                }
            }
        }
        else if(c[0]=='R'){

            //            printf("time?\n");
            scanf("%d",&time);
            while(time--){
                if(n==0)
                    break;
                //                printf("time=%d\n",time);
                if(head==tail){
                    head=-1;
                    tail=-1;
                    break;
                }
                else{
                    head++;
                    if(head>n-1)head=0;
                }
            }
        }
        else if(c[0]=='L'){
            if(n==0 || (head==-1 && tail==-1))
                continue;
            if(head<=tail){
                for(i=head;i<=tail;i++){
                    printf("%s\n",a[i].arr);
                }
                //      printf("\n");
            }
            else{
                for(i=head;i<n;i++){
                    printf("%s\n",a[i].arr);
                }
                for(i=0;i<=tail;i++){
                    printf("%s\n",a[i].arr);
                }
                //       printf("\n");
            }
        }
        else if(c[0]=='Q') 
            return 0;
    }
    return 0;
}





