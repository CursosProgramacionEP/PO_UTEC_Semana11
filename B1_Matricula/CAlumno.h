#ifndef CALUMNO_H
#define CALUMNO_H

#include "Tipos.h"

class CAlumno {
private:
    TipoString m_Codigo;
    TipoString m_Nombres;
    TipoString m_ApePaterno;
    TipoString m_ApeMaterno;
    TipoString m_CuentaCorreo;
    TipoEntero m_Edad;
    TipoEntero m_CreditosAcumulados;

public:
    CAlumno();
    CAlumno(const TipoString& pCodigo, const TipoString& pNombres, const TipoString& pApePaterno, const TipoString& pApeMaterno, const TipoString& pCuentaCorreo, TipoEntero pEdad,
            TipoEntero pCreditosAcumulados);
    ~CAlumno();

    TipoString getCodigo() const;
    TipoString getNombres() const;
    TipoEntero getCreditosAcumulados() const;

    void imprimir() const;
};

#endif
