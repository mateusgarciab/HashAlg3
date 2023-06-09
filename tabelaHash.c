#include "tabelaHash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matarProgramaFaltaMemoria() {
    fputs("Falha ao alocar memoria.\n", stderr);
    exit(1);
}

struct aluno* getAluno1() {
    struct aluno* retorno = malloc(sizeof(struct aluno));
    if (!retorno) matarProgramaFaltaMemoria();
    retorno->nome = malloc(sizeof("Mateus Garcia Baiak"));  // sizeof conta o \0
    if (!retorno->nome)
        matarProgramaFaltaMemoria();
    retorno->nomeDinf = malloc(sizeof("mgb22"));
    if (!(retorno->nomeDinf))
        matarProgramaFaltaMemoria();

    strcpy(retorno->nome, "Mateus Garcia Baiak");
    strcpy(retorno->nomeDinf, "mgb22");
    retorno->grr = 1234;

    return retorno;
}

struct aluno* getAluno2() {
    return NULL;
}

void imprimirDadosAlunos() {
    struct aluno* aluno = getAluno1();

    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);

    aluno = getAluno2();
    if (!aluno) return;

    printf("...E... \n\n");
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);
}

struct nodoHash* geraNodoHash(int chave) {
    struct nodoHash* nodo = malloc(sizeof(struct nodoHash));

    if (!nodo)
        matarProgramaFaltaMemoria();
    nodo->chave = chave;
    nodo->ant = NULL;
    nodo->prox = NULL;

    return nodo;
}

struct listaHash* gerarTabelaHash(size_t tamTabela) {
    struct listaHash* lista = malloc(sizeof(struct listaHash) * tamTabela);

    if (!lista)
        matarProgramaFaltaMemoria();

    for (size_t i = 0; i < tamTabela; i++) {
        lista[i].inicio = NULL;
        lista[i].fim = NULL;
    }

    return lista;
}

size_t encontraPosicao(size_t tamTabela, unsigned int chave) {
    return chave % tamTabela;
}

struct nodoHash* inserir(struct listaHash tabelaHash[], size_t tamTabela, int chave) {
    struct nodoHash* nodo = geraNodoHash(chave);
    size_t pos = encontraPosicao(tamTabela, chave);

    /* lembrar de fazeer a busca para evitar duplicatas */
    printf(" %ld \n", pos);

    if (tabelaHash[pos].inicio == NULL){
        tabelaHash[pos].inicio = nodo;
        tabelaHash[pos].fim = nodo;
    } else {
        nodo->ant = tabelaHash[pos].fim;
        tabelaHash[pos].fim = nodo;
        nodo->ant->prox = nodo;
    }

    return nodo;
}

void liberarTabelaHash(struct listaHash tabelaHash[], size_t tamTabela) {

}

void imprimirTabelaHash(struct listaHash tabelaHash[], size_t tamTabela) {
    struct nodoHash* nodo; 

    for (size_t i = 0; i < tamTabela; i++) {
        printf("%ld ", i);
        nodo = tabelaHash[i].inicio;
        while (nodo != NULL) {
            printf("[%d] -> ", nodo->chave);
            nodo = nodo->prox;
        }
        printf("NULL\n");
    }

    return;
}

struct nodoHash* buscar(struct listaHash tabelaHash[], size_t tamTabela, int chave) {
    return NULL;
}

void excluir(struct listaHash tabelaHash[], size_t tamTabela, struct nodoHash* nodo) {
    
}