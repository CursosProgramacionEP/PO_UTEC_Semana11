#include "Alumno.h"
#include <iostream>

using namespace std;

Alumno::Alumno() {
    this->nombre = "sin nombre";
    this->codigo = "sin codigo";
}

Alumno::Alumno(const string& nombre, const string& codigo) {
    this->nombre = nombre;
    this->codigo = codigo;
}

// El alumno no destruye sus cursos: solo guarda los punteros.
Alumno::~Alumno() {
    cout << "Eliminandose el alumno " << codigo << endl;
}

void Alumno::set_nombre(const string& nombre) { this->nombre = nombre; }
void Alumno::set_codigo(const string& codigo) { this->codigo = codigo; }
string Alumno::get_nombre() const { return nombre; }
string Alumno::get_codigo() const { return codigo; }

void Alumno::agregar_clase(Curso* curso) {
    cursos.push_back(curso);
}

void Alumno::imprimir_clase() const {
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
