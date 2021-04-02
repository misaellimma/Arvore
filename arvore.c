#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *esq;
	struct Node *dir;
};
typedef struct Node* Arvore;

int menu();
void limpaTela();
Arvore* cria_Arvore();
void executaOpcao(Arvore* raiz, int opt);
void imprimePreOrdem(Arvore *raiz);
void imprimeEmOrdem(Arvore *raiz);
void imprimePosOrdem(Arvore *raiz);
int inserirNo(Arvore* raiz, int valor);
int removerNo(Arvore *raiz, int valor);
struct Node* removeAtual(struct Node* atual);
	
int main(){
	Arvore* raiz = cria_Arvore();
	int op;

	do{
        op = menu();
        executaOpcao(raiz, op);
    }while(op != 0);
	
	return 0;
}

Arvore* cria_Arvore(){
	Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
	if(raiz != NULL){
		*raiz = NULL;
    }
	return raiz;
}

int menu(){
	int opcao;
    
    printf("\nEscolha uma opcao:\n");
    printf("Digite 0 para sair\n");
    printf("Digite 1 para adicionar na arvore\n");
    printf("Digite 2 para remover da arvore\n");
    printf("Digite 3 para listar em pre ordem\n");
    printf("Digite 4 para listar em ordem\n");
    printf("Digite 5 para listar em pos ordem\n");
    printf(">> ");
    scanf("%d", &opcao);
    
    return opcao;
}

void limpaTela(){
    system("cls");
}

void executaOpcao(Arvore* raiz, int op){
	int num;
    switch (op){
    case 0:
        limpaTela();
        printf("Encerrando...");
        break;
    case 1:
        limpaTela();
        printf("Inserindo na arvore\n\n");
        printf("Digite um numero: ");
        scanf("%d", &num);
        raiz = inserirNo(raiz, num);
        break;
    case 2:
        limpaTela();
        printf("removendo da arvore\n\n");
        printf("Digite um numero para ser removido: ");
        scanf("%d", &num);
        raiz = removerNo(raiz, num);
        break;
    case 3:
        limpaTela();
        printf("listando em pre ordem\n\n");
        imprimePreOrdem(raiz);
        break;
    case 4:
        limpaTela();
        printf("listando em ordem\n\n");
        imprimeEmOrdem(raiz);
        break;
    case 5:
        limpaTela();
        printf("listando em pos ordem\n\n");
        imprimePosOrdem(raiz);
        break;
    default:
        limpaTela();
        printf("Comando invalido!\n\n");
        break;
    }
}

void imprimePreOrdem(Arvore *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		printf("%d\n", (*raiz)->num);
		imprimePreOrdem(&((*raiz)->esq));
		imprimePreOrdem(&((*raiz)->dir));
	}
}

void imprimeEmOrdem(Arvore *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		imprimeEmOrdem(&((*raiz)->esq));
		printf("%d\n", (*raiz)->num);
		imprimeEmOrdem(&((*raiz)->dir));
	}
}

void imprimePosOrdem(Arvore *raiz){
	if(raiz == NULL){
		return;
    }
	if(*raiz != NULL){
		imprimePosOrdem(&((*raiz)->esq));
		imprimePosOrdem(&((*raiz)->dir));
		printf("%d\n", (*raiz)->num);
	}
}

int inserirNo(Arvore* raiz, int valor){
	if(raiz == NULL){
		return 0;
    }
	struct Node* novo;
	novo = (struct Node*) malloc(sizeof(struct Node));

	if(novo == NULL){
		return 0;
    }
	novo->num = valor;
	novo->dir = NULL;
	novo->esq = NULL;
	
	if(*raiz == NULL){
		*raiz = novo;
	}else{
		struct Node* atual = *raiz;
		struct Node* ant = NULL;
		while(atual != NULL){
			ant = atual;
			if(valor == atual->num){
				free(novo);
				printf("Valor ja existe na arvore \n\n");
				return 0;
			}
			if(valor > atual->num){
				atual = atual->dir;
			}else{
				atual = atual->esq;
            }
		}
		if(valor > ant->num){
			ant->dir = novo;
		}else{
			ant->esq = novo;
        }
	}	
	printf("\nValor inserido com sucesso\n");
	return 1;
}

int removerNo(Arvore *raiz, int valor){
	if(raiz == NULL){
        return 0;
    }
	struct Node* ant = NULL;
	struct Node* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->num){
			if(atual == *raiz){
				*raiz = removeAtual(atual);
			}else{
				if(ant->dir == atual){
					ant->dir = removeAtual(atual);
				}else{
					ant->esq = removeAtual(atual);
                }
			}
		    return 1;
		}

        ant = atual;
        if(valor > atual->num){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
	
	if(valor != atual && valor != ant){
		printf("\nValor nao encontrado\n");
		return 0;
    }
}

struct Node* removeAtual(struct Node* atual){
	struct Node *no1;
	struct Node *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		printf("\nValor removido com sucesso\n");
		return no2;
	}

	no1 = atual;
	no2 = atual->esq;
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}

	if(no1 != atual){
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}

	no2->dir = atual->dir;
	free(atual);
	return no2;
}