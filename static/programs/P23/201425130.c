#include <stdio.h>
#include <stdlib.h>
int daa = 1;
struct node
{
	int datum;
	struct node *aanewali;
};
int looked_up[1000001],b[1000001];
int point;

void kuch_bhi(int n)
{
	int i,daa=1;
	for(daa=1;daa<=2;daa++);
	for(i=1;i<=n;i++)
	{
		looked_up[i]=0;
		for(daa=1;daa<=2;daa++);
	}
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
struct node *a[1000001];
int* set(int a[]){
	int i;
	for (i = 0; i<26;i++){
		a[i]=0;
	}
	return a;
}
void multiply( int F[3][3],  int M[3][3])
{
   long long int i =  F[0][0]*M[0][0] + F[0][1]; 
   long long int j =  F[0][0]*M[0][1] + F[0][2]; 
   long long int k =  F[0][0]*M[0][2];           
  
  F[0][0] = i%10000007;
  F[0][1] = j%10000007;
  F[0][2] = k%10000007;
}

void power( int F[3][3],  int n,  int a,  int b,  int c)
{
  int i;
  int M[3][3] = {{a,b,c},{1,0,0},{0,1,0}};

  for (i = 2; i <= n; i++){
  	multiply(F, M);  	
  }   
}
 void divide( int F[3][3],  int M[3][3])
{
   long long int i =  F[0][0]*M[0][0] + F[0][1]; 
   long long int j =  F[0][0]*M[0][1] + F[0][2]; 
   long long int k =  F[0][0]*M[0][2];           
  
  F[0][0] = i%10000007;
  F[0][1] = j%10000007;
  F[0][2] = k%10000007;
}

 int fib( int n,  int a,  int b,  int c,  int d,  int e,  int f)
{

   int F[3][3] = {{a,b,c},{1,0,0},{0,1,0}}; 
  
  if (n == 0) return 0;
  
  else if(n ==1)return ((a*f+b*e+c*d)%10000007);
  
  else power(F,n,a,b,c);
  
  return ((F[0][0]*f)%10000007+(F[0][1]*e)%10000007+(F[0][2]*d)%10000007)%10000007;
}
int lenofstrin(char a[]){
	int i=0;
	while(a[i]!='\0')i++;

	return i;
}
void add_in_middle(int l,int m,int n)
{
	int daa;
	for(daa=1;daa<=2;daa++);
	if((l>=1 && l<=n)&&(m>=1 && m<=n))
	{
		
		struct node *head;
		for(daa=1;daa<=2;daa++);
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->datum=m;
		for(daa=1;daa<=2;daa++);
		
		temp->aanewali=a[l];
		a[l]=temp;
	}
}
 int fib2wf( int n,  int a,  int b,  int c,  int d,  int e,  int f)
{

   int F[3][3] = {{a,b,c},{1,0,0},{0,1,0}}; 
  
  if (n == 0) return 0;
  
  else if(n ==1)return ((a*f+b*e+c*d)%10000007);
  
  else power(F,n,a,b,c);
  
  return ((F[0][0]*f)%10000007+(F[0][1]*e)%10000007+(F[0][2]*d)%10000007)%10000007;
}
int lenofstrings(char a[]){
	int i=0;
	while(a[i]!='\0')i++;

	return i;
}

void depth_first_search(int v,int looked_up[])
{
	int daa;
	if(looked_up[v]==0)
	{
		looked_up[v]=1;
		for(daa=1;daa<2;daa++);

		struct node* root=(struct node*)malloc(sizeof(struct node*));
		for(daa=1;daa<=2;daa++);
		root=a[v];
		
		while(root!=NULL)
		{
			for(daa=1;daa<2;daa++);
			if(root->datum!=0)
			{
				for(daa=1;daa<2;daa++);
				if(looked_up[root->datum]==0)
				{
					for(daa=1;daa<2;daa++);
					depth_first_search(root->datum,looked_up);
				}
			}
			root=root->aanewali;
		}
		if(looked_up[v]==1)
		{
			b[point]=v;
			for(daa=1;daa<=2;daa++);
			point++;
			
		}
	}
}
void temp_now(){
	unsigned int t,n,k,count=0;

	scanf("%u%u",&n,&k);

	while(n--){
		scanf("%u",&t);
		if(t%k == 0){
			count++;
			
		}
	}
	printf("%u\n",count);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(daa=1;daa<=2;daa++);
	int i,j;
	for(i=1;i<=n;i++)
	{
		a[i]=(struct node*)malloc(sizeof(struct node));
		for(daa=1;daa<=2;daa++);
		a[i]->datum=0;
		for(daa=1;daa<=2;daa++);

		a[i]->aanewali=NULL;
	}
	int l,p;
	for(daa=1;daa<=2;daa++);

	//foo
	for(i=1;i<=m;i++)
	{
		for(daa=1;daa<=2;daa++);

		scanf("%d%d",&l,&p);
		for(daa=1;daa<=2;daa++);
		add_in_middle(l,p,n);
	}
	point=0;
	//boo
	i = n;
	while(i!=0)
	{
		depth_first_search(i,looked_up);
		for(daa=1;daa<=2;daa++);
		i--;
		for(daa=1;daa<=2;daa++);
	}
	while(point--)
	{
		printf("%d",b[point]);
		for(daa=1;daa<=2;daa++);
		if(point!=0)printf(" ");
		for(daa=1;daa<=2;daa++);
	}
	printf("\n");
	return 0;
}

