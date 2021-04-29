#include <stdio.h>
#include <stdlib.h>

struct NO{
	int info;
	struct NO *esq;
	struct NO *dir;
};
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if(raiz != NULL)
		*raiz = NULL;
	return raiz;
}

int menu(void);
void executamenu(ArvBin* raiz, int opt);
int menu2(void);
void executamenu2(ArvBin* raiz, int opt2);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
	

int main(){
	
	ArvBin* raiz = cria_ArvBin();
	
	int opt=1;
	int opt2;
	while(opt > 0){
		opt = menu();
		executamenu(raiz, opt);
		if (opt == 1){
			opt2 = menu2();
			executamenu2(raiz, opt2);
		}
	}
	
	return 0;
}

int menu(void){
	
	int opt;
	
	printf("\n 1. Imprimir\n");
	printf("\n 2. Inserir novo valor\n");
	printf("\n 3. Remover da arvode\n");
	printf("\n 4. Sair \n");
	scanf("%d", &opt);
	return opt;
	
}

void executamenu(ArvBin* raiz, int opt){
	
	switch(opt){
		
		int valor;
		
		case 1:
			
		break;
		
		case 2:
			printf("\n Valor para inserir: \n");
			scanf("%d", &valor);
			insere_ArvBin(raiz, valor);
		break;
		
		case 3:
			printf("\n Valor para remover: \n");
			scanf("%d", &valor);
			remove_ArvBin(raiz, valor);
		break;
		
		case 4:
			printf("\n Saindo \n");
			exit(1);
		break;
		
		default:
			printf("\n Opcao invalida \n");
	}
}

int menu2(){
	int opt2;
	printf("\n 1.Pre-Ordem \n");
	printf("\n 2.Em-Ordem \n");
	printf("\n 3.Pos-Ordem \n");
	scanf("%d", &opt2);
	return opt2;
}

void executamenu2(ArvBin* raiz, int opt2){
	
	switch(opt2){
		
		case 1:
			printf("\n Imprimindo Pre-Ordem \n");
			preOrdem_ArvBin(raiz);
		break;
		
		case 2:
			printf("\n Imprimindo Em-Ordem \n");
			emOrdem_ArvBin(raiz);
		break;
		
		case 3:
			printf("\n Imprimindo Pos-Ordem \n");
			posOrdem_ArvBin(raiz);
		break;
		
		default:
			printf("\n Opcao invalida(2) \n");
	}
}

void preOrdem_ArvBin(ArvBin *raiz){
	
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		printf("%d\n", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin *raiz){
	if (raiz == NULL)
		return;
	if (*raiz != NULL){
		emOrdem_ArvBin(&((*raiz)->esq));
		printf(("%d\n"), (*raiz)->info);
		emOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_ArvBin(ArvBin *raiz){
	if(raiz == NULL)
		return;
	if(*raiz != NULL){
		posOrdem_ArvBin(&((*raiz)->esq));
		posOrdem_ArvBin(&((*raiz)->dir));
		printf("%d\n", (*raiz)->info);
	}
}

int insere_ArvBin(ArvBin* raiz, int valor){
	if(raiz == NULL)
		return 0;
	struct NO* novo;
	novo = (struct NO*) malloc(sizeof(struct NO));
	if(novo == NULL)
		return 0;
	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;
	
	if(*raiz == NULL)
		*raiz = novo;
	else{
		struct NO* atual = *raiz;
		struct NO* ant = NULL;
		while(atual != NULL){
			ant = atual;
			if(valor == atual->info){
				free(novo);
				printf("Valor ja inserido na arvore \n");
				return 0;
			}
			if(valor > atual->info)
				atual = atual->dir;
			else
				atual = atual->esq;
		}
		if(valor > ant->info)
			ant->dir = novo;
		else
			ant->esq = novo;
	}	
	printf("Valor inserido com sucesso");
	return 1;
}

int remove_ArvBin(ArvBin *raiz, int valor){
	
	if(raiz == NULL)
		return 0;
	struct NO* ant = NULL;
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			if(atual == *raiz)
				*raiz = remove_atual(atual);
			else{
				if(ant->dir == atual)
					ant->dir = remove_atual(atual);
				else
					ant->esq = remove_atual(atual);	
			}

		return 1;
		}
	ant = atual;
	if(valor > atual->info)
		atual = atual->dir;
	else
		atual = atual->esq;
	}
	
	if(valor != (atual && ant))
		printf("Valor nao encontrado \n");
		return 0;
}

struct NO* remove_atual(struct NO* atual){
	struct NO *no1;
	struct NO *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		printf("Valor removido com sucesso \n");
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




