#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "entrada.h"

int conta_a_validar;
int senha_a_validar;
int tentativas = 3;

void bemvindo(){
    printf("\nBem vindo ao Banco Monaco!\n\n");
}

void entrar(){

    sleep(1);

    printf("Número da Conta: ");
    scanf("%d", &conta_a_validar);

    sleep(1);

    printf("Senha: ");
    scanf("%d", &senha_a_validar);

    printf("\nValidando...\n");
    sleep(2);
}

void entrada(){
    
    printf("Acesso permitido.\n");

    sleep(1);

    printf("Entrando...\n\n");

    sleep(3);

    printf("Olá! Bem vindo à sua conta!\n");
    exit(1);
}

int validou(){

    FILE* arquivo_conta = fopen("./db/conta.txt", "r");
    FILE* arquivo_senha = fopen("./db/senha.txt", "r");

    if(arquivo_conta == 0 || arquivo_senha == 0 ){
        printf("Erro no sistema. Saindo...\n");
        exit(1);
    }

    int conta;
    fscanf(arquivo_conta, "%d", &conta);

    if (conta_a_validar == conta){

        int senha;
        fscanf(arquivo_senha, "%d", &senha);

        if (senha_a_validar == senha){
            return 1;
        }
    }

    fclose(arquivo_conta);
    fclose(arquivo_senha);
    
    return 0;
}

void acesso_negado(int bloqueado){
    tentativas--;
    
    if(tentativas == 0){
        printf("Acesso Bloqueado. Você tentou demais.\n");
        exit(1);
    }

    printf("Acesso negado! Você digitou algo errado. Você tem mais %d tentativas. Depois disso, seu acesso será bloqueado.\n\n", tentativas);
}