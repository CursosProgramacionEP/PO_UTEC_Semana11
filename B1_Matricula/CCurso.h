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
    CCurso(const TipoString& pCodigo, const TipoString& pNombre, const TipoString& pPreRequisito, TipoEntero pCiclo,
           TipoEntero pCreditos);
    ~CCurso();

    TipoString getCodigo() const;
    TipoString getNombre() const;
    TipoEntero getCreditos() const;

    void imprimir() const;
};

#endif
