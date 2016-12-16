#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert(int *front,int *rear,char x[],int n,char *q[])
{
//	printf("%d %d %d\n",*front,*rear,n);
    if((*front==0 && *rear==n-1)||(*front>0 && *rear==*front-1))
    {
	    /*printf("Queue is overflow\n");
	    return;
	    */
	    if((*rear)==n-1)
	    {		    *rear=0;
	       strcpy(q[*rear],x);
	       (*front)++;
    }
	    else
	    {  if((*front)==n-1)
                     

		    {	    strcpy(q[++(*rear)],x);
		    *front=0;
	    }
		    else
		    {
		    strcpy(q[++(*rear)],x);
	    (*front)++;
	    }
	    }
    }
    else
    {
        if((*rear)==n-1&&(*front)>0)
        {
            (*rear)=0;
            strcpy(q[(*rear)],x);
        }
        else
        {
            if(((*front)==0&&(*rear)==-1)||((*rear)!=(*front)-1))
                strcpy(q[++(*rear)],x);
        }
    }
    return;
}
void  delet(int *front,int *rear,int n,char *q[])
{char a[110];
    if(((*front)==0)&&((*rear)==-1))
    {
      // printf("Queue is underflow\n");
	    return;
    }
    if((*front)==(*rear))
    {
        strcpy(a,q[(*front)]);
        *rear=-1;
        *front=0;
    }
    else
        if(*front==n-1)
        {
       strcpy(a,q[*front]);
            *front=0;
        }
        else strcpy(a,q[(*front)++]);
    return;
}
 
void display(int *front,int *rear,int n,char *q[])
{
    int i,j;
    //printf("%d %d\n",*front,*rear);
    if(*front==0 && *rear==-1)
    {
     //printf("Queue is underflow\n");
	    return;
    }
    if((*front)>(*rear))
    {
    /*    for(i=0;i<=(*rear);i++)
            printf("%s\n",q[i]);*/
        for(j=(*front);j<=n-1;j++)
            printf("%s\n",q[j]);
        for(i=0;i<=(*rear);i++)
            printf("%s\n",q[i]);
        //printf("\nrear is at %d\n",q[rear]);
        //printf("\nfront is at %d\n",q[front]);
    }
    else
    {
        for(i=*front;i<=*rear;i++)
        {
            printf("%s\n",q[i]);
        }
        //printf("\nrear is at %d\n",q[rear]);
        //printf("\nfront is at %d\n",q[front]);
    }
    return;
}

int main()
{int n,y,i,t;
	char x[2];
	int front=0,rear=-1;
	char string[110];
	//rear points to topmost element of queue;
	//front points to element to be deleted;
        scanf("%d",&n);
	t=n;
	char **str=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		str[i]=(char*)malloc(100*sizeof(char));
	scanf("%s",x);
	while((strcmp(x,"Q")!=0) && (strcmp(x,"A")==0||strcmp(x,"L")==0||strcmp(x,"R")==0))
	{
	if(strcmp(x,"A")==0)
	{scanf("%d",&y);
	
		for(i=0;i<y;i++)
		{  
			scanf("%s",string);
                      insert(&front,&rear,string,t,str);
		}
	}
	if(strcmp(x,"L")==0)
	{      
		display(&front,&rear,t,str);
	}
	if(strcmp(x,"R")==0)
	{
	scanf("%d",&y);
		for(i=0;i<y;i++)
                 delet(&front,&rear,t,str);

	}
	scanf("%s",x);
	}
	return 0;
}

