#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include "Hebrew.h"

void Hebrew::criptografar(char *mensagem, char *resposta) {
    int i = 0;
    while(mensagem[i]) {
        mensagem[i] = toupper(mensagem[i]);
        resposta[i] = alfabeto[(int) mensagem[i] - 65];
        i++;
    }
    resposta[i] = '\0';
}

void Hebrew::descriptografar(char *mensagem, char *resposta) {
    criptografar(mensagem, resposta);
}