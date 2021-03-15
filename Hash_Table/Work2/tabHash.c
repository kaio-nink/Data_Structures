#include<stdio.h>
#include<stdlib.h>

typedef struct aluno
{
	int matricula;
	float cr;
	
	struct aluno *prox;
}tAluno;

typedef tAluno* Hash;

int hash(int mat, int tam)
{
	return mat % tam;
}

int hashMult(int mat, int tam)
{
	float w = 64, a = 19; //w- numero de palavras do computador a - numero primo
	
	int h = mat * (a/w);
	
	if(h >= tam) // valor da hash maior que o tamanho da tabela, ir pra ultima posição
		return tam -1;
	else
		return h;
}	

void inicializa(Hash *tab, int m)
{
	int i;
	
	for(i = 0; i < m; i++)
		tab[i] = NULL;
}

tAluno* aloca(int mat, float cr)
{
	tAluno *novo = (tAluno*) malloc(sizeof(tAluno));
	novo->matricula = mat;
	novo-> cr = cr;
	novo->prox = NULL;
	return novo;
}

void insere(Hash *tab, int m, int mat, float cr)
{
	int h = hashMult(mat, m);
	
	tAluno *p = tab[h];
	tAluno *ant = NULL;
	
	while((p != NULL) && (p->matricula != mat))
	{
		ant = p;
		p = p->prox;
	}
	
	if(p)
	{
		p->cr = cr;
		return;
	}
	
	tAluno *novo = aloca(mat, cr);
	
	if(!ant)
		tab[h] = novo;
	else
		ant->prox = novo;
		
}

void imprime(Hash *tab, int m)
{
	int i;
	
	for(i = 0; i < m; i++)
	{
		printf("%d", i);
		if(tab[i])
		{
			tAluno *p = tab[i];
			printf("\n");
			while(p)
			{
				printf("\t%d\t%.2f\t%p\n", p->matricula, p->cr, p->prox);
				p = p->prox;
			}
		}
		else
			printf("\n\tNULL\n");
		
	}
}

tAluno* busca(Hash *tab, int m, int mat)
{
	int h = hashMult(mat, m);
	
	tAluno *p = tab[h];
	
	while((p) && (p->matricula != mat))
		p = p->prox;
	
	return p;
}

float excluir(Hash *tab, int m, int mat)
{
	int h = hashMult(mat, m);
	
	if(tab[h] == NULL)
		return -1;
	
	tAluno *p = tab[h];
	tAluno *ant = NULL;
	float cr = -1;
	
	while((p != NULL) && (p->matricula != mat))
	{
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL)
		return cr;
	
	if( ant == NULL)
		tab[h] = p->prox;
	else
		ant->prox = p->prox;
	
	cr = p->cr;
	free(p);
	
	return cr;
}

void libera(Hash *tab, int m)
{
	int i;
	
	for(i = 0; i < m; i++)
	{
		if(tab[i])
		{
			tAluno *p = tab[i];
			tAluno *q;
			
			while(p)
			{
				q = p;
				p = p->prox;
				free(q);
			}
		}
	}				
}	

int main()
{
	int m = 5;
	
	
	Hash *tab[m];
	inicializa(tab, m);
	
	insere(tab, m, 5, 6.85);
	insere(tab, m, 6, 7.35);
	insere(tab, m, 7, 8.69);
	insere(tab, m, 5, 3.45);
	insere(tab, m, 8, 9.71);
	insere(tab, m, 9, 10.00);
	insere(tab, m, 10, 5.15);
	insere(tab, m, 11, 4.95);
	insere(tab, m, 16, 6.95);
		
	imprime(tab, m);
	
	tAluno *p = busca(tab, m, 11);
	if(!p)
		printf("Matricula não encontrada\n");
	else
		printf("Matricula:%d\tcr:%.2f\n", p->matricula, p->cr);
	
	printf("---------------------------\n");	
	float cr = excluir(tab, m, 11);
	if(cr != -1)
		printf("Matricula:%d\tcr:%.2f foi excluido\n", 11, cr);
	
	imprime(tab, m);
	
	libera(tab, m);
	printf("Test here");
	imprime(tab, m);
		
	return 0;
	
	
}
