//Tarefa 1 - Estrutura de Dados
// Kaio Felipe Nink Cardoso

#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista; 

Lista *cria_lista(void){
    return NULL;
}

//Inserir item na lista
Lista *insere_inicio (Lista *li, int i)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

Lista *insere_fim (Lista *li, int i)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = NULL;

    Lista *p;
    Lista *q;
    p = li;
    q=li;

    while (p !=NULL)
    {   q = p;
        p = p->prox;
    }
    if(q != NULL)
        q->prox = novo;
    else
        li = novo;
   
    return li;
}

Lista *insere_ordenado (Lista *li, int i)
{
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = li;

    while (p != NULL && p->info < i)
    {
        ant = p;
        p = p->prox;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;

    if (ant == NULL)
    {
        novo->prox = li;
        li = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return li;
}

//Funções Recursivas
Lista* insere_fim_recursivo (Lista* li, int i)
{
    Lista *p=li;
    if(p == NULL)
    {
        Lista *novo = (Lista*) malloc(sizeof(Lista));
        novo->info = i;
        novo->prox = NULL;

        return novo;  
    }   
    else 
        p->prox = insere_fim_recursivo(p->prox,i);
    
    return p;
}

Lista *insere_ordenado_recursivo(Lista *li, Lista* ant, int i)
{
    Lista *p = li;
    Lista *q = ant;
    
    if(p == NULL || p->info > i)
    {
        Lista *novo = (Lista*) malloc(sizeof(Lista));
        novo->info = i;
        
        novo->prox = p;
        if(q == NULL)
            q = novo;

        else
            q->prox = novo;
        return novo; 
    }
    else if(p != NULL)
    {
        q = p;
        p->prox = insere_ordenado_recursivo(p->prox,q,i);
    }

    return p;
}


//Excluir item da lista
Lista *exclui(Lista* li, int i)
{  
    Lista *p = li;
    if(li->info == i)
    {   
        li = li->prox;
        free(p);
        return li;
    }

    Lista *q;
    while (p != NULL)
    {   
        q = p;
        p = p->prox;
        if(p && p->info == i)
        {
            q->prox = p->prox;
            free(p);
            return li;
        }
    }

    printf("\nItem nao encontrado para excluir.\n");
    return li;
}

//Alterar item da lista
Lista *altera(Lista* li, int vantigo, int vnovo)
{
    Lista *p = li;

    while (p != NULL)
    {
        if(p->info==vantigo)
        {
            p->info = vnovo;
            return li;
        }
        p = p->prox;
    }
    
    printf("\nItem nao encontrado para alterar.\n");
    return li;
}



void imprime (Lista *li)
{          
    Lista *p;
    printf("\n");
    for (p = li; p != NULL; p = p->prox)
    {
        printf("Info = %d\n", p->info);
    }    
}



int main(){
    Lista *lst;
    lst = cria_lista();

    lst = insere_ordenado_recursivo(lst, NULL, 6);
    lst = insere_fim_recursivo(lst,38);
    lst = insere_ordenado(lst,13);
    lst = insere_inicio(lst,12);
    lst = insere_ordenado_recursivo(lst, NULL, 87);
    lst = insere_fim(lst,32);
    lst = insere_fim_recursivo(lst,76);
    lst = insere_inicio(lst,15);
    lst = insere_ordenado_recursivo(lst, NULL, 10);
    lst = insere_fim(lst,99);
    lst = insere_ordenado(lst,43);
    lst = insere_fim_recursivo(lst,55);
    imprime(lst);

    lst = altera(lst, 10, 3);
    lst = altera(lst, 99, 88);
    lst = altera(lst, 42, 5);
    imprime(lst);

    lst = exclui(lst, 88);
    lst = exclui(lst, 44);
    lst = exclui(lst, 32);
    lst = exclui(lst, 15);
    imprime(lst);


    return(0);
}