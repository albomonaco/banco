#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "entrada.h"

int bloqueado = 0;

int main(){

    bemvindo();
    
    do{
        entrar();
        
        if(validou()){
            entrada();
        }

        acesso_negado(bloqueado);
        
    } while(!bloqueado);
}