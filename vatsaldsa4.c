#include <stdio.h>
#include <conio.h>
#define MAX 5
int st[MAX], top=-1;
void push(int st[], int val);
int pop(int st[]);
void display(int st[] );
int main()
{
   int val, option;
  
    
    {
        printf("\nEnter Choice \n1.PUSH \n2.POP\n3.DISPLAY \n4.EXIT \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the number to be pushed on stack :");
            scanf("%d", &val);
            push(st,val);
            break;
        case 2:
            val = pop(st);
            if(val!= -1)
             printf("The value deleted from the stack is: %d",val);
            break;
        case 3:
            display(st);
            break;
        }
    }while(option !=4);
    getch();
    return 0;
}

void push(int st[],int val)
{
    if(top==MAX-1)
    {
        printf("\n STACK OVERFLOW");

    }
    else
    {
        top++;
        st[top]=val;

    }
}

int pop (int st[])
{
    int val;
    if (top==-1)

    {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;

    }
}
       
void display( int st[])
{
    int i;
    if(top== -1)
    printf("\n STACK IS EMPTY");
    else
    {
        for (i=top; i>=0;i--)
        printf("\n %d",st[i]);

    }
}
