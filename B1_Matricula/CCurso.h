#ifndef CCURSO_H
#define CCURSO_H

#include "Tipos.h"

class CCurso {
private:
    TipoString m_Codigo;
    TipoString m_Nombre;
    TipoString m_PreRequisito;
    TipoEntero m_Ciclo;
    TipoEntero m_Creditos;

public:
    CCurso();
    CCurso(TipoString pCodigo, TipoString pNombre,
           TipoString pPreRequisito, TipoEntero pCiclo,
           TipoEntero pCreditos);
    ~CCurso();

    TipoString getCodigo();
    TipoString getNombre();
    TipoEntero getCreditos();

    void imprimir();
};

#endif
