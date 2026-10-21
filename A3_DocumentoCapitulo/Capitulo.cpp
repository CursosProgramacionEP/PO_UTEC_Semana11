#include "Capitulo.h"
#include <iostream>

using namespace std;

Capitulo::Capitulo() {
    this->numero = 0;
    this->titulo = "sin titulo";
}

Capitulo::Capitulo(int numero, const string& titulo) {
    this->numero = numero;
    this->titulo = titulo;
}

Capitulo::~Capitulo() {
}

void Capitulo::set_numero(int numero) { this->numero = numero; }
void Capitulo::set_titulo(const string& titulo) { this->titulo = titulo; }
int Capitulo::get_numero() const { return numero; }
string Capitulo::get_titulo() const { return titulo; }

void Capitulo::imprimir() const {
    cout << "Capitulo " << numero << ": " << titulo << endl;
}
