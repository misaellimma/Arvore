#include<stdio.h>
#include<stdlib.h>

struct arvore{
    int num;
    struct arvore* esq;
    struct arvore* dir;
};
typedef struct arvore Arvore;

void inicia_arvore(Arvore* ARVORE);
Arvore* insere(Arvore* ARVORE, int num);
Arvore* retira(Arvore* ARVORE, int num);
int menu();
void executa_opcao(int op, Arvore* ARVORE);


int main(){
    int op;
    Arvore *ARVORE = /*(Arvore*)malloc(sizeof(Arvore))*/NULL;
    //inicia_arvore(ARVORE);

/*
    if(!ARVORE){
        printf(" memoria cheia");
        //exit(1);
    }else{*/
        //inicia_arvore(ARVORE);
        //printf("..%d..\n", &ARVORE);/*
        ARVORE = insere(ARVORE, 10);

        ARVORE = insere(ARVORE, 5);
        ARVORE = insere(ARVORE, 1);
        ARVORE = insere(ARVORE, 2);
        ARVORE = insere(ARVORE, 7);
        ARVORE = insere(ARVORE, 20);
        ARVORE = insere(ARVORE, 33);
        ARVORE = insere(ARVORE, 30);

        do{
            op = menu();
            executa_opcao(op, ARVORE);
        }while(op != 0);

    //}
    return 0;
}

int menu(){
    int opcao;
    
    printf("Escolha uma opcao:\n");
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

void executa_opcao(int op, Arvore* ARVORE){
    int num;
    switch (op){
    case 0:
        system("cls");
        printf("Encerrando...");
        break;
    case 1:
        system("cls");
        printf("Inserindo na arvore\n\n");
        //int num;
        printf("Digite um numero: ");
        scanf("%d", &num);
        printf("..%d..", num);
        ARVORE = insere(ARVORE, num);
        break;
    case 2:
        system("cls");
        printf("removendo da arvore\n\n");
        //int num = 0;
        printf("Digite um numero para ser removido: ");
        scanf("%d", &num);
        ARVORE = retira(ARVORE, num);
        break;
    case 3:
        system("cls");
        printf("listando em pre ordem\n\n");
        imprimePreOrdem(ARVORE);
        break;
    case 4:
        system("cls");
        printf("listando em ordem\n\n");
        imprime_ordem(ARVORE);
        break;
    case 5:
        system("cls");
        printf("listando em pos ordem\n\n");
        imprimePosOrdem(ARVORE);
        break;
    default:
        system("CLS");
        printf("Comando invalido!\n\n");
        break;
    }
}

void inicia_arvore(Arvore* ARVORE){
    ARVORE->dir = NULL;
    ARVORE->esq = NULL;
    ARVORE->num = NULL;
}

void imprimePreOrdem(Arvore* ARVORE){
    if(ARVORE == NULL)
        return;
    if(ARVORE != NULL){
        printf("%d \n", ARVORE->num);
        imprimePreOrdem(ARVORE->esq);
        imprimePreOrdem(ARVORE->dir);
    }
}

void imprime_ordem(Arvore* ARVORE){
    if(ARVORE == NULL)
        return;
    if(ARVORE != NULL){
        imprime_ordem(ARVORE->esq);
        printf("%d \n", ARVORE->num);
        imprime_ordem(ARVORE->dir);
    }
}

void imprimePosOrdem(Arvore* ARVORE){
    if(ARVORE == NULL)
        return;
    if(ARVORE != NULL){
        imprimePosOrdem(ARVORE->esq);
        imprimePosOrdem(ARVORE->dir);
        printf("%d \n", ARVORE->num);
    }
}

Arvore* insere(Arvore* ARVORE, int num){
    if(ARVORE == NULL){
        Arvore *aux = (Arvore*)malloc(sizeof(Arvore));
        aux->num = num;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }else if(num > ARVORE->num){
        ARVORE->dir = insere(ARVORE->dir, num);
    }else if(num < ARVORE->num){
        ARVORE->esq = insere(ARVORE->esq, num);
    }
    return ARVORE;
        //printf("..%d..\n", ARVORE->esq);
    //printf("..%d..\n", ARVORE->dir);

/*
    if(ARVORE == NULL){
        ARVORE = (Arvore *) malloc(sizeof(Arvore));
        ARVORE->num = num;
        ARVORE->esq = NULL;
        ARVORE->dir = NULL;
        printf("%d ", ARVORE->num);
    }else if(num < ARVORE->num){
        printf("%d ", ARVORE->num);
        ARVORE->esq = insere(ARVORE->esq, num);
    }else if(num > ARVORE->num){
        printf("%d ", ARVORE->num);
        ARVORE->dir = insere(ARVORE->dir, num);
    }
    return ARVORE;*/
}

Arvore* min(Arvore* ARVORE){
    if(ARVORE != NULL){
        Arvore* aux = ARVORE;
        while(aux->esq != NULL){
            aux = aux->esq;
        }
        return aux;
    }
    return NULL;
}

Arvore* max(Arvore* ARVORE){
    if(ARVORE != NULL){
        Arvore* aux = ARVORE;
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        return aux;
    }
    return NULL;
}

Arvore* retira(Arvore* ARVORE, int num){
    if(ARVORE == NULL){
        return NULL;
    }else if(ARVORE->num > num){
        ARVORE->esq = retira(ARVORE->esq, num);
    }else if(ARVORE->num < num){
        ARVORE->dir = retira(ARVORE->dir, num);
    }else{
        if(ARVORE->esq == NULL && ARVORE->dir == NULL){
            free(ARVORE);
            return NULL;
        }else if(ARVORE->esq == NULL && ARVORE->dir != NULL){
            Arvore* aux = ARVORE->dir;
            free(ARVORE);
            return aux;
        }else if(ARVORE->dir == NULL && ARVORE->esq != NULL){
            Arvore* aux = ARVORE->esq;
            free(ARVORE);
            return aux;
        }else{
            Arvore* aux;
            if(ARVORE->dir != NULL){
                aux = min(ARVORE->dir);
            }else{
                aux = max(ARVORE->esq);
            }
            Arvore* tmp = aux->num;
            ARVORE = retira(ARVORE, aux->num);
            ARVORE->num = tmp;
        }
    }
    return ARVORE;
}