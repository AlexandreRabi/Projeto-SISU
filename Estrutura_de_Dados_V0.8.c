/* ----- ESTRUTURA DE DADOS PROJETO SISU - CAP -----
Autores: Leonardo Utida - 628182
         Rodolfo Asbahr - 628042
         Tiago Marto    - 628522
         T�lio Reis     - 628050

--- CHANGELOG
- 0.1 - estrutura de dados inicial, primitiva e rascunhada
- 0.2 - retirada da tUniversidade
- 0.3 - remo��o de valores irrelevantes para as fun��es b�sicas (presentes na vers�o 0.2)
- 0.4 - inser��o dos menus enumerados
- 0.5 - inser��o dos prot�tipos de fun��es de leitura
- 0.6 - inser��o dos prot�tipos de fun��es de valida��o e de busca
- 0.7 - tipo enumerado como par�metro
*/

#include <stdio.h>
#define MAX_NOME 64     // Todos os chars que caracterizam nomes tem no m�ximo 64 caracteres
#define MAX_VETOR 128   // Os vetores principais manipulados no c�digo tem no m�ximo 128 posi��es

/// ----------------------------------------------------------------------------------------
/// Desenvolvimento das tipagens utilizadas para entrada e sa�da de dados
// tCurso: referente a cada curso
typedef struct {
    int id;                 // ID de cada curso
    char nome[MAX_NOME];    // Nome do curso
    tVaga vagas;            // Total de vagas disponibilizadas
    char universidade[MAX_VETOR][MAX_NOME];   // Vetor de quais as universidades que possuem esse curso
} tCurso;


// tCandidato: referente a cada candidato
typedef struct {
    int numeroInsc;         // Referente ao n�mero de inscri��o do candidato
    char nome[MAX_NOME];    // Nome do candidato
    tData dataNasc;         // Data de nascimento do candidato
    tEndereco endereco;     // Endere�o do candidato
    char cpf[15];           // CPF do candidato
    char rg[15];            // RG do candidato
    int sexo;               // C�digo de Sexo do candidato; enum menuDeclara
    char nomeMae[MAX_NOME]; // Nome da m�e do candidato.

    int autodeclaracao;     // 1 - Branco; 2 - Pardo; 3 - Negro; 4 - Ind�gena; (...)
    tNotas notas;           // Referente as notas das provas do candidato
    int formacaoMedio;          // 1 - P�blico; 2 - Privado; 3 - Parte privado com bolsa; 4 - Parte privado sem bolsa; (...)
    int classificado;           // 1 - Aprovado na vaga; 0 - N�o aprovado; Imita tipo boolean

    int inscricao1;         // Armazena o ID do curso que o candidato colocou na primeira op��o
    int inscricao2;         // Armazena o ID do curso que o candidato colocou na segunda op��o
} tCandidato;


// tData: referente toda e qualquer data usada no c�digo
// USADA EM tCandidato
typedef struct {
    int dia;
    int mes;
    int ano;
} tData;


// tEndereco: referente a todo e qualquer endere�o usado no c�digo
// USADA EM tCandidato
typedef struct {
    char logradouro[MAX_NOME];  // Descri��o raiz do endere�o (Exemplo: Avenida S�o Carlos, 2160)
    char bairro[MAX_NOME];      // Nome do bairro do endere�o descrito (Exemplo: Centro)
    char cidade[MAX_NOME];      // Nome da cidade (Exemplo: S�o Carlos)
    char UF[3];                 // Unidade Federativa (Exemplo: SP)
    char CEP[10];               // CEP do endere�o descrito
} tEndereco;


// tNotas: referente as notas de cada candidato
// USADA EM tCandidato
typedef struct {
    double redacao;     // Referente a nota do candidato na prova de reda��o
    double linguagens;  // Referente a nota do candidato na prova de Linguagens, C�digos e suas tecnologias
    double matematica;  // Referente a nota do candidato na prova de Matem�tica e suas tecnologias
    double natureza;    // Referente a nota do candidato na prova de Ci�ncias da Natureza e suas tecnologias
    double humanas;     // Referente a nota do candidato na prova de Ci�ncias Humanas e suas tecnologias
    double media;       // M�dia aritm�tica das 5 notas do aluno (usada em cursos sem pesos definidos nas provas)n
} tNotas;


// tVaga: referente as vagas de cada curso
// USADA EM tCurso
typedef struct {
    int total;      // Numero total de vagas que s�o disponibilizadas em um curso
    int grupo1;     // Cota: escola p�blica com renda inferior a 1,5 sal�rio m�nimo per capita
    int grupo2;     // Cota: pretos, pardos e ind�genas com renda inferior a 1,5 sal�rio m�nimo per capita
    int grupo3;     // Cota: egressos de escola p�blica independente da renda
    int grupo4;     // Cota: pretos, pardos e ind�genas independente da renda
    int grupo5;     // Ampla concorr�ncia
} tVaga;









/// ----------------------------------------------------------------------------------------
/// Cria��o dos menus enumerados dos respectivos elementos
enum optSexo {
    Masculino = 1,
    Feminino
    };
//typedef enum optSexo menuSexo;

enum optDeclara {
    Branco = 1,
    Pardo,
    Negro,
    Indigena
    };
//typedef enum optDeclara menuDeclara;

enum optFormMedio {
    Publica = 1,
    Parte publica,
    Privada
    };
//typedef enum optFormMedio menuFormMedio;













/// ----------------------------------------------------------------------------------------
/// Cria��o dos prot�tipos de fun��es b�sicas
// FUN��ES DE INSER��O
void getNome (char *nome[MAX_NOME]);    // Fun��o �til para todas as entradas de nomes
void getUniversidade (char *nome[][MAX_NOME]);    // Leitura de nomes de universidades
void getData (tData *data);             // Leitura de datas
void getEndereco (tEndereco *endereco); // Leitura de endere�os
void getCPF (char *cpf[15]);            // Leitura de CPF
void getRG (char *rg[15]);              // Leitura de RG
void getVagas (tVaga *vagas);

void getEnum (enum tipoDado, char *dado); /// "ENUM" PODE SER UM PAR�METRO???
/* Objetivo: leitura de dados que s�o coletados por meio de menus enumerados
   Parametros:
        - tipoDado: menu enumerado a se consultar o n�mero inserido pelo usu�rio
        - dado: elemento que recebe o valor correspondente � entrada do usu�rio no menu enumerado */


// FUN��ES DE VALIDA��O
int validaData (tData data);
int validaCPF (char cpf[15]);
int validaRG (char rg[15]);


// FUN��ES DE BUSCA
// O usu�rio do Sisu pode realizar buscas por nome do curso, nome da universidade e por cidade
void buscaTermo(char vetorBusca[][MAX_NOME], int tamanhoVetor);
/* Objetivo: encontrar a cadeia de char em forma de substring inserida pelo usu�rio em um vetor. */

/// FUN��ES DE EDI��O? DE REMO��O?

/// ----------------------------------------------------------------------------------------
tCurso cursos[MAX_VETOR];
tCandidato concorrentes[MAX_VETOR];
