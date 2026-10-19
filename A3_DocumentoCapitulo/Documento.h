#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <string>
#include <vector>
#include "Capitulo.h"
using namespace std;

class Documento {
private:
    string titulo;
    Capitulo capitulo;             // composicion: un capitulo que es parte del documento
    vector<Capitulo> capitulos;    // composicion: los capitulos viven dentro del documento

public:
    Documento();
    Documento(string titulo, vector<Capitulo> capitulos);
    ~Documento();

    void set_titulo(string titulo);
    string get_titulo();

    void agregar_capitulo(Capitulo capitulo);
    int cantidad_capitulos();

    void imprimir();
};

#endif
