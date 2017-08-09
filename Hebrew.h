#ifndef HEBREW_H
#define HEBREW_H

class Hebrew {
public:
    void criptografar(char *mensagem, char *resposta);
    void descriptografar(char *mensagem, char *resposta);
protected:
    char alfabeto[26];
};
#endif