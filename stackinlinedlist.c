#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
 struct stack *push(struct stack *,int);
struct stack pop(struct stack *);
struct stack display(struct stack * );
int main()
{
   int val, option;
  
    do
    {
        printf("\nEnter Choice \n1.PUSH \n2.POP\n3.DISPLAY \n4.EXIT \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the number to be pushed on stack :");
            scanf("%d", &val);
            top=push(top,val);
            break;
        case 2:
            top = pop(top);
            
            break;
        case 3:
            top=display(st);
            break;
        }
    }while(option !=4);
    getch();
    return 0;
}

struct stack *push(strct stack *top,int val)
{
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->data=val;

    if(top==NULL)
    {
       ptr->next=NULL;
       top=ptr;

    }
    else
    {
      ptr->next=top;
       top=ptr;
    }
    return top;
}

struct stack *pop (struct stack *top)
{
    struct stack *ptr;
    ptr=top;
    if (top==NULL)
           printf("\n STACK UNDERFLOW");
   
    else
    {
        top = top->next;
        printf("\n The value being deleted is:%d",ptr->data);
        free(ptr);
    }
    return top;
}
       
struct stack *display( struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if(top==NULL)
    printf("\n STACK IS EMPTY");
    else
    {
        while(ptr!=NULL)
       {
            printf("\n %d",ptr->data);
            ptr= ptr->next;
       }
    }
    return top;
}   
