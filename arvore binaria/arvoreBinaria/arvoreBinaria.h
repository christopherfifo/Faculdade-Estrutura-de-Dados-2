typedef struct NO *ArvBin;

ArvBin *cria_arvBin();

int vazia_arvBin(ArvBin *raiz);

int altura_arvBin(ArvBin *raiz);

int insere_arvBin(ArvBin *raiz, int valor);

int totalNO_arvBin(ArvBin *raiz);

void preOrdem_arvBin(ArvBin *raiz);

void emOrdem_arvBin(ArvBin *raiz);

void posOderm_arvBin(ArvBin *raiz);

int remove_arvBin(ArvBin *raiz, int valor);

int consulta_arvBin(ArvBin *raiz, int valor);

void liberar_arvBin(ArvBin *raiz);
