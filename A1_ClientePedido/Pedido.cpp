#include "Pedido.h"
#include <iostream>

using namespace std;

Pedido::Pedido() {
    this->fecha = "sin fecha";
    this->monto = 0.0;
}

Pedido::Pedido(const string& fecha, double monto) {
    this->fecha = fecha;
    this->monto = monto;
}

// El pedido avisa cuando se destruye: sirve para comprobar
// que el Cliente no lo destruye por su cuenta (asociacion).
Pedido::~Pedido() {
    cout << "Eliminandose el pedido del " << fecha << endl;
}

void Pedido::set_fecha(const string& fecha) { this->fecha = fecha; }
void Pedido::set_monto(double monto) { this->monto = monto; }
string Pedido::get_fecha() const { return fecha; }
double Pedido::get_monto() const { return monto; }

void Pedido::imprimir() const {
    cout << "Pedido -> fecha de entrega: " << fecha
         << " | monto: S/ " << monto << endl;
}
