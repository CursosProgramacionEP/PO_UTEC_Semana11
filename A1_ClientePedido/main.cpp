#include <iostream>
#include "Cliente.h"
#include "Pedido.h"

using namespace std;

int main() {
    // El pedido se crea aparte del cliente: son dos objetos independientes.
    Pedido* pedido = new Pedido("15/11/2026", 250.50);

    Cliente cliente("Ana Torres");
    cliente.asociar_pedido(pedido);

    cout << "--- El cliente realiza su pedido ---" << endl;
    cliente.imprimir();

    cout << "\n--- El cliente cancela el pedido ---" << endl;
    cliente.cancelar_pedido();
    cliente.imprimir();

    // El pedido sigue vivo aunque el cliente ya no lo apunte.
    cout << "\nEl objeto pedido sigue existiendo:" << endl;
    pedido->imprimir();

    cout << "\n--- Fin del programa ---" << endl;
    delete pedido;   // lo libera quien lo creo, no el cliente
    pedido = nullptr;

    return 0;
}
