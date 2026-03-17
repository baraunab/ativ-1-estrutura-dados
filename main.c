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


void listaAluno(Aluno aluno);
void listaTurma(Turma turma);
void listaCurso(Curso curso);

void cadastrarAluno() {
	FILE *f = fopen("./arquivos/alunos.txt", "a");

	if (f == NULL){
		printf("Erro - cadastrarAluno: abertura de arquivo");
		return;
	}

	Aluno aluno = {0};

	printf("=== CADASTRAR ALUNO ===\n");
	getchar();
	printf("Nome: ");
	fgets(aluno.nome, MAX, stdin);
	aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

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
	
	printf("=== CADASTRAR CURSO ===\n");
	getchar();
	printf("Nome: ");
	fgets(curso.nome, MAX, stdin);
	curso.nome[strcspn(curso.nome, "\n")] = '\0';

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
	getchar();
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
	getchar();
	printf("Horas de participacao: ");
	scanf("%d", &turma.horasParticipacao);

	fprintf(f, "%d|%d|%s|%d|%f|%d\n", turma.num, turma.cpf, turma.codigo, turma.ano, turma.nota, turma.horasParticipacao);

	fclose(f);

}

int contarLinhas(char *arquivo){
	FILE *f = fopen(arquivo, "r");
	char c;
	int linhas = 0;
	while (!feof(f)){
		c = fgetc(f);
		if (c == '\n') linhas++;

	}

	fclose(f);

	return linhas;
}

Aluno * listarAlunos(int *qtd){

	char *arquivo = "./arquivos/alunos.txt";
	
	int linhas = contarLinhas(arquivo);
	
	*qtd = linhas;

	FILE *f = fopen(arquivo, "r");
		
	if (f == NULL) {
		printf("Erro - listarAlunos: abertura de arquivo");
	}

	Aluno *aluno = malloc(sizeof(Aluno)*linhas);

	char linha[MAX];

	for (int i = 0; i < linhas; i++) {
		fgets(linha, sizeof(linha), f);
		sscanf(linha, "%[^|]|%d|%d", aluno[i].nome, &aluno[i].cpf, &aluno[i].idade);
	}
	fclose(f);
	
	return aluno;

}

Curso * listarCursos(int *qtd){
	char *arquivo = "./arquivos/cursos.txt";
	int linhas = contarLinhas(arquivo);
	*qtd = linhas;

	FILE *f = fopen(arquivo, "r");

	if (f == NULL){
		printf("Erro - listarCursos: abertura de arquivo");
	}

	Curso *curso = malloc(sizeof(Curso)*linhas);
	char linha[MAX];

	for (int i = 0; i < linhas; i++){
		fgets(linha, sizeof(linha), f);
		sscanf(linha, "%[^|]|%[^|]|%d|%d|%d", curso[i].nome, curso[i].codigo, &curso[i].horas, &curso[i].nVagas, &curso[i].nParticipantes );
	}
	fclose(f);
	
	return curso;
}

Turma * listarTurmas(int *qtd) {
	char *arquivo = "./arquivos/turmas.txt";
	int linhas = contarLinhas(arquivo);
	*qtd = linhas;

	FILE *f = fopen(arquivo, "r");

	if (f == NULL) {
		printf("Erro - listarTurmas: abertura de arquivo");
	}

	Turma *turma = malloc(sizeof(Turma)*linhas);
	char linha[MAX];

	for (int i = 0; i < linhas; i++){
		fgets(linha, sizeof(linha), f);
		sscanf(linha, "%d|%d|%[^|]|%d|%f|%d", 
				&turma[i].num, &turma[i].cpf, turma[i].codigo, &turma[i].ano, &turma[i].nota, &turma[i].horasParticipacao);
	}
	
	fclose(f);

	return turma;
}

void listaTurma(Turma turma){
	printf("\nNumero: %d", turma.num);
	printf("\nCPF: %d", turma.cpf);
	printf("\nCodigo: %s", turma.codigo);
	printf("\nAno: %d", turma.ano);
	printf("\nNota: %.2f", turma.nota);
	printf("\nHoras: %d\n", turma.horasParticipacao);
}

void listaCurso(Curso curso){
	printf("\nNome: %s", curso.nome);
	printf("\nCodigo: %s", curso.codigo);
	printf("\nHoras: %d", curso.horas);
	printf("\nN. Vagas: %d", curso.nVagas);
	printf("\nN. Participantes: %d\n", curso.nParticipantes);
}

void pesquisarAluno(char *info){
	FILE *f = fopen("./arquivos/alunos.txt", "r");

	if (f == NULL)
		printf("Erro - listarCursos: abertura de arquivo");
	
	char linha[MAX];
	Aluno aluno;

	printf("=== RESULTADOS ===");
	while(fgets(linha, MAX, f) != NULL){
		if (strstr(linha, info) != NULL) {
			if (sscanf(linha, "%[^|]|%d|%d", aluno.nome, &aluno.cpf, &aluno.idade) == 3){
				printf("\n- Nome: %s   CPF: %d   Idade: %d", aluno.nome, aluno.cpf, aluno.idade);
			}
		}
	}

	fclose(f);

}

void pesquisarTurma(char *info){
	FILE *f = fopen("./arquivos/turma.txt", "r");

	if (f == NULL)
		printf("Erro - listarCursos: abertura de arquivo");
	
	char linha[MAX];
	Aluno aluno;

	printf("=== RESULTADOS ===");
	while(fgets(linha, MAX, f) != NULL){
		if (strstr(linha, info) != NULL) {
			if (sscanf(linha, "%[^|]|%d|%d", aluno.nome, &aluno.cpf, &aluno.idade) == 3){
				printf("\n- Nome: %s   CPF: %d   Idade: %d", aluno.nome, aluno.cpf, aluno.idade);
			}
		}
	}

	fclose(f);

}


void crud(){
	printf("\n1 - Cadastrar");
	printf("\n2 - Pesquisar");
	printf("\n0 - Voltar");
	printf("\nEscolha: ");

}

void menu(){
	printf("\n=== TopArtBare - Opcoes ===\n");
	printf("\n1 - Discentes");
	printf("\n2 - Turmas");
	printf("\n3 - Cursos");
	printf("\n4 - Relatorios");
	printf("\n0 - Sair");

	int op = -1;
	int qtd;
	printf("\nEscolha: ");
	scanf("%d", &op);
	

	switch(op){
		case 1:
			system("clear");
			printf("=== DISCENTES ===");
			crud();
			
			scanf("%d", &op);
						
			switch(op){
				case 1:

			system("clear");
					cadastrarAluno();
					menu();
					break;
				case 2: 
			
			system("clear");
					char info[MAX];
					printf("Insira uma informacao para pesquisar (Nome ou CPF): ");
					scanf("%s", info);

					pesquisarAluno(info);
				
					menu();
					break;
				case 0:
					menu();
					break;
				default:
					printf("Opcao invalida!!");
					menu();
			}

			break;

		case 2:
			printf("=== TURMAS ===");
			printf("\n1 - Cadastro");
			printf("\n0 - Voltar");
			printf("\nEscolha: ");
			scanf("%d", &op);
			
			switch(op){
				case 1:
					cadastrarTurma();
				case 0:
					menu();
					break;
				default:
					printf("\nOpcao invalida");
					menu();
			}

			break;

		case 3:
			printf("=== CURSOS ===");
			crud();
			scanf("%d", &op);

			switch(op){
				
				case 1: 
			system("clear");
					cadastrarCurso();
					menu();
					break;
				case 0:
					menu();
					break;
			}
			break;

		case 4:

			system("clear");
			printf("=== RELATORIOS ===");
			printf("\n1 - Lista de Discentes");
			printf("\n2 - Lista de Turmas");
			printf("\n3 - Lista de Cursos");
			printf("\nEscolha:");
			scanf("%d", &op);

			switch(op){
				case 1:
					printf("\n=== LISTA DE DISCENTES ===\n");
					Aluno *aluno = listarAlunos(&qtd);
					
					for (int i = 0; i < qtd; i++){
						listaAluno(aluno[i]);		
					}
					menu();
					break;
				case 2: 
					printf("\n=== LISTA DE TURMAS ===");
					Turma *turma = listarTurmas(&qtd);
					printf("%f", turma[0].nota);
					for (int i = 0; i < qtd; i++){
						listaTurma(turma[i]);
					}
					menu();
					break;
				case 3:
					printf("\n=== LISTA DE CURSOS ===\n");
					Curso *curso = listarCursos(&qtd);
					for (int i = 0; i < qtd; i++){
						listaCurso(curso[i]);
					}
					menu();
					break;
				default:
					printf("\nOpcao invalida!!\n");
					menu;
			}
			break;

		case 0:
			printf("Saindo...");
			getchar();
			break;
		default:
			printf("\nOpcao Invalida!");
			getchar();
			system("clear");
			menu();
	}	

}

void listaAluno(Aluno aluno){
	printf("\nNome: %s", aluno.nome);
	printf("\tCPF: %d", aluno.cpf);
	printf("\tIdade: %d", aluno.idade);
}

int main (){
	menu();
}
