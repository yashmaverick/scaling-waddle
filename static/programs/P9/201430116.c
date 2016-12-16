#include<stdio.h>
int main()
{
        int n,mod;
	scanf("%d %d",&n,&mod);
	int i,j,*a[n],k,b[n],index,swap;
	long long int total;
/*	a[0]=(int *)malloc(mod*sizeof(int));
	for(i=0;i<mod;i++){
		scanf("%d",&a[0][i]);
	}
	for(i=0;i<mod;i++){
		printf("%d ",a[0][i]);
	} */
        for(i=0;i<n;i++){
            total=0;
	    scanf("%d",&j);
            a[i]=(int *)malloc((j+2)*sizeof(int));
	    a[i][0]=j;
	    for(k=1;k<=j;k++){
		    scanf("%d",&a[i][k]);
		    total+=a[i][k];
		    total=total%mod;
	    }
	    a[i][j+1]=total;
	}
     for(i=0;i<n;i++){
     	b[i]=i;
     }
    for(i=0;i<n;i++){
	//	index=i;                                    //sorting
		for(j=0;j<n-i-1;j++){
			if(a[b[j]][a[b[j]][0]+1]>a[b[j+1]][a[b[j+1]][0]+1]){
				swap=b[j];
				b[j]=b[j+1];
				b[j+1]=swap;
			}
		}
	//	b[i]=index;
	}
        for(i=0;i<n;i++){
		k=b[i];
	//	printf("b %d  ",k);                       //printing sorted array
		printf("%d\n",a[k][a[k][0]+1]);
		for(j=1;j<=a[k][0];j++)
			printf("%d\n",a[k][j]);
		printf("\n");
	}	
	return 0;
}
