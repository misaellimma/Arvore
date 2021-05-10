#include<stdio.h>
#include<stdlib.h>

int main(){
    const TAM = 10;
    int vet[10];
    int i, j, min;

    for(i = 0; i < TAM; i++){
        min = i;
        for(j = i+1; j < TAM;j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }

        if(i != min){
            int aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
    return 0;
}

imprime(){ 
    int a;
    //for(int i = 0; i < lenght.a){
        
    //}
}