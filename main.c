#include <stdio.h>

#include "tabelaHash.h"

int main(){
    size_t tam;
    char op;
    int val;
    struct nodoHash* nodo;
	imprimirDadosAlunos();
    scanf("%ld", &tam);

    struct listaHash* tabela = gerarTabelaHash(tam);
    scanf("%c", &op);
    while (op != 'f') {
        switch (op) {
        case 'i':
            scanf("%d", &val);
            nodo = inserir(tabela, tam, val);
            if (nodo == NULL)
                printf("Falha ao inserir\n");

            break;

        case 'r':
            scanf("%d", &val);
            nodo = buscar(tabela, tam, val);
            if (nodo == NULL)
                printf("Falha ao remover %d.\n", val);
            else
                excluir(tabela, tam, nodo);
            break;

        case 'b':
            scanf("%d", &val);
            nodo = buscar(tabela, tam, val);
            if (nodo == NULL)
                printf("Nao encontrado %d.\n", val);
            else
                printf("Encontrado %d.\n",val);
            break;

        case 'l':
            imprimirTabelaHash(tabela, tam);    
            break;

        default:
            break;
        }
        scanf("%c", &op);
    }
    liberarTabelaHash(tabela, tam);
    
    return 0;
}