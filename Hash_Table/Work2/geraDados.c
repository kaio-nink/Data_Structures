#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//#include"listaestatica.c"
/*#include"numeros.c"*/




int main()
{
	
	int n=2, i, nume, j, negativo;
	FILE *arq;
	char texto[100];
	
	printf("numeros por aquivo\n");
	scanf("%d", &nume);


	for(i=1; i <= n; i++)
	{
		sprintf(texto, "%d-arq%d.txt", nume, i);
		arq = fopen (texto, "w");
		
		if(arq == NULL)
		{
			printf("ERRO AO ABRIR O ARQUIVO\n");
			return 0;
		}
		
		srand( (unsigned) i + j *time(NULL));
		
		for(j=0; j < nume; j++)
		{
			negativo =  rand()%1024;
			
			if(negativo <= 0)
				negativo = negativo * (-1);	
			fprintf(arq, "%d\n", negativo);
		}
		
		fclose(arq);	
	}

}

