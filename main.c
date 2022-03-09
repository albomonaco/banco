#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "entrada.h"

int logado = 0;

void cumprimentar(){
    char nome[70];
    
    FILE* arquivo_nome = fopen("./db/nome.txt", "r");    
    fscanf(arquivo_nome, "%s", nome);

    printf("Olá %s!\n", nome);

    fclose(arquivo_nome);
}

void ver_saldo(){

    FILE* arquivo_saldo = fopen("./db/saldo.txt", "r");

    float saldo;
    fscanf(arquivo_saldo, "%f", &saldo);
    
    printf("\nSaldo: %0.2f reais.\n", saldo);
    
    
    fclose(arquivo_saldo);
}

int comandar(){
    
    int comando;

    printf("\nO que você deseja fazer?\n");
    printf("(1) Ver Saldo (2) Sair\n\n");

    scanf("%d", &comando);

    return comando;
}

int main(){

    bemvindo();
    login(&logado);

    if(logado) cumprimentar();

    while(logado){

        switch(comandar()){
            case SALDO:
                ver_saldo();
                break;
            case SAIR:
                logado = 0;
                
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }

    }
}