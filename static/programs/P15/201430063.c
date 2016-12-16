#include<stdio.h>
void push(int n);
void pop();
int to();
int empty();
int top=-1;
int a[10007];
int j;
void push(int n)
{
top++;
a[top]=n;
}
void pop()
{
top--;
}
int empty()
{int i;
if(top==-1)
return 1;
else
return 0;
}
int to()
{
return a[top];
}
int main()
{
int t;
int n;
int k;
int i;
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&n,&k);
int b[n];
 j=0;
//printf("j is %d\n",j);
for(i=0;i<n;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
{
while(!empty()&&top>j-1)
{if(b[i]<to())
pop();
else
break;
}
push(b[i]);
if(i==k-1&&k!=n)
printf("%d ",a[j]);
if(i>k-1&&i<n-1)
{
if(a[j]==b[i-k])
j++;
printf("%d ",a[j]);
}
if(i==n-1)
{
if(a[j]==b[i-k])
j++;
printf("%d",a[j]);
}
}
printf("\n");
while(!empty())
pop();

}
return 0;
}



