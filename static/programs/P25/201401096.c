#include<stdio.h>
#include<stdlib.h>
#define size_v 1000003
#define size_e 1000003
typedef struct edge{
    int s,d,w;
}edge;
edge edges[size_e],temp[size_e];
typedef struct subset{
    int Parent;
    int Rank;
}subset;
int v,e;
subset sub[size_v];

int find(subset sub[],int a)
{
    if(sub[a].Parent==a)
        return a;
    else
    {
        sub[a].Parent=find(sub,sub[a].Parent);
        return sub[a].Parent;
    }
}
void Union(subset sub[],int a, int b)
{
    int pa,pb;
    //find Parents
    pa=find(sub,a);
    pb=find(sub,b);
    //attach smaller Rank under bigger Rank
    if(sub[pa].Rank>sub[pb].Rank)
        sub[pb].Parent=pa;
    else if(sub[pb].Rank>sub[pa].Rank)
        sub[pa].Parent=pb;
    else
    {
        // Ranks are equal
        sub[pb].Parent=pa;
        sub[pa].Rank++;
    }
}


void mergeSort(int low,int mid,int high){

    int i,b,count,a;

    a=low;
    i=low;
    b=mid+1;

    while((a<=mid)&&(b<=high)){

        if(edges[a].w<=edges[b].w){
            temp[i]=edges[a];
            a++;
        }
        else{
            temp[i]=edges[b];
            b++;
        }
        i++;
    }


    if(a>mid){
        for(count=b;count<=high;count++){
            temp[i]=edges[count];
            i++;
        }
    }
    else {
        for(count=a;count<=mid;count++){
            temp[i]=edges[count];
            i++;
        }
    }

    for(count=low;count<=high;count++){
        edges[count]=temp[count];
    }
}



void split(int low,int high){

    int mid;
    if(low<high){
        mid=(low+high)/2;
        split(low,mid);
        //printf("hi\n");
        split(mid+1,high);
        mergeSort(low,mid,high);
    }
}


void kruskal()
{
   
    int ed=0,i,src,dest;
    long long int count=0;
    int last;
    edge next;
    
    //1.sort all edges
 
	//printf("hiiiiiiiiii");   
     split(0,e-1);
   
    //for(i=0;i<e+1;++i)
      // printf("%d:\n",edges[i].w);
    

	//for(i=0;i<e;++i)
        //printf("%d\n",edges[i].w);
    
    //2.create subsets
    //initialise all Parents,Ranks
    //we are using unoin find by Rank
    for(i=0;i<v;++i)
    {
        sub[i].Parent=i;
        sub[i].Rank=0;
    }

    //3.MST

    i=0;
    last=e-1;
    while(ed<v-1&&i<e)
    {
        //a)pick smallest edge
        next=edges[i++];
        src=next.s;
        dest=next.d;
        
        //b)check Parents of each and check  if they form a cycle 
        int p1=find(sub,src);
        int p2=find(sub,dest);
       
    //    printf("%d<-->%d: %d , p1%d p2%d\n",next.s,next.d,next.w,p1,p2);
        
        if(p1==p2)
            continue;
        else
        {
            //ans[ed++]=next;
            count+=next.w;
            ed++;
            Union(sub,src,dest);
        }

    }
    //printf("MST\n");
/*   for (i=1;i<=v;++i)
    {
        printf("%d  <== %d\n", i, sub[i].Parent);
    //count+=ans[i].w;
    }
    printf("%d ed\n",ed);
*/
    if(ed==v-1&&i<=e)
    	printf("%lld\n",count);
	else if(ed<v-1&&i>=e)
    	printf("-1\n");

}

int main()
{
    int i;
    scanf("%d %d",&v,&e);
    //graph *g=(graph*)malloc(sizeof(graph));
   // g->v=v;
   // g->e=e;
    
    for(i=0;i<e;++i)
        scanf("%d %d %d",&edges[i].s,&edges[i].d,&edges[i].w);
    kruskal();


return 0;
}
