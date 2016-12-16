#include<stdio.h>
#include<stdlib.h>
//used long long int as l
typedef long long int l;
l m=1000000007;
struct datastructure_heap
{
    int no_elements;
    int max;
    int count;
    int *list;
};
typedef struct datastructure_heap heap;
int median(heap* hl , heap* hr);
void add(heap *hr,heap * hl ,l val);
void  resizeheap(heap *h);
void insert_min(heap* h ,int data);
void insert_max(heap* h ,int data);
int delete_max(heap *h);
int delete_min(heap *h);
int child(heap *h , int i ,int flag);
void heapify_min(heap *h , int i);
heap *new_heap(heap *h,int max);
void heapify_max(heap *h , int i);
l fun(l f1,l a, l b , l c,int i );
int main()
{
    l a,b,c,temp,med;
    l f[200001];
    int i,n,test_cases;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
	f[1]=1;
    	heap *hr,*hl; 
	hr=new_heap(hr,200001);
	hl=new_heap(hl,200001);
	//add(hr,hl,1);
	insert_max(hr,1);
	scanf("%lld%lld%lld%d",&a,&b,&c,&n);
//printf("hii\n");	
for(i=2 ; i<=n ; i++)
	{
	    med=median(hl,hr);
	   
//	    printf("median value upto i =%d is %lld\n",i,med);
	   
	    temp=fun(med,a,b,c,i);
	    f[i]=temp;
//	printf("the value of fun %lld\n",temp);
	if(i!=n)    
	add(hr,hl,temp);
	}
temp=0;
for(i=1 ; i<=n ; i++)
    temp+=f[i];
	printf("%lld\n",temp);
	free(hr);
	free(hl);
    }
    return 0;
}
l fun(l f1,l a, l b , l c,int i )
{

    l f ;

//printf("i am in fun\n");
    f=((((a*f1)%m)+(b*i))%m+c)%m;
    return f;
}
int child(heap *h , int i , int flag)
{
    int left=2*i+1;
    int right=2*i+2;
    if(flag==0)
    {
//printf("i am in min  child\n");
	if(left>=h->count)
	    return -1;
	return left;

    }
    //if(flag==1)
    else
    {
//printf("i am in max child\n");
	if(right>=h->count)
	    return -1;
	return right;
    }
}
void heapify_min(heap *hl , int i)
{
//printf("i am in min  heapify\n");
    int l,r,min,temp;
    l=child(hl,i,0);
    r=child(hl,i,1);
    if(l!=-1&& hl->list[l]<hl->list[i])
	min=l;
    else
	min=i;
    if(r!=-1&&hl->list[r]<hl->list[min])
	min=r;
    if(min!=i)
    {
	temp=hl->list[i];
	hl->list[i]=hl->list[min];
	hl->list[min]=temp;
    	heapify_min(hl,min);
    }
}
void heapify_max(heap *hr , int i)
{
//printf("i am in max heapify\n");
    int l,r,max,temp;
    l=child(hr,i,0);
    r=child(hr,i,1);
    if(l!=-1&&hr->list[l]>hr->list[i])
	max=l;
    else
	max=i;
    if(r!=-1&&hr->list[r]>hr->list[max])
	max=r;
    if(max!=i)
    {
	temp=hr->list[i];
	hr->list[i]=hr->list[max];
	hr->list[max]=temp;
    heapify_max(hr,max);
    }
}
void insert_max(heap* hr ,int data)
{
  //  printf("iam right count %d\n",hr->count);
//printf("i am in max  insert\n");
    int i;
    // if(h->count==h->max)
    //resizeheap(h);
    hr->count++;
    i=hr->count-1;
    while(i>0 && data>hr->list[(i-1)/2])
    {
	hr->list[i]=hr->list[(i-1)/2];
	i=(i-1)/2;
    }
    hr->list[i]=data;
  // printf("hr->list[%d]--%d\n",i,data);
}
void insert_min(heap* hl ,int data)
{
//printf("i am in min  insert\n");
    int i;
    if(hl->count==hl->max)
	resizeheap(hl);
    hl->count++;
    i=(hl->count)-1;
  //  printf("iam left count %d\n",hl->count);
    while(i>0 && data<hl->list[(i-1)/2])
    {
	hl->list[i]=hl->list[(i-1)/2];
	i=(i-1)/2;
    }
    hl->list[i]=data;
  //printf("hl->list[%d]--%d\n",i,data);
}
int delete_max(heap *hr)
{

//printf("i am in max  delete\n");
    int data;
    if(hr->count==0)
	return -1;
    data=hr->list[0];
    hr->list[0]=hr->list[hr->count-1];
    hr->count--;
    heapify_max(hr,0);
    return data;
}
int delete_min(heap* hl)
{

//printf("i am in min delete\n");
    int data;
    if(hl->count==0)
	return -1;
    data=hl->list[0];
    hl->list[0]=hl->list[hl->count-1];
    hl->count--;
    heapify_min(hl,0);
    return data;
}
void  resizeheap(heap *h)
{
    int i,*list_old=h->list;
    h->list=(int*)malloc(sizeof(int)*h->max*2);
    for(i=0 ;i<h->max ; i++ )
	h->list[i]=list_old[i];
    h->max*=2;
    free(list_old);
}
void add(heap *hr,heap * hl , l val)

{
    l top;
    if(val>hr->list[0])
    {
    insert_min(hl,val);
    }
    else
    {
    insert_max(hr,val);
    
    }
if((hr->count-hl->count)>1)
    {
//printf("i am in min  heap add \n");
	top=delete_max(hr);
	if(top!=-1)
	insert_min(hl,top);
    }
    if((hl->count-hr->count)>1)
    {
//printf("i am in max heap add \n");
	top=delete_min(hl);
	if(top!=-1)
	insert_max(hr,top);
    }
}
int median(heap* hl , heap* hr )
{
//printf("i am in median \n");
    if(hr->count==hl->count)
    {
	return hr->list[0];
    }
    else if(hr->count>hl->count)
    {
	return hr->list[0];
    }
    else
    {
	return hl->list[0];
    }
}
heap *new_heap(heap *h,int max)
{
    h=(heap*)malloc(sizeof(heap));
    h->count=0;
    h->max=max;
    h->list=(int*)malloc(sizeof(int)*max);
    return h;
}
