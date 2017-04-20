// definindo o tipo arvore binaria como um ponteiro para no
typedef struct no *ARVOREBIN;

// prototipos
ARVOREBIN *criaArvoreBinaria();

void liberaArvoreBinaria(ARVOREBIN *raiz);

void insereNo(ARVOREBIN *raiz, int valor);

void removeNo(ARVOREBIN *raiz, int valor);

void preOrdem(ARVOREBIN *raiz);
void emOrdem(ARVOREBIN *raiz);
void posOrdem(ARVOREBIN *raiz);

int encontraMaior(ARVOREBIN *raiz, int *comp);
