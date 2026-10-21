#include "CObstaculo.h"

using namespace std;

CObstaculo::CObstaculo() {
    this->m_Nombre = "sin nombre";
    this->m_Simbolo = '#';
    this->m_Dureza = 1;
}

CObstaculo::CObstaculo(const TipoString& pNombre, TipoCaracter pSimbolo,
                       TipoEntero pPosX, TipoEntero pPosY, TipoEntero pDureza)
    : m_Coordenada(pPosX, pPosY) {
    this->m_Nombre = pNombre;
    this->m_Simbolo = pSimbolo;
    this->m_Dureza = pDureza;
}

CObstaculo::~CObstaculo() {
}

TipoString   CObstaculo::getNombre() const { return m_Nombre; }
TipoCaracter CObstaculo::getSimbolo() const { return m_Simbolo; }
TipoEntero   CObstaculo::getPosX() const { return m_Coordenada.getPosX(); }
TipoEntero   CObstaculo::getPosY() const { return m_Coordenada.getPosY(); }
TipoEntero   CObstaculo::getDureza() const { return m_Dureza; }
