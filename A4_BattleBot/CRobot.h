#ifndef CROBOT_H
#define CROBOT_H

#include "Tipos.h"
#include "CCoordenada.h"
#include "CObstaculo.h"

class CRobot {
private:
    TipoString   m_Nombre;
    TipoCaracter m_Color;
    CCoordenada  m_Coordenada;   // composicion: la coordenada es parte del robot
    TipoEntero   m_Vidas;
    TipoEntero   m_Peso;

public:
    CRobot();
    CRobot(const TipoString& pNombre, TipoCaracter pColor,
           TipoEntero pPosX, TipoEntero pPosY);
    CRobot(const TipoString& pNombre, TipoCaracter pColor,
           TipoEntero pPosX, TipoEntero pPosY,
           TipoEntero pVidas, TipoEntero pPeso);
    virtual ~CRobot();

    void setNombre(const TipoString& pNombre);
    void setVidas(TipoEntero pVidas);
    void moverse(TipoEntero pPosX, TipoEntero pPosY);
    void golpear(CRobot &pEnemigo);
    void Chocar(CObstaculo &pObstaculo);

    TipoString   getNombre() const;
    TipoEntero   getPosX() const;
    TipoEntero   getPosY() const;
    TipoCaracter getColor() const;
    TipoEntero   getVidas() const;
    TipoEntero   getPeso() const;
    TipoString   mostrarPosicion() const;
};

#endif
