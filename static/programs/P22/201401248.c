#include<stdio.h>

#define mod 1000000007

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int a,b,c,d,n;
      long long int sum=0;
      scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
      //n=20;
      long long int minheap[1000005],maxheap[1000005];
      long long int minheap_counter=1,maxheap_counter=1;
      maxheap[1]=1;
      sum+=1;
      maxheap_counter++;
      long long int j,k,l,tmp;
      for(j=2;j<=n;j++)
	{
	  //	  printf("j is:%d\n",j);
	  tmp=(((a*maxheap[1])%mod + (b*j)%mod)%mod + c)%mod;
	  //scanf("%d",&tmp);
	  //printf("tmp is:%d\n",tmp);
	  if(maxheap_counter > minheap_counter)
	    {
	      //    	       printf("came when maxheap_counter is:%d > minheap_counter is:%d\n",maxheap_counter,minheap_counter);
	      if(tmp >= maxheap[1])
		{
		  //	  	  printf("came to tmp is:%d >= maxheap[%d] is:%d\n",tmp,maxheap_counter-1,maxheap[1]);
		  minheap[minheap_counter]=tmp;
		  // printf("minheap[%d] is:%d\n",minheap_counter,minheap[minheap_counter]);
		  k=minheap_counter;
		  minheap_counter++;
		  while(minheap[k] < minheap[k/2] && k != 1)
		    {
		      //          printf("came to swap %d with %d\n",minheap[k],minheap[k/2]);
		      l=minheap[k];
		      minheap[k]=minheap[k/2];
		      minheap[k/2]=l;
		      k=k/2;
		    }
		}
	      else
		{
		  //printf("came to tmp is:%d < maxheap[%d] is:%d\n",tmp,maxheap_counter,maxheap[1]);
		  maxheap[maxheap_counter]=tmp;
		  //printf("maxheap[maxheap_counter] is:%d\n",maxheap[maxheap_counter]);
		  k=maxheap_counter;
		  maxheap_counter++;
		  while(maxheap[k] > maxheap[k/2] && k!= 1)
		    {
		      //        printf("came to swap %d with %d\n",maxheap[k],maxheap[k/2]);
		      l=maxheap[k];
		      maxheap[k]=maxheap[k/2];
		      maxheap[k/2]=l;
		      k=k/2;
		    }
		  minheap[minheap_counter]=maxheap[1];
		  //printf("minheap[minheap_counter] is:%d",minheap[minheap_counter]);
		  k=minheap_counter;
		  minheap_counter++;
		  while(minheap[k] < minheap[k/2] && k != 1)
		    {
		      ///        printf("came to swap %d with %d\n",minheap[k],minheap[k/2]);
		      l=minheap[k];
		      minheap[k]=minheap[k/2];
		      minheap[k/2]=l;
		      k=k/2;
		    }
		  maxheap[1]=maxheap[maxheap_counter-1];
		  //printf("maxheap[1] is:%d\n",maxheap[1]);
		  maxheap_counter--;
		  k=1;
		  while((maxheap[k] < maxheap[2*k] || maxheap[k] < maxheap[2*k+1]) && 2*k+1 <= maxheap_counter)
		    {
		      //       printf("came to delete %d\n",maxheap[1]);
		      if(maxheap[k*2] > maxheap[k*2+1])
			{
			  //	  	   printf("came to swap %d with %d\n",maxheap[k*2],maxheap[k]);
			  l=maxheap[k];
			  maxheap[k]=maxheap[k*2];
			  maxheap[k*2]=l;
			  k=k*2;
			}
		      else if(maxheap[k*2] <= maxheap[k*2+1])
			{
			  // printf("came to swap %d with %d\n",maxheap[k*+1],maxheap[k]);
			  l=maxheap[k];
			  maxheap[k]=maxheap[k*2+1];
			  maxheap[k*2+1]=l;
			  k=k*2+1;
			}
		    }
		}
	    }
	  else if(maxheap_counter == minheap_counter)
	    {
	      // printf("came when maxheap_counter is:%d <= minheap_counter is:%d\n",maxheap_counter,minheap_counter);
	      if(tmp >= maxheap[1])
		{
		  //	    printf("came to tmp is:%d >= maxheap[1] is:%d\n",tmp,maxheap[1]);
		  minheap[minheap_counter]=tmp;
		  // printf("minheap[minheap_counter] is:%d\n",minheap[minheap_counter]);
		  k=minheap_counter;
		  minheap_counter++;
		  // printf("going to while while k is:%d\n",k);
		  while(minheap[k] < minheap[k/2] && k != 1)
		    {
		      //         printf("came to swap %d with %d\n",minheap[k/2],minheap[k]);
		      l=minheap[k];
		      minheap[k]=minheap[k/2];
		      minheap[k/2]=l;
		      k=k/2;
		    }
		 
		  maxheap[maxheap_counter]=minheap[1];
		  //printf("maxheap[maxheap_counter] is:%d\n",maxheap[maxheap_counter]);
		  k=maxheap_counter;
		  maxheap_counter++;
		  while(maxheap[k] > maxheap[k/2] && k != 1)
		    {
		      //      printf("came to swap %d with %d\n",maxheap[k/2],maxheap[k]);
		      l=maxheap[k];
		      maxheap[k]=maxheap[k/2];
		      maxheap[k/2]=l;
		      k=k/2;
		    }
		  minheap[1]=minheap[minheap_counter-1];
		  //printf("minheap[1] is:%d\n",minheap[1]);
		  k=1;
		
		  minheap_counter--;
		  //printf("came to while for deleting with k is:%d and minheap_counter is:%d\n",k,minheap_counter);
		  while((minheap[k] > minheap[k*2] || minheap[k] > minheap[k*2+1]) && (k*2 <= minheap_counter-1))
		    {
		      //        printf("came to delete %d with k is:%d\n",minheap[minheap_counter],k);
		      if(minheap[k*2] >= minheap[k*2+1])
			{
			  //	   printf("came to swap %d with %d\n",minheap[k*2+1],minheap[k]);
			  l=minheap[k*2+1];
			  minheap[k*2+1]=minheap[k];
			  minheap[k]=l;
			  k=k*2+1;
			}
		      else if(minheap[k*2] < minheap[k*2+1])
			{
			  //		  printf("came to swap %d with %d\n",minheap[k*2],minheap[k]);
			  l=minheap[k*2];
			  minheap[k*2]=minheap[k];
			  minheap[k]=l;
			  k=k*2;
			}
		    }
		}
	      else
		{
		  maxheap[maxheap_counter]=tmp;
		  //printf("maxheap[maxheap_counter] is:%d\n",maxheap[maxheap_counter]);
		  k=maxheap_counter;
		  maxheap_counter++;
		  ///printf("came to insert tmp is :%d\n",tmp);
		  while(maxheap[k] > maxheap[k/2])
		    {
		      //         printf("came to swap %d with %d\n",maxheap[k/2],maxheap[k]);
		      l=maxheap[k];
		      maxheap[k]=maxheap[k/2];
		      maxheap[k/2]=l;
		      k=k/2;
		    }
		}
	    }
	  // printf("maxheap[maxheap_counter-1] is:%d minheap[minheap_counter-1] is:%d\n",maxheap[maxheap_counter-1],minheap[minheap_counter-1]);
	  sum+=tmp;
	  /* int i; */
	  /*  printf("\033c"); */
	  /* printf("MAXHEAP\n"); */
	  /* for(i=1; i<maxheap_counter; i++){ */
	  /*   printf("%d ",maxheap[i]); */
	  /* } */
	  /* puts(""); */
	  /* printf("MINHEAP\n"); */
	  /* for(i=1; i<minheap_counter; i++){ */
	  /*   printf("%d ",minheap[i]); */
	  /* } */
	  /* puts(""); */
	}
     
      printf("%lld\n",sum);
    }
}
