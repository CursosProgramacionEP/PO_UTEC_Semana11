#ifndef CCOORDENADA_H
#define CCOORDENADA_H

#include "Tipos.h"

class CCoordenada {
private:
    TipoEntero m_PosX;
    TipoEntero m_PosY;

public:
    CCoordenada();
    CCoordenada(TipoEntero pPosX, TipoEntero pPosY);
    virtual ~CCoordenada();

    void setPosX(TipoEntero pPosX);
    void setPosY(TipoEntero pPosY);
    TipoEntero getPosX();
    TipoEntero getPosY();
};

#endif
