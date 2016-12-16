#include <stdio.h>
#include <math.h>
//current is not the place in which the last element is inserted, it is the position on which next element will be inserted
int current;
int size;
int oldest;
char A[10001][101];
int flag;

int append (int n) {
	if(n<=0)
		return 0;
int i,val,j;
// char c[101];
	for (i = 0; i < n; i++) {
		val=(current+i)%size;
		scanf("%s", A[val]);
		j=0;
		/*while(c[j]!='\0'){
			A[val][j]=c[j];
			j++;
		}*/
		// A[val][j]='\0';
		if(val==oldest) {
			if(flag==0)
				flag=1;
				else{
			oldest=(oldest+1)%size;
			}
		}
	}
	current=(val+1)%size;
    // printf("Insert-> oldest is %d and current %d \n", oldest, current);
	return 0;
}


int remov (int n)  {
int i,j,rem;
int copy=fabs(size+current-oldest);
copy=copy%size;
	/*for (i = 0; i < n; i++) {
		rem=(copy+i)%size;
		for(j=0;j<101;j++){
			A[rem][j]='\0';
		}
		// oldest=(oldest+1)%size;
	}*/
	if ((copy==n && current!=oldest) || n==size)
	{
		for(i=0;i<size;i++){
			for (j = 0; j < 101; j++) {
				A[i][j]='\0';
			}
		}
	current=oldest;
	flag=0;
		// oldest=0;
	}
	else
	 oldest=(oldest+n)%size;
    // printf("Remove-> oldest is %d and current is %d\n", oldest, current);
	 return 0;

}


void print (){

	int test;
	int i,j,k;
	i=oldest;
	if(A[oldest][0]!='\0')
	printf("%s\n",A[oldest]);
	i=(i+1)%size;
	while(i!=current){
		if(A[i][0]!='\0')
		printf("%s\n",A[i]);
		i=(i+1)%size;
	}
    // printf("Print-> oldest is %d and current is %d \n", oldest, current);

}


int main()
{

	char a,c;
	int b;
	scanf("%d%c", &size,&c);
	if (size==0)
	{
		return 0;
	}
	while((a=getchar()) != 'Q'){
		if(a == 'A'){
			scanf("%d", &b);
			append(b);
		}
		else if (a == 'R') {
			scanf("%d", &b);
			remov(b);
		}
		else if(a == 'L'){
			print();
		}
		else if(a == 'Q'){
			return 0;
		}
	}
return 0;
}