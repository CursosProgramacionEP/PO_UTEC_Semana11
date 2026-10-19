#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Pedido.h"
using namespace std;

class Cliente {
private:
    string nombre;
    Pedido* pedido;   // asociacion: el cliente conoce al pedido, no lo crea ni lo destruye

public:
    Cliente();
    Cliente(string nombre);
    ~Cliente();

    void set_nombre(string nombre);
    string get_nombre();

    void asociar_pedido(Pedido* pedido);
    void cancelar_pedido();
    bool tiene_pedido();

    void imprimir();
};

#endif
