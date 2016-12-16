
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
int height[500000][2];
int flag[500000];
int stack[500000];
int up=-1;
//int popped=-1;
void push(int element){stack[++up]=element;}
void pop(){if(up==-1) return;  up--;}
int top(){if(up==-1) return -1; else return stack[up];}
int is_equal()
{
    int i;
    for(i=1;i<=up;i++) 
        if(height[stack[i]][0]!=height[stack[i-1]][0]) 
        {
            return 0;} 
    return 1;
}

long long int calc_wrong(int n)
{
    int i,k;
    long long int wrong=0;
    up=-1;
    for(i=0;i<n;i++)
    {
     //   printf("-------------\n");
     //   printf("%d-top() %d-i\n",top(),i);
        if(top()==-1) push(i);
        else if(height[i][0]<=height[top()][0]) {
            wrong++;
            if(height[i][0]==height[top()][0]) {
       //        for(k=0;k<=up ;k++) printf("%d ",stack[k]);
        //       printf("\n");
                if(is_equal()) wrong--;
          //      printf("%d-isequal\n",is_equal());
            //if(flag[top()]=1) { flag[i]=1; wrong++;}
            height[i][1]=height[top()][1]+1;
            wrong+=height[i][1];   
        }   
            push(i);
        }
        else{
            while(height[i][0]>height[top()][0]) {pop(); wrong++; if(top()==-1) break;}
            if(top()!=-1)
            {
                if(height[i][0]==height[top()][0]) { height[i][1]=height[top()][1]+1; wrong+=height[i][1]; if(is_equal()) wrong--;}
                  wrong++;
            }
//      printf("%d-i \n",i);
            push(i);
        }
  // printf("%d-i %lld-wrong\n",i,wrong);
    }
  // printf("$$$%lld-wrong\n",wrong);
    return wrong;
}

int main()
{
    int n,i;
    long long int result;

    while(1)
    {
        scanf("%d",&n); if(n==0) break;
        for(i=0;i<n;i++) height[i][1]=0;
        for(i=0;i<n;i++) scanf("%d",&height[i][0]);
        result= (long long int)((long long int )n*(long long int)(n-1))/2 - calc_wrong(n);
        printf("%lld\n",result);
    }
return 0;
}

