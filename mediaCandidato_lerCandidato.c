/*
    Funções mediaCandidato() e lerCandidatos()

    Alunos: Leonardo Tavares(628174)
            Gabriel Gonçalves (628123)
            Bruna Zamith (628093)
            Felipe Akira (628115)
*/

#define CANDIDATOS_FILE "candidatos.txt"

double mediaCandidato(int i, int opcao)
{
    //declaracao de variavel
    double media;

    //calculo da media
    if (opcao == 1)
    {
        media = (candidato[i].notas.humanas*curso[candidato[i].opcao1.idCurso].pesos.humanas+candidato[i].notas.linguagens*curso[candidato[i].opcao1.idCurso].pesos.linguagens+candidato[i].notas.matematica*curso[candidato[i].opcao1.idCurso].pesos.matematica+candidato[i].notas.natureza*curso[candidato[i].opcao1.idCurso].pesos.natureza+candidato[i].notas.redacao*curso[candidato[i].opcao1.idCurso].pesos.redacao)/(curso[candidato[i].opcao1.idCurso].pesos.redacao+curso[candidato[i].opcao1.idCurso].pesos.natureza+curso[candidato[i].opcao1.idCurso].pesos.matematica+curso[candidato[i].opcao1.idCurso].pesos.linguagens+curso[candidato[i].opcao1.idCurso].pesos.humanas);
    }
    else if (opcao == 2)
    {
        media = (candidato[i].notas.humanas*curso[candidato[i].opcao2.idCurso].pesos.humanas+candidato[i].notas.linguagens*curso[candidato[i].opcao2.idCurso].pesos.linguagens+candidato[i].notas.matematica*curso[candidato[i].opcao2.idCurso].pesos.matematica+candidato[i].notas.natureza*curso[candidato[i].opcao2.idCurso].pesos.natureza+candidato[i].notas.redacao*curso[candidato[i].opcao2.idCurso].pesos.redacao)/(curso[candidato[i].opcao2.idCurso].pesos.redacao+curso[candidato[i].opcao2.idCurso].pesos.natureza+curso[candidato[i].opcao2.idCurso].pesos.matematica+curso[candidato[i].opcao2.idCurso].pesos.linguagens+curso[candidato[i].opcao2.idCurso].pesos.humanas);
    }

    //retorno da media
    return media;
}

int lerCandidatos(tCandidato candidato[])
{
    //declaracao das variaveis
    int nCandidatos;
    FILE *ifp;
    char *mode = "r";
    char nomeTemp[TAM_NOME];
    int i,j;

    //leitura do arquivo e teste de validade
    ifp = fopen(CANDIDATOS_FILE, mode);

    if (ifp == NULL) {
        exit(1);
    }

    //leitura do numero max de candidatos
    fscanf(ifp, "%d", &nCandidatos);

    //leitura dos cursos
    for(i=0;i<nCandidatos;i++)
    {
        fscanf(ifp,"%s",nomeTemp);

        //correcao do nome
        for( j = 0;j < strlen(nomeTemp); j++){
            if(nomeTemp[j]==95){
                nomeTemp[j]=32;
            }
        }
        strcpy(candidato[i].nome,nomeTemp);

        fscanf(ifp,"%Lf %Lf %Lf %Lf %Lf",&candidato[i].notas.humanas,&candidato[i].notas.linguagens,&candidato[i].notas.matematica,&candidato[i].notas.natureza,&candidato[i].notas.redacao);
        fscanf(ifp,"%d %d %d %d",&candidato[i].opcao1.idCurso,&candidato[i].opcao1.grupo,&candidato[i].opcao2.idCurso,&candidato[i].opcao2.grupo);

        //calculo da media para o curso escolhido
        candidato[i].opcao1.media = mediaCandidato(i,1);
        candidato[i].opcao2.media = mediaCandidato(i,2);
        candidato[i].classificado = -1; // inicialização para nao classificado
    }

    //fechando o arquivo de entrada
    fclose(ifp);

    //retorno
    return nCandidatos;
}