#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente() {
    this->nombre = "sin nombre";
    this->pedido = nullptr;
}

Cliente::Cliente(const string& nombre) {
    this->nombre = nombre;
    this->pedido = nullptr;
}

// En una asociacion el cliente NO libera el pedido:
// el pedido tiene vida propia y lo libera quien lo creo.
Cliente::~Cliente() {
    cout << "Eliminandose el cliente " << nombre << endl;
}

void Cliente::set_nombre(const string& nombre) { this->nombre = nombre; }
string Cliente::get_nombre() const { return nombre; }

void Cliente::asociar_pedido(Pedido* pedido) {
    this->pedido = pedido;
}

// Cancelar solo rompe el enlace: el objeto Pedido sigue existiendo.
void Cliente::cancelar_pedido() {
    this->pedido = nullptr;
}

bool Cliente::tiene_pedido() const {
    return pedido != nullptr;
}

void Cliente::imprimir() const {
    cout << "Cliente: " << nombre << endl;
    if (pedido != nullptr) {
        cout << "  ";
        pedido->imprimir();
    } else {
        cout << "  (sin pedido asociado)" << endl;
    }
}
