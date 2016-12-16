/*
_____________________________________________
PROBLEM STATEMENT: 
TEST CASES:
COMMENTS:

		SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int stack[1000000];
int up=-1;
int popped=-1;
void push(int element){up++;stack[up]=element;}
void pop(){if(up==-1) popped=-1;  else popped=stack[up];   up--;}
int top(){if(up==-1) return -1; else return stack[up];}
int main()
{
    //declaration
    int arr[100001][2],T,i,n,t,max,maxel;
    scanf("%d",&T);
    while(T--)
    {
        up=-1;
        popped=-1;
        for(i=0;i<100001;i++)
        {arr[i][1]=0;}
        scanf("%d",&n);
        if(n==0){printf("%d %d",arr[1][0],0);continue;}
        for(i=0;i<n;i++)
            scanf("%d",&arr[i][0]);
        t=n-1;
        push(t);
        max=arr[t][1];
        maxel=arr[t][0];
        t--;
        while(t != -1)
        {
            if(arr[t][0]>arr[top()][0]) { arr[t][1]=1+arr[top()][1]; push(t); t--;continue; }
            while(arr[t][0]<arr[top()][0])
            {                
                pop();
                if(arr[t][0]>arr[top()][0]){push(t);arr[t][1]=1+arr[popped][1];break;}
                if(top()==-1){push(t);arr[t][1]=1;break;}
            }t--;
        }
        for(i=0;i<n;i++)
        {if(arr[i][1]>max) { maxel=arr[i][0];max=arr[i][1]; }
            if(arr[i][1]==max) { if (arr[i][0]<maxel) maxel=arr[i][0]; }
        }
            printf("%d %d\n",maxel,max);
    }
    return 0;
}
