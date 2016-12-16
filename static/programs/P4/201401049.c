#include <stdio.h>
#define s(t) scanf("%d",&t)
#define str(t) scanf("%s",t);
#define mod 1000000007
#define ll long long
#define w(t) while(t--)
#define f(i,n) for(i=1;i<n;i++)
#define p(t) printf("%d\n",t)
#define ret(a) return a
#define elif else if
#define c(t) t*(t-1)/2
#define F(t) for(t=0;a[t]!='\0';t++)

char a[100005];
int sum[100005],b[100005];

void merge(int *, int, int , int);
void msort(int *, int, int);

int main(void)
{
	int t,i,n,freq=1,add,result;
	s(t);
	w(t)
	{
		result=0;
		str(a);
		//printf("%s\n",a);
		freq=1;
		F(i)
		{
			//printf("%c",a[i]);
			if(a[i]=='J') add=100000;
			elif(a[i]=='M') add= -100001;
			else add = 1;
			sum[i+1]=sum[i]+add;
		}
		n=i+1;
		msort(sum, 0, n-1);
		f(i,n)
		{
			if(sum[i]-sum[i-1])
			{
				result+=c(freq);
				freq=1;
			}
			else freq++;
		}
		result+=c(freq);
		p(result);
	}
	ret(0);
}

void msort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        msort(a,low,mid);
        msort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{ 
    int i,j,k;
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        a[i] = b[ i];
}