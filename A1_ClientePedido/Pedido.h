#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>

class Pedido {
private:
    std::string fecha;
    double monto;

public:
    Pedido();
    Pedido(const std::string& fecha, double monto);
    ~Pedido();

    void set_fecha(const std::string& fecha);
    void set_monto(double monto);
    std::string get_fecha() const;
    double get_monto() const;

    void imprimir() const;
};

#endif
