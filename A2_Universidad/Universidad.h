#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>
#include <vector>
#include "Alumno.h"
#include "Curso.h"
using namespace std;

class Universidad {
private:
    string nombre;
    vector<Alumno*> alumnos;   // agregacion
    vector<Curso*> cursos;     // agregacion

public:
    Universidad();
    Universidad(string nombre);
    ~Universidad();

    void set_nombre(string nombre);
    string get_nombre();

    void agregar_alumno(Alumno* alumno);
    void agregar_clase(Curso* curso);
    void imprimir_alumno();
    void imprimir_clase();
};

#endif
