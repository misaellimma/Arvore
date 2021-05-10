#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const TAM = 10;

void lerArquivo(char nome[]);
void bubleSort();


int main(){
    char ordenado[] = "ordenado.txt";
    char ordeminversa[] = "ordeminversa.txt";
    char aleatorio[] = "aleatorio.txt";

    lerArquivo(ordenado);

    int i, j, aux;
    int vet[10] = {5, 1, 30, 50, 4, 20, 6, 7, 8, 9};
    
    for(i = 0; i < TAM; i++){
        printf(" %d", vet[i]);
    }
    printf("\n");
    
    for(i = 1; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    for(i = 0; i < TAM; i++){
        printf(" %d", vet[i]);
    }


    return 0;
}

void lerArquivo(char nome[]){
    printf("arquivo %s ", nome);
    FILE *arquivo = fopen(nome, "r");
    if(arquivo == NULL){
        printf("\n Erro na abertura do arquivo");
        exit(1);
    }
    int numero;
    printf("\n teste");
    /*while(scanf("%d", &numero) == 1){
        printf(" %d");
    }*/
    fclose(arquivo);
/*
    int vetor[1000];
    while(!feof(f)){
        fscanf(f, "");
    }*/
}

void gravarArquivo(){

}

void bubleSort(){
    int i, j, vet[TAM], aux;
    for(i = 1; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}