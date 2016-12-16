#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        int* next;
        int m;

};
typedef struct node node;
void swap(node* p,node* q) 
{
        node temp=(*p);
        *p=*q;
        *q=temp;
}
int partition(node a[],int start,int end)
{
        node* pivot=&(a[end]);
        int pindex=start,i;
        for(i=start;i<end;i++)
        {
                if(a[i].data<=pivot->data)
                {
                        swap(&a[i],&a[pindex]);
                        pindex++;
                }
        }
        swap(&a[end],&a[pindex]);
        return pindex;
}  
void quicksort(node a[],int start,int end)
{
        if(start<end)
        {
                int pindex=partition(a,start,end);
                quicksort(a,start,pindex-1);
                quicksort(a,pindex+1,end);
        }

}
int main()
{
        int n,mod,m,w,i,j;
        scanf("%d%d",&n,&mod);
        node* a=(node* )malloc(n*sizeof(node));
       
        for(i=0;i<n;i++)
        {
                /*node* q=(node* )malloc(sizeof(node));
                  q->next=NULL;

                  if(head==NULL)
                  {
                  head=q;
                  tail=q;
                  }
                  else
                  {
                  tail->next=q;
                  tail=q;
                  } */        

                //a[i]=(node* )malloc(sizeof(node));
                a[i].data=0;
                //node* temp=a[i];
                scanf("%d",&m);
                int* temp=(int* )malloc(m*sizeof(int));
                a[i].next=temp;
                a[i].m=m;
                for(j=0;j<m;j++)
                {
                        scanf("%d",&w);
                        //node* p=(node* )malloc(sizeof(node));
                        //p->data=w;
                        //p->next=NULL;
                        //temp->next=p;
                        temp[j]=w;
                        a[i].data=(a[i].data+w)%mod;
                        //printf("%d ",sum);
                }
                //a[i]->data=sum;
        }
        //printf("%d %d %d\n",a[0]->data, a[0]->next->data,a[0]->next->next->data);
        //mergesort(a,0,n-1);
        quicksort(a,0,n-1);

        // bubble_sort(n);
        for(i=0;i<n;i++)
        {
                printf("%d\n",a[i].data);
                /*node* temp=a[i]->next;
                while(temp!=NULL)
                {
                        printf("%d\n",temp->data);
                        temp=temp->next;
                }                
                printf("\n");*/
                for(j=0;j<a[i].m;j++)
                        printf("%d\n",a[i].next[j]);
                printf("\n");
        }
//        for(i=0;i<n;i++)
  //              free(a[i]);
        return 0;
}
