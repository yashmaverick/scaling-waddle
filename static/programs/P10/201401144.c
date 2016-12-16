#include <stdio.h>
#include <string.h>
int indexadd(int index, int N);
int indexsub(int index, int N);
void printprev(int index, int last);
char arr[100000][100];
int N;
int main(){
    scanf("%d",&N);
    int index=N-1, first=0,state=0,count=0;
    char a;
    getchar();
    while (1) {
        scanf("%c",&a);
        //printf("%c\n", a);
        if (a == 'A'){
            int n;
            scanf("%d",&n);
            int i;
            for(i=0;i<n;i++){
                //printf("done %d\n", n);
                //printf("index %d,first %d, count %d\n",index,first,count);
                count++;
                if(count>N){
                    first=indexadd(first,N);
                    //printf("count neg\n");
                    count--;
                }
                index = indexadd(index, N);
                scanf("%s",arr[index]);
                //printf("%s, index %d,first %d, count %d\n",arr[index],index,first,count);
            }
            //printf("done input\n");
        }
        else if (a == 'R'){
            //printf("run %d,%d\n",first,index);
            int i,n;
            scanf("%d",&n);
            for(i=0;i<n;i++){
                count--;
            	//printf("iter\n");
                if(count==-1){
                    count++;
                    break;
                }
                first=indexadd(first,N);
            }
        }
        else if (a=='L'){
            //printf("First:- %d Last:-%d\n",first,index);
            int temp,i;
            temp=first;
            for (i = 0; i < count; ++i)
            {
                printf("%s\n", arr[temp]);
                temp=indexadd(temp,N);

            }
            /*int temp=indexsub(index,N);
            //printf("%s\n", arr[index]);
            printprev(temp,last);*/
        }
        else if(a=='Q'){
            break;
        }
        getchar();
        //printf("next command\n");
    }
    return 0;
}

int indexadd(int index, int N){
    index ++;
    if (index==N) {
        index=0;
    }
    return index;
}
int indexsub(int index, int N){
    index --;
    if (index==-1) {
        index=N-1;
    }
    return index;
}