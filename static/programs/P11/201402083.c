
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
//typedef struct stack stack;
//global   
int input[100001],leftres[100001],rightres[100001];
//struct stack{
//    int data;
//    stack *next;
//};
int stack[100001];
int up=-1;

//stack *push(stack *head,int element);
//stack *pop(stack *head);
//int top(stack *head);
void push(int element);
void pop();
int top();
void calc_left(int n);
void calc_right(int n);
void print(int arr[],int n){int i;for(i=0;i<n;i++) printf ("%d  ",arr[i]);  printf("\n");}
void init(int arr[],int n){int i=0;for(i=0;i<n;i++) arr[i]=0;}
int main()
{
    //declaration
    int n,i;
    long long int maxarea=0,temparea=0;
    
    while(1){
        maxarea=0;
        up=-1;
        scanf("%d",&n);
        init(input,n);  init(leftres,n);  init(rightres,n); 
        if(n==0) break;
        for(i=0;i<n;i++) scanf("%d",&input[i]);
        calc_left(n);
        calc_right(n);
      //  print(input,n);
      //  print(leftres,n);
      //  print(rightres,n);
       for(i=0;i<n;i++){
            temparea = (long long int)((long long int)(rightres[i]-leftres[i]+1)*(long long int)(input[i]));
        //    printf("%lld ",temparea);
            if (temparea>maxarea) maxarea=temparea;
        }
       //printf("\n");
        printf("%lld\n",maxarea);
    }
return 0;
}

//stack *push(stack *head,int element){
//    stack *temp=(stack *)malloc(sizeof(stack));
//    temp->data=element;
//    temp->next=head;
//    return temp;
//}
void push(int element){up++;stack[up]=element;}


//stack *pop(stack *head){
//    if(head==NULL)  return ;
//    return head->next;
//}
void pop(){if(up==-1) return ;else up--;}

//int top(stack *head){
//    if(head==NULL) return -1;
//    else return head->data;
//}
int top(){if(up==-1) return -1; else return stack[up];}

void calc_left(int n){
    //stack *head=NULL;
    init(stack,n);
    int i;
    for(i=0;i<n;i++){
        while(input[top()]>=input[i]) {pop();if(top()==-1) break;}
        leftres[i]=top()+1;
        push(i);
    }
}

void calc_right(int n){
    //stack *head=NULL;
    init(stack,n);
    int i;
    for(i=n-1;i>=0;i--){
        while(input[top()]>=input[i]) {pop();if(top()==-1) break;}
        if(top()==-1)   rightres[i]=n-1;
        else  rightres[i]=top()-1;
        push(i);
    }
}


