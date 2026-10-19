#ifndef COBSTACULO_H
#define COBSTACULO_H

#include "Tipos.h"
#include "CCoordenada.h"

class CObstaculo {
private:
    TipoString   m_Nombre;
    TipoCaracter m_Simbolo;
    CCoordenada  m_Coordenada;   // composicion
    TipoEntero   m_Dureza;

public:
    CObstaculo();
    CObstaculo(TipoString pNombre, TipoCaracter pSimbolo,
               TipoEntero pPosX, TipoEntero pPosY, TipoEntero pDureza);
    virtual ~CObstaculo();

    TipoString   getNombre();
    TipoCaracter getSimbolo();
    TipoEntero   getPosX();
    TipoEntero   getPosY();
    TipoEntero   getDureza();
};

#endif
