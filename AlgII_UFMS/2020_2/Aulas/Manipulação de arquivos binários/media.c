#include <stdio.h>

typedef struct{
	char nome[50], situacao[10];
	double notas[4], media;
} aluno;

int main(int argc, char *argv[])
{	
	double *nt;
	FILE *arquivo;
	aluno sala[50], *pt;
	int i, num_alunos;
	
	pt = sala;
	num_alunos = 0;
	
	for(i=0; i<3; i++, pt++)
	{	
		printf("Aluno 0%d: ", i+1);
		scanf(" %[^\n]", pt->nome);
		printf("Notas: ");
		nt = pt->notas;
		scanf("%lf %lf %lf %lf", nt, nt+1, nt+2, nt+3);

	
		pt->media = 0;
		for(nt=pt->notas; nt<pt->notas+4; nt++)
			pt->media = pt->media + *nt;
		
		pt->media = pt->media/4;	
	
		if(pt->media >= 6)
			sprintf(pt->situacao, "%s", "APROVADO");
		else
			sprintf(pt->situacao, "%s", "REPROVADO");
			
		num_alunos = num_alunos + 1;
	}


	arquivo = fopen("respostas.bkp", "wb");
	if(arquivo == NULL)
	{
		fprintf(stderr, "Erro ao abrir o arquivo respostas.bkp\n");
		return 0;
	}
	
	fwrite(sala, sizeof(aluno), num_alunos, arquivo);
	
	fclose(arquivo);
	
	
	return 0;
}




















