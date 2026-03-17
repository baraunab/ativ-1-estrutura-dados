#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// Structs

typedef struct {
	char nome[MAX];
	int cpf;
	int idade;
} Aluno;

typedef struct {
	char nome[MAX];
	char codigo[MAX];
	int horas;
	int nVagas;
	int nParticipantes;
} Curso;

typedef struct {
	int num;
	int cpf;
	char codigo[MAX];
	int ano;
	float nota;
	int horasParticipacao;
} Turma;

void cadastrarAluno() {
	FILE *f = fopen("./arquivos/alunos.txt", "a");

	if (f == NULL){
		printf("Erro - cadastrarAluno: abertura de arquivo");
		return;
	}

	Aluno aluno = {0};

	printf("=== CADASTRAR ALUNO ===");
	printf("Nome: ");
	scanf("%s", aluno.nome);

	printf("CPF: ");
	scanf("%d", &aluno.cpf);

	printf("Idade: ");
	scanf("%d", &aluno.idade);

	fprintf(f, "%s|%d|%d\n", aluno.nome, aluno.cpf, aluno.idade);
	

	fclose(f);

}

void cadastrarCurso() {
	FILE *f = fopen("./arquivos/cursos.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarCurso: abertura de arquivo");
	}

	Curso curso = {0};
	
	printf("=== CADASTRAR CURSO ===");
	printf("Nome: ");
	scanf("%s", curso.nome);

	printf("Codigo: ");
	scanf("%s", curso.codigo);

	printf("Horas: ");
	scanf("%d", &curso.horas);

	printf("Numero de vagas: ");
	scanf("%d", &curso.nVagas);

	printf("Numero de participantes: ");
	scanf("%d", &curso.nParticipantes);

	fprintf(f, "%s|%s|%d|%d|%d\n", curso.nome, curso.codigo, curso.horas, curso.nVagas, curso.nParticipantes);
	
	fclose(f);

}

void cadastrarTurma() {
	FILE *f = fopen("./arquivos/turmas.txt", "a");

	if (f == NULL) {
		printf("Erro - cadastrarTurma: abertura de arquivo");
	}

	Turma turma = {0};

	printf("\n=== CADASTRAR TURMA ===\n");
	printf("Numero: ");
	scanf("%d", &turma.num);

	printf("CPF: ");
	scanf("%d", &turma.cpf);

	printf("Codigo: ");
	scanf("%s", turma.codigo);
	
	printf("Ano: ");
	scanf("%d", &turma.ano);
	
	printf("Nota: ");
	scanf("%f", &turma.nota);
	
	printf("Horas de participacao: ");
	scanf("%d", &turma.horasParticipacao);

	fprintf(f, "%d|%d|%s|%d|%.2f|%d", turma.num, turma.cpf, turma.codigo, turma.ano, turma.nota, turma.horasParticipacao);


	fclose(f);


}

void listarAluno(Aluno aluno){
	printf("\n- Nome: %s", aluno.nome);
	printf("    CPF: %d", aluno.cpf);
	printf("    Idade: %d", aluno.idade);
}


void listarAlunos(){

	char *arquivo = "./arquivos/alunos.txt";
	
	FILE *f = fopen(arquivo, "r");
		
	if (f == NULL) {
		printf("Erro - listarAlunos: abertura de arquivo");
	}

	Aluno aluno;
	char linha[MAX];

	while(fgets(linha, sizeof(linha), f) != NULL){
		if (sscanf(linha, "%[^|]|%d|%d", aluno.nome, &aluno.cpf, &aluno.idade) == 3){
			printf("\n- Nome: %s   CPF: %d   Idade: %d", aluno.nome, aluno.cpf, aluno.idade);
		}
	}

	fclose(f);
}

void crud(){
	printf("\n1 - Cadastrar");
	printf("\n2 - Editar");
	printf("\n3 - Pesquisar");
	printf("\n4 - Excluir");
	printf("\n0 - Voltar");
	printf("\nEscolha: ");

}

void menu(){
	printf("=== TopArtBare - Opcoes ===");
	printf("\n1 - Discentes");
	printf("\n2 - Cursos");
	printf("\n3 - Turmas");
	printf("\n4 - Relatorios");
	printf("\n0 - Sair");

	int op = -1;
	printf("\nEscolha: ");
	scanf("%d", &op);
	system("clear");

	switch(op){
		case 1:
			printf("=== TopArtBare - Discentes ===");
			crud();
			scanf("%d", &op);

			system("clear");

			switch(op){
				case 1:
					cadastrarAluno();
					break;
				case 2: 
					printf("edit disc");
					break;
				case 3:
					printf("pesquisar dsic");
					break;
				case 4:
					printf("excluir disc");
					break;
				default:
					printf("Valor invalido!");
					getchar();
					system("clear");
					menu();
			}// crud discente
			break;

		case 2:
			printf("=== TopArtBare - Curso ===");
			crud();
			scanf("%d", &op);

			system("clear");

			switch(op){
				case 1:
					cadastrarCurso();
					break;
				case 2: 
					printf("edit curso");
					break;
				case 3:
					printf("pesquisar curso");
					break
				case 4:
					printf("excluir curso");
					break;
				default:
					printf("Valor invalido!");
					getchar();
					system("clear");
					menu();
			}// crud curso;
			break;
		case 3:
			printf("=== TopArtBare - Turmas ===");
			crud();
			scanf("%d", &op);

			system("clear");

			switch(op){
				case 1:
					cadastraTurma();
					break;
				case 2: 
					printf("edit turma");
					break;
				case 3:
					printf("pesquisar turma");
					break
				case 4:
					printf("excluir turma");
					break;
				default:
					printf("Valor invalido!");
					getchar();
					system("clear");
					menu();
			}// crud turma
			break;

		case 4: 
			printf("=== RELATORIOS ===");
			printf("\n1 - Lista de Discentes");
			printf("\n2 - Lista de Cursos");
			printf("\n3 - Lista de Discentes (por nome)");
			printf("\n4 - Lista de Turmas + Discentes");
			printf("\n5 - Lista de Turmas + Discentes + Cursos");
			printf("\n6 - Lista de Discentes de uma Turma");
			printf("\n7 - Lista de Turmas e media de notas");
			printf("\n0 - Voltar");
			printf("\nEscolha: ");
			scanf("%d", &op);
			
			switch (op){
				case 1: 
					printf("=== Lista de Alunos ===");
					listarAlunos();
					getchar();
					menu();
					break;
			}
			break;

		case 0:
			printf("\nSaindo...");
			return;

		default:
			printf("\nOpcao Invalida!");
			getchar();
			system("clear");
			menu();
	}	

}

int main (){
	menu();
}
