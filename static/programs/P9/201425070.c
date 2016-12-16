// #Authored : Jaipal Singh Goud
// Part of : D.S. Assignment 2 
// Date : 2/3/2015
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct xyz
{
    int data;
    struct xyz *next;
}node;

void scanint(int *p);
void print_bags(int n);
void sort_elements(int n);
void add_elements(int n);

node *a[1000];
int b[1000];
int mod;
int sum,temp,temp2,weight;

int main()
{

    int i,j,n,m,d;
    int mem,pos;
    int weight;
    d = 0;
    pos = 0;

    scanf("%d %d",&n,&mod);

    int**sorter=(int**)malloc(sizeof(int*)*n);
    int**values=(int**)malloc(sizeof(int*)*n);

    for(i=0;i<n;i++)                                                // Every element has 3 fields. Weight , Corresponding index and the Total members
        sorter[i]=(int*)malloc(sizeof(int)*3);                          

    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%d",&mem);
        values[i]=(int*)malloc(sizeof(int)*mem);
 
        for(j=0;j<mem;j++)
        {
            scanf("%d",&weight);
            sum=(sum+weight)%mod;
            values[i][j]=weight;
        }
        
        sorter[pos][1]=i;
        sorter[pos][0]=sum%mod;
        sorter[pos][2]=mem;
        pos++;
    }

    for(i=0;i<n-1;i++)                                              // Bubble Sort :P n^2
    {
        for(j=i+1;j<n;j++)
        {
            if( sorter[i][0] > sorter[j][0] )
            {
                temp = sorter[i][0];
                sorter[i][0] = sorter[j][0];
                sorter[j][0] = temp;

                temp = sorter[i][1];
                sorter[i][1] = sorter[j][1];
                sorter[j][1] = temp;

                temp = sorter[i][2];
                sorter[i][2] = sorter[j][2];
                sorter[j][2] = temp;

            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",sorter[i][0]);
        for(j=0;j<sorter[i][2];j++)
        {
            printf("%d\n",values[sorter[i][1]][j]);
        }
        printf("\n");
    }
    return 0;
}

/*sort_elements(n);
  print_bags(n);
  return 0;
  }
  void add_elements(int n)
  {
  int len,x,sum;
  sum = 0;
  scanf("%d",&len);
  node *temp,*head;
  head = (node *)malloc(sizeof(node));
  temp = head;
  head->data = len;

  int i , j;
  for( i=1;i<=len;i++)                     // Iterates for Length - 1 times because one node is already created while creating the head
  {
  temp->next = (node *)malloc(sizeof(node));
  temp = temp->next;
  scanf("%d",&x);
  temp->data = x;
  sum = (sum+x)%mod;
  }
// head->weight = sum;
temp->next = NULL;
a[n] = head;
b[n] = sum;
}

void print_bags(int n)
{
int i,j,x;
node *ptr;
for(i=0;i<n;i++)
{
ptr = a[i];
x = b[i];
printf("%d\n",x);
ptr = ptr->next;
while(ptr != NULL)
{
printf("%d\n",ptr->data);
ptr = ptr->next;
}
printf("\n");
}
}

void sort_elements(int n)
{
node *temp;
int temp2;
int i,j,k;
int hold;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if( b[i] > b[j] )
{
temp = a[i];
a[i] = a[j];
a[j] = temp;

temp2 = b[i];
b[i] = b[j];
b[j] = temp2;
}
}
}
}
*/
