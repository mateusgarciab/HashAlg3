#include <stdio.h>

#include "tabelaHash.h"

int main(){
	imprimirDadosAlunos();
    size_t tam;
    scanf("%ld", &tam);

    struct listaHash* tabela = gerarTabelaHash(tam);
    inserir(&tabela, tam, 1000);
    inserir(&tabela, tam, 100);


    printf("%d", tabela[0].inicio->chave);
    printf("%d", tabela[0].fim->chave);

    
    return 0;
}