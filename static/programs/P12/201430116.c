#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	while(n!=0){
	int a[n+9];
	for(i=0;i<n;i++){
        scanf("%d",&a[i]);
	}
	int d[n][2],j=0,state=0,k=0,first,in;   // k for storing poped out index
	long long int total=0;   // state to indicate push or pop
	d[0][0]=a[0];
    d[0][1]=0;
	for(i=1;i<n;i++){
		if(a[i]>d[j][0]){
//			int temptotal=0;
			while ((a[i]>d[j][0])&&j>0){
			//    if(a[i]>d[j-1][0])
			      total+=(d[j][1]-d[j-1][1]-1);      // 1 2 3 !! arry mei aise ele nahi ..
				j--;				
			}
			if(j==0&&(a[i]>d[j][0])){
				total+=d[j][1];        //  2 1 4 7 3 3 8 && 1 2  3 4
				d[j][0]=a[i];
				d[j][1]=i;
			}
//			imp equal case dal
			else if(a[i]==d[j][0]){
			    int temp,temptotal=0;;
			    temp=j;
			   while(temp>=1&&a[i]==d[temp][0]){
	//			  if(d[temp-1][0]==a[i])
					  temptotal+=(d[temp][1]-d[temp-1][1]-1);
				  temp--;
			     }
			    if(a[i]<d[temp][0])
			    	temptotal+=d[temp][1];
			    else if(temp==0&&a[i]==d[temp][0])
				   temptotal+=d[temp][1];
			  total+=temptotal;
			  j++;
			  d[j][0]=a[i];
              d[j][1]=i;
		    }
			else{
				total+=d[j][1];
				j++;
				d[j][0]=a[i];
				d[j][1]=i;
			}
		}
		else if(a[i]==d[j][0]){
			int temp,temptotal=0;;
			temp=j;
			while(temp>=1&&a[i]==d[temp][0]){
	//			if(d[temp-1][0]==a[i])
					temptotal+=(d[temp][1]-d[temp-1][1]-1);
				temp--;
			}
			if(a[i]<d[temp][0])
			    	temptotal+=d[temp][1];
			if(temp==0&&a[i]==d[temp][0])
				temptotal+=d[temp][1];
			total+=temptotal;
			j++;
			d[j][0]=a[i];
           d[j][1]=i;
		}
		else if(a[i]<d[j][0]){
			total+=d[j][1];
			j++;
			d[j][0]=a[i];
			d[j][1]=i;
		}
	}
	printf("%lld\n",total);
	scanf("%d",&n);
    }
	return 0;
}