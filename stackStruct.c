#ifndef stackStruct_c
#define stackStruct_c

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int value;
    struct stack *next;
} stack;

typedef struct list
{
    int value;
    struct list *next;
} list;

//-----------Stack functions-----------//

int insertStack(stack **st)
{
    int value, count;
    stack *new, *aux;
    new = (stack *) malloc(sizeof (stack) * 1);

    printf("Value: ");
    scanf("%d",&value);
    
    if (new == NULL)
        printf("Insertion error");
    else
    {
    new->value = value;
    new->next = NULL;    
    }
    
    if (*st == NULL)
    { 
        *st = new;
    }
    else 
    {
        aux = *st;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    printf("\n");
    count = 1;
    return count;
}

void alterStack (stack *st, int count)
{
    int i, pos;
    printf("\nSet position: ");
    scanf("%d",&pos);
    if(pos > count-1)
        printf("Unvalid position");
    else
    {
        stack *aux;
        aux = st;
        for (i=0; i < pos; i++)
            aux = aux->next;
        printf("New value: ");
        scanf("%d",&aux->value);
    }
    printf("\n");  
}

stack removeStack(stack **st)
{
    stack *aux, *temp, copy;

    if (st == NULL)
    {
        copy = **st;
        free(*st);
        *st = NULL;
        return copy;
    }
    else
    {
        temp = *st;
        while (temp->next != NULL)
        {
            aux = temp;
            temp = temp->next;
        }
        copy = *temp;
        free(temp);
        aux->next = NULL;
        return copy;
    }
}

void printStack(stack *st)
{
    if (st == NULL)
        printf("Empty stack");
    else
    {
        stack *aux;
        aux = st;
        printf("Printed stack: ");
        do
        {
            printf("%d\t",aux->value);
            aux = aux->next;
        } while (aux != NULL);
    }
    printf("\n\n");  
}

#endif