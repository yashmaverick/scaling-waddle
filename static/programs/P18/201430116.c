#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
};
typedef struct list element;
typedef element *link;
int visited[1009],n,count;
void dfs(link node,link a[])
{
//    if(state!=1){

        visited[node->data]=1;
        (count)++;
    //    printf("%d\n",count);
    /*    if(count==n)
            state=1; */
        link tmp;
        tmp=node->next;
        while(tmp!=NULL){
            if(visited[tmp->data]!=1){
                dfs(a[tmp->data],a);
            }
            tmp=(tmp->next);
        }
//        visited[node->data]=0;
//    printf("%d\n",node->data);
        return;
  //  }
}
int main()
{
    int sw,z;
    scanf("%d",&sw);
    for(z=0;z<sw;z++)
    {
	   int i,nh,temp,j;
	   scanf("%d",&n);
        link a[n+9],b[n+9];
        link t,tm;
    //    a=malloc((n+9)*sizeof(link));
     //   int d[n+9];
      //  d=malloc((n+9)*sizeof(int));

      //  d[0]=0;
        for(i=1;i<=n;i++)
        {
    	//   d[i]=0;
    	   a[i]=malloc(sizeof(element));
    	   a[i]->data=i;
    	   a[i]->next=NULL;
           b[i]=malloc(sizeof(element));
           b[i]->data=i;
           b[i]->next=NULL;
        }
        for(i=1;i<=n;i++)
        {
      //      for(j=1;j<=n;j++)
        //        d[j]=0;
           t=b[i];
    	   scanf("%d",&nh);  // nh kitno se hara
    	   for(j=1;j<=nh;j++)
    	   {
              link temp2;
    		  scanf("%d",&temp);
    	//	  d[temp]=1;
              temp2=malloc(sizeof(element));
              temp2->data=i;
              temp2->next=(a[temp]->next);
              a[temp]->next=temp2;
              link temp3;
         //     scanf("%d",&temp);
        //    d[temp]=1;
              temp3=malloc(sizeof(element));
              temp3->data=temp;
              temp3->next=t->next;
              t->next=temp3;
              t=t->next;
    	   }
    //	   t=a[i];
    	/*   for(j=1;j<=n;j++)
    	   {
    		  if((j!=i)&&(d[j]!=1))          
    		  {
    			 (t->next)=malloc(sizeof(element));
    			 (t->next)->data=j;
    			 (t->next)->next=NULL;
                    t=t->next;
    		  }
    	   } */
        }
/*    for(j=1;j<=n;j++)
    {
        t=b[j];
        while(t!=NULL)            // printing graph
        {
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }  */ 
        // d as visited array
        int ans=0;
        for(i=1;i<=n;i++)
        {    
            for(j=1;j<=n;j++)
                visited[j]=0;// har node ke liye dfs isliye visited=0
            count=0; // no of node visited
    //        state=0;
            dfs(a[i],a);
    //    printf("%d\n",count);
            if(count==n){
                tm=a[i];
                ans++;
                break;
            }
        }
        if(ans){
            count=0;
            for(j=1;j<=n;j++)
                visited[j]=0;
            dfs(b[tm->data],b);
            ans=count;

        }
        printf("%d\n",ans);
    } 
	return 0;
}