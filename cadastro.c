/*
 * 
 * V1.0 - CRIAÇÃO DE FUNÇÕES DE CADASTROS 
 * SEM USO DE ALOCAÇÃO DE MEMÓRIA
 * 
 * */

#include <stdio.h>
//#include "cadastro.h"

// Structs

typedef struct {
	char nome[256];
	int cpf;
	int idade;
} Aluno;

typedef struct {
	char nome[256];
	char codigo[10];
	int horas;
	int nVagas;
	int nParticipantes;
} Curso;

typedef struct {
	int num;
	int cpf;
	char codigo[10];
	int ano;
	int horasParticipacao;
} Turma;


// cria o cadastro de um aluno
void cadastrarAluno(Aluno aluno){
	FILE *f = fopen("arquivos/alunos.txt", "a");

	if (f == NULL) {
		printf("Erro: abertura de arquivo");
		return;
	}

	char temp[256];

	printf("\n======= CADASTRO DE ALUNO =======\n");
	printf("NOME  : ");
	scanf("%s", &aluno.nome);
	printf("CPF   : ");
	scanf("%d", &aluno.cpf);
	printf("IDADE : ");
	scanf("%d", &aluno.idade);
	
	// adiciona o dados no arquivo de dados
	fprintf(f, "%s %d %d\n", aluno.nome, aluno.cpf, aluno.idade);
	
	// retorna o cadastro
	printf("====== CADASTRO REALIZADO! ======\n");
	printf("NOME  : %s\n", aluno.nome);
	printf("CPF   : %d\n", aluno.cpf);
	printf("IDADE : %d anos\n", aluno.idade);

	fclose(f);
}

// cadastra um novo curso

void cadastrarCurso (Curso curso) {
	FILE *f = fopen("arquivos/cursos.txt", "a");

	if (f == NULL) {
		printf("Erro: abertura de arquivo");
	}
	
// nome, cod, horas, nvagas, nparticipante
	printf("\n======= CADASTRO DE CURSO =======\n");
	printf("NOME   : ");
	scanf("%s", &curso.nome);
	printf("CODIGO :");
	scanf("%s", &curso.codigo);
	printf("HORAS  : ");
	scanf("%d", &curso.horas);
	printf("QTD. VAGAS :");
	scanf("%d", &curso.nVagas);
	printf("QTD. PARTICIPANTES: ");
	scanf("%d", &curso.nParticipantes);
	
	fprintf(f, "%s %s %d %d %d\n", curso.nome, curso.codigo, curso.horas, curso.nVagas, curso.nParticipantes);
	
	printf("NOME: %s\n", curso.nome);
	printf("CODIGO: %s\n", curso.codigo);
	printf("HORAS: %dh\n", curso.horas);
	printf("QTD. VAGAS: %d\n", curso.nVagas);
	printf("QTD. PARTICIPANTES: %d\n", curso.nParticipantes);
	fclose(f);
}


int subtraiVagas(){
	//TODO ao adicionar participante, subtrai o numero de vagas do curso
}


int main () {
	Aluno aluno;
	Curso curso;
	cadastrarAluno(aluno);
	cadastrarCurso(curso);
}
