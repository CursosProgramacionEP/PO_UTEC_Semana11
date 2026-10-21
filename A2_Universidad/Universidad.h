#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>
#include <vector>
#include "Alumno.h"
#include "Curso.h"

class Universidad {
private:
    std::string nombre;
    std::vector<Alumno*> alumnos;   // agregacion
    std::vector<Curso*> cursos;     // agregacion

public:
    Universidad();
    Universidad(const std::string& nombre);
    ~Universidad();

    void set_nombre(const std::string& nombre);
    std::string get_nombre() const;

    void agregar_alumno(Alumno* alumno);
    void agregar_clase(Curso* curso);
    void imprimir_alumno() const;
    void imprimir_clase() const;
};

#endif
