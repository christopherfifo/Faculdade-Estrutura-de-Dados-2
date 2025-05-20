typedef struct NO *arvoreLLRB;

arvoreLLRB *cria_arvoreLLRB();

int vazia_arvoreLLRB(arvoreLLRB *raiz);

int altura_arvoreLLRB(arvoreLLRB *raiz);

int insere_arvoreLLRB(arvoreLLRB *raiz, int valor);

int totalNO_arvoreLLRB(arvoreLLRB *raiz);

void preOrdem_arvoreLLRB(arvoreLLRB *raiz);

void emOrdem_arvoreLLRB(arvoreLLRB *raiz);

void posOderm_arvoreLLRB(arvoreLLRB *raiz);

int remove_arvoreLLRB(arvoreLLRB *raiz, int valor);

int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor);

void liberar_arvoreLLRB(arvoreLLRB *raiz);
