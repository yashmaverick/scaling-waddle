#include<stdio.h>
#include<limits.h>
typedef long long int lint;
typedef long long int ll;
#define MOD 1000000007
lint minHeap[1000001], maxHeap[1000001], minsize, maxsize;
lint median;
void insertmin(lint element)
{
        minsize++;
        minHeap[minsize]=element;
        ll now=minsize, temp;
        while(now/2>0 && minHeap[now/2]>minHeap[now])
        {
                temp=minHeap[now];
                minHeap[now]=minHeap[now/2];
                minHeap[now/2]=temp;
                now=now/2;
        }
}
void minheapify(lint index)
{
        if(2*index>minsize) //if no children
                return ;
         if(2*index+1>minsize) //if no rightchild
        {
                lint temp;
                if(minHeap[index]>minHeap[2*index])
                {
                        temp=minHeap[index];
                        minHeap[index]=minHeap[2*index];
                        minHeap[2*index]=temp;
                        minheapify(2*index);
                }
                else
                        return ;
        }
        if(minHeap[2*index]>=minHeap[index] && minHeap[2*index+1]>=minHeap[index])
                return;
        lint temp;
        if(minHeap[2*index]>minHeap[2*index+1])
        {
                temp=minHeap[2*index+1];
                minHeap[2*index+1]=minHeap[index];
                minHeap[index]=temp;
                minheapify(2*index+1);
        }
        else
        {
                temp=minHeap[2*index];
                minHeap[2*index]=minHeap[index];
                minHeap[index]=temp;
                minheapify(2*index);
        }
        return;                
       /* else
        {
                lint now=index, min_index, temp;
                while(2*now+1<=minsize)
                {
                        if(minHeap[2*now]<minHeap[2*now+1])
                                min_index=2*now;
                        else
                                min_index=2*now+1;
                        if(minHeap[now]>minHeap[min_index])
                        {
                                temp=minHeap[now];
                                minHeap[now]=minHeap[min_index];
                                minHeap[min_index]=temp;
                                now=min_index;
                        }
                        else
                                break;
               }

        }*/
}
lint mindelete()
{
        lint min=minHeap[1];
        minHeap[1]=minHeap[minsize];
        minsize--;
        minheapify(1);
        return min;
}

/* FOR MAX*/
void insertmax(lint element)
{
        maxsize++;
        maxHeap[maxsize]=element;
        ll now=maxsize, temp;
        while(now/2>0 && maxHeap[now/2]<maxHeap[now])
        {
                temp=maxHeap[now];
                maxHeap[now]=maxHeap[now/2];
                maxHeap[now/2]=temp;
                now=now/2;
        }

        
}
void maxheapify(lint index)
{
        if(2*index>maxsize) //if no children
                return ;
        else if(2*index+1>maxsize) //if no rightchild
        {
                ll temp;
                if(maxHeap[index]<maxHeap[2*index])
                {
                        temp=maxHeap[index];
                        maxHeap[index]=maxHeap[2*index];
                        maxHeap[2*index]=temp;
                        maxheapify(2*index);
                }
                else
                        return ;
        }
        if(maxHeap[2*index]<=maxHeap[index] && maxHeap[2*index+1]<=maxHeap[index])
                return;
        lint temp;
        if(maxHeap[2*index]<maxHeap[2*index+1])
        {
                temp=maxHeap[2*index+1];
                maxHeap[2*index+1]=maxHeap[index];
                maxHeap[index]=temp;
                maxheapify(2*index+1);
        }
        else
        {
                temp=maxHeap[2*index];
                maxHeap[2*index]=maxHeap[index];
                maxHeap[index]=temp;
                maxheapify(2*index);
        }
        return ;


        /*else
        {
                ll now=index, max_index, temp;
                while(2*now+1<=maxsize)
                {
                        if(maxHeap[2*now]>maxHeap[2*now+1])
                                max_index=2*now;
                        else
                                max_index=2*now+1;
                        if(maxHeap[now]<maxHeap[max_index])
                        {
                                temp=maxHeap[now];
                                maxHeap[now]=maxHeap[max_index];
                                maxHeap[max_index]=temp;
                                now=max_index;
                        }
                        else
                                break;
               }

        }*/
}
lint maxdelete()
{
        lint max=maxHeap[1];
        maxHeap[1]=maxHeap[maxsize--];
        maxheapify(1);
        return max;
}
void get_median(lint element)
{
       // printf("maxsize(left heap):%lld minsize(right heap):%lld\n", maxsize, minsize);
       if(element>maxHeap[1])
               insertmin(element);
       else
               insertmax(element);
       if(maxsize>minsize)
               insertmin(maxdelete());
       else if (maxsize<minsize)
               insertmax(mindelete());
       median=maxHeap[1];

}
void findmedian(lint a, lint b, lint c, lint n)
{
        median=1;
        ll i=2, sum=1,j;
        insertmax(1);
        lint element;
        while(i<=n)
        {
                element=(a*median+b*i+c)%MOD;
                //printf("f[%lld]=%lld median=%lld\n", i, element, median);
                /*printf("MaxHeap:");
                  for(j=0; j<=maxsize; j++)
                  printf("%lld ", maxHeap[j]);
                  printf("\nMinHeap:");
                  for(j=0; j<=minsize; j++)
                  printf("%lld ", minHeap[j]);
                  printf("\n\n");
                sum=sum+element;*/
                lint ins1, ins2;
                sum=sum+element;
                if(maxsize==minsize)
                {
                        if(element<=minHeap[1])
                        {
                                insertmax(element);
                                median=maxHeap[1];
                        }
                        else
                        {
                                insertmin(element);
                                median=minHeap[1];
                        }
                }
                else if(maxsize>minsize)
                {
                        insertmin(element);
                        if(maxHeap[1]>minHeap[1])
                        {
                                ins1=maxdelete();
                                ins2=mindelete();
                                insertmax(ins2);
                                insertmin(ins1);
                        }
                        median=maxHeap[1];
                }
                else if(maxsize<minsize)
                {
                        insertmax(element);
                        if(maxHeap[1]>minHeap[1])
                        {
                                ins1=maxdelete();
                                ins2=mindelete();
                                insertmax(ins2);
                                insertmin(ins1);
                        }
                        median=maxHeap[1];
                }
                i++;

                /*if(element<median)
                {
                        if(minsize-maxsize==1)
                        {
                                insertmax(element);
                                median=maxHeap[1];
                        }
                        else if(maxsize-minsize==1)
                        {
                                ins=maxdelete();
                                insertmin(ins);
                                insertmax(element);
                                median=maxHeap[1];

                        }
                        else if(maxsize==minsize)
                        {
                                insertmax(element);
                                median=maxHeap[1];

                        }
                        else if(maxsize-minsize==2)
                        {
                                ins=maxdelete();
                                insertmin(ins);
                                insertmax(element);
                                median=maxHeap[1];
                        }
                        else if(minsize-maxsize==2)
                        {
                                ins=mindelete();
                                insertmax(ins);
                                insertmax(element);
                                median=maxHeap[1];
                        }
                        
                        continue;
                }*/

                //NIKITA        
                /*if(element<=median)
                {
                        if(maxsize-minsize>1)
                        {
                                ins=maxdelete();
                                insertmin(ins);
                        }
                        insertmax(element);
                }
                else
                {
                        if(minsize-maxsize>1)
                        {
                                ins=mindelete();
                                insertmax(ins);
                        }
                        insertmin(element);
                }*/
                //------------------------------

                /*if(maxsize-minsize>1)
                {
                        ins=maxdelete();
                        insertmin(ins);
                        median=maxHeap[1];  //
                }
                else if(minsize-maxsize>1)
                {
                        ins=mindelete();
                        insertmax(ins);
                        median=minHeap[1];
                }
                else if(maxsize-minsize==1)
                        median=maxHeap[1];
                else if(maxsize-minsize==-1)
                        median=minHeap[1];
                else if (maxsize==minsize)
                        median=maxHeap[1];

                element=(a*median+b*i+c)%MOD;
                sum+=element;
                if(element<=median)
                        insertmax(element);
                else
                        insertmin(element);

                if(maxsize>=minsize)
                     median=maxHeap[1];
                else
                      median=minHeap[1];*/

                //i++;

        }
                                       
        printf("%lld\n", sum);

}
int main()
{
        lint T,a,b,c,n;
        scanf("%lld", &T);
        //minHeap[0]=LONG_MIN;
        //maxHeap[0]=LONG_MAX;
        while(T--)
        {
                minsize=0;
                maxsize=0;
                scanf("%lld %lld %lld %lld", &a, &b, &c, &n);
                findmedian(a,b,c,n);
        }

        return 0;
}
