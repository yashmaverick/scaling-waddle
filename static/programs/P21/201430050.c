#include<stdio.h>
#include<stdlib.h>
typedef long long int lld;
typedef struct node
{lld vertex;
	lld weight;
	struct node* next;
}node;
lld visar[100010]={0};
lld disar[100010]={1000000000000010};
lld c[100010];
lld track[100010][2];
node* a[100010];
void swap(lld *a,lld *b)
{lld t;
	t=*a;
	*a=*b;
	*b=t;
}
lld top;
void key(int x,int index)
{lld t;
    //track[index][0]=x;
	lld data=index;
  lld flag=0;
    while(1)
    {if(x>=track[(index)/2][0])
        {track[(index)][0]=x;
		//flag=1;
	//	printf("chootah\n");
            break;
        }
        if(x<track[(index)/2][0])
        {   flag=1;
	//printf("flag=%lld\n",flag);
            t=track[(index)][0];
            track[(index)][0]=track[(index)/2][0];
            track[(index)/2][0]=t;
            swap(&track[index][1],&track[index/2][1]);
	    swap(&c[track[index][1]],&c[track[index/2][1]]);
            
            index=(index)/2;
        }
    }
    lld i;
                track[top][0]=10000000000000010;
		track[top][1]=-4;
	/*	for(i=1;i<=(top-1)/2;i++)
		{    
		     if(track[i][0]>track[2*i][0] || track[i][0]>track[2*i+1][0])
			{
				if(track[2*i][0]<track[2*i+1][0])
				{swap(&track[i][0],&track[2*i][0]);
				        swap(&track[i][1],&track[2*i][1]);
					
				        swap(&c[track[i][1]],&c[track[2*i][1]]);
				}
				else

				{swap(&track[i][0],&track[2*i+1][0]);
				        swap(&track[i][1],&track[2*i+1][1]);
				        swap(&c[track[i][1]],&c[track[2*i][1]]);
				}
			}
		}*/
		if(flag==0 && data<=(top-1)/2)
		 {
		while(1)
		{    
		       if(data>(top-1)/2)
		       {  //printf("limit eceeded\n");
			       break;
		       }
			if(track[data][0]<track[2*data][0] && track[data][0]<track[2*data+1][0])
			{  //printf("shuffledown ho gya\n");
				break;}
			//if(track[data][0]>track[2*data][0] || track[data][0]>track[2*data+1][0])
			else
			{
				if(track[2*data][0]<track[2*data+1][0])
				{swap(&track[data][0],&track[2*data][0]);
				        swap(&track[data][1],&track[2*data][1]);
					
				        swap(&c[track[data][1]],&c[track[2*data][1]]);
					data=2*data;
				}
				else

				{swap(&track[data][0],&track[2*data+1][0]);
				        swap(&track[data][1],&track[2*data+1][1]);
				        swap(&c[track[data][1]],&c[track[2*data][1]]);
					data=2*data+1;
				}
			}
		}
		 }

}
void delete(lld in,lld n)
{lld t;
swap(&track[in][0],&track[n][0]);
swap(&track[in][1],&track[n][1]);
swap(&c[track[in][1]],&c[track[n][1]]);
t=track[n][0];
track[n][0]=10000000000000010;

    while(in<=(n-1)/2)
    {
	if(track[in][0]<track[2*in][0]&&track[in][0]<track[(2*in)+1][0])
        break;
        else
        {
            if(track[2*in][0]<=track[(2*in)+1][0])
            { 
		    swap(&track[in][0],&track[2*in][0]);
		    swap(&track[in][1],&track[2*in][1]);
				swap(&c[track[in][1]],&c[track[2*in][1]]);
                  in=2*in;
            }
            else if(track[2*in+1][0]<track[2*in][0])
            {  
		    swap(&track[in][0],&track[2*in+1][0]);
		    swap(&track[in][1],&track[2*in+1][1]);
				swap(&c[track[in][1]],&c[track[2*in+1][1]]);
                   
                    in=(2*in)+1;
           }
        }
    }
    track[n][0]=t;
}
void func(lld index,lld min)
{
		visar[index]=1;
		node* tmp2=(node*)malloc(sizeof(node));
		tmp2=a[index];
		while(tmp2->next!=NULL)
		{     if(disar[tmp2->next->vertex]>(min+tmp2->next->weight))
			  {disar[tmp2->next->vertex]=min+tmp2->next->weight;
				  track[top][0]=disar[tmp2->next->vertex];
				  track[top][1]=tmp2->next->vertex;
				  c[track[top][1]]=top;
				  top++;
                                        key(track[c[tmp2->next->vertex]][0],c[tmp2->next->vertex]);

                                              
			  }
			  //else
				  //track[c[tmp2->next->vertex]][0]=disar[tmp2->next->vertex];
			  tmp2=tmp2->next;
		}
		return;
}
int main()
{
	      lld t1,i,v,k,x,y,z,m,n,t;
	      //scanf("%lld",&t1);
	      //while(t1--)
	     // {
		scanf("%lld%lld",&v,&k);
		for(i=1;i<=v;i++)
		{	  a[i]=(node*)malloc(sizeof(node));
			a[i]->vertex=i;
			a[i]->weight=0;
			a[i]->next=NULL;
		}
		for(i=1;i<=k;i++)
		{scanf("%lld%lld%lld",&x,&y,&z);

			node* tmp=(node*)malloc(sizeof(node));
			tmp->vertex=y;
			tmp->weight=z;
			tmp->next=NULL;
			if(a[x]->next==NULL)
			{  a[x]->next=(node*)malloc(sizeof(node));
				a[x]->next=tmp;
			}
			else
			{node *tmp1=(node*)malloc(sizeof(node));
				tmp1=a[x]->next;
				a[x]->next=tmp;
				tmp->next=(node*)malloc(sizeof(node));
				tmp->next=tmp1;
			}

			/*node* tmp12=(node*)malloc(sizeof(node));
			tmp12->vertex=x;
			tmp12->weight=z;
			tmp12->next=NULL;
			if(a[y]->next==NULL)
			{  a[y]->next=(node*)malloc(sizeof(node));
				a[y]->next=tmp12;
			}
			else
			{node *tmp11=(node*)malloc(sizeof(node));
				tmp11=a[y]->next;
				a[y]->next=tmp12;
				tmp12->next=(node*)malloc(sizeof(node));
				tmp12->next=tmp11;
			}*/
          	}
for(i=0;i<=v;i++)
{disar[i]=1000000000000010;
    visar[i]=0;
}
scanf("%lld%lld",&m,&n);
	        disar[m]=0;
		track[0][0]=-1;
		track[0][1]=0;
		track[1][0]=disar[m];
		track[1][1]=m;
		top=2;
		c[m]=1;
		lld size;
		lld min;
		lld index;
		size=4;
		//for(i=1;i<=v;i++)
		//printf("weight=%lld vertex=%lld\n",track[i][0],track[i][1]);
		lld flagg;
		while(size!=0)
		{
		//lld index;
		min=track[1][0];
		index=track[1][1];
		//printf("min=%lld index=%lld\n",min,index);
                //printf("##\n");
		/*node* tmp9=(node*)malloc(sizeof(node));
		tmp9=a[index];
		while(tmp9->next!=NULL)
		{
			track[top][0]=1000000010;
			track[top][1]=tmp9->next->vertex;
			c[track[top][1]]=top;
			top++;
			tmp9=tmp9->next;
		}*/
		/*for(i=1;i<top;i++)
			printf("insertinw=%lld v=%lld\n",track[i][0],track[i][1]);
                printf("##\n");*/
		func(index,min);
		//printf("c\n");
    //           for(i=1;i<=v;i++)
//                printf("dis=%lld\n",disar[i]);
  //              printf("##\n");
//	        for(i=1;i<top;i++)
//		printf("heapw=%lld v=%lld\n",track[i][0],track[i][1]);
  //              printf("##\n");
                size=top-1;

	/*	if(visar[n]==1)
			break;
			*/
	        delete(1,size);//deletes heap[1];
		//size=size-1;
		top--;
		//printf("size=%lld\n",size);

		//rpintf("%lld\n",size);
	//	for(i=1;i<top;i++)
	//		printf("weightdel=%lld vertexdel=%lld\n",track[i][0],track[i][1]);
		//printf("d\n");
	//	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
         	}
		//printf("e\n");

            	if(disar[n]==1000000000000010)
			printf("NO\n");
		else
		printf("%lld\n",disar[n]);
	         // }	
		//top=
		
		
             	
	return 0;
}

