#ifndef CAPITULO_H
#define CAPITULO_H

#include <string>
using namespace std;

class Capitulo {
private:
    int numero;
    string titulo;

public:
    Capitulo();
    Capitulo(int numero, string titulo);
    ~Capitulo();

    void set_numero(int numero);
    void set_titulo(string titulo);
    int get_numero();
    string get_titulo();

    void imprimir();
};

#endif
