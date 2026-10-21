#include "Curso.h"
#include <iostream>

using namespace std;

Curso::Curso() {
    this->nombre = "sin nombre";
    this->codigo = "sin codigo";
}

Curso::Curso(const string& nombre, const string& codigo) {
    this->nombre = nombre;
    this->codigo = codigo;
}

Curso::~Curso() {
    cout << "Eliminandose el curso " << codigo << endl;
}

void Curso::set_nombre(const string& nombre) { this->nombre = nombre; }
void Curso::set_codigo(const string& codigo) { this->codigo = codigo; }
string Curso::get_nombre() const { return nombre; }
string Curso::get_codigo() const { return codigo; }

void Curso::imprimir() const {
    cout << codigo << " - " << nombre << endl;
}
