#include<stdio.h>
#define MAX 200000 
#define mod 1000000007
int a[MAX],left[MAX],right[MAX];
void swap(int a[], int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;

}
void heapup_max(int heap[],int newnode)
{
    if (newnode==0)
        return;
    else
    {
        int parent=(newnode-1)/2;
        if(heap[newnode]>heap[parent])
        {
            //for maxheap
            swap(heap,parent,newnode);
            heapup_max(heap,parent);
        }

    }
}
void heapdown_max(int heap[],int beg, int end)
{
    if(2*beg+1<=end) //one child exists
    {
        int l,r,largest;
        l=2*beg+1;
        largest=l;
        if(2*beg+2<=end)
        {
            //right child exists
            r=2*beg+2;
            if(heap[r]>heap[l])
                largest=r;
            else 
                largest=l;
        }
        
        if(heap[largest]>heap[beg])
        {
            swap(heap,largest,beg);
            heapdown_max(heap,largest,end);
        }
    }

}


int insertHeap_max(int heap[],int *last,int data)
{
    if (*last==MAX)
        return 0;
    else
    {
        *last=*last+1;
        heap[*last]=data;
        heapup_max(heap,*last);
        return 1;
    }

}

int deleteHeap_max(int heap[],int *last)
{
    if(*last<0)
        return 0;

    else
    {int gone=heap[0];
        heap[0]=heap[*last];
        *last=*last-1;
        heapdown_max(heap,0,*last);
    return gone;
    }

}
/***********************************************/
void heapup_min(int heap[],int newnode)
{
    if (newnode==0)
        return;
    else
    {
        int parent=(newnode-1)/2;
        if(heap[newnode]<=heap[parent])
        {
            //for maxheap
            swap(heap,parent,newnode);
            heapup_min(heap,parent);
        }

    }
}
void heapdown_min(int heap[],int beg, int end)
{
    if(2*beg+1<=end) //one child exists
    {
        int l,r,largest;
        l=2*beg+1;
        largest=l;
        if(2*beg+2<=end)
        {
            //right child exists
            r=2*beg+2;
            if(heap[r]<heap[l])
                largest=r;
            else 
                largest=l;
        }
        
        if(heap[largest]<=heap[beg])
        {
            swap(heap,largest,beg);
            heapdown_min(heap,largest,end);
        }
    }

}

//void buildHeap(int heap[],int size)
//{

  //  int walker=1;
    //while(walker<size)
    //{
      //  heapup(heap,walker);
        //walker=walker+1;
    //}

//}

int insertHeap_min(int heap[],int *last,int data)
{
    if (*last==MAX)
        return 0;
    else
    {
        *last=*last+1;
        heap[*last]=data;
        heapup_min(heap,*last);
        return 1;
    }

}

int deleteHeap_min(int heap[],int *last)
{
    if(*last<0)
        return 0;

    else
    {int gone=heap[0];
        heap[0]=heap[*last];
        *last=*last-1;
        heapdown_min(heap,0,*last);
        return gone;
    }

}

int main()
{
    int n,i;
    int test;
    int last_left,last_right;
    long long int sum=1;
    int sl,sr;
    int temp;
    long long int f,a,b,c;
    scanf("%d",&test);
    while(test--)
    {
    scanf("%lld%lld%lld%d",&a,&b,&c,&n);
    f=1;
    last_left=-1;
    last_right=-1;
    sl=0;
    sr=0;
    sum=1;
    insertHeap_min(left,&last_left,1);
    sl++;
    //calculation;
    for(i=2;i<=n;++i)
    {
        temp=left[0];
        f=(a*temp+b*(i)+c)%mod;
    //    printf("temp:%d f[%d]=%lld left:%d right:%d\n",temp,i,f,sl,sr);
        sum+=f;

        if(sl>sr)
        { if(f<temp)
            {
                deleteHeap_max(left,&last_left);
                insertHeap_min(right,&last_right,temp);
                insertHeap_max(left,&last_left,f);

                
            }
            else
            {
                insertHeap_min(right,&last_right,f);
                
            }
            
            sr++;
  //          printf("1left!!!%d right!!!%d\n",left[0],right[0]);
       }
        else
        { 
            temp=right[0];
            if(f>temp)
            {
                deleteHeap_min(right,&last_right);
            //    printf("--%d--\n",temp);
            
                insertHeap_max(left,&last_left,temp);
                insertHeap_min(right,&last_right,f);

            }
            else
            {
                insertHeap_max(left,&last_left,f);
            }
                        sl++;
//            printf("2left!!!%d right!!!%d\n",left[0],right[0]);
        }

    }
    printf("%lld\n",sum);
    }
   

 return 0;
}

