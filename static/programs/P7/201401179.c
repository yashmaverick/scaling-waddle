 #include<stdio.h>
#define MAX 1000003
#define ll long long int
#define cout(n) printf("%lld\n",n)
#define cin(n) scanf("%d", &n)

void SORT(int DuPe[],int min,int mid,int max){

    int i,m,k,l,temp[MAX];

    l=min;
    i=min;
    m=mid+1;

    while((l<=mid)&&(m<=max)){

         if(DuPe[l]<=DuPe[m]){
             temp[i]=DuPe[l];
             l++;
         }
         else{
             temp[i]=DuPe[m];
             m++;
         }
         i++;
    }

    if(l>mid)
    {
        k=m;
         while(k<=max)
         {
             temp[i]=DuPe[k];
             i++;
             k++;
         }
    }
    else{
        k=l;
         while(k<=mid){
             temp[i]=DuPe[k];
             i++;
             k++;
         }
    }
   
    for(k=min;k<=max;k++){
         DuPe[k]=temp[k];
    }
}

void SPLIT(int DuPe[],int min,int max){

    int mid;

    if(min<max){
         mid=(min+max)/2;
         SPLIT(DuPe,min,mid);
         SPLIT(DuPe,mid+1,max);
         SORT(DuPe,min,mid,max);
    }
}

int main(){
   
    
    int Test;

    cin(Test);
    while(Test>0)
    {
                int DUPE[MAX],B[MAX],i,n,FLAG;
                ll dupairs=0,count;
                cin(n);

                for(i=0;i<n;i++){
                     scanf("%d",&DUPE[i]);
                }

                SPLIT(DUPE,0,n-1);
                FLAG= 0,count= 1 ;
                i=0; 
                while (i<n-1)
                {
                    if (DUPE[i] == DUPE[i+1])
                    {
                        count++;
                        FLAG = 1;
                        //printf("%lld\n",count);
                    }


                    else
                    {
                        dupairs += (count * (count-1))/2;
                        FLAG = 0;
                        count = 1;
                    }
                    i++;
                }
                //printf("%lld\n",count);
                dupairs = dupairs + count * (count-1)/2;
                cout(dupairs);
                Test--;
    }

        /*if(DUPE[0]==DUPE[1])
            B[j]=count++;
 if (DUPE[i]==DUPE[i+1] && (i+1)!=n )
        {
            if(DUPE[i]==DUPE[i-1])
                B[j]=count+1; else
            {     
        }*/
       

   return 0;
}




