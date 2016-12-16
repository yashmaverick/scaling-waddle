
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
#define long long int lld;
#define unsigned long long int ulld;
int cursize;
void app(char arr[][101],int size,int n,int *begin,int *end);
void rem (char arr[][101],int size,int n,int *begin,int *end);
void print(char arr[][101],int size,int *begin,int *end);
int main()
{
    int N;
    char arr[10001][101];
    int i,j,n;
    char opt;
    int begin=0;
    int end=-1;

    scanf("%d",&N);getchar();
    while(1)
    {
        scanf("%c",&opt);
        if(opt=='A' || opt=='R') {scanf("%d",&n); getchar();}
        if(opt=='A') {  app(arr,N,n,&begin,&end);}
        //cursize=cursize + n;if(cursize>N) cursize=N
        else if(opt=='R') { rem(arr,N,n,&begin,&end);} 
       //cursize=cursize-n;
        else if(opt=='L') print(arr,N,&begin,&end);
        else if(opt=='Q') break;
    }
return 0;
}

void app(char arr[][101],int size,int n,int *begin,int *end)
{
    int i;
    for(i=0;i<n;i++)
    {
        char str[101];
        scanf("%s",str);
        
        if(cursize==size)
        {
            *begin = (*begin +1)%size;
            *end=(*end+1)%size;
        }
        else
            *end=(*end +1)%size;
        strcpy(arr[*end],str);
        cursize=cursize+1;
        if(cursize>size)
          cursize=size;
    }
}

void rem (char arr[][101],int size,int n,int *begin,int *end)
{
      while(n--)
      {
         *begin=(*begin+1)%size;
          cursize=cursize-1;
    if(cursize==0)
    {
        *begin=0;
        *end=-1;
        return ;

    }
      }
}

void print(char arr[][101],int size,int *begin,int *end)
{
    int i=*begin;
    int k=0;
    for(i=*begin;k<cursize;k++)
    {
        printf("%s\n",arr[i]);
        i=(i+1)%size;
    }
}
