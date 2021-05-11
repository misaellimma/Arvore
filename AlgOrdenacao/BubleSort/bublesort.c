#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TAM 100000
int vetor[TAM];

void lerArquivo(char nome[]);
void bubleSort(int vet[]);
void imprimeVetor(int vetor[]);
void funcao(char url[], char nome[]);


int main(){
    char ordenado[] = "ordenado.txt";
    char ordeminversa[] = "ordeminversa.txt";
    char aleatorio[] = "aleatorio.txt";

    funcao(ordenado, "Ordenado");
    funcao(ordeminversa, "Ordem inversa");
    funcao(aleatorio, "Aleatorio");
    printf("\n");
    return 0;
}

void funcao(char url[], char nome[]){
    clock_t tempo_1, tempo_2;
    lerArquivo(url);
    tempo_1 = clock();
    bubleSort(vetor);
    tempo_2 = clock();

    double dif = tempo_2 - tempo_1;

    printf("\n Tempo de execucao %s: %f\n", nome, (dif));
}

void charToInt(char texto[]){
    int i = 1;
    char *retorno;
    retorno = strtok(texto, " ");
    vetor[0] = atoi(retorno);
    do{
        retorno = strtok('\0', " ");
        if(retorno){
            vetor[i] = atoi(retorno);
        }
        i++;
    }while(retorno);
}

void lerArquivo(char nome[]){
    int c;
    char texto[588895]; //588895
    FILE *arquivo = fopen(nome, "r");
    if(!arquivo){
        printf("\n Erro na abertura do arquivo");
        exit(1);
    }else{
        int i = 0;
        while((c = getc(arquivo)) != EOF){
            texto[i] = c;
            i++;
        }
        charToInt(texto);
    }
    fclose(arquivo);
}

void bubleSort(int vet[]){
    int i, j, aux;

    //valor da esquerda sendo analizado
    for(i = 0; i < TAM; i++){
        //valor da direita sendo analisado
        for(j = i +1; j < TAM; j++){
            //confere se precisa fazer a troca
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void imprimeVetor(int vetor[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf(" %d", vetor[i]);
    }
    printf("\n");
}