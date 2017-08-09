#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ATBASH.h"
#include "ALBAM.h"
#include "ATBAH.h"

using namespace std;

char* mensagem;
int cripto = -1;

void configuracaoErrada() {
    cout << "Configuração mal realizada. Por favor, utilize a opção -h.";
}

void mostrarAjuda() {
    cout << "---- Instituto Federal de Rondônia - Campus Ariquemes ----" << endl;
    cout << "Criptografa e descriptografa mensagens usando Cifra Hebraica (ATBASH, ATBAH ou ALBAM)" << endl;
    cout << "N. A. V. Simões <natanael.simoes@ifro.edu.br>" << endl;
    cout << "http://github.com/ifroariquemes/Hebrew" << endl << endl;
    cout << "Uso:" << endl << endl;
    cout << "      hebrew -c|-d mensagem [-m metodo]" << endl << endl;
    cout << " -c mensagem      Criptografa uma mensagem" << endl;
    cout << " -d mensagem      Decriptografa uma mensagem" << endl;
    cout << " -m metodo        Estabelece o metodo atbash(padrao), atbah ou albam" << endl;
    cout << " -h               Mostra essa mensagem" << endl << endl;
    cout << " Criptografar: hebrew -c mensagem -m atbash " << endl;
    cout << " Decriptografar: hebrew -d NVMHZTVN" << endl;
}

int decisao(Hebrew *at) {
    char resposta[strlen(mensagem) + 1];
    switch (cripto) {
        case -1:
            configuracaoErrada();
            return 1;
        case 1:
            at->criptografar(mensagem, resposta);
            break;
        case 0:
            at->descriptografar(mensagem, resposta);
            break;
    }
    resposta[strlen(mensagem) + 1] = '\0';
    cout << resposta;
    return 0;
}

int main(int argc, char** argv) {
    char metodo[6];
    char *mPar;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][2] == '\0') { // Parametro chegando
            switch (argv[i][1]) {
                case 'd':
                    mensagem = argv[++i];
                    cripto = 0;
                    break;
                case 'c':
                    mensagem = argv[++i];
                    cripto = 1;
                    break;
                case 'm':
                    mPar = argv[++i];
                    for(int i = 0; mPar[i]; i++) {
                        metodo[i] = mPar[i];
                    }
                    break;
                case 'h':
                    if (argc > 2) {
                        configuracaoErrada();
                        return 1;
                    }
                    mostrarAjuda();
                    return 0;
                default:
                    configuracaoErrada();
                    return 1;
            }
        }
    }
    if (strcmp(metodo, "atbah") == 0) {
        ATBAH at;
        return decisao(&at);
    } else if (strcmp(metodo, "albam") == 0) {
        ALBAM at;
        return decisao(&at);
    } else {
        ATBASH at;
        return decisao(&at);
    }
}