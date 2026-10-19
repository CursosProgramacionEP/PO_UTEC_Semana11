#ifndef CPROFESOR_H
#define CPROFESOR_H

#include "Tipos.h"

class CProfesor {
private:
    TipoString m_Codigo;
    TipoString m_Nombres;
    TipoString m_ApePaterno;
    TipoString m_ApeMaterno;
    TipoString m_CuentaCorreo;

public:
    CProfesor();
    CProfesor(TipoString pCodigo, TipoString pNombres,
              TipoString pApePaterno, TipoString pApeMaterno,
              TipoString pCuentaCorreo);
    ~CProfesor();

    TipoString getCodigo();
    TipoString getNombres();

    void imprimir();
};

#endif
