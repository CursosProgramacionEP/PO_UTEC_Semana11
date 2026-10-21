#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <string>
#include <vector>
#include "Capitulo.h"

class Documento {
private:
    std::string titulo;
    Capitulo capitulo;             // composicion: un capitulo que es parte del documento
    std::vector<Capitulo> capitulos;   // composicion: los capitulos viven dentro del documento

public:
    Documento();
    Documento(const std::string& titulo, const std::vector<Capitulo>& capitulos);
    ~Documento();

    void set_titulo(const std::string& titulo);
    std::string get_titulo() const;

    void agregar_capitulo(const Capitulo& capitulo);
    int cantidad_capitulos() const;

    void imprimir() const;
};

#endif
