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
    CProfesor(const TipoString& pCodigo, const TipoString& pNombres, const TipoString& pApePaterno, const TipoString& pApeMaterno, const TipoString& pCuentaCorreo);
    ~CProfesor();

    TipoString getCodigo() const;
    TipoString getNombres() const;

    void imprimir() const;
};

#endif
