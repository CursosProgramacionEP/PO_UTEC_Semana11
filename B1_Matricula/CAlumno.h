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
    CAlumno(TipoString pCodigo, TipoString pNombres,
            TipoString pApePaterno, TipoString pApeMaterno,
            TipoString pCuentaCorreo, TipoEntero pEdad,
            TipoEntero pCreditosAcumulados);
    ~CAlumno();

    TipoString getCodigo();
    TipoString getNombres();
    TipoEntero getCreditosAcumulados();

    void imprimir();
};

#endif
