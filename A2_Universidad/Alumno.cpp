#include "Alumno.h"
#include <iostream>

Alumno::Alumno() {
    this->nombre = "sin nombre";
    this->codigo = "sin codigo";
}

Alumno::Alumno(string nombre, string codigo) {
    this->nombre = nombre;
    this->codigo = codigo;
}

// El alumno no destruye sus cursos: solo guarda los punteros.
Alumno::~Alumno() {
    cout << "Eliminandose el alumno " << codigo << endl;
}

void Alumno::set_nombre(string nombre) { this->nombre = nombre; }
void Alumno::set_codigo(string codigo) { this->codigo = codigo; }
string Alumno::get_nombre() { return nombre; }
string Alumno::get_codigo() { return codigo; }

void Alumno::agregar_clase(Curso* curso) {
    cursos.push_back(curso);
}

void Alumno::imprimir_clase() {
    cout << "Cursos de " << nombre << " (" << codigo << "):" << endl;
    if (cursos.empty()) {
        cout << "  (sin cursos matriculados)" << endl;
        return;
    }
    for (int i = 0; i < (int)cursos.size(); ++i) {
        cout << "  ";
        cursos[i]->imprimir();
    }
}
