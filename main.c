#include <stdio.h>
#include <stdlib.h>

#include "stackStruct.c"

int main()
{       
    stack *st;
    st = NULL;
    int count = 0;


    count += insertStack(&st);
    count += insertStack(&st);

    printStack(st);

    alterStack(st, count);

    printStack(st);

    removeStack(&st);

    printStack(st);

    return 1;
}