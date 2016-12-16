#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void push(int x);
void pop();
int to();
int empty();
int top=-1;
int a[1000001];

int to()
{
return a[top];
}
int empty()
{
if(top==-1)
return 0;
else
return 1;
}
void push(int x)
{
top++;
a[top]=x;
}
void pop()
{
top--;
}
int main()
{
int n;
n=-5;
while(n!=0)
{scanf("%d",&n);
int arr[n];
int j,k;
for(j=0;j<n;j++)
scanf("%d",&arr[j]);
long long int count=0;
int maxi;
for(j=0;j<n-1;j++)
{
maxi=arr[j+1];
for(k=j+1;k<n;k++)
{
if(arr[k]>arr[j])
{
count=count+n-k-1;
break;
}
if(arr[k]<maxi)
count=count+1;
if(arr[k]>maxi)
maxi=arr[k];
}
}
if(n!=0)
printf("%lld\n",count);
}
return 0;
}








