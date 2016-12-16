#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int front=0,rear=0;
int capacity=0;
int numElements=0;

void PrintBuffer(char buffer[][101])
{
    int i;
    for (i=0;i<numElements;i++)
        printf("%s\n", buffer[(front+i)% capacity]);
}

void Remove()
{
    if (numElements==0)
        return;

    numElements--;
    front=(front+1)%capacity;
}

void Append(char buffer[][101])
{
    if (numElements ==capacity)
        Remove();

    scanf("%s",buffer[rear]);
    rear=(rear+1)%capacity;
    numElements++;
}

int main()
{
    char ch;
    int d;
    scanf("%d",&capacity);
    char buffer[capacity][101];
    while(1)
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case('A'):
                {
                    scanf("%d",&d);
                    while(d--)
                        Append(buffer);
                    break;
                }
            case('L'):
                PrintBuffer(buffer);
                break;
            case('R'):
                {
                    scanf("%d",&d);
                    while(d--)
                        Remove();
                    break;
                }
            case('Q'):
                exit(0);
                break;
        }
    }
    return 0;
}
