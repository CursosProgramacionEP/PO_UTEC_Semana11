#include "Pedido.h"
#include <iostream>

Pedido::Pedido() {
    this->fecha = "sin fecha";
    this->monto = 0.0;
}

Pedido::Pedido(string fecha, double monto) {
    this->fecha = fecha;
    this->monto = monto;
}

// El pedido avisa cuando se destruye: sirve para comprobar
// que el Cliente no lo destruye por su cuenta (asociacion).
Pedido::~Pedido() {
    cout << "Eliminandose el pedido del " << fecha << endl;
}

void Pedido::set_fecha(string fecha) { this->fecha = fecha; }
void Pedido::set_monto(double monto) { this->monto = monto; }
string Pedido::get_fecha() { return fecha; }
double Pedido::get_monto() { return monto; }

void Pedido::imprimir() {
    cout << "Pedido -> fecha de entrega: " << fecha
         << " | monto: S/ " << monto << endl;
}
