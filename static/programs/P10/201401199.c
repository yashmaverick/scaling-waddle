#include<stdio.h>
#define size 10004
int front=-1,end=-1;

void app(char cb[size][105],int N,int n)
{
    //    printf("APP\n");
    int i;char str[105];
    if(N==0)
    {
	for(i=0;i<n;i++)
	    scanf("%s",str);
	return;
    }

    for(i=0;i<n;i++)
    {
	//	printf("front=%d , end=%d\n",front,end);
	//	printf("i=%d , n=%d\n",i,n);
	end=(end+1)%N;
	//	printf("end=%d\n",end);
	if(end==front || front==-1)
	{
	    front=(front+1)%N;
	    //	    printf("front=%d\n",front);
	}

	scanf("%s",cb[end]);
	//	printf("cb[%d]=%s\n",end,cb[end]);
    }
    //	printf("before exiting\nfront=%d , end=%d\n",front,end);
//    return;
}

void rem(char cb[size][105],int N,int n)
{
//    printf("enter rem\n");
//    printf("front=%d , end=%d\n",front,end);
    if(n==0)
	return;
    if(N==0)
	return;
    int val,i;
    if(front==end) 
    {
	front=-1;
	end=-1;
	return;
    }


    val=(front+n)%N;
//    printf("val=%d\n",val);
    if(val==front)
    {
	front=-1;
	end=-1;
	return;
    }
//    printf("looping\n");
    for(i=0;i<n;i++)
    {
	front=(front+1)%N;
//	printf("in loop front=%d\n",front);
	if(front==end && i<n-1)
	{
	    front=-1;
	    end=-1;
//    printf("before exiting\nfront=%d , end=%d\n",front,end);

	    return;
	}
    }
//    printf("complete loop\n");
//    printf("before exiting\nfront=%d , end=%d\n",front,end);
  //  return;
}

void list(char cb[size][105],int N)
{
//    printf("L\n");
//    printf("front=%d , end=%d\n",front,end);
    int i;
    if(N==0)
	return;
    if(front==-1)
	return;
    if(front<=end)
    {
//	printf("f<=e\n");
	for(i=front;i<=end;i++)
	{
//	    printf("i=%d\n",i);
	    printf("%s\n",cb[i]);
	}
    }
    else
    {
//	printf("f>e\n");
	for(i=front;i<N;i++)	
	{
//	    printf("i=%d\n",i);
	    printf("%s\n",cb[i]);
	}
	for(i=0;i<=end;i++)	
	{
//	    printf("i=%d\n",i);
	    printf("%s\n",cb[i]);
	}
    }
//    return;
}

int main()
{
    int N;
    char cb[size][105],c;
    scanf("%d",&N);
    scanf("%c",&c);
    while(c!='Q')
    {
	int n;
	if(c=='L')
	    list(cb,N);
	else if(c=='A')
	{
	    scanf("%d",&n);
	    app(cb,N,n);
	}
	else if(c=='R')
	{
	    scanf("%d",&n);
	    rem(cb,N,n);
	}
	scanf("%c",&c);
    }
    return 0;
}
