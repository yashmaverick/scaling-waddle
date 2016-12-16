#include<stdio.h>
#include<math.h>
long long int i,x,y,m;
long long int f[1000004];
long long int a[1000004],b[1000004];
void call_a(long long int u){
	long long int tempi; 
	long long int j=2*u;
	if(j>x) return;
	if(j+1<=x && a[j+1]>a[j])
		j++;
	if(a[u]<a[j]) {
		tempi=a[u]; 
		a[u]=a[j];
		a[j]=tempi; 
		u=j;
		call_a(u);
	}
	else
		return;
}
void call_b(long long int u) {
	long long int tempa;
	long long int j=2*u;
	if(j>y)
		return;
	if(j+1<=y && b[j+1]<b[j])
		j++;
	if(b[u]>b[j]) {
		tempa=b[u]; 
		b[u]=b[j];
		b[j]=tempa; 
		u=j;
		call_b(u);
	}
	else
		return;
}
void insert(){
	long long int g,temp;

//	printf("x=%lld y=%lld i=%lld k\n",x,y,i);
	if(x==y){
		if(f[i]<=a[1]||f[i]<=b[1]){
			x=x+1;
			a[x]=f[i];
			g=x;
			if(g>=2){
				while( g>1 && a[g/2]<a[g]){
					temp=a[g];
					a[g]=a[g/2];
					a[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
			m=a[1];
		}
		else{
			y=y+1;
			b[y]=f[i];
			g=y;
			if(g>=2){
				while(g>1 && b[g/2]>b[g]){
					temp=b[g];
					b[g]=b[g/2];
					b[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
			m=b[1];
		}

	}
	else if(x>y){
//		printf("yes1\n");
		if(f[i]<a[1]){
			if(y>0){
//				printf("yeswrong\n");
				y=y+1;
				b[y]=a[1];
				g=y;
				if(g>=2){
					while(b[g/2]>b[g]){
						temp=b[g];
						b[g]=b[g/2];
						b[g/2]=temp;
						g=g/2;
						if(g<2){
							break;
						}
					}
				}
				a[1]=a[x];
				x=x-1;
				call_a(1);
				x=x+1;
				a[x]=f[i];
				g=x;
				if(g>=2){
					while(a[g/2]<a[g]){
						temp=a[g];
						a[g]=a[g/2];
						a[g/2]=temp;
						g=g/2;
						if(g<2){
							break;
						}
					}
				}
			}
		}
		else
		{
//			printf("yes\n");
			y=y+1;
			b[y]=f[i];
			g=y;
			if(g>=2){
				while(b[g/2]>b[g]){
					temp=b[g];
					b[g]=b[g/2];
					b[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
		}
		if(x>=y){
			m=a[1];
		}
		if(x<y){
			m=b[1];
		}



	}
	else if(x<y){
		if(f[i]<=a[1]||((f[i]<b[1])&&(y>0))){
			x=x+1;
			a[x]=f[i];
			g=x;
			if(g>=2){
				while(a[g/2]<a[g]){
					temp=a[g];
					a[g]=a[g/2];
					a[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
			m=a[1];
		}
		else{
			x=x+1;
			a[x]=b[1];
			g=x;
			if(g>=2){
				while(a[g/2]<a[g]){
					temp=a[g];
					a[g]=a[g/2];
					a[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
			b[1]=b[y];
			y=y-1;
			call_b(1);
			y=y+1;
			b[y]=f[i];
			g=y;
			if(g>=2){
				while(b[g/2]>b[g]){
					temp=b[g];
					b[g]=b[g/2];
					b[g/2]=temp;
					g=g/2;
					if(g<2){
						break;
					}
				}
			}
		}

		if(x>=y){
			m=a[1];
		}
		else{
			m=b[1];
		}



	}
}

int mod=1000000007;
void func(long long int A,long long int B,long long int c){
	f[i]=(((A*m)%mod+(B*i)%mod+c%mod)%mod);
	int d;
//	for(d=1;d<=x;d++){
//		printf("%lld ",a[d]);
//	}
//	printf("\n");
//	for(d=1;d<=y;d++){
//		printf("%lld ",b[d]);
//	}
//	printf("\n");
//	printf("%lld,%lld\n",f[i],m);
//	printf("-------------------------------------------------------------------------------------------\n");
	insert();
}
int main(){
	long long  int t,n,S,A,B,c;
	scanf("%lld",&t);
	while(t--){
		x=1;
		y=0;
		scanf("%lld%lld%lld%lld",&A,&B,&c,&n);
		f[1]=1;
		m=1;
		a[1]=1;
		for(i=2;i<=n;i++){
			func(A,B,c);
		}
		S=0;
		for(i=1;i<=n;i++){
			S=S+f[i];
		}
		printf("%lld\n",S);
	}
	return 0;
}


