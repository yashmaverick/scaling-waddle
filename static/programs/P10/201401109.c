#include<stdio.h>
#include<string.h>
int n,num,head,tail,ne,length;
//ne=number of elemets present in the array at the present time
char a[10010][110],b[110],c[110],D[10010];
void append(char b[])
{
    length=strlen(b);
    int i;

    if(head==tail&&ne==n)
    {
        if(head==n)
        {
            head=0;
        }
        if(tail==n)
        {
            tail=0;
        }
        for(i=0;i<length;i++)
            a[tail][i]=b[i];
        D[tail]=length;
        head++;
        tail++;
    }
    else
    {
        if(tail==n)
            tail=0;
        for(i=0;i<length;i++)
            a[tail][i]=b[i];
            D[tail]=length;
        tail++;
        if(tail==n)
            tail=0;
        if(ne<n)
            ne++;
    }


}
void delete()
{
    if(num>=ne)
    {
        ne=0;
        head=0;tail=0;
    }
    else
    {
        head=(head+num)%n;
        ne=ne-num;
    }
}
void print()
{
    int i,j;
//    printf("ne==%d\nhead==%dtail==%d\n",ne,head,tail);

    if(tail<=head&&ne>0)
    {
        for(i=head;i<=n-1;i++)
        {
            for(j=0;j<D[i];j++)
            printf("%c",a[i][j]);
            printf("\n");
        }
        for(i=0;i<tail;i++)
        {
            for(j=0;j<D[i];j++)
            printf("%c",a[i][j]);
            printf("\n");
        }
    }
    else
    {
        for(i=head;i<tail;i++)
        {
            for(j=0;j<D[i];j++)
            printf("%c",a[i][j]);
            printf("\n");
        }
    }
}
int main()
{
    int i,j,k;
    head=0;tail=0;ne=0;
    char dummy,t;
    scanf("%d",&n);
    while(1) 
    {

        scanf("%c",&t);
        if(t=='A')
        {
            scanf("%d",&num);
            for(i=0;i<num;i++)
            {
                scanf("%s",c);
                append(c);
            }
        }
        if(t=='R')
        {
            scanf("%d",&num);
            delete();
        }
        if(t=='L')
        {
            print();
        }
        if(t=='Q')
            break;
    }
    return 0;
}
