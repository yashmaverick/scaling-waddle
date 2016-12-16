#include<stdio.h>

int something[100000],left=-1,right=-1,n,k;

void el(int val){
    if(left==right && left==-1){
        left=0;
        right=0;
        something[left]=val;
        return;
    }
    left++;
    if(left==k)left=0;
    something[left]=val;
    return;
}

void er(int val){
    if(left==right && left==-1){
        left=0;
        right=0;
        something[left]=val;
        return;
    }
    right--;
    if(right==-1)right=k-1;
    something[right]=val;
    return;
}

int dl(){
    if(left==right && left==-1){
        return -1;
    }
    int x=something[left];
    if(left==right){
        left=-1;right=-1;
    }
    else{
        left--;
        if(left==-1)left=k-1;
    }
    return x;
}

int dr(){
    if(left==right && left==-1){
        return -1;
    }
    int x=something[right];
    if(left==right){
        left=-1;right=-1;
    }
    else{
        right++;
        if(right==k)right=0;
    }
    return x;
}

int pl(){
    if(left==right && left==-1){
        return -1;
    }
    return something[left];
}

int pr(){
    if(left==right && left==-1){
        return -1;
    }
    return something[right];
}

int main(){
    int t;
    int a[100000],i,j;
    scanf("%d",&t);
    while(t--){
        left=-1;right=-1;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<k;i++){
            //    printf("left=%d right=%d peek=%d\n",left,right,a[pr()]);
            while(1){
                if(a[pr()]>=a[i] && left!=-1)
                    dr();
                else
                    break;
            }
            er(i);
        }
        for(i=k;i<n;++i){
            printf("%d ",a[pl()]);
            while(1){
                if(pl()<=i-k && left!=-1){
                    dl();
                }
                else{
                    break;}
            }
            while(1){
                if(a[pr()]>=a[i] && left!=-1)
                    dr();
                else{
                    break;
                }
            }
            er(i);
        }
        printf("%d\n",a[pl()]);
    }
    return 0;
}


