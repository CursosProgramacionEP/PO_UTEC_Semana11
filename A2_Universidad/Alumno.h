#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <vector>
#include "Curso.h"
using namespace std;

class Alumno {
private:
    string nombre;
    string codigo;
    vector<Curso*> cursos;   // agregacion: el alumno apunta a cursos que no le pertenecen

public:
    Alumno();
    Alumno(string nombre, string codigo);
    ~Alumno();

    void set_nombre(string nombre);
    void set_codigo(string codigo);
    string get_nombre();
    string get_codigo();

    void agregar_clase(Curso* curso);
    void imprimir_clase();
};

#endif
