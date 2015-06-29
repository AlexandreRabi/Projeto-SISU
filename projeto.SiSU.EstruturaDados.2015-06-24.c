/* ----- ESTRUTURA DE DADOS PROJETO SISU - CAP ----- */

#include <stdio.h>
#define MAX_NOME 64     // Todos os chars que caracterizam nomes tem no m�ximo 64 caracteres
#define MAX_VETOR 128   // Os vetores principais manipulados no c�digo tem no m�ximo 128 posi��es

/// ----------------------------------------------------------------------------------------
/// Desenvolvimento das tipagens utilizadas para entrada e sa�da de dados
// tNotas: referente as notas de cada candidato
// USADA EM tCandidato
typedef struct {
    double redacao;     // Referente a nota do candidato na prova de reda��o
    double linguagens;  // Referente a nota do candidato na prova de Linguagens, C�digos e suas tecnologias
    double matematica;  // Referente a nota do candidato na prova de Matem�tica e suas tecnologias
    double natureza;    // Referente a nota do candidato na prova de Ci�ncias da Natureza e suas tecnologias
    double humanas;     // Referente a nota do candidato na prova de Ci�ncias Humanas e suas tecnologias
} tNotas;


// tVaga: referente as vagas de cada curso
// USADA EM tCurso
typedef struct {
    int total;      // Numero total de vagas que s�o disponibilizadas em um curso
    int grupo1;     // Cota: pretos, pardos e ind�genas com renda inferior a 1,5 sal�rio m�nimo per capita
    int grupo2;     // Cota: escola p�blica com renda inferior a 1,5 sal�rio m�nimo per capita
    int grupo3;     // Cota: pretos, pardos e ind�genas independente da renda
    int grupo4;     // Cota: egressos de escola p�blica independente da renda
    int grupo5;     // Ampla concorr�ncia
} tVaga;


// tCurso: referente a cada curso
typedef struct {
    int id;                   // ID de cada curso
    char nome[MAX_NOME];      // Nome do curso
    // char categoria[MAX_NOME]; // para busca por �rea de cursos
    tVaga vagas;              // Total de vagas disponibilizadas
    tNotas pesos;             // Armazena os pesos de cada prova
    int aprovados[MAX_VETOR]; // Vetor que controla os aprovados no curso
} tCurso;


// tInscricao: referente a inscri��o de cada candidato
typedef struct {
    int idCurso;         // Armazena o ID do curso que o candidato colocou na op��o
    int grupo;           // Referente ao grupo que o candidato se inscreveu
    double media;      // Nota m�dia
} tInscricao;


// tCandidato: referente a cada candidato
typedef struct {
    int numeroInsc;         // Referente ao n�mero de inscri��o do candidato
    char nome[MAX_NOME];    // Nome do candidato
    tNotas notas;           // Referente as notas das provas do candidato
    tInscricao opcao1;
    tInscricao opcao2;
    int classificado;           // 1 - Aprovado na vaga; 0 - N�o aprovado; Imita tipo boolean
} tCandidato;



/// ----------------------------------------------------------------------------------------
/// Cria��o dos prot�tipos de fun��es b�sicas
// FUN��ES DE INSER��O
void getNome (char *nome[MAX_NOME]);    // Fun��o �til para todas as entradas de nomes
void getUniversidade (char *nome[][MAX_NOME]);    // Leitura de nomes de universidades
void getCPF (char *cpf[15]);            // Leitura de CPF
void getVagas (tVaga *vagas);


// FUN��ES DE BUSCA
// O usu�rio do Sisu pode realizar buscas por nome do curso, nome da universidade e por cidade
void buscaTermo(char vetorBusca[][MAX_NOME], int tamanhoVetor);
/* Objetivo: encontrar a cadeia de char em forma de substring inserida pelo usu�rio em um vetor. */


/// ----------------------------------------------------------------------------------------
tCurso cursos[MAX_VETOR];
tCandidato concorrentes[MAX_VETOR];
// tem que ter estruturas de dados para o processamento intermedi�rio dos candidato
// tem que ter estruturas de dados para armazenar os candidatos aprovados por curso

