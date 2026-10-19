#include "CObstaculo.h"

CObstaculo::CObstaculo() {
    this->m_Nombre = "sin nombre";
    this->m_Simbolo = '#';
    this->m_Dureza = 1;
}

CObstaculo::CObstaculo(TipoString pNombre, TipoCaracter pSimbolo,
                       TipoEntero pPosX, TipoEntero pPosY, TipoEntero pDureza)
    : m_Coordenada(pPosX, pPosY) {
    this->m_Nombre = pNombre;
    this->m_Simbolo = pSimbolo;
    this->m_Dureza = pDureza;
}

CObstaculo::~CObstaculo() {
}

TipoString   CObstaculo::getNombre()  { return m_Nombre; }
TipoCaracter CObstaculo::getSimbolo() { return m_Simbolo; }
TipoEntero   CObstaculo::getPosX()    { return m_Coordenada.getPosX(); }
TipoEntero   CObstaculo::getPosY()    { return m_Coordenada.getPosY(); }
TipoEntero   CObstaculo::getDureza()  { return m_Dureza; }
