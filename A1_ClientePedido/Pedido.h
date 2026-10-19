#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
using namespace std;

class Pedido {
private:
    string fecha;
    double monto;

public:
    Pedido();
    Pedido(string fecha, double monto);
    ~Pedido();

    void set_fecha(string fecha);
    void set_monto(double monto);
    string get_fecha();
    double get_monto();

    void imprimir();
};

#endif
