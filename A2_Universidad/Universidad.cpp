#include "Universidad.h"
#include <iostream>

Universidad::Universidad() {
    this->nombre = "sin nombre";
}

Universidad::Universidad(string nombre) {
    this->nombre = nombre;
}

// Agregacion: si la universidad desaparece, los alumnos y los cursos
// siguen existiendo. Por eso el destructor no libera nada.
Universidad::~Universidad() {
    cout << "Eliminandose la universidad " << nombre << endl;
}

void Universidad::set_nombre(string nombre) { this->nombre = nombre; }
string Universidad::get_nombre() { return nombre; }

void Universidad::agregar_alumno(Alumno* alumno) {
    alumnos.push_back(alumno);
}

void Universidad::agregar_clase(Curso* curso) {
    cursos.push_back(curso);
}

void Universidad::imprimir_alumno() {
    cout << "Alumnos de " << nombre << ":" << endl;
    for (int i = 0; i < (int)alumnos.size(); ++i) {
        cout << "  " << alumnos[i]->get_codigo()
             << " - " << alumnos[i]->get_nombre() << endl;
    }
}

void Universidad::imprimir_clase() {
    cout << "Cursos de " << nombre << ":" << endl;
    for (int i = 0; i < (int)cursos.size(); ++i) {
        cout << "  ";
        cursos[i]->imprimir();
    }
}
