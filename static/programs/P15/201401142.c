#include <stdio.h>
typedef long long int LL;
LL cirq[200001];
LL cirqstart,k,num;
LL cirqend;
LL stay[200001];
void pri()
{
/*   int i;
   printf("Queue\n");
   for(i=cirqstart;i<=cirqend;i++,i=i%k)
      printf("%lld ",cirq[i]);
   printf("\n");*/
}
LL putinbuffer(LL what)
{
   LL popped=0;
   if(stay[cirqstart]==0)
   {
      //Move the queue ahead.
      cirqstart++;
      cirqstart = cirqstart%k;
   }
   else
      stay[cirqstart]--;
   if(what<=cirq[cirqstart])
   {
      stay[cirqstart] = k - 1;
      cirq[cirqstart] = what;
      cirqend = cirqstart;
   }
   else
   {
      while(what<=cirq[cirqend])
      {
         popped += stay[cirqend];
         cirqend--;
         if(cirqend<0)
            cirqend+=k;
         popped++;
      }
      cirqend++;
      cirqend = cirqend%k;
      cirq[cirqend] = what;
      stay[cirqend] = popped;
   }
   pri();
   return 0;
}
int main()
{
   LL te,i,input;
   scanf("%lld",&te);
   while(te--)
   {
      //Buffer is initialied.
      cirqstart = cirqend = 0;
      scanf("%lld %lld",&num,&k);
      scanf("%lld",&cirq[0]);
      stay[0] = k - 1;
      if(k==1)
         if(num!=1)
            printf("%lld ",cirq[0]);
         else 
            printf("%lld", cirq[0]);
      for(i=1;i<num;i++)
      {
         scanf("%lld",&input);
         putinbuffer(input);
         if(i>=(k-1))
            if(i!=(num-1))
               printf("%lld ",cirq[cirqstart]);
            else 
               printf("%lld",cirq[cirqstart]);
      }
      printf("\n");
   }
   return 0;
}
