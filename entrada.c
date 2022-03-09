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

int login(int* logado){

    do{
        sleep(1);

        printf("Número da Conta: ");
        scanf("%d", &conta_a_validar);

        sleep(1);

        printf("Senha: ");
        scanf("%d", &senha_a_validar);

        printf("\nValidando...\n");
        sleep(2);
    } while(!entrou(logado) && !bloqueado());
    
    
}

int bloqueado(){
    return tentativas == 0 ? 1 : 0;
}

int entrou(int* logado){
    
    if(validou()){
        printf("Acesso permitido.\n");

        sleep(1);

        printf("Entrando...\n\n");

        sleep(3);

        *logado = 1;
        return 1;

    }

    tentativas--;

    if(bloqueado()){
        printf("Acesso Bloqueado. Você tentou demais.\n");
        return 0;
    }

    printf("Conta Inválida. Você tem mais %d tentativas.\n\n", tentativas);
    return 0;
}

int validou(){

    FILE* arquivo_conta = fopen("./db/conta.txt", "r");
    FILE* arquivo_senha = fopen("./db/senha.txt", "r");

    if(arquivo_conta == 0 || arquivo_senha == 0 ){
        printf("Erro no sistema. Saindo...\n");
        sleep(2);
        exit(1);
    }

    int conta;
    fscanf(arquivo_conta, "%d", &conta);

    if (conta_a_validar == conta){

        int senha;
        fscanf(arquivo_senha, "%d", &senha);

        if (senha_a_validar == senha){
            
            fclose(arquivo_conta);
            fclose(arquivo_senha);

            return 1;
        }
    }

    fclose(arquivo_conta);
    fclose(arquivo_senha);
    
    return 0;
}