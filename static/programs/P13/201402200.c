#include<stdio.h>
//#include<string.h>
int visit[100001];
void ans(int root,int depth);
int maxdepth,maxvalue;

    int ind[1000001];
    int arr[100001];
int N;
int main()
{

    int i,test_cases,top;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
	//visit[100001]={0};
	int stack[100001]={0};
	scanf("%d",&N);
	for(i=0 ; i<N ; i++)
	{
	    scanf("%d",&arr[i]);
		visit[i]=0;
	}
	//memset(ind,-2,100001);
	top=-1;
	ind[0]=-1;
	int j;
	for(i= 1; i<N ; i++)
	{
	    if(arr[i]>arr[i-1])
	    {
		ind[i]=i-1;
	    }
	    else
	    {	
		j=i-1;
		while(j>=0&& arr[i]<=arr[j])
		{
		    if(ind[j]!=-1)
		    {
			if(arr[ind[j]]<arr[i])
		//	while(j>=0 )
			{ 
			    ind[i]=ind[j];
			    break;
			}
			else
			    j=ind[j];
		    }
		    else
		    {
				ind[i]=-1;
		break;
		    }

		}
	    }
	    //	    printf("%d ",ind[i]);
	}
/*	for(i=0 ; i <N ;i++)
	  {
	  printf("for i=%d ind[]=%d\n ",i,ind[i]);
    }
	  printf("\n");*/

	maxdepth=0;
	maxvalue=arr[N-1];
	ans(N-1,0);
   printf("%d %d\n",maxvalue,maxdepth);
    
   }
    return 0;
}
void ans(int root,int depth)

{
    int i;
    visit[root]=1;
    if(depth>maxdepth)
    {
	maxdepth=depth;
       maxvalue=arr[root];
    }
  //  else if(maxdepth==depth)
   // {   
//	if(arr[root]<maxvalue)
//	    maxvalue=arr[root];
  //  }
    /*for(i=0 ;i<N ;i++)
    {
	printf("%d====",visit[i]);
    }*/
    //printf("\n");
	if(root==0 || (root>0&&visit[root-1]==1)  )
    {
    //printf("prachi");
	return ;
    }
//	printf("%d---%d\n",maxdepth,depth);
    int rval=ind[root];
  //  printf("===%d\n",rval);
    if(rval!=-1 && visit[rval]==0)
    {
//	printf("lincy\n");
	ans(rval,depth+1);
    }
    if(root>0)
    {
	if(visit[root-1]!=1)
    	   ans(root-1,depth+1);
    
    }	
return;
}
