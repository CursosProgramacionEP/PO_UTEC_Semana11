#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Pedido.h"

class Cliente {
private:
    std::string nombre;
    Pedido* pedido;   // asociacion: el cliente conoce al pedido, no lo crea ni lo destruye

public:
    Cliente();
    Cliente(const std::string& nombre);
    ~Cliente();

    void set_nombre(const std::string& nombre);
    std::string get_nombre() const;

    void asociar_pedido(Pedido* pedido);
    void cancelar_pedido();
    bool tiene_pedido() const;

    void imprimir() const;
};

#endif
