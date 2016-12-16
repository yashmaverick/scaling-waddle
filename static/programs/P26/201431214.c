#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    long long  int weight;
    struct node* next;
}node;
int b;
int visited2[11111],q[11111],flag=0;
node* head[11111];
int front=-1;
int top=0;
int prime[11111];
void insert(int num1,int num2,int we){
    node* p;
    node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->value=num2;
    temp->next=NULL;
    temp->weight=we;
    if(head[num1]==NULL)
    {

        head[num1]=temp;
    }
    else{
        p=head[num1];
        head[num1]=temp;
        temp->next=p;
    }
}
/*void print(){
  int i;
  for(i=1;i<=top;i++)
  printf("we=%lld src= %d\n",q[i]->we,q[i]->src);
  printf("\n");
  }*/
/*void print(int v1,int v2)
  {
  int i;
  i=1033;
  for(i=1000;i<=10000;i++)
  {
  if(prime[i]==0)
  {
  printf("%d------------> ",i);
  node* temp=head[i];
  while(temp!=NULL)
  {
  printf("%d ",temp->value);
  temp=temp->next;
  }

  printf("\n");
  }}
  }*/
void sieve()
{
    int i,j;
    for(i=2;i*i<=10000;i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=10000;j=j+i)
            {
                prime[j]=1;
            }
        }
    }
}
int main()
{
    int i,j,d1,d2,d3,d4;
    for(i=1;i<=10000;i++)
    {
        prime[i]=0;
    }
    sieve();
    for(j=1000;j<=9999;j++)
    { 
        if(prime[j]==0)
        {
            d1=j%10;
            i=j;
            while(i<=9999 && d1<=9)
            {
                if(prime[i]==0 && i!=j)
                {
                    insert(i,j,1);
                    insert(j,i,1);
                }
                i++;
                d1=d1+1;
            }
            d2=j/10;
            d2=d2%10;
            i=j;
            while(i<=9999 && d2<=9)
            {
                if(prime[i]==0 && i!=j)
                {
                    insert(i,j,1);
                    insert(j,i,1);
                }
                i=i+10;
                d2=d2+1;
            }
            d3=j/100;
            d3=d3%10;
            i=j;
            while(i<=9999 && d3<=9)
            {
                if(prime[i]==0 && i!=j)
                {
                    insert(i,j,1);
                    insert(j,i,1);
                }
                i=i+100;
                d3=d3+1;
            }
            d4=j/1000;
            i=j;
            while( i<=9999 && d4<=9)
            {
                if(prime[i]==0 && i!=j)
                {
                    insert(i,j,1);
                    insert(j,i,1);
                }
                i=i+1000;
                d4=d4+1;
            }
        }
    }
    //print(1000,10000);
    int test,t,c,depth[11111];
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {   
        top=0;
        int a,b,c;
        scanf("%d %d",&a,&b);
        // scanf("%d %d",&a,&b);    
        if(a!=b)
        {
            for(i=1000;i<=10000;i++)
            {
                visited2[i]=0;
                depth[i]=0;
            }
            node* temp=head[a];
            front++;
            q[front]=a;
            visited2[a]=1;
            while(front>=top)
            {
                temp=head[q[top]];
                c=q[top];
                visited2[q[top]]=2;
                top++;
                while(temp!=NULL)
                {
                    if(visited2[temp->value]==0)
                    {
                    front++;
                    visited2[temp->value]=1;
                   depth[temp->value]=depth[c]+1;
                    q[front]=temp->value;}
                    if(temp->value==b)
                    {
                        flag=1;
                    }
                    temp=temp->next;
                }
                if(flag==1)
                {
                    break;
                }
            }
            }
        top=0;
        front=-1;
        flag=0;
        
            //printf("%d\n",depth[b]);

            if(a!=b && visited2[b]==0 )
              {
              printf("Impossible\n");
              }
              else if(a!=b && visited2[b]==1 )
              {
              printf("%d\n",depth[b]);
              }
              else if(a==b)
              {
              printf("0\n");
              }
        }
        return 0;
    }

