#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <vector>
#include "Curso.h"

class Alumno {
private:
    std::string nombre;
    std::string codigo;
    std::vector<Curso*> cursos;   // agregacion: el alumno apunta a cursos que no le pertenecen

public:
    Alumno();
    Alumno(const std::string& nombre, const std::string& codigo);
    ~Alumno();

    void set_nombre(const std::string& nombre);
    void set_codigo(const std::string& codigo);
    std::string get_nombre() const;
    std::string get_codigo() const;

    void agregar_clase(Curso* curso);
    void imprimir_clase() const;
};

#endif
