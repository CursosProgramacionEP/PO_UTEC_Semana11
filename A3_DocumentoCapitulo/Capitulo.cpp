#include "Capitulo.h"
#include <iostream>

Capitulo::Capitulo() {
    this->numero = 0;
    this->titulo = "sin titulo";
}

Capitulo::Capitulo(int numero, string titulo) {
    this->numero = numero;
    this->titulo = titulo;
}

Capitulo::~Capitulo() {
}

void Capitulo::set_numero(int numero) { this->numero = numero; }
void Capitulo::set_titulo(string titulo) { this->titulo = titulo; }
int Capitulo::get_numero() { return numero; }
string Capitulo::get_titulo() { return titulo; }

void Capitulo::imprimir() {
    cout << "Capitulo " << numero << ": " << titulo << endl;
}
