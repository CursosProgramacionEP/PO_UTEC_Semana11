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
    CLaboratorio(const TipoString& pCodigo, TipoEntero pNroPiso,
                 TipoEntero pNroComputadoras);
    ~CLaboratorio();

    TipoString getCodigo() const;
    TipoEntero getNroComputadoras() const;

    void imprimir() const;
};

#endif
