Aluno: Mateus Garcia Baiak
GRR: 20224378
Nome Dinf: mgb22

Structs:
    Para a criação da lista duplamente encadeada foram necessárias as seguintes structs:
    struct nodoHash{
        int chave;
        struct nodoHash* prox;
        struct nodoHash* ant;
    };

    struct listaHash{
        struct nodoHash* inicio;
        struct nodoHash* fim;
    };

Funções de criação e liberação:
    A função gerarTabelaHash aloca um vetor do tipo listaHash com o tamanho passado e inicializa todos os ponteiros para NULL.
        struct listaHash* gerarTabelaHash(size_t tamTabela)

    A função geraNodoHash aloca um nodo com a chave passada inicializa todos os ponteiros para NULL.
        struct nodoHash* geraNodoHash(int chave)

    A função liberarTabelaHash libera a memória da tabela Hash assim como todos seus nodos.
        void liberarTabelaHash(struct listaHash tabelaHash[], size_t tamTabela)

Funções de operação:
    A função inserir insere na tabela na última posição da lista ligada, a função não aceita duplicatas.
        struct nodoHash* inserir(struct listaHash tabelaHash[], size_t tamTabela, int chave)

    A função imprimirTabelaHash imprime na saída padrão a tabela Hash.
        void imprimirTabelaHash(struct listaHash tabelaHash[], size_t tamTabela)

    A função buscar procura a chave passada, caso encontre retorna o nodo correspondente e caso contrário NULL.
        struct nodoHash* buscar(struct listaHash tabelaHash[], size_t tamTabela, int chave) 

    A função excluir remove o nodo passado da tabela e libera sua memória.
        void excluir(struct listaHash tabelaHash[], size_t tamTabela, struct nodoHash* nodo)

Função auxiliar:
    A função encontraPosicao é uma função auxiliar utilizada para calcular a posição na tabela que um nodo deve ocupar a partir de sua chave.
        size_t encontraPosicao(size_t tamTabela, unsigned int chave)