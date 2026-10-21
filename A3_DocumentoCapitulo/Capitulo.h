#ifndef CAPITULO_H
#define CAPITULO_H

#include <string>

class Capitulo {
private:
    int numero;
    std::string titulo;

public:
    Capitulo();
    Capitulo(int numero, const std::string& titulo);
    ~Capitulo();

    void set_numero(int numero);
    void set_titulo(const std::string& titulo);
    int get_numero() const;
    std::string get_titulo() const;

    void imprimir() const;
};

#endif
