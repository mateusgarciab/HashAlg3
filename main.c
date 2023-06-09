#include <stdio.h>

#include "tabelaHash.h"

int main(){
    size_t tam;
    char op;
    int val;
	imprimirDadosAlunos();
    scanf("%ld", &tam);

    struct listaHash* tabela = gerarTabelaHash(tam);
    scanf("%c", &op);
    while (op != 'f') {
        switch (op) {
        case 'i':
            scanf("%d", &val);
            inserir(tabela, tam, val);        
            break;
        case 'r':
            scanf("%d", &val);
            
            break;
        case 'b':
            scanf("%d", &val);
            
            break;
        case 'l':
            imprimirTabelaHash(tabela, tam);    
            break;
        default:
            break;
        }
        scanf("%c", &op);
    }
    
    return 0;
}