#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TAM 100000
//declaracao do vetor global
int vetor[TAM];

//declaracao de funcoes.
void lerArquivo(char nome[]);
void selectionSort(int vet[]);
void insertionSort(int vet[]);
void bubleSort(int vet[]);
void imprimeVetor(int vetor[]);
void funcao(char url[], char nome[]);

//funcao principal
int main(){
    //armazenando os nomes de arquivos de entrada.
    char ordenado[] = "ordenado.txt";
    char ordeminversa[] = "ordeminversa.txt";
    char aleatorio[] = "aleatorio.txt";
    printf("\n=================================================================");

    //chama funcao para medir o tempo de execucao, abrir arquivo e ordenar o vetor.
    funcao(ordenado, "Ordenado");
    printf("\n=================================================================");
    funcao(ordeminversa, "Ordem inversa");
    printf("\n=================================================================");
    funcao(aleatorio, "Aleatorio");
    printf("\n=================================================================");

    printf("\n");

    return 0;
}

//funcao que mede o tempo de execucao, abre arquivo e organiza o vetor.
void funcao(char url[], char nome[]){
    //declaracao das variaveis que armazena o clock.
    clock_t tempo_1, tempo_2;
    double diferenca;

    lerArquivo(url);//chama a funcao para ler o arquivo.
    tempo_1 = clock();//registra o tempo do clock.
    selectionSort(vetor);//chama a funcao para ordenar o vetor
    tempo_2 = clock();//registra o tempo do clock
    
    diferenca = difftime(tempo_2, tempo_1);//calcula quanto tempo foi gasto na execucao da funcao.
    diferenca = diferenca / (double)CLOCKS_PER_SEC;//transforma o valor em segundos
    
    printf("\n Tempo de execucao de forma %s e: %f segundos\n", nome, (diferenca));//imprime na tela o tempo de execucao.


    lerArquivo(url);//chama a funcao para ler o arquivo.
    tempo_1 = clock();//registra o tempo do clock.
    insertionSort(vetor);//chama a funcao para ordenar o vetor
    tempo_2 = clock();//registra o tempo do clock
    
    diferenca = difftime(tempo_2, tempo_1);//calcula quanto tempo foi gasto na execucao da funcao.
    diferenca = diferenca / (double)CLOCKS_PER_SEC;//transforma o valor em segundos
    
    printf("\n Tempo de execucao de forma %s e: %f segundos\n", nome, (diferenca));//imprime na tela o tempo de execucao.

    
    lerArquivo(url);//chama a funcao para ler o arquivo.
    tempo_1 = clock();//registra o tempo do clock.
    bubleSort(vetor);//chama a funcao para ordenar o vetor
    tempo_2 = clock();//registra o tempo do clock
    
    diferenca = difftime(tempo_2, tempo_1);//calcula quanto tempo foi gasto na execucao da funcao.
    diferenca = diferenca / (double)CLOCKS_PER_SEC;//transforma o valor em segundos
    
    printf("\n Tempo de execucao de forma %s e: %f segundos\n", nome, (diferenca));//imprime na tela o tempo de execucao.
}

//funcao que separa cada grupo de numeros e converte de caracter para inteiro
void charToInt(char texto[]){
    //declaracao das variaveis.
    int i = 0;
    char *retorno;
    
    //laco onde separa cada grupo de numeros e aloca em uma posicao do vetor.
    do{
        if(i == 0){
            retorno = strtok(texto, " ");
            vetor[i] = atoi(retorno);//converte para inteiro e coloca no vetor.
        }else{
            retorno = strtok('\0', " ");
            if(retorno){
                vetor[i] = atoi(retorno);//converte para inteiro e coloca no vetor.
            }
        }

        i++;
    }while(retorno);
}
//funcao que le o arquivo
void lerArquivo(char nome[]){
    //declaracao das variaveis
    int c;
    char texto[588897]; //588897 tamanho do vetor
    FILE *arquivo = fopen(nome, "r");//funcao que abre o arquivo
    if(!arquivo){
        printf("\n Erro na abertura do arquivo");
        exit(1);
    }else{
        int i = 0;//contador
        while((c = getc(arquivo)) != EOF){//percorre cada caracter do arquivo ate o fim do arquivo.
            texto[i] = c;
            i++;
        }
        charToInt(texto);//chama a funcao para converter o array de caracteres para o vetor.
    }
    fclose(arquivo);//fecha o arquivo.
}

//funcao de ordenacao
void selectionSort(int vet[]){
    printf("\n SelectionSort");
    //declaracao das variaveis.
    int posicaoMenorValor, i, j, aux;

    for(i = 0; i < TAM; i++){
        posicaoMenorValor = i;//Recebe a posicao inicial para o menor valor.
        //Analisa os elementos na frente
        for(j = i + 1; j < TAM; j++){
            //caso encontre um valor menor na frente dos analisados
            if(vetor[j] < vetor[posicaoMenorValor]){
                posicaoMenorValor = j;
            }
        }
        //verifica se houve mudanca e troca os valores
        if(posicaoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoMenorValor];
            vetor[posicaoMenorValor] = aux;
        }
    }
}

void insertionSort(int vet[]){
    printf("\n InsertionSort");

    //declaracao das variaveis.
    int i, j, atual;

    for(i = 1; i < TAM; i++){
        atual = vetor[i];
        j = i - 1;

        while((j >= 0) && (atual < vetor[j])){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        vetor[j + 1] = atual;
    }
}

void bubleSort(int vet[]){
    printf("\n BubleSort");

    //declaracao das variaveis.
    int i, j, aux;

    for(i = 0; i < TAM; i++){//valor da esquerda sendo analizado.
        for(j = i +1; j < TAM; j++){//valor da direita sendo analisado.
            if(vet[i] > vet[j]){//confere se precisa fazer a troca.
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}