#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

class Curso {
private:
    string nombre;
    string codigo;

public:
    Curso();
    Curso(string nombre, string codigo);
    ~Curso();

    void set_nombre(string nombre);
    void set_codigo(string codigo);
    string get_nombre();
    string get_codigo();

    void imprimir();
};

#endif
