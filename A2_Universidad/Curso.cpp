#include "Curso.h"
#include <iostream>

Curso::Curso() {
    this->nombre = "sin nombre";
    this->codigo = "sin codigo";
}

Curso::Curso(string nombre, string codigo) {
    this->nombre = nombre;
    this->codigo = codigo;
}

Curso::~Curso() {
    cout << "Eliminandose el curso " << codigo << endl;
}

void Curso::set_nombre(string nombre) { this->nombre = nombre; }
void Curso::set_codigo(string codigo) { this->codigo = codigo; }
string Curso::get_nombre() { return nombre; }
string Curso::get_codigo() { return codigo; }

void Curso::imprimir() {
    cout << codigo << " - " << nombre << endl;
}
