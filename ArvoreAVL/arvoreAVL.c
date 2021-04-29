#include<stdio.h>
#include<stdlib.h>

struct NO{
    int info;
    int alt; /* altura da subarvore */
    struct NO *esq;
    struct NO *dir;
};
typedef struct NO* arvoreAVL;

int menuPrincipal();
int menuSecundario();
void limparTela();
arvoreAVL* cria_Arvore();
void executaMenuPrincipal(arvoreAVL* raiz, int op);
void executaMenuSecundario(arvoreAVL* raiz, int op);
void imprimePreOrdem(arvoreAVL *raiz);
void imprimeEmOrdem(arvoreAVL *raiz);
void imprimePosOrdem(arvoreAVL *raiz);

int main(){
    arvoreAVL* raiz = cria_Arvore();
	int op;

	do{
        op = menuPrincipal();
        executaMenuPrincipal(raiz, op);
    }while(op != 4);

    return 0;
}

arvoreAVL* cria_Arvore(){
	arvoreAVL* raiz = (arvoreAVL*) malloc(sizeof(arvoreAVL));
	if(raiz != NULL){
		*raiz = NULL;
    }
	return raiz;
}

int menuPrincipal(){
	int opcao;
    
    printf("\nEscolha uma opcao:\n");
    printf("1. Imprimir\n");
    printf("2. Inserir novo valor\n");
    printf("3. Remover da arvore\n");
    printf("4. Sair\n");
    printf(">> ");
    scanf("%d", &opcao);
    
    return opcao;
}

int menuSecundario(){
	int opcao;
    
    printf("\nEscolha uma opcao:\n");
    printf("1. Pre-Ordem\n");
    printf("2. Em-Ordem\n");
    printf("3. Pos-Ordem\n");
    printf("4. Voltar\n");
    printf(">> ");
    scanf("%d", &opcao);
    
    return opcao;
}

void limparTela(){
    //Detecta se e linux ou windows, para limpar a tela sem erros.
    #ifdef linux
        system("clear");
    #elif WIN32
        system("cls");
    #endif
}

void executaMenuPrincipal(arvoreAVL* raiz, int op){
	int num;
    switch (op){
    case 1:
        limparTela();
		int op2;
        do{
            op2 = menuSecundario();
		    executaMenuSecundario(raiz, op2);
        }while(op2 != 4);
        break;
    case 2:
        limparTela();
        printf("Inserindo na arvore\n\n");
        printf("Digite um numero: ");
        scanf("%d", &num);
        //raiz = inserirNo(raiz, num);
        break;
    case 3:
        limparTela();
        printf("removendo da arvore\n\n");
        printf("Digite um numero para ser removido: ");
        scanf("%d", &num);
        //raiz = removerNo(raiz, num);
        break;
    case 4:
        limparTela();
        printf("Saindo...\n");
        break;
    default:
        limparTela();
        printf("Comando invalido!\n\n");
        break;
    }
}

void executaMenuSecundario(arvoreAVL* raiz, int op){
	int num;
    switch (op){
    case 1:
        limparTela();
        printf("listando em Pre Ordem\n\n");
        imprimePreOrdem(raiz);
        break;
    case 2:
        limparTela();
        printf("listando em Em Ordem\n\n");
        imprimeEmOrdem(raiz);
        break;
    case 3:
        limparTela();
        printf("listando em Pos Ordem\n\n");
        imprimePosOrdem(raiz);
        break;
    case 4:
        limparTela();
        break;
    default:
        limparTela();
        printf("Comando invalido!\n\n");
        break;
    }
}

void imprimePreOrdem(arvoreAVL *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		printf("%d\n", (*raiz)->info);
		imprimePreOrdem(&((*raiz)->esq));
		imprimePreOrdem(&((*raiz)->dir));
	}
}

void imprimeEmOrdem(arvoreAVL *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		imprimeEmOrdem(&((*raiz)->esq));
		printf("%d\n", (*raiz)->info);
		imprimeEmOrdem(&((*raiz)->dir));
	}
}

void imprimePosOrdem(arvoreAVL *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		imprimePosOrdem(&((*raiz)->esq));
		imprimePosOrdem(&((*raiz)->dir));
		printf("%d\n", (*raiz)->info);
	}
}


//calcula a altura de um no
int alt_NO(struct NO* no){
    if(no == NULL){
        return -1;
    }else{
        return no->alt;
    }
}
//calcula o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x,int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

void rotacaoLL(arvoreAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;


}

