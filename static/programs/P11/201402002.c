#include<stdio.h>
#include<stdlib.h>

struct stack{
    long long int key;
    struct stack* prev;
};

void push(long long int elem, struct stack **top)
{
    struct stack *copy=(struct stack*)malloc(sizeof(struct stack));
    copy->key=elem;
    copy->prev=(*top);
    (*top)=copy;
}

long long int pop(struct stack **top)
{
    if ((*top)==NULL)
        return -1;

    long long int TORETURN=(*top)->key;
    struct stack *temp=(*top)->prev;
    free(*top);
    *top=temp;
    return TORETURN;
}

long long int TOP(struct stack *top){
    if (top==NULL)
        return -1;
    else
        return top->key;
}

long long int main()
{

    while(1)
    {
        struct stack *top=NULL;
        long long int no;
        scanf("%lld",&no);
        if (no==0)
            break;
        long long int i=no;
        long long int arr[no];

        while(i--)
            scanf("%lld",&arr[i]);
        i=0;

        long long int max=-1;
        long long int area,value,VAL;

        while (i < no)
        {
            if ( TOP(top)==-1 || arr[TOP(top)] <= arr[i])
            {
                push(i,&top);
                i++;
            }

            else
            {
                value=pop(&top);
                VAL=((TOP(top)==-1) ? i : i - TOP(top) - 1);
                area = arr[value] * VAL;
                max = (area > max)? area : max;
            }
        }

        while (TOP(top)!=-1)
        {
            value=pop(&top);
            VAL = ((TOP(top)==-1) ? i : i - TOP(top) - 1);
            area = arr[value] * VAL;
            max = (area > max)? area : max;
        }

        printf("%lld\n",max);
    }
    return 0;
}
