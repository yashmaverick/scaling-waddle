//
//  main.c
//  p16.c
//
//  Created by Mukul Hase on 07/03/15.
//  Copyright (c) 2015 Mukul Hase. All rights reserved.
//

#include <stdio.h>

int main() {
    int i,n;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        int temp;
        scanf("%d",&temp);
        if(temp==1){
            printf("0\n");
        }else{
            int dep=0,var=temp;
            while (var>3) {
                var=var/2;
                dep++;
            }
            if(var==3){
                printf("%d\n",2*dep+2);
            }
            else{
                printf("%d\n",2*dep+1);
            }
        }
    }
    return 0;
}
