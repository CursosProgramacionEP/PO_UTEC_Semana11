#ifndef CLABORATORIO_H
#define CLABORATORIO_H

#include "Tipos.h"

class CLaboratorio {
private:
    TipoString m_Codigo;
    TipoEntero m_NroPiso;
    TipoEntero m_NroComputadoras;

public:
    CLaboratorio();
    CLaboratorio(TipoString pCodigo, TipoEntero pNroPiso,
                 TipoEntero pNroComputadoras);
    ~CLaboratorio();

    TipoString getCodigo();
    TipoEntero getNroComputadoras();

    void imprimir();
};

#endif
