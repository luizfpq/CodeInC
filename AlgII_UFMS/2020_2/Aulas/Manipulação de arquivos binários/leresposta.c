#include <stdio.h>

typedef struct{
	char nome[50], situacao[10];
	double notas[4], media;
} aluno;


int main(int argc, char *argv[])
{

	double *nt;
	FILE *arquivo;
	aluno a1, *pt;
	
	pt = &a1;
		
	arquivo = fopen("respostas.bkp", "rb");
	if(arquivo == NULL)
	{
		fprintf(stderr, "Erro ao abrir o arquivo respostas.bkp\n");
		return 0;
	}	
	
	fread(pt, sizeof(aluno), 1, arquivo);
	while(!feof(arquivo))
	{			
		printf("Nome:%s\n", pt->nome);
		printf("Notas:");
		for(nt=pt->notas; nt<pt->notas+4; nt++)
			printf(" %.2f", *nt);
		printf("\nMedia: %.2f\n", pt->media);
		printf("%s\n\n", pt->situacao);
		
		fread(pt, sizeof(aluno), 1, arquivo);
	}
	
	fclose(arquivo);
		
	
	return 0;
}





















