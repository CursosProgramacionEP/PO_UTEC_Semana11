#include "Documento.h"
#include <iostream>

Documento::Documento() {
    this->titulo = "sin titulo";
}

// Los capitulos se copian dentro del documento: son parte de el.
Documento::Documento(string titulo, vector<Capitulo> capitulos) {
    this->titulo = titulo;
    this->capitulos = capitulos;
    if (!capitulos.empty()) {
        this->capitulo = capitulos[0];   // el capitulo inicial del documento
    }
}

// Al destruirse el documento desaparecen tambien sus capitulos:
// el vector los libera automaticamente porque los guarda por valor.
Documento::~Documento() {
    cout << "Eliminandose el documento " << titulo
         << " y sus " << capitulos.size() << " capitulos" << endl;
}

void Documento::set_titulo(string titulo) { this->titulo = titulo; }
string Documento::get_titulo() { return titulo; }

void Documento::agregar_capitulo(Capitulo capitulo) {
    capitulos.push_back(capitulo);
}

int Documento::cantidad_capitulos() {
    return (int)capitulos.size();
}

void Documento::imprimir() {
    cout << "Documento: " << titulo << endl;
    cout << "  Capitulo inicial -> ";
    capitulo.imprimir();
    cout << "  Contenido:" << endl;
    for (int i = 0; i < (int)capitulos.size(); ++i) {
        cout << "    ";
        capitulos[i].imprimir();
    }
}
